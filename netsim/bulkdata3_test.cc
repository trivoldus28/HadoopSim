#include "netsim/netsim.h"
#include <array>
#include <unordered_map>
#include "gtest/gtest.h"
namespace HadoopNetSim {

/*
TOPOLOGY
rackrow-50-6

EVENTS after ready
2 seconds
  a Server send 2 x 49 DataRequest (256B) to all other servers
  reply DataResponse (64MB)
*/

const std::array <std::string, 512> Server = {
    "server-0.novalocal",
    "server-1.novalocal",
    "server-2.novalocal",
    "server-3.novalocal",
    "server-4.novalocal",
    "server-5.novalocal",
    "server-6.novalocal",
    "server-7.novalocal",
    "server-8.novalocal",
    "server-9.novalocal",
    "server-10.novalocal",
    "server-11.novalocal",
    "server-12.novalocal",
    "server-13.novalocal",
    "server-14.novalocal",
    "server-15.novalocal",
    "server-16.novalocal",
    "server-17.novalocal",
    "server-18.novalocal",
    "server-19.novalocal",
    "server-20.novalocal",
    "server-21.novalocal",
    "server-22.novalocal",
    "server-23.novalocal",
    "server-24.novalocal",
    "server-25.novalocal",
    "server-26.novalocal",
    "server-27.novalocal",
    "server-28.novalocal",
    "server-29.novalocal",
    "server-30.novalocal",
    "server-31.novalocal",
    "server-32.novalocal",
    "server-33.novalocal",
    "server-34.novalocal",
    "server-35.novalocal",
    "server-36.novalocal",
    "server-37.novalocal",
    "server-38.novalocal",
    "server-39.novalocal",
    "server-40.novalocal",
    "server-41.novalocal",
    "server-42.novalocal",
    "server-43.novalocal",
    "server-44.novalocal",
    "server-45.novalocal",
    "server-46.novalocal",
    "server-47.novalocal",
    "server-48.novalocal",
    "server-49.novalocal",
    "server-50.novalocal",
    "server-51.novalocal",
    "server-52.novalocal",
    "server-53.novalocal",
    "server-54.novalocal",
    "server-55.novalocal",
    "server-56.novalocal",
    "server-57.novalocal",
    "server-58.novalocal",
    "server-59.novalocal",
    "server-60.novalocal",
    "server-61.novalocal",
    "server-62.novalocal",
    "server-63.novalocal",
    "server-64.novalocal",
    "server-65.novalocal",
    "server-66.novalocal",
    "server-67.novalocal",
    "server-68.novalocal",
    "server-69.novalocal",
    "server-70.novalocal",
    "server-71.novalocal",
    "server-72.novalocal",
    "server-73.novalocal",
    "server-74.novalocal",
    "server-75.novalocal",
    "server-76.novalocal",
    "server-77.novalocal",
    "server-78.novalocal",
    "server-79.novalocal",
    "server-80.novalocal",
    "server-81.novalocal",
    "server-82.novalocal",
    "server-83.novalocal",
    "server-84.novalocal",
    "server-85.novalocal",
    "server-86.novalocal",
    "server-87.novalocal",
    "server-88.novalocal",
    "server-89.novalocal",
    "server-90.novalocal",
    "server-91.novalocal",
    "server-92.novalocal",
    "server-93.novalocal",
    "server-94.novalocal",
    "server-95.novalocal",
    "server-96.novalocal",
    "server-97.novalocal",
    "server-98.novalocal",
    "server-99.novalocal",
    "server-100.novalocal",
    "server-101.novalocal",
    "server-102.novalocal",
    "server-103.novalocal",
    "server-104.novalocal",
    "server-105.novalocal",
    "server-106.novalocal",
    "server-107.novalocal",
    "server-108.novalocal",
    "server-109.novalocal",
    "server-110.novalocal",
    "server-111.novalocal",
    "server-112.novalocal",
    "server-113.novalocal",
    "server-114.novalocal",
    "server-115.novalocal",
    "server-116.novalocal",
    "server-117.novalocal",
    "server-118.novalocal",
    "server-119.novalocal",
    "server-120.novalocal",
    "server-121.novalocal",
    "server-122.novalocal",
    "server-123.novalocal",
    "server-124.novalocal",
    "server-125.novalocal",
    "server-126.novalocal",
    "server-127.novalocal",
    "server-128.novalocal",
    "server-129.novalocal",
    "server-130.novalocal",
    "server-131.novalocal",
    "server-132.novalocal",
    "server-133.novalocal",
    "server-134.novalocal",
    "server-135.novalocal",
    "server-136.novalocal",
    "server-137.novalocal",
    "server-138.novalocal",
    "server-139.novalocal",
    "server-140.novalocal",
    "server-141.novalocal",
    "server-142.novalocal",
    "server-143.novalocal",
    "server-144.novalocal",
    "server-145.novalocal",
    "server-146.novalocal",
    "server-147.novalocal",
    "server-148.novalocal",
    "server-149.novalocal",
    "server-150.novalocal",
    "server-151.novalocal",
    "server-152.novalocal",
    "server-153.novalocal",
    "server-154.novalocal",
    "server-155.novalocal",
    "server-156.novalocal",
    "server-157.novalocal",
    "server-158.novalocal",
    "server-159.novalocal",
    "server-160.novalocal",
    "server-161.novalocal",
    "server-162.novalocal",
    "server-163.novalocal",
    "server-164.novalocal",
    "server-165.novalocal",
    "server-166.novalocal",
    "server-167.novalocal",
    "server-168.novalocal",
    "server-169.novalocal",
    "server-170.novalocal",
    "server-171.novalocal",
    "server-172.novalocal",
    "server-173.novalocal",
    "server-174.novalocal",
    "server-175.novalocal",
    "server-176.novalocal",
    "server-177.novalocal",
    "server-178.novalocal",
    "server-179.novalocal",
    "server-180.novalocal",
    "server-181.novalocal",
    "server-182.novalocal",
    "server-183.novalocal",
    "server-184.novalocal",
    "server-185.novalocal",
    "server-186.novalocal",
    "server-187.novalocal",
    "server-188.novalocal",
    "server-189.novalocal",
    "server-190.novalocal",
    "server-191.novalocal",
    "server-192.novalocal",
    "server-193.novalocal",
    "server-194.novalocal",
    "server-195.novalocal",
    "server-196.novalocal",
    "server-197.novalocal",
    "server-198.novalocal",
    "server-199.novalocal",
    "server-200.novalocal",
    "server-201.novalocal",
    "server-202.novalocal",
    "server-203.novalocal",
    "server-204.novalocal",
    "server-205.novalocal",
    "server-206.novalocal",
    "server-207.novalocal",
    "server-208.novalocal",
    "server-209.novalocal",
    "server-210.novalocal",
    "server-211.novalocal",
    "server-212.novalocal",
    "server-213.novalocal",
    "server-214.novalocal",
    "server-215.novalocal",
    "server-216.novalocal",
    "server-217.novalocal",
    "server-218.novalocal",
    "server-219.novalocal",
    "server-220.novalocal",
    "server-221.novalocal",
    "server-222.novalocal",
    "server-223.novalocal",
    "server-224.novalocal",
    "server-225.novalocal",
    "server-226.novalocal",
    "server-227.novalocal",
    "server-228.novalocal",
    "server-229.novalocal",
    "server-230.novalocal",
    "server-231.novalocal",
    "server-232.novalocal",
    "server-233.novalocal",
    "server-234.novalocal",
    "server-235.novalocal",
    "server-236.novalocal",
    "server-237.novalocal",
    "server-238.novalocal",
    "server-239.novalocal",
    "server-240.novalocal",
    "server-241.novalocal",
    "server-242.novalocal",
    "server-243.novalocal",
    "server-244.novalocal",
    "server-245.novalocal",
    "server-246.novalocal",
    "server-247.novalocal",
    "server-248.novalocal",
    "server-249.novalocal",
    "server-250.novalocal",
    "server-251.novalocal",
    "server-252.novalocal",
    "server-253.novalocal",
    "server-254.novalocal",
    "server-255.novalocal",
    "server-256.novalocal",
    "server-257.novalocal",
    "server-258.novalocal",
    "server-259.novalocal",
    "server-260.novalocal",
    "server-261.novalocal",
    "server-262.novalocal",
    "server-263.novalocal",
    "server-264.novalocal",
    "server-265.novalocal",
    "server-266.novalocal",
    "server-267.novalocal",
    "server-268.novalocal",
    "server-269.novalocal",
    "server-270.novalocal",
    "server-271.novalocal",
    "server-272.novalocal",
    "server-273.novalocal",
    "server-274.novalocal",
    "server-275.novalocal",
    "server-276.novalocal",
    "server-277.novalocal",
    "server-278.novalocal",
    "server-279.novalocal",
    "server-280.novalocal",
    "server-281.novalocal",
    "server-282.novalocal",
    "server-283.novalocal",
    "server-284.novalocal",
    "server-285.novalocal",
    "server-286.novalocal",
    "server-287.novalocal",
    "server-288.novalocal",
    "server-289.novalocal",
    "server-290.novalocal",
    "server-291.novalocal",
    "server-292.novalocal",
    "server-293.novalocal",
    "server-294.novalocal",
    "server-295.novalocal",
    "server-296.novalocal",
    "server-297.novalocal",
    "server-298.novalocal",
    "server-299.novalocal",
    "server-300.novalocal",
    "server-301.novalocal",
    "server-302.novalocal",
    "server-303.novalocal",
    "server-304.novalocal",
    "server-305.novalocal",
    "server-306.novalocal",
    "server-307.novalocal",
    "server-308.novalocal",
    "server-309.novalocal",
    "server-310.novalocal",
    "server-311.novalocal",
    "server-312.novalocal",
    "server-313.novalocal",
    "server-314.novalocal",
    "server-315.novalocal",
    "server-316.novalocal",
    "server-317.novalocal",
    "server-318.novalocal",
    "server-319.novalocal",
    "server-320.novalocal",
    "server-321.novalocal",
    "server-322.novalocal",
    "server-323.novalocal",
    "server-324.novalocal",
    "server-325.novalocal",
    "server-326.novalocal",
    "server-327.novalocal",
    "server-328.novalocal",
    "server-329.novalocal",
    "server-330.novalocal",
    "server-331.novalocal",
    "server-332.novalocal",
    "server-333.novalocal",
    "server-334.novalocal",
    "server-335.novalocal",
    "server-336.novalocal",
    "server-337.novalocal",
    "server-338.novalocal",
    "server-339.novalocal",
    "server-340.novalocal",
    "server-341.novalocal",
    "server-342.novalocal",
    "server-343.novalocal",
    "server-344.novalocal",
    "server-345.novalocal",
    "server-346.novalocal",
    "server-347.novalocal",
    "server-348.novalocal",
    "server-349.novalocal",
    "server-350.novalocal",
    "server-351.novalocal",
    "server-352.novalocal",
    "server-353.novalocal",
    "server-354.novalocal",
    "server-355.novalocal",
    "server-356.novalocal",
    "server-357.novalocal",
    "server-358.novalocal",
    "server-359.novalocal",
    "server-360.novalocal",
    "server-361.novalocal",
    "server-362.novalocal",
    "server-363.novalocal",
    "server-364.novalocal",
    "server-365.novalocal",
    "server-366.novalocal",
    "server-367.novalocal",
    "server-368.novalocal",
    "server-369.novalocal",
    "server-370.novalocal",
    "server-371.novalocal",
    "server-372.novalocal",
    "server-373.novalocal",
    "server-374.novalocal",
    "server-375.novalocal",
    "server-376.novalocal",
    "server-377.novalocal",
    "server-378.novalocal",
    "server-379.novalocal",
    "server-380.novalocal",
    "server-381.novalocal",
    "server-382.novalocal",
    "server-383.novalocal",
    "server-384.novalocal",
    "server-385.novalocal",
    "server-386.novalocal",
    "server-387.novalocal",
    "server-388.novalocal",
    "server-389.novalocal",
    "server-390.novalocal",
    "server-391.novalocal",
    "server-392.novalocal",
    "server-393.novalocal",
    "server-394.novalocal",
    "server-395.novalocal",
    "server-396.novalocal",
    "server-397.novalocal",
    "server-398.novalocal",
    "server-399.novalocal",
    "server-400.novalocal",
    "server-401.novalocal",
    "server-402.novalocal",
    "server-403.novalocal",
    "server-404.novalocal",
    "server-405.novalocal",
    "server-406.novalocal",
    "server-407.novalocal",
    "server-408.novalocal",
    "server-409.novalocal",
    "server-410.novalocal",
    "server-411.novalocal",
    "server-412.novalocal",
    "server-413.novalocal",
    "server-414.novalocal",
    "server-415.novalocal",
    "server-416.novalocal",
    "server-417.novalocal",
    "server-418.novalocal",
    "server-419.novalocal",
    "server-420.novalocal",
    "server-421.novalocal",
    "server-422.novalocal",
    "server-423.novalocal",
    "server-424.novalocal",
    "server-425.novalocal",
    "server-426.novalocal",
    "server-427.novalocal",
    "server-428.novalocal",
    "server-429.novalocal",
    "server-430.novalocal",
    "server-431.novalocal",
    "server-432.novalocal",
    "server-433.novalocal",
    "server-434.novalocal",
    "server-435.novalocal",
    "server-436.novalocal",
    "server-437.novalocal",
    "server-438.novalocal",
    "server-439.novalocal",
    "server-440.novalocal",
    "server-441.novalocal",
    "server-442.novalocal",
    "server-443.novalocal",
    "server-444.novalocal",
    "server-445.novalocal",
    "server-446.novalocal",
    "server-447.novalocal",
    "server-448.novalocal",
    "server-449.novalocal",
    "server-450.novalocal",
    "server-451.novalocal",
    "server-452.novalocal",
    "server-453.novalocal",
    "server-454.novalocal",
    "server-455.novalocal",
    "server-456.novalocal",
    "server-457.novalocal",
    "server-458.novalocal",
    "server-459.novalocal",
    "server-460.novalocal",
    "server-461.novalocal",
    "server-462.novalocal",
    "server-463.novalocal",
    "server-464.novalocal",
    "server-465.novalocal",
    "server-466.novalocal",
    "server-467.novalocal",
    "server-468.novalocal",
    "server-1676.novalocal",
    "server-1677.novalocal",
    "server-1678.novalocal",
    "server-1680.novalocal",
    "server-1681.novalocal",
    "server-1682.novalocal",
    "server-1683.novalocal",
    "server-1684.novalocal",
    "server-1685.novalocal",
    "server-1686.novalocal",
    "server-1687.novalocal",
    "server-1688.novalocal",
    "server-1689.novalocal",
    "server-1691.novalocal",
    "server-1693.novalocal",
    "server-1694.novalocal",
    "server-1695.novalocal",
    "server-1696.novalocal",
    "server-1697.novalocal",
    "server-1698.novalocal",
    "server-1699.novalocal",
    "server-1700.novalocal",
    "server-1701.novalocal",
    "server-1702.novalocal",
    "server-1703.novalocal",
    "server-1704.novalocal",
    "server-1705.novalocal",
    "server-1706.novalocal",
    "server-1707.novalocal",
    "server-1708.novalocal",
    "server-1709.novalocal",
    "server-1710.novalocal",
    "server-1711.novalocal",
    "server-1712.novalocal",
    "server-1713.novalocal",
    "server-1714.novalocal",
    "server-1716.novalocal",
    "server-1717.novalocal",
    "server-1718.novalocal",
    "server-1719.novalocal",
    "server-1720.novalocal",
    "server-1721.novalocal",
    "server-1722.novalocal"
};

class BulkData3TestRunner {
  public:
    BulkData3TestRunner(NetSim* netsim) {
      this->netsim_ = netsim;
      this->netsim_->set_ready_cb(ns3::MakeCallback(&BulkData3TestRunner::Ready, this));
      this->userobj_ = this;
      this->lastID = 0;
    }
    void Verify() {
      std::unordered_map<MsgType,ns3::Ptr<ns3::MinMaxAvgTotalCalculator<double>>,std::hash<int>> calcs;
      calcs[kMTDataRequest] = ns3::Create<ns3::MinMaxAvgTotalCalculator<double>>();
      calcs[kMTDataResponse] = ns3::Create<ns3::MinMaxAvgTotalCalculator<double>>();
      for (std::unordered_map<MsgId,ns3::Ptr<MsgInfo>>::const_iterator it = this->received_.cbegin(); it != this->received_.cend(); ++it) {
        ns3::Ptr<MsgInfo> msg = it->second;
        calcs[msg->type()]->Update((msg->finish() - msg->start()).GetSeconds());
      }
      int sentDataRequest = 0, sentDataResponse = 0;
      for (std::unordered_map<MsgId,MsgType>::const_iterator it = this->sent_.cbegin(); it != this->sent_.cend(); ++it) {
        if (it->second == kMTDataRequest) ++sentDataRequest;
        else if (it->second == kMTDataResponse) ++sentDataResponse;
      }
      printf("DataRequest(%d,%ld) %f,%f,%f\n", sentDataRequest, calcs[kMTDataRequest]->getCount(), calcs[kMTDataRequest]->getMin(), calcs[kMTDataRequest]->getMean(), calcs[kMTDataRequest]->getMax());
      printf("DataResponse(%d,%ld) %f,%f,%f\n", sentDataResponse, calcs[kMTDataResponse]->getCount(), calcs[kMTDataResponse]->getMin(), calcs[kMTDataResponse]->getMean(), calcs[kMTDataResponse]->getMax());
      assert(calcs[kMTDataRequest]->getCount() == 1046528);
      assert(calcs[kMTDataResponse]->getCount() == 1046528);
    }

  private:
    void* userobj_;
    NetSim* netsim_;
    std::unordered_map<MsgId,MsgType> sent_;
    std::unordered_map<MsgId,ns3::Ptr<MsgInfo>> received_;
    MsgId lastID;

    void Ready(NetSim*) {
      ns3::Simulator::Schedule(ns3::Seconds(2.0), &BulkData3TestRunner::DataRequestAll, this);
    }
    void DataRequestAll() {
      printf("Start at %f\n", ns3::Simulator::Now().GetSeconds());
      for (size_t i = 0; i < 1024; ++i) {
        for (size_t j = 0; j < Server.size(); ++j) {
          if (i%512 == j) continue;
          //ns3::Simulator::Schedule(ns3::Seconds(0.001 * j), &BulkData3TestRunner::DataRequest, this, i, j);
          this->DataRequest(i%512, j);
        }
      }
      ns3::Simulator::Schedule(ns3::Seconds(36000), &ns3::Simulator::Stop);
    }
    void DataRequest(size_t i, size_t j) {
      MsgId id;
      id = this->netsim_->DataRequest(Server[i], Server[j], 9000, ns3::MakeCallback(&BulkData3TestRunner::DataResponse, this), this->userobj_);
      assert(id != MsgId_invalid);
      this->sent_[id] = kMTDataRequest;

      id = this->netsim_->DataRequest(Server[i], Server[j], 9000, ns3::MakeCallback(&BulkData3TestRunner::DataResponse, this), this->userobj_);
      assert(id != MsgId_invalid);
      this->sent_[id] = kMTDataRequest;
    }
    void DataResponse(ns3::Ptr<MsgInfo> request_msg) {
      printf("got DataRequest %"PRIu64" %f\n", request_msg->id(), ns3::Simulator::Now().GetSeconds());
      assert(this->sent_[request_msg->id()] == kMTDataRequest);
      assert(request_msg->userobj() == this->userobj_);
      assert(this->received_.count(request_msg->id()) == 0);
      this->received_[request_msg->id()] = request_msg;
      MsgId id = this->netsim_->DataResponse(request_msg->id(), request_msg->dst(), request_msg->src(), 1000, ns3::MakeCallback(&BulkData3TestRunner::DataFinish, this), this->userobj_);
      assert(id != MsgId_invalid);
      this->sent_[id] = kMTDataResponse;
    }
    void DataFinish(ns3::Ptr<MsgInfo> response_msg) {
      printf("got DataResponse %"PRIu64" %f\n", response_msg->id(), ns3::Simulator::Now().GetSeconds());
      assert(this->sent_[response_msg->id()] == kMTDataResponse);
      assert(response_msg->userobj() == this->userobj_);
      assert(this->received_.count(response_msg->id()) == 0);
      this->received_[response_msg->id()] = response_msg;
    }
    DISALLOW_COPY_AND_ASSIGN(BulkData3TestRunner);
};

TEST(NetSimTest, BulkData3) {
  Topology topology;
  //topology.Load("examples/HadoopSim/bench-trace/star.nettopo");
  topology.Load("examples/HadoopSim/bench-trace/rackrow-50-6.nettopo");
  std::unordered_set<HostName> managers; managers.insert("manager");
  //ASSERT_EQ(52, topology.nodes().size());

  EXPECT_EXIT({
    NetSim netsim;
    //ns3::Config::SetDefault("ns3::DropTailQueue::MaxPackets", ns3::UintegerValue(200));
    //ns3::LogComponentEnable("TcpSocketBase", ns3::LOG_LEVEL_LOGIC);
    //ns3::LogComponentEnable("TcpNewReno", ns3::LOG_LEVEL_LOGIC);
    netsim.BuildTopology(topology);
    netsim.InstallApps(managers);

    BulkData3TestRunner runner(&netsim);
    ns3::Simulator::Run();
    ns3::Simulator::Destroy();
    runner.Verify();
    ::exit(0);
  }, ::testing::ExitedWithCode(0), "");
}

};//namespace HadoopNetSim