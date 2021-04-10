add_library(olcPixelGameEngine STATIC
        pge.cpp
        olcPixelGameEngine/olcPixelGameEngine.h
)

find_package(X11 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(PNG REQUIRED)

target_include_directories(olcPixelGameEngine SYSTEM
        PUBLIC olcPixelGameEngine
)

target_compile_definitions(olcPixelGameEngine PRIVATE OLC_PGE_APPLICATION)
target_link_libraries(olcPixelGameEngine
        PRIVATE project_options project_warnings
        ${X11_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${PNG_LIBRARIES}
        $<$<PLATFORM_ID:Linux>:pthread>
        )