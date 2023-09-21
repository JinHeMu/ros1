#!/usr/bin/env python3
#coding=utf-8

import rospy
from std_msgs.msg import String
from qq_msgs.msg import Carry 


def chao_callback(msg):
    rospy.loginfo(msg.star)
    rospy.loginfo(msg.grade)
    rospy.loginfo(msg.data)

def yao_callback(msg):
    pass



if __name__ == "__main__":
    rospy.init_node("ma_node")

    sub = rospy.Subscriber("kuai_shang_che", Carry, chao_callback,queue_size=10)
    sub2 = rospy.Subscriber("ge_ge_dai_wo", Carry, yao_callback,queue_size=10)
    

    rospy.spin()