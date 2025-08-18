#include "ros/ros.h"
#include "qq_msgs/Carry.h"
#include "std_msgs/String.h"


void CarryCallback(const qq_msgs::Carry msg)
{

    ROS_INFO("data:%s\tgrade:%s\tstar:%d",msg.data.c_str(),msg.grade.c_str(),msg.star);
}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "ma_node");

    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe<qq_msgs::Carry>("wang_zhe_kai_hei_qun", 10, &CarryCallback);

    ros::spin();
    

    return 0;
}
