add_library(UI STATIC
        include/Window.h Window.cpp
        Renderer.h Renderer.cpp
)

target_link_libraries(UI
        PUBLIC olcPixelGameEngine
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_include_directories(UI
        PUBLIC include
        )

target_link_libraries(UI
        PRIVATE project_options project_warnings
        )
