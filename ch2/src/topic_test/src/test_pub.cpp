/*
    ����: ʵ�ֻ����Ļ���ͨ�ţ�һ���������ݣ�һ���������ݣ�
         ʵ�ֵĹؼ���:
         1.���ͷ�
         2.���շ�
         3.����(�˴�Ϊ��ͨ�ı�)

         PS: ������Ҫ������ͬ�Ļ���


    ��Ϣ������:
        ѭ��������Ϣ:HelloWorld ��׺���ֱ��

    ʵ������:
        1.����ͷ�ļ� 
        2.��ʼ�� ROS �ڵ�:����(Ψһ)
        3.ʵ���� ROS ���
        4.ʵ���� ������ ����
        5.��֯�����������ݣ�����д�߼���������

*/
// 1.����ͷ�ļ� 
#include "ros/ros.h"
#include "std_msgs/String.h" //��ͨ�ı����͵���Ϣ
#include <sstream>

int main(int argc, char  *argv[])
{   
    //���ñ���
    setlocale(LC_ALL,"");

    //2.��ʼ�� ROS �ڵ�:����(Ψһ)
    // ����1�Ͳ���2 ����Ϊ�ڵ㴫ֵ��ʹ��
    // ����3 �ǽڵ����ƣ���һ����ʶ������Ҫ��֤���к��� ROS ����������Ψһ
    ros::init(argc,argv,"talker");
    //3.ʵ���� ROS ���
    ros::NodeHandle nh;//�����װ�� ROS �е�һЩ���ù���

    //4.ʵ���� ������ ����
    //����: ��������Ϣ����
    //����1: Ҫ�������Ļ���
    //����2: ��������󱣴����Ϣ���������˷�ֵʱ���Ƚ���������(ʱ�����������)
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",10);

    //5.��֯�����������ݣ�����д�߼���������
    //����(��̬��֯)
    std_msgs::String msg;
    // msg.data = "��ð�������";
    std::string msg_front = "Hello ��ã�"; //��Ϣǰ׺
    int count = 0; //��Ϣ������

    //�߼�(һ��10��)
    ros::Rate r(1);

    //�ڵ㲻��
    while (ros::ok())
    {
        //ʹ�� stringstream ƴ���ַ�������
        std::stringstream ss;
        ss << msg_front << count;
        msg.data = ss.str();
        //������Ϣ
        pub.publish(msg);
        //������ԣ���ӡ���͵���Ϣ
        ROS_INFO("���͵���Ϣ:%s",msg.data.c_str());

        //����ǰ���ƶ��ķ���ƶƵ���Զ����� ����ʱ�� = 1/Ƶ�ʣ�
        r.sleep();
        count++;//ѭ������ǰ���� count ����
        //����Ӧ��
        ros::spinOnce();
    }


    return 0;
}