#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "test_param_add");

    std::vector<std::string> stus;
    stus.push_back("zhangsan");
    stus.push_back("����");
    stus.push_back("����");
    stus.push_back("����Դ�");

    std::map<std::string,std::string> friends;
    friends["guo"] = "huang";
    friends["yuang"] = "xiao";

    //NodeHandle--------------------------------------------------------
    ros::NodeHandle nh;
    nh.setParam("nh_int",10); //����
    nh.setParam("nh_double",3.14); //������
    nh.setParam("nh_bool",true); //bool
    nh.setParam("nh_string","hello NodeHandle"); //�ַ���
    nh.setParam("nh_vector",stus); // vector
    nh.setParam("nh_map",friends); // map

    //�޸���ʾ(��ͬ�ļ�����ͬ��ֵ)
    nh.setParam("nh_int",10000);

    //param--------------------------------------------------------
    ros::param::set("param_int",20);
    ros::param::set("param_double",3.14);
    ros::param::set("param_string","Hello Param");
    ros::param::set("param_bool",false);
    ros::param::set("param_vector",stus);
    ros::param::set("param_map",friends);

        //�޸���ʾ(��ͬ�ļ�����ͬ��ֵ)
    ros::param::set("param_int",20000);
    return 0;

}