# 环境配置

VMWare17+Ubuntu20.04+ROS1 noetic

## 虚拟机配置

- VMWare tools 安装

```bash
sudo apt install open-vm-tools-desktop -y
```

- VPN配置

详见[NAT上网](https://blog.csdn.net/hhc550056259/article/details/123916999)和[VPN](https://blog.csdn.net/weixin_45993094/article/details/141811057)

## Github配置

- Github密钥

```bash
ssh-keygen -t rsa -c "490754775@qq.com"
```

- git安装

```bash
sudo apt install git
```

## ROS1安装

- [小鱼的一键安装系列](https://fishros.org.cn/forum/topic/20/%E5%B0%8F%E9%B1%BC%E7%9A%84%E4%B8%80%E9%94%AE%E5%AE%89%E8%A3%85%E7%B3%BB%E5%88%97)

```bash
wget http://fishros.com/install -O fishros && . fishros
```

# ROS1

## ch1

### 1.1创建工作空间并初始化

```
mkdir -p 自定义空间名称/src #如果没有 -p 选项，当你要创建的目录的上级目录不存在时，命令会报错
cd 自定义空间名称
catkin_make
```

### 1.2进入 src 创建 ros 包并添加依赖

```
cd src
catkin_create_pkg 自定义ROS包名 roscpp rospy std_msgs
```

- 若\#include "ros/ros.h" 报错，则在c_cpp_properties.json 中包含ROS路径.

- **pwd** 输出当前目录路径

### 1.3创建可执行文件



