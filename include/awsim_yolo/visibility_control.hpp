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

#ifndef AWSIM_YOLO__VISIBILITY_CONTROL_HPP_
#define AWSIM_YOLO__VISIBILITY_CONTROL_HPP_

////////////////////////////////////////////////////////////////////////////////
#if defined(__WIN32)
  #if defined(AWSIM_YOLO_BUILDING_DLL) || defined(AWSIM_YOLO_EXPORTS)
    #define AWSIM_YOLO_PUBLIC __declspec(dllexport)
    #define AWSIM_YOLO_LOCAL
  #else  // defined(AWSIM_YOLO_BUILDING_DLL) || defined(AWSIM_YOLO_EXPORTS)
    #define AWSIM_YOLO_PUBLIC __declspec(dllimport)
    #define AWSIM_YOLO_LOCAL
  #endif  // defined(AWSIM_YOLO_BUILDING_DLL) || defined(AWSIM_YOLO_EXPORTS)
#elif defined(__linux__)
  #define AWSIM_YOLO_PUBLIC __attribute__((visibility("default")))
  #define AWSIM_YOLO_LOCAL __attribute__((visibility("hidden")))
#elif defined(__APPLE__)
  #define AWSIM_YOLO_PUBLIC __attribute__((visibility("default")))
  #define AWSIM_YOLO_LOCAL __attribute__((visibility("hidden")))
#else
  #error "Unsupported Build Configuration"
#endif

#endif  // AWSIM_YOLO__VISIBILITY_CONTROL_HPP_
