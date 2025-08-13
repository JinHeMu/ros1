# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "topic_test: 1 messages, 1 services")

set(MSG_I_FLAGS "-Itopic_test:/home/a/ros1/ch2/src/topic_test/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(topic_test_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/msg/person.msg" NAME_WE)
add_custom_target(_topic_test_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "topic_test" "/home/a/ros1/ch2/src/topic_test/msg/person.msg" ""
)

get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv" NAME_WE)
add_custom_target(_topic_test_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "topic_test" "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(topic_test
  "/home/a/ros1/ch2/src/topic_test/msg/person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/topic_test
)

### Generating Services
_generate_srv_cpp(topic_test
  "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/topic_test
)

### Generating Module File
_generate_module_cpp(topic_test
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/topic_test
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(topic_test_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(topic_test_generate_messages topic_test_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/msg/person.msg" NAME_WE)
add_dependencies(topic_test_generate_messages_cpp _topic_test_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv" NAME_WE)
add_dependencies(topic_test_generate_messages_cpp _topic_test_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(topic_test_gencpp)
add_dependencies(topic_test_gencpp topic_test_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS topic_test_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(topic_test
  "/home/a/ros1/ch2/src/topic_test/msg/person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/topic_test
)

### Generating Services
_generate_srv_eus(topic_test
  "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/topic_test
)

### Generating Module File
_generate_module_eus(topic_test
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/topic_test
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(topic_test_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(topic_test_generate_messages topic_test_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/msg/person.msg" NAME_WE)
add_dependencies(topic_test_generate_messages_eus _topic_test_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv" NAME_WE)
add_dependencies(topic_test_generate_messages_eus _topic_test_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(topic_test_geneus)
add_dependencies(topic_test_geneus topic_test_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS topic_test_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(topic_test
  "/home/a/ros1/ch2/src/topic_test/msg/person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/topic_test
)

### Generating Services
_generate_srv_lisp(topic_test
  "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/topic_test
)

### Generating Module File
_generate_module_lisp(topic_test
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/topic_test
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(topic_test_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(topic_test_generate_messages topic_test_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/msg/person.msg" NAME_WE)
add_dependencies(topic_test_generate_messages_lisp _topic_test_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv" NAME_WE)
add_dependencies(topic_test_generate_messages_lisp _topic_test_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(topic_test_genlisp)
add_dependencies(topic_test_genlisp topic_test_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS topic_test_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(topic_test
  "/home/a/ros1/ch2/src/topic_test/msg/person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/topic_test
)

### Generating Services
_generate_srv_nodejs(topic_test
  "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/topic_test
)

### Generating Module File
_generate_module_nodejs(topic_test
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/topic_test
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(topic_test_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(topic_test_generate_messages topic_test_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/msg/person.msg" NAME_WE)
add_dependencies(topic_test_generate_messages_nodejs _topic_test_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv" NAME_WE)
add_dependencies(topic_test_generate_messages_nodejs _topic_test_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(topic_test_gennodejs)
add_dependencies(topic_test_gennodejs topic_test_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS topic_test_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(topic_test
  "/home/a/ros1/ch2/src/topic_test/msg/person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/topic_test
)

### Generating Services
_generate_srv_py(topic_test
  "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/topic_test
)

### Generating Module File
_generate_module_py(topic_test
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/topic_test
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(topic_test_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(topic_test_generate_messages topic_test_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/msg/person.msg" NAME_WE)
add_dependencies(topic_test_generate_messages_py _topic_test_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/a/ros1/ch2/src/topic_test/srv/add_int.srv" NAME_WE)
add_dependencies(topic_test_generate_messages_py _topic_test_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(topic_test_genpy)
add_dependencies(topic_test_genpy topic_test_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS topic_test_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/topic_test)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/topic_test
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(topic_test_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/topic_test)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/topic_test
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(topic_test_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/topic_test)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/topic_test
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(topic_test_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/topic_test)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/topic_test
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(topic_test_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/topic_test)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/topic_test\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/topic_test
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(topic_test_generate_messages_py std_msgs_generate_messages_py)
endif()
