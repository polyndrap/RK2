include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_VERSION ${PRINT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "C++ Adapter Pattern dev design pattern")
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)

set(CPACK_SOURCE_IGNORE_FILES
"\\\\.cmake;/build/;/.git/;/.github/")

set(CPACK_SOURCE_INSTALLED_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR};Patterns/AdapterPattern")

set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")

set(CPACK_DEBIAN_PACKAGE_NAME "prototype-dev")
set(CPACK_DEBIAN_FILE_NAME "prototype-${PRINT_VERSION}.deb")
set(CPACK_DEBIAN_PACKAGE_VERSION ${PRINT_VERSION})
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "all")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "polyndrap")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Adapter Pattern dev design pattern")
set(CPACK_DEBIAN_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/packages")

set(CPACK_GENERATOR "DEB")

include(CPack)
