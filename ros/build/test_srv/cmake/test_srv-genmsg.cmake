# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "test_srv: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(test_srv_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/a/my_ros/src/test_srv/srv/AddInts.srv" NAME_WE)
add_custom_target(_test_srv_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "test_srv" "/home/a/my_ros/src/test_srv/srv/AddInts.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(test_srv
  "/home/a/my_ros/src/test_srv/srv/AddInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/test_srv
)

### Generating Module File
_generate_module_cpp(test_srv
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/test_srv
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(test_srv_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(test_srv_generate_messages test_srv_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/a/my_ros/src/test_srv/srv/AddInts.srv" NAME_WE)
add_dependencies(test_srv_generate_messages_cpp _test_srv_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(test_srv_gencpp)
add_dependencies(test_srv_gencpp test_srv_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS test_srv_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(test_srv
  "/home/a/my_ros/src/test_srv/srv/AddInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/test_srv
)

### Generating Module File
_generate_module_eus(test_srv
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/test_srv
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(test_srv_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(test_srv_generate_messages test_srv_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/a/my_ros/src/test_srv/srv/AddInts.srv" NAME_WE)
add_dependencies(test_srv_generate_messages_eus _test_srv_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(test_srv_geneus)
add_dependencies(test_srv_geneus test_srv_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS test_srv_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(test_srv
  "/home/a/my_ros/src/test_srv/srv/AddInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/test_srv
)

### Generating Module File
_generate_module_lisp(test_srv
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/test_srv
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(test_srv_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(test_srv_generate_messages test_srv_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/a/my_ros/src/test_srv/srv/AddInts.srv" NAME_WE)
add_dependencies(test_srv_generate_messages_lisp _test_srv_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(test_srv_genlisp)
add_dependencies(test_srv_genlisp test_srv_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS test_srv_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(test_srv
  "/home/a/my_ros/src/test_srv/srv/AddInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/test_srv
)

### Generating Module File
_generate_module_nodejs(test_srv
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/test_srv
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(test_srv_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(test_srv_generate_messages test_srv_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/a/my_ros/src/test_srv/srv/AddInts.srv" NAME_WE)
add_dependencies(test_srv_generate_messages_nodejs _test_srv_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(test_srv_gennodejs)
add_dependencies(test_srv_gennodejs test_srv_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS test_srv_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(test_srv
  "/home/a/my_ros/src/test_srv/srv/AddInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/test_srv
)

### Generating Module File
_generate_module_py(test_srv
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/test_srv
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(test_srv_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(test_srv_generate_messages test_srv_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/a/my_ros/src/test_srv/srv/AddInts.srv" NAME_WE)
add_dependencies(test_srv_generate_messages_py _test_srv_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(test_srv_genpy)
add_dependencies(test_srv_genpy test_srv_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS test_srv_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/test_srv)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/test_srv
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(test_srv_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/test_srv)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/test_srv
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(test_srv_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/test_srv)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/test_srv
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(test_srv_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/test_srv)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/test_srv
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(test_srv_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/test_srv)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/test_srv\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/test_srv
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(test_srv_generate_messages_py std_msgs_generate_messages_py)
endif()
