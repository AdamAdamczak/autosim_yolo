cmake_minimum_required(VERSION 3.14)
project(awsim_yolo)

find_package(autoware_cmake REQUIRED)
autoware_package()
find_package(OpenCV REQUIRED)
set(ONNX_RUNTIME_PATH "/opt/onnxruntime/onnxruntime-linux-x64-cuda-1.17.1")

ament_auto_add_library(${PROJECT_NAME} SHARED
  include/awsim_yolo/awsim_yolo.hpp
  include/awsim_yolo/visibility_control.hpp
  src/awsim_yolo.cpp
  ${OpenCV_INCLUDE_DIRS}
  ${ONNX_RUNTIME_PATH}/include

)

ament_auto_add_library(${PROJECT_NAME}_node SHARED
  include/awsim_yolo/awsim_yolo_node.hpp
  src/awsim_yolo_node.cpp
)

rclcpp_components_register_node(${PROJECT_NAME}_node
  PLUGIN "awsim_yolo::AwsimYoloNode"
  EXECUTABLE ${PROJECT_NAME}_node_exe
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  ament_add_ros_isolated_gtest(test_awsim_yolo
    test/test_awsim_yolo.cpp
  )
  ament_target_dependencies(test_awsim_yolo ${TEST_SOURCES})
  target_link_libraries(test_awsim_yolo ${PROJECT_NAME})
endif()

ament_auto_package(INSTALL_TO_SHARE
  launch
  config
)
