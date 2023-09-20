#!/usr/bin/env python3
#coding=utf-8

import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("yao_node")
    rospy.logwarn("我是yao妹")

    pub = rospy.Publisher("ge_ge_dai_wo", String, queue_size=10)

    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        rospy.loginfo("我要开始刷屏了")
        msg = String()
        msg.data = "国父马超，随便应"
        pub.publish(msg)
        rate.sleep()