#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <std_srvs/Empty.h>



geometry_msgs::Twist cmd_vel;

int clear_line = 0 ;

void joy_callback(const sensor_msgs::Joy& joy_msg)
{
   cmd_vel.linear.x = joy_msg.axes[0];
   cmd_vel.linear.y = joy_msg.axes[1];
   cmd_vel.angular.z = joy_msg.axes[3];
   clear_line = joy_msg.buttons[1];
}

int main(int argc, char** argv)
{
   ros::init(argc, argv, "psjoy");
   ros::NodeHandle nh;

   ros::service::waitForService("clear");
   ros::ServiceClient clearClient = nh.serviceClient<std_srvs::Empty>("/clear");
   std_srvs::Empty srv;
   ros::Publisher cmd_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
   ros::Subscriber joy_sub = nh.subscribe("joy", 10, joy_callback);

   ros::Rate loop_rate(10);
   while (ros::ok())
   {
	 if(clear_line == 1){
		 clearClient.call(srv);																									}
		   cmd_pub.publish(cmd_vel);
		   ros::spinOnce();
	           loop_rate.sleep();
																													     }
   return 0;
}
