#include "netsim/nameserver.h"
#include "netsim/portnumber.h"
namespace HadoopNetSim {

NameServer::NameServer(void) {
  this->running_ = false;
  this->sock_ = NULL;
}

static ns3::TypeId NameServer::GetTypeId(void) {
  static ns3::TypeId tid = ns3::TypeId("HadoopNetSim::NameServer")
                           .SetParent<ns3::Application>()
                           .AddConstructor<NameServer>();
}

void NameServer::StartApplication() {
  this->sock_ = ns3::Socket::CreateSocket(this->GetNode(), ns3::TcpSocketFactory::GetTypeId());
  ns3::InetSocketAddress addr = ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), kNameServerPort);
  this->sock_->Bind(addr);
  this->sock_->Listen();
  this->sock_->ShutdownSend();

  this->sock_->SetAcceptCallback(ns3::MakeNullCallback<bool, ns3::Ptr<ns3::Socket>, const ns3::Address&>(),
                                        ns3::MakeCallback(&NameServer::HandleAccept, this));
}

void NameServer::HandleAccept(ns3::Ptr<ns3::Socket> sock, const ns3::Address& from) {
  ns3::Ptr<MsgTransport> mt = ns3::Create<MsgTransport>(sock);
  this->mts_.push_back(sock);
}

ns3::Ptr<MsgTransport> NameServer::FindMTByPeer(HostName peer) const {
  for (std::unordered_set<ns3::Ptr<MsgTransport>>::iterator it = this->mts_.begin(); it != this->mts_.end(); ++it) {
    ns3::Ptr<MsgTransport> mt = *it;
    if (mt->peer() == peer) return mt;
  }
  return NULL;
}

bool NameServer::NameResponse(ns3::Ptr<MsgInfo> msg) {
  assert(msg->type() == kMTNameResponse);
  ns3::Ptr<MsgTransport> mt = this->FindMTByPeer(msg->dst());
  if (mt == NULL) return false;
  mt->Send(msg);
}

};//namespace HadoopNetSim