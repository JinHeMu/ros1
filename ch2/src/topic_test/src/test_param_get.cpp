#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "test_param_get");
        //param--------------------------------------------------------
    ROS_INFO("++++++++++++++++++++++++++++++++++++++++");
    int res3 = ros::param::param("param_int",20); //����
    int res4 = ros::param::param("param_int2",20); // �����ڷ���Ĭ��
    ROS_INFO("param��ȡ���:%d,%d",res3,res4);

    // getParam ����
    int param_int_value;
    double param_double_value;
    bool param_bool_value;
    std::string param_string_value;
    std::vector<std::string> param_stus;
    std::map<std::string, std::string> param_friends;

}