#include "ros/ros.h"
#include "topic_test/add_int.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    if(argc != 3) 
    {
        ROS_INFO("Please enter two number for add_int_server.");
        return 1;
    }

    ros::init(argc, argv, "test_srv_cli");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<topic_test::add_int>("add_int_server");
    topic_test::add_int srv;
    srv.request.num1 = atof(argv[1]);
    srv.request.num2 = atof(argv[2]);
    bool flag = client.call(srv);
    if(flag) 
    {
        ROS_INFO("Result is: %d", srv.response.sum);
    }
    else 
    {
        ROS_ERROR("Failed!");
        return 1;
    }
    return 0;
}

