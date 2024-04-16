// Copyright 2024 AAdamczak
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "awsim_yolo/awsim_yolo_node.hpp"

namespace awsim_yolo
{

AwsimYoloNode::AwsimYoloNode(const rclcpp::NodeOptions & options)
:  Node("awsim_yolo", options)
{
  using std::placeholders::_1;
  std::string engine_path = declare_parameter("engine_path", std::string());

  this->awsim_yolo_ = std::make_unique<awsim_yolo::AwsimYolo>(engine_path);
  using std::chrono_literals::operator""ms;
  timer_ = rclcpp::create_timer(
    this, get_clock(), 100ms, std::bind(&AwsimYoloNode::connectCb, this));

  this->image_pub_ = image_transport::create_publisher(this, "out/image");
  this->image_sub_  = image_transport::create_subscription(this, "in/image", std::bind(&AwsimYoloNode::callback, this, _1), "raw",rmw_qos_profile_sensor_data);
}

void AwsimYoloNode::connectCb()
{
  using std::placeholders::_1;
  std::lock_guard<std::mutex> lock(connect_mutex_);
  if (objects_pub_->get_subscription_count() == 0 && image_pub_.getNumSubscribers() == 0) {
    image_sub_.shutdown();
  } else if (!image_sub_) {
    image_sub_ = image_transport::create_subscription(
      this, "in/image", std::bind(&AwsimYoloNode::callback, this, _1), "raw",
      rmw_qos_profile_sensor_data);
  }
}

void AwsimYoloNode::callback(const sensor_msgs::msg::Image::ConstSharedPtr image_msg)
{
  
  std::vector<Detection> output;
  this->awsim_yolo_->infer(image_msg, output);
  cv::Mat cv_image = cv_bridge::toCvCopy(image_msg, sensor_msgs::image_encodings::BGR8)->image;
  this->awsim_yolo_->draw_bbox(cv_image, output);
  this->image_pub_.publish(cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", cv_image).toImageMsg());

}

}  // namespace awsim_yolo

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(awsim_yolo::AwsimYoloNode)
