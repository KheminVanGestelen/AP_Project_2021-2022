cmake_minimum_required(VERSION 3.10)
project(AP-Project-2021-2022)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP-Project-2021-2022 main.cpp Visuals/Game.h Visuals/Game.cpp Logic/Background.h Logic/Background.cpp
        Logic/Bonus.h Logic/Bonus.cpp Logic/Camera.h Logic/Camera.cpp Logic/Entity.h Logic/Entity.cpp Logic/Platform.h
        Logic/Platform.cpp Logic/Player.h Logic/Player.cpp Logic/Random.cpp Logic/Random.h Logic/Stopwatch.h
        Logic/Stopwatch.cpp Logic/World.h Logic/World.cpp Logic/Vector2D.cpp Logic/Vector2D.h Logic/AbstractFactory.cpp
        Logic/AbstractFactory.h Visuals/ConcreteFactory.cpp Visuals/ConcreteFactory.h Logic/Observer.cpp
        Logic/Observer.h Visuals/EntityView.cpp Visuals/EntityView.h Visuals/PlatformView.cpp Visuals/PlatformView.h
        Visuals/PlayerView.cpp Visuals/PlayerView.h Visuals/BonusView.cpp Visuals/BonusView.h Logic/Score.cpp
        Logic/Score.h Visuals/TextureLoader.cpp Visuals/TextureLoader.h Visuals/BackgroundView.cpp Visuals/BackgroundView.h)

include_directories(/usr/include c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(AP-Project-2021-2022 ${SFML_LIBRARIES})
endif()

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()