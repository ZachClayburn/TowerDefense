add_subdirectory(thirdParty)
add_subdirectory(examples)
add_subdirectory(core)
add_subdirectory(UI)

add_executable(intro main.cpp)
target_link_libraries(intro
        PRIVATE project_options
        project_warnings
        CONAN_PKG::docopt.cpp
        CONAN_PKG::fmt
        CONAN_PKG::spdlog
        core
        )
