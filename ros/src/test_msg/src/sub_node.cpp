/*
    需求: 订阅人的信息

*/

#include "ros/ros.h"
#include "test_msg/Person.h"

void doPerson(const test_msg::Person::ConstPtr& person_p){
    ROS_INFO("订阅的人信息:%s, %d, %.2f", person_p->name.c_str(), person_p->age, person_p->height);
}

void doPerson2(const test_msg::Person::ConstPtr& person_p){
    ROS_INFO("2!!!订阅的人信息:%s, %d, %.2f", person_p->name.c_str(), person_p->age, person_p->height);
}

int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");

    //1.初始化 ROS 节点
    ros::init(argc,argv,"sub_node");
    //2.创建 ROS 句柄
    ros::NodeHandle nh;
    //3.创建订阅对象
    ros::Subscriber sub = nh.subscribe<test_msg::Person>("chatter",10,doPerson);

    ros::Subscriber sub2 = nh.subscribe<test_msg::Person>("chatter",10,doPerson2);

    //4.回调函数中处理 person

    //5.ros::spin();
    ros::spin();    
    return 0;
}
