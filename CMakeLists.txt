cmake_minimum_required(VERSION 3.18)
project(colutius-desktop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#设置头文件路径
include_directories(
        ${PROJECT_SOURCE_DIR}/libcolutius/src/Message
        ${PROJECT_SOURCE_DIR}/libcolutius/src/Channel
        ${PROJECT_SOURCE_DIR}/libcolutius/src/Server
)
set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets Network)
set(REQUIRED_LIBS_QUALIFIED
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Network

        colutius-server
        colutius-channel
        colutius-message
        )
add_subdirectory(libcolutius)
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/ui/widget.cpp
        src/ui/widget.h
        src/ui/widget.ui
        )

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})