#include <ros/ros.h>
#include <std_msgs/String.h>
#include <qq_msgs/Carry.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "chao_node");
    printf("我是个马超\n");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<qq_msgs::Carry>("kuai_shang_che", 10);

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        printf("我要开始刷屏了\n");
        qq_msgs::Carry msg;
        msg.grade = "荣耀王者";
        msg.star  = 1000;
        msg.data = "国父马超带你们飞";
        pub.publish(msg);
        loop_rate.sleep();
    }
    
    return 0;
}
