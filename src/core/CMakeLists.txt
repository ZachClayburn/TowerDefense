add_library(core STATIC
        include/Scene.h Scene.cpp
        Application.cpp include/Application.h)

target_include_directories(core
        PUBLIC include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_link_libraries(core
        PRIVATE project_options
        PRIVATE project_warnings
        PUBLIC CONAN_PKG::entt
        PRIVATE CONAN_PKG::spdlog
        PUBLIC UI
        )