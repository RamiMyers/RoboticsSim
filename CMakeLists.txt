cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

project(RoboticsSim)

add_compile_definitions(NAME="${PROJECT_NAME}")

add_executable(${PROJECT_NAME} src/main.cpp)

include_directories(include/)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.5.1
)
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 1.0.3
)
FetchContent_MakeAvailable(glfw glm)

add_library(glad src/glad.c)

target_link_libraries(${PROJECT_NAME} glad glfw glm)