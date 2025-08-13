#include "ros/ros.h"
#include "topic_test/add_int.h"

bool doRequest(topic_test::add_int::Request &req, 
    topic_test::add_int::Response &resp) {
    int num1 = req.num1;
    int num2 = req.num2;

    ROS_INFO("Request : %d + %d", num1, num2);

    if (num1 < 0 || num2 < 0) 
    {
        ROS_INFO("negative number input");
        return false;
    }
    resp.sum = num1 + num2;
    return true;
    }

    int main(int argc, char **argv) 
    {
        setlocale(LC_ALL, "");
        
        ros::init(argc, argv, "test_srv_ser");
        ros::NodeHandle nh;
        ros::ServiceServer server = nh.advertiseService("add_int_server", doRequest);
        ROS_INFO("service ok");
        ros::spin();
        return 0;
    }