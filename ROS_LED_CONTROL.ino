/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle  nh;

void control_LED( const std_msgs::Int16 & cmd_msg)
{
  int value = cmd_msg.data;
  digitalWrite(13, value);   // blink the led
}

ros::Subscriber<std_msgs::Int16> sub("topic_LED_13", &control_LED );

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
