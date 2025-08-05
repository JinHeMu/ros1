/*
    ����: ʵ�ֻ����Ļ���ͨ�ţ�һ���������ݣ�һ���������ݣ�
         ʵ�ֵĹؼ���:
         1.���ͷ�
         2.���շ�
         3.����(�˴�Ϊ��ͨ�ı�)


    ��Ϣ���ķ�:
        ���Ļ��Ⲣ��ӡ���յ�����Ϣ

    ʵ������:
        1.����ͷ�ļ� 
        2.��ʼ�� ROS �ڵ�:����(Ψһ)
        3.ʵ���� ROS ���
        4.ʵ���� ������ ����
        5.�����ĵ���Ϣ(�ص�����)
        6.����ѭ�����ûص�����

*/
// 1.����ͷ�ļ� 
#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg_p){
    ROS_INFO("������:%s",msg_p->data.c_str());
    // ROS_INFO("������:%s",(*msg_p).data.c_str());
}
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    //2.��ʼ�� ROS �ڵ�:����(Ψһ)
    ros::init(argc,argv,"listener");
    //3.ʵ���� ROS ���
    ros::NodeHandle nh;

    //4.ʵ���� ������ ����
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("chatter",10,doMsg);
    //5.�����ĵ���Ϣ(�ص�����)

    //     6.����ѭ�����ûص�����
    ros::spin();//ѭ����ȡ���յ����ݣ������ûص���������

    return 0;
}