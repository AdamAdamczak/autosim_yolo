cmake_minimum_required(VERSION 3.14)
project(awsim_yolo)

find_package(autoware_cmake REQUIRED)
autoware_package()
find_package(OpenCV REQUIRED)
find_package(CUDA REQUIRED)
include_directories(
  include
  ${CUDA_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

ament_auto_add_library(${PROJECT_NAME} SHARED
  include/awsim_yolo/awsim_yolo.hpp
  include/awsim_yolo/visibility_control.hpp
  src/awsim_yolo.cpp
)
# set(HEADERS
#     src/yolov9.h
#     src/macros.h
#     src/logging.h
#     src/cuda_utils.h
#     src/preprocess.h
# )

ament_auto_add_library(${PROJECT_NAME}_node SHARED
  include/awsim_yolo/awsim_yolo_node.hpp
  src/awsim_yolo_node.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${CUDA_LIBRARIES}
  ${OpenCV_LIBRARIES}
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
