#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "chao_node");
    printf("我是个马超\n");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("kuai_shang_che", 10);

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        printf("我要开始刷屏了\n");
        std_msgs::String msg;
        msg.data = "国父马超带你们飞";
        pub.publish(msg);
        loop_rate.sleep();
    }
    
    return 0;
}
