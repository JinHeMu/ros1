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

# ROS基操

### 1 创建工作空间并初始化

```
mkdir -p 自定义空间名称/src #如果没有 -p 选项，当你要创建的目录的上级目录不存在时，命令会报错
cd 自定义空间名称
catkin_make
```

### 2 进入 src 创建 ros 包并添加依赖

```
cd src
catkin_create_pkg 自定义ROS包名 roscpp rospy std_msgs
```

- 若\#include "ros/ros.h" 报错，则在c_cpp_properties.json 中包含ROS路径.

- **pwd** 输出当前目录路径

### 3 创建可执行文件

- 进入 ros 包的 src 目录编辑源文件
- 编辑 ros 包下的 Cmakelist.txt文件

```cmake
add_executable(步骤3的源文件名
  src/步骤3的源文件名.cpp
)
target_link_libraries(步骤3的源文件名
  ${catkin_LIBRARIES}
)
```

- 进入工作空间目录并编译

```cmake
cd 自定义空间名称
catkin_make
```

### 4 执行

```bash
roscore #bash1
cd 工作空间
source ./devel/setup.bash
rosrun 包名 C++节点 #bash2
```

# 自定义消息

## 1.创建新软件包

依赖项：``message_generation``、``message_runtime``

## 2.添加msg目录

以.msg结尾，首字母大写

## 3.修改CMakeLists

## 4. 修改package.xml

