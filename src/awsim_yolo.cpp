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

AwsimYolo::AwsimYolo()
{
}

bool AwsimYolo::load_model(const std::string &model_path)
{
    Ort::SessionOptions session_options;
    session_options.SetIntraOpNumThreads(1);
    session_options.SetGraphOptimizationLevel(ORT_ENABLE_ALL);

    try {
        session_ = std::make_unique<Ort::Session>(env_, model_path.c_str(), session_options);
        return true;
    } catch (const Ort::Exception &exception) {
        std::cerr << "Error loading ONNX model: " << exception.what() << std::endl;
        return false;
    }
}

}  // namespace awsim_yolo
