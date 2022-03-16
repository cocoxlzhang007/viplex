colormsg(_HIBLUE_ "---Start---Configuring viplex App")
##
#############################################################
message(${IDE_TARGET_NAME})
project(${IDE_TARGET_NAME})

if(${SYSTEMTYPE} STREQUAL "MacOS")
INCLUDE_DIRECTORIES(
 ${THIRDPARTY_ROOT}/quazip/${SYSTEMTYPE}/${Platform}/include/
${THIRDPARTY_ROOT}/tcplib/include/
 ${THIRDPARTY_ROOT}/curllib/${SYSTEMTYPE}/${Platform}/include/
${THIRDPARTY_ROOT}/../src/libs/viplexcore
)
message(${THIRDPARTY_ROOT}/quazip/${SYSTEMTYPE}/${Platform}/include/)
#依赖库的地址
LINK_DIRECTORIES(
 ${THIRDPARTY_ROOT}/quazip/${SYSTEMTYPE}/${Platform}/lib
 ${THIRDPARTY_ROOT}/curllib/${SYSTEMTYPE}/${Platform}/lib/
)

#依赖库
set(DEPENDENCIES
    libquazip5.a
    ${THIRDPARTY_ROOT}/sqlite3/${SYSTEMTYPE}/lib/libsqlite3.tbd
    ${THIRDPARTY_ROOT}/curllib/${SYSTEMTYPE}/${Platform}/lib/libcurl.a
    ${THIRDPARTY_ROOT}/curllib/${SYSTEMTYPE}/${Platform}/lib/libcrypto.a
    ${THIRDPARTY_ROOT}/curllib/${SYSTEMTYPE}/${Platform}/lib/libnghttp2.a
    ${THIRDPARTY_ROOT}/curllib/${SYSTEMTYPE}/${Platform}/lib/libssl.a
)
else()
INCLUDE_DIRECTORIES(
    ${THIRDPARTY_ROOT}/../src/libs/viplexcore
	${THIRDPARTY_ROOT}/quazip/${SYSTEMTYPE}/${Platform}/include/
	${THIRDPARTY_ROOT}/httplib/openssl_1.1.1/${SYSTEMTYPE}/${Platform}/include
	${THIRDPARTY_ROOT}/tcplib/include/
	${THIRDPARTY_ROOT}/curllib/${SYSTEMTYPE}/${Platform}/include/
)

#依赖库的地址
LINK_DIRECTORIES(
	${THIRDPARTY_ROOT}/quazip/${SYSTEMTYPE}/${Platform}/lib
	${THIRDPARTY_ROOT}/httplib/openssl_1.1.1/${SYSTEMTYPE}/${Platform}/lib
	${THIRDPARTY_ROOT}/curllib/${SYSTEMTYPE}/${Platform}/lib/
)

endif()

IF (WIN32)
	set(DEPENDENCIES
	quazip.lib
	)
	ENDIF()

#添加源文件 Source files.
SET(SOURCES 
	${SOURCES}
    main.cpp
	demoGUI.cpp
	demoChildGUI.cpp
	changepassword.cpp
	logindialog.cpp
)


#添加头文件Header files.
SET(HEADERS
    ${HEADERS}  
	resource.h
	demoGUI.h
	demoChildGUI.h
	changepassword.h
	logindialog.h
)

#添加UI文件 UI files
FILE(GLOB_RECURSE FORMS "${CMAKE_CURRENT_SOURCE_DIR}/*.ui")

#添加资源文件Resource files.
SET (RESOURCES
	

)
#添加其他文件Other files
SET(OTHER_FILES
	version.rc
)	

#Qt模块
SET(QT_MODULES
    Core
    Gui
    Widgets
)

if(${SYSTEMTYPE} STREQUAL "android")
    # 依赖非Qt库，非本项库  undefined reference to `COMP_CTX_new'  两个库的顺序问题  ssl要在前
	#依赖库
	set(DEPENDENCIES
		libquazip.a
		libcurl.a
		libssl.a
		libcrypto.a
		)
elseif(${SYSTEMTYPE} STREQUAL "iOS")
set(DEPENDENCIES
		libQt5Quazip.a
		)
endif()

SET(WIS_MODULE_DEPS
    viplexcore
    )


########################################################
## 生成主应用程序
WIS_QT_INIT_EXE_MODULE(TRUE TRUE)
if(${SYSTEMTYPE} STREQUAL "linux")
    find_package(Threads)
        target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
        set(CMAKE_CXX_FLAGS   "${CMAKE_CXX_FLAGS} -Wl,-z,origin,-rpath,$ORIGIN:$ORIGIN/lib")
endif()
######################################################3.0.4
IF (MSVC)
	##取消管理员权限,放在add_executable的后面
	MESSAGE(${IDE_TARGET_NAME})
    #SET_TARGET_PROPERTIES(${IDE_TARGET_NAME} PROPERTIES
	#	LINK_FLAGS "/MANIFESTUAC:\"level='asInvoker' uiAccess='false'\"")
ENDIF()

#文件拷贝
 IF(WIN32)
     # string(REPLACE "/" "\\" NATIVE_SOURCE_DIR ${CMAKE_SOURCE_DIR} )
     # string(REPLACE "/" "\\" NATIVE_BIN_DIR ${BIN_DIR} )
	 # ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
			 # COMMAND call ${NATIVE_SOURCE_DIR}\\build\\bat\\copy_files.bat ${CMAKE_BUILD_TYPE} ${Platform}
	 # )
 ENDIF()

