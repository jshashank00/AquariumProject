project(AquariumLib)

set(SOURCE_FILES MainFrame.h MainFrame.cpp pch.h
        AquariumView.cpp
        AquariumView.h
        Aquarium.cpp
        Aquarium.h
        Item.cpp
        Item.h
        FishBeta.cpp
        FishBeta.h
        ids.h
        BubbleFish.cpp
        BubbleFish.h
        Dory.cpp
        Dory.h
        DecorCastle.cpp
        DecorCastle.h
        Fish.cpp
        Fish.h
)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})