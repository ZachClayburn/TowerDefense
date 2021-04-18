add_executable(breakout
        Breakout.cpp
        )

target_link_libraries(breakout
        PRIVATE project_options project_warnings
        PRIVATE olcPixelGameEngine
        )