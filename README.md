# awsim_yolo
<!-- Required -->
<!-- Package description -->

## Installation
<!-- Required -->
<!-- Things to consider:
    - How to build package? 
    - Are there any other 3rd party dependencies required? -->

```bash
rosdep install --from-paths src --ignore-src -y
colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=On --packages-up-to awsim_yolo
```

## Usage
<!-- Required -->
<!-- Things to consider:
    - Launching package. 
    - Exposed API (example service/action call. -->

```bash
ros2 launch awsim_yolo awsim_yolo.launch.py
```

## API
<!-- Required -->
<!-- Things to consider:
    - How do you use the package / API? -->

### Input

| Name         | Type                  | Description  |
| ------------ | --------------------- | ------------ |
| `in/image` | sensor_msgs/Image | Input Image |

### Output

| Name         | Type                  | Description  |
| ------------ | --------------------- | ------------ |
| `out/objects` | tier4_perception_msgs/DetectedObjectsWithFeature | 2D bounding boxes info |

### Services and Actions


### Parameters

TODO


## References / External links
<!-- Optional -->
