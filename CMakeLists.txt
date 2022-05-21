cmake_minimum_required(VERSION 3.18)
project(colutius-desktop)
#设置动态库输出位置
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets Network)
set(REQUIRED_LIBS_QUALIFIED
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Network

        colutius
        )
#复制共享库头文件
file(GLOB LIBCOLUTIUSINCLUDE ${PROJECT_SOURCE_DIR}/lib/libcolutius/src/*.h)
file(COPY ${LIBCOLUTIUSINCLUDE} DESTINATION ${PROJECT_SOURCE_DIR}/include/libcolutius)
#添加子目录
add_subdirectory(lib/libcolutius)
#设置头文件路径
include_directories(
        ${PROJECT_SOURCE_DIR}/include
)
#获取ui头文件
file(GLOB UserInterface ${PROJECT_SOURCE_DIR}/include/ui/*.h)
file(GLOB ColutiusCore ${PROJECT_SOURCE_DIR}/include/core/*.h)
add_executable(${PROJECT_NAME}
        src/main.cpp
        #ui类
        ${UserInterface}
        src/UserInterface/widget.cpp
        src/UserInterface/widget.ui
        src/UserInterface/login.cpp
        src/UserInterface/login.ui
        src/UserInterface/config.cpp
        src/UserInterface/config.ui
        src/UserInterface/systemtrayicon.cpp
        #core类
        ${ColutiusCore}
        src/ColutiusCore/log.cpp
        src/ColutiusCore/storage.cpp
        src/ColutiusCore/notifymanager.cpp
        src/ColutiusCore/notify.cpp
        src/ColutiusCore/client.cpp
        #qrc文件
        resource/resource.qrc
        )

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})