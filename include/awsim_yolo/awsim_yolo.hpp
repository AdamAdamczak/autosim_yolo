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

#ifndef AWSIM_YOLO__AWSIM_YOLO_HPP_
#define AWSIM_YOLO__AWSIM_YOLO_HPP_

#include <cstdint>
#include <string>
#include "awsim_yolo/visibility_control.hpp"
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include "yolov9.h"
#include <tier4_perception_msgs/msg/detected_objects_with_feature.hpp>
namespace awsim_yolo
{

class AWSIM_YOLO_PUBLIC AwsimYolo
{
public:
  AwsimYolo(std::string model_path);

  void infer(const sensor_msgs::msg::Image::ConstSharedPtr & image_msg, vector<Detection> & output);
  void draw_bbox(cv::Mat& image,const vector<Detection> & output);
private:
  std::shared_ptr<Yolov9> _yolo;
  
  
};

}  // namespace awsim_yolo

#endif  // AWSIM_YOLO__AWSIM_YOLO_HPP_
