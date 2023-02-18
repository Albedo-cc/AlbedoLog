add_subdirectory(spdlog-1.11.0)

file(GLOB BACKEND_FILES
    "albedolog_backend.h"
    "albedolog_backend.cc")

set(ALBEDOLOG_BACKEND_FILES ${BACKEND_FILES} PARENT_SCOPE)
set(ENV{ALBEDOLOG_BACKEND_INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR})

function(AlbedoLog_load_backend)
    target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)
    target_include_directories(${PROJECT_NAME} PUBLIC $ENV{ALBEDOLOG_BACKEND_INCLUDE})
endfunction(AlbedoLog_load_backend)