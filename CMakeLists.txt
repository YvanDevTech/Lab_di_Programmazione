cmake_minimum_required(VERSION 3.25)
project(Project_Chat)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES Chat.cpp Chat.h User.cpp User.h Message.cpp Message.h ChatRegister.cpp ChatRegister.h)
add_library(core ${SOURCE_FILES})
add_executable(ChatProject main.cpp)
target_link_libraries(ChatProject core)