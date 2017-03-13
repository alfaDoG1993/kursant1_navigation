#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "kursant1_tf_publisher");
  ros::NodeHandle n;
  ros::Rate r(100);

  tf::TransformBroadcaster laser_to_base_link_broadcaster;
  tf::TransformBroadcaster base_footprint_to_odom_broadcaster;
  tf::TransformBroadcaster base_link_to_base_footprint_broadcaster;
  tf::TransformBroadcaster base_footprint_to_map_broadcaster;
  //tf::TransformListener listener;
  while(n.ok()){

      base_footprint_to_odom_broadcaster.sendTransform(
            tf::StampedTransform(
            tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.0, 0.0)),
              ros::Time::now(),"odom", "base_footprint"));

      base_link_to_base_footprint_broadcaster.sendTransform(
            tf::StampedTransform(
              tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.0, 0.0)),
              ros::Time::now(),"base_footprint", "base_link"));

      laser_to_base_link_broadcaster.sendTransform(
              tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.2, 0.0, 0.2)),// Кватернион, отображающий положение лазера относительно центра робота. Vector3 - x y z координаты лазера относительно центра робота
                ros::Time::now(),"base_link", "laser"));
    




//tf::StampedTransform transform_in_map;
//try {
//  listener.lookupTransform("odom", "base_footprint", ros::Time(0), transform_in_map);
//} catch(tf::TransformException &exception) {
//  ROS_ERROR("%s", exception.what());
//}



//base_footprint_to_map_broadcaster.sendTransform(
//      tf::StampedTransform(
//       tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.0, 0.0)),
//        ros::Time::now(),"map", "base_footprint"));


    r.sleep();
  }
}
