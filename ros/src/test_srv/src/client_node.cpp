#include <ros/ros.h>
#include "test_srv/AddInts.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    // 调用时动态传值,如果通过 launch 的 args 传参，需要传递的参数个数 +3
    if (argc != 3)
    // if (argc != 5)//launch 传参(0-文件路径 1传入的参数 2传入的参数 3节点名称 4日志路径)
    {
        ROS_ERROR("请提交两个整数");
        return 1;
    }


    ros::init(argc, argv, "AddInts_Client");

    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<test_srv::AddInts>("AddInts");

    ros::service::waitForService("AddInts");

    test_srv::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    bool flag = client.call(ai);

    if (flag)
    {
        ROS_INFO("请求正常处理,响应结果:%d",ai.response.sum);
    }
    else
    {
        ROS_ERROR("请求处理失败....");
        return 1;
    }

    return 0;

}