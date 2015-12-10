#include "ros/ros.h"
#include "geometry_msgs/Pose.h"
#include "goal_subscriber_class.hpp"

int main(int argc, char** argv){

ros::init(argc, argv, "send_goals");
ros::NodeHandle n;



ros::Publisher goal= n.advertise<geometry_msgs::Pose>("my_goals/goal",100);

ros::Rate r(10);



geometry_msgs::Pose goal_msg;


int i=25;
while(i>0){
    goal_msg.position.x= i;
    goal_msg.position.y = 19.75;
    goal_msg.position.z = 0.000;
    goal_msg.orientation.x = 0.000;
    goal_msg.orientation.y = 0.000;
    goal_msg.orientation.z = 1;
    goal_msg.orientation.w = 0;
    goal.publish(goal_msg);
    i--;
    ROS_INFO("goal [%f]",goal_msg.position.x);
    ros::spinOnce();
    r.sleep();
}

return 0;
}
