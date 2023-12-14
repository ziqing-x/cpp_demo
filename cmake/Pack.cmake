set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "${PKG_NAME}")
set(CPACK_PACKAGE_VERSION "${VERSION}")
set(CPACK_PACKAGE_CONTACT "jassimxiong@gmail.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "jassimxiong@gmail.com")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "这是一个demo")
set(CPACK_PACKAGING_INSTALL_PREFIX "${APP_ROOT_DIR}")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
install(
    PROGRAMS ${CMAKE_BINARY_DIR}/bin/${APP_NAME}
    DESTINATION ${APP_ROOT_DIR}/bin
)
install(
    FILES ${CMAKE_BINARY_DIR}/${SERVICE}
    DESTINATION /lib/systemd/system
)
install(
    FILES ${CMAKE_BINARY_DIR}/config/app.conf
    DESTINATION ${APP_ROOT_DIR}/config
)

include(CPack)