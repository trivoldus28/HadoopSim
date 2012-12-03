#ifndef HADOOPSIM_NETSIM_TOPOLOGY_H_
#define HADOOPSIM_NETSIM_TOPOLOGY_H_
#include "netsim/defs.h"
#include <unordered_set>
#include <unordered_map>
#include "json/json.h"
namespace HadoopNetSim {

enum NodeType {
  kNTNone,
  kNTHost,
  kNTSwitch
};

class Node : public ns3::SimpleRefCount<Node> {
  public:
    Node(void);
    virtual ~Node(void) {}
    
    const std::string& name(void) const { return this->name_; }
    NodeType type(void) const { return this->type_; }
    const ns3::Ipv4Address& ip(void) const { return this->ip_; }
    const std::unordered_set<std::string>& devices(void) const { return this->devices_; }

    void FromJson(::json_value* o);

  private:
    std::string name_;
    NodeType type_;
    ns3::Ipv4Address ip_;
    std::unordered_set<std::string> devices_;

    DISALLOW_COPY_AND_ASSIGN(Node);
};

typedef int32_t LinkId;
static const LinkId LinkId_invalid = 0;
//LinkId>0: from node1.port1 to node2.port2
//LinkId<0: from node2.port2 to node1.port1

enum LinkType {
  kLTNone,
  kLTEth1G
};

class Link : public ns3::SimpleRefCount<Node> {
  public:
    Link(void);
    virtual ~Link(void) {}
    
    LinkId id(void) const { return this->id_; }
    const std::string& node1(void) const { return this->node1_; }
    const std::string& port1(void) const { return this->port1_; }
    const std::string& node2(void) const { return this->node2_; }
    const std::string& port2(void) const { return this->port2_; }
    LinkType type(void) const { return this->type_; }
    
    void FromJson(::json_value* o);

  private:
    LinkId id_;//LinkId from node1.port1 to node2.port2
    std::string node1_;
    std::string port1_;
    std::string node2_;
    std::string port2_;
    LinkType type_;

    DISALLOW_COPY_AND_ASSIGN(Link);
};

class Topology {
  public:
    Topology(void) {}
    const std::unordered_map<std::string,ns3::Ptr<Node>>& nodes(void) const { return this->nodes_; }
    const std::unordered_map<LinkId,ns3::Ptr<Link>>& links(void) const { return this->links_; }

    void Load(const std::string& filename);
    void LoadString(char* json);
    
  private:
    std::unordered_map<std::string,ns3::Ptr<Node>> nodes_;//name=>Node
    std::unordered_map<LinkId,ns3::Ptr<Link>> links_;//positive LinkId=>Link
    DISALLOW_COPY_AND_ASSIGN(Topology);
};

};//namespace HadoopNetSim
#endif//HADOOPSIM_NS3_TOPOLOGY_H_