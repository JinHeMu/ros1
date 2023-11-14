#include <ros/ros.h>
#include "test_msg/Person.h"

int main(int argc,char** argv)
{
    setlocale(LC_ALL, "");

    ros::init(argc, argv, "pub_node");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<test_msg::Person>("chatter", 1000);

    test_msg::Person msg;
    msg.name = "jinhemu";
    msg.age = 20;
    msg.height = 1.8;

    ros::Rate r(1);

    while (ros::ok())
    {
        pub.publish(msg);
        msg.age +=1;
        ROS_INFO("i am: %s, i am %d year old and height is %.2fm", msg.name.c_str(), msg.age, msg.height);

        r.sleep();
        ros::spinOnce;
    }
    



}