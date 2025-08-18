#include "ros/ros.h"
#include "sensor_msgs/Imu.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"

ros::Publisher vel_pub;

void IMUCallback(const sensor_msgs::Imu msg)
{
    geometry_msgs::Twist vel_cmd;
    if(msg.orientation_covariance[0] < 0.0f)
        return;
    tf::Quaternion quaternion(
        msg.orientation.x,
        msg.orientation.y,
        msg.orientation.z,
        msg.orientation.w
    );

    double roll, pitch, yaw;
    tf::Matrix3x3(quaternion).getRPY(roll, pitch, yaw);
    roll = roll*180.0f/3.1415926f;
    pitch = pitch*180.0f/3.1415926f;
    yaw = yaw*180.0f/3.1415926f;

    ROS_INFO("roll:%f,pitch:%f,yaw:%f", roll, pitch, yaw);
    //ROS_INFO("%f, %f, %f",msg.linear_acceleration.x, msg.linear_acceleration.y, msg.linear_acceleration.z);
    if(yaw > 0)
    {
        vel_cmd.angular.z = -1;
    }else
    {
        vel_cmd.angular.z = 1;
    }
    vel_pub.publish(vel_cmd);
    
}

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "imu_node");

    ros::NodeHandle n;
    ros::Subscriber imu_sub = n.subscribe("/imu/data", 10, IMUCallback);
    vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);


    ros::spin();


    return 0;
}