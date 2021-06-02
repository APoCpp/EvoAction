cmake_minimum_required(VERSION 3.12)

project(EvoAction
        VERSION 0.0.1
        DESCRIPTION "..."
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY EVO_ACTION_PROJECT EvoAction)
add_subdirectory(EvoAction)
