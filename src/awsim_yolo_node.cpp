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
  awsim_yolo_ = std::make_unique<awsim_yolo::AwsimYolo>();
  param_name_ = this->declare_parameter("param_name", 456);
  awsim_yolo_->foo(param_name_);
}

}  // namespace awsim_yolo

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(awsim_yolo::AwsimYoloNode)
