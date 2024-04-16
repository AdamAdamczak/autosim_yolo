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

#ifndef AWSIM_YOLO__AWSIM_YOLO_NODE_HPP_
#define AWSIM_YOLO__AWSIM_YOLO_NODE_HPP_

#include <memory>
#include <rclcpp/rclcpp.hpp>

#include "awsim_yolo/awsim_yolo.hpp"

namespace awsim_yolo
{
using AwsimYoloPtr = std::unique_ptr<awsim_yolo::AwsimYolo>;

class AWSIM_YOLO_PUBLIC AwsimYoloNode : public rclcpp::Node
{
public:
  explicit AwsimYoloNode(const rclcpp::NodeOptions & options);

private:
  AwsimYoloPtr awsim_yolo_{nullptr};
  std::string model_path_{};
};
}  // namespace awsim_yolo

#endif  // AWSIM_YOLO__AWSIM_YOLO_NODE_HPP_
