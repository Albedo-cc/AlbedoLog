# include <AlbedoLog.hpp>

# Load backend
if (backend_spdlog)
    message(NOTICE "[Albedo Log] >> Backend is spdlog")
    add_subdirectory(backends/spdlog)
else()
    message(FATAL_ERROR "[Albedo Log] >> Unknown backend!")
endif()

# Create library
add_library(${PROJECT_NAME}
        STATIC
        AlbedoLog.hpp
        ${ALBEDOLOG_BACKEND_FILES})
AlbedoLog_load_backend()

source_group("" FILES AlbedoLog.hpp)
source_group("backend" FILES ${ALBEDOLOG_BACKEND_FILES})
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})