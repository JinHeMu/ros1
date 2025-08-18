#include "ros/ros.h"
#include "qq_msgs/Carry.h"


int main(int argc, char** argv) 
{
    ros::init(argc, argv, "chao_node");

    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<qq_msgs::Carry>("wang_zhe_kai_hei_qun", 10);

    ros::Rate rate(10);
    qq_msgs::Carry carry;

    while(ros::ok())
    {
        carry.data = "guofumachao";
        carry.grade = "wangzhe";
        carry.star = 200;
        pub.publish(carry);
        rate.sleep();
    }
    return 0;

}