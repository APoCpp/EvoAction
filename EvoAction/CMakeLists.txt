set(EVO_ACTION_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE EVO_ACTION_SRC_FILES "${EVO_ACTION_SRC_DIR}/*.cpp")

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(${PROJECT_NAME} ${EVO_ACTION_SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${EVO_ACTION_SRC_DIR})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)
