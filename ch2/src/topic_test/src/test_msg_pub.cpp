#include "ros/ros.h"
#include "topic_test/person.h"

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "test_msg");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<topic_test::person>("person_info", 1000);

    topic_test::person p;
    p.name = "уехЩ";
    p.age = 18;
    p.height = 1.75;

    ros::Rate r(1);
    while (ros::ok())
    {
        pub.publish(p);
        p.age++;
        ROS_INFO("pub:name=%s, age=%d, height=%.2f", p.name.c_str(), p.age, p.height);
        r.sleep();
       ros::spinOnce();
    }
    return 0;
}
