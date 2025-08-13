#include "ros/ros.h"
#include "topic_test/person.h"

void doMsg(const topic_test::person::ConstPtr& msg_p){
    ROS_INFO("rec: name=%s, age=%d, height=%.2f", msg_p->name.c_str(), msg_p->age, msg_p->height);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"test_msg_sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<topic_test::person>("person_info",10,doMsg);
    
    
    ros::spin();
    return 0;
}
