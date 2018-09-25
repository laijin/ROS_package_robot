#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Twist.h>
#include<iostream>
#include <string>
#include <sensor_msgs/JointState.h>
#include <robot_state_publisher/robot_state_publisher.h>
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

ros::Publisher robot_vel;
using namespace std;

void voiceCallback1(const std_msgs::String::ConstPtr& msg)
{
    ros::NodeHandle node;
    ros::Rate rate(10);
    
    //机械臂
    ros::Publisher joint_pub = node.advertise<sensor_msgs::JointState>("joint_states", 1);    //设置一个发布者，将消息发布出去,发布到相应的节点中去
    const double degree = M_PI/180;
    const double radius = 2;
    int i=-69;
    // robot state
    double angle= 0;
    // message declarations
    sensor_msgs::JointState joint_state;

    //小车
    robot_vel=node.advertise<geometry_msgs::Twist>("/cmd_vel",10);

    //发布速度指令
    if (msg->data == "向左。")
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x=2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }
    if (msg->data == "向右。")
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x=-2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }
    if (msg->data == "向前。")
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.y=2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }    
    if (msg->data == "向后。")
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.y=-2;
        robot_vel.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }   
    // ROS_INFO("I heard: NO");
    if (msg->data == "运动。")
    {
        joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(6);
        joint_state.position.resize(6);
    joint_state.name[0]="joint1";
        joint_state.position[0] = i*degree;
    joint_state.name[1] ="joint2";
        joint_state.position[1] = i*degree;
    joint_state.name[2] ="joint3";
        joint_state.position[2] = i*degree;
        joint_state.name[3] ="joint4";
        joint_state.position[3] = i*degree;
    joint_state.name[4] ="joint5";
        joint_state.position[4] = i*degree;
    joint_state.name[5] ="joint6";
        joint_state.position[5] = i*degree;
        if(i<=70)
            i++;
        else
            i=-69; 

        //send the joint state and transform
        joint_pub.publish(joint_state);
        rate.sleep();
    }
}




int main(int argc, char** argv)
{
    // 初始化节点
    ros::init(argc, argv, "robot_pro_broadcaster");
    ros::NodeHandle node;
 

    ros::Subscriber sub1 = node.subscribe("voiceWords", 1000,  &voiceCallback1);


    return 0;
};
