cmake_minimum_required(VERSION 3.10)
project(AP-Project-2021-2022)

SET(CMAKE_CXX_STANDARD 14)

#Added so that Clion can find SFML directory on my windows system
if(WIN32)
    INCLUDE_DIRECTORIES(c:/SFML/include)
endif()

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

ADD_EXECUTABLE(AP-Project-2021-2022 main.cpp Logic/Player.cpp Logic/Player.h Logic/Platform.cpp Logic/Platform.h
        Logic/Bonus.cpp Logic/Bonus.h Visuals/VS_Game.cpp Visuals/VS_Game.h Logic/Stopwatch.cpp Logic/Stopwatch.h
        Logic/Camera.cpp Logic/Camera.h Logic/Random.cpp Logic/Random.h Logic/World.cpp Logic/World.h
        Logic/Background.cpp Logic/Background.h Logic/Entity.cpp Logic/Entity.h)

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(AP-Project-2021-2022 ${SFML_LIBRARIES})

INSTALL(TARGETS AP-Project-2021-2022 DESTINATION ${PROJECT_SOURCE_DIR}/bin)
