cmake_minimum_required(VERSION 3.21.0)

project("AlbedoLog" 
    LANGUAGES CXX
    VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Explicitly require the standard
set(CMAKE_CXX_EXTENSIONS OFF) # Vendor-specific Extensions

# Choose backend
option(backend_spdlog "Set the spdlog as the backend of AlbedoLog" ON)

add_subdirectory(include)
add_library(Albedo::log ALIAS AlbedoLog)

add_executable(test main.cc)
target_link_libraries(test PRIVATE Albedo::log)