add_library(UI STATIC
        include/MainWindow.h MainWindow.cpp
        Renderer.h Renderer.cpp
)

target_link_libraries(UI
        PRIVATE olcPixelGameEngine
        )

target_include_directories(UI
        PUBLIC include
        )

target_link_libraries(UI
        PRIVATE project_options project_warnings
        )
