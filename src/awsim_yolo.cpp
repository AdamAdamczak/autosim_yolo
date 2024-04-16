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

#include "awsim_yolo/awsim_yolo.hpp"

#include <iostream>

namespace awsim_yolo
{

AwsimYolo::AwsimYolo(std::string model_path)
{
  this->_yolo = std::make_shared<Yolov9>(model_path);
}


void AwsimYolo::infer(const sensor_msgs::msg::Image::ConstSharedPtr&image_msg,vector<Detection> & output)
  {
    cv_bridge::CvImagePtr in_image_ptr;
    in_image_ptr = cv_bridge::toCvCopy(image_msg, sensor_msgs::image_encodings::BGR8);
    this->_yolo->predict(in_image_ptr->image,output);
    
  }
void AwsimYolo::draw_bbox(cv::Mat& image,const vector<Detection> & output)
{
    this->_yolo->draw(image,output);
}

}  // namespace awsim_yolo
