cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(cpp_node src/my_first_node.cpp)
ament_target_dependencies(cpp_node rclcpp)

add_executable(robot_news_staton src/robot_news_station.cpp)
ament_target_dependencies(robot_news_staton rclcpp example_interfaces)

add_executable(Phone_node src/smart_phone.cpp)
ament_target_dependencies(Phone_node rclcpp example_interfaces)

install(TARGETS
  cpp_node
  robot_news_staton
  Phone_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package() 