cmake_minimum_required(VERSION 3.18)
project(colutius-desktop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#复制头文件
file(GLOB LIBCOLUTIUSINCLUDE ${PROJECT_SOURCE_DIR}/lib/libcolutius/src/*.h)
file(COPY ${LIBCOLUTIUSINCLUDE} DESTINATION ${PROJECT_SOURCE_DIR}/include/libcolutius)
#设置头文件路径
include_directories(
        ${PROJECT_SOURCE_DIR}/include
)
set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets Network)
set(REQUIRED_LIBS_QUALIFIED
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Network

        colutius
        )
add_subdirectory(lib/libcolutius)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/ui/widget.cpp
        src/ui/widget.h
        src/ui/widget.ui
        )

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})