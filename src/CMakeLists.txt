add_library(onset-http  SHARED
        PluginInterface.cpp
        Singleton.hpp
        Plugin.hpp
        Plugin.cpp
		Helpers.hpp
        )

target_include_directories(onset-http  PRIVATE
        ${HORIZONSDK_INCLUDE_DIR}
        )

set_property(TARGET onset-http  PROPERTY CXX_STANDARD 17)
set_property(TARGET onset-http  PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET onset-http  PROPERTY PREFIX "")
if(WIN32)
	target_link_libraries(onset-http wsock32 ws2_32)
endif()

target_link_libraries(onset-http  ${HORIZONSDK_LIBRARY})

#  /W4
# increase warning levels
if (MSVC)
    target_compile_options(onset-http  PRIVATE
          
            /WX
            /permissive-
            /wd4505
            )
elseif(UNIX)
    target_compile_options(onset-http  PRIVATE
            -Wall
            -Wextra
            -pedantic

            -Wno-unused-function
            )
endif()

target_link_libraries(onset-http  ${HORIZONSDK_LIBRARY})

if(UNIX)
    if(NOT APPLE)
        target_link_libraries(onset-http  rt)
    endif()

    set_target_properties(onset-http  PROPERTIES
            INSTALL_RPATH "$ORIGIN/..:$ORIGIN/")
endif()

install(TARGETS onset-http  DESTINATION "plugins/")

set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
if(WIN32)
    set(CPACK_GENERATOR ZIP)
else()
    set(CPACK_GENERATOR TGZ)
endif()

include(CPack)