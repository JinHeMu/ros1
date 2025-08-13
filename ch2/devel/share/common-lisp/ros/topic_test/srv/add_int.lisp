; Auto-generated. Do not edit!


(cl:in-package topic_test-srv)


;//! \htmlinclude add_int-request.msg.html

(cl:defclass <add_int-request> (roslisp-msg-protocol:ros-message)
  ((num1
    :reader num1
    :initarg :num1
    :type cl:integer
    :initform 0)
   (num2
    :reader num2
    :initarg :num2
    :type cl:integer
    :initform 0))
)

(cl:defclass add_int-request (<add_int-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <add_int-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'add_int-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name topic_test-srv:<add_int-request> is deprecated: use topic_test-srv:add_int-request instead.")))

(cl:ensure-generic-function 'num1-val :lambda-list '(m))
(cl:defmethod num1-val ((m <add_int-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader topic_test-srv:num1-val is deprecated.  Use topic_test-srv:num1 instead.")
  (num1 m))

(cl:ensure-generic-function 'num2-val :lambda-list '(m))
(cl:defmethod num2-val ((m <add_int-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader topic_test-srv:num2-val is deprecated.  Use topic_test-srv:num2 instead.")
  (num2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <add_int-request>) ostream)
  "Serializes a message object of type '<add_int-request>"
  (cl:let* ((signed (cl:slot-value msg 'num1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'num2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <add_int-request>) istream)
  "Deserializes a message object of type '<add_int-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num1) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num2) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<add_int-request>)))
  "Returns string type for a service object of type '<add_int-request>"
  "topic_test/add_intRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'add_int-request)))
  "Returns string type for a service object of type 'add_int-request"
  "topic_test/add_intRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<add_int-request>)))
  "Returns md5sum for a message object of type '<add_int-request>"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'add_int-request)))
  "Returns md5sum for a message object of type 'add_int-request"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<add_int-request>)))
  "Returns full string definition for message of type '<add_int-request>"
  (cl:format cl:nil "int32 num1~%int32 num2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'add_int-request)))
  "Returns full string definition for message of type 'add_int-request"
  (cl:format cl:nil "int32 num1~%int32 num2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <add_int-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <add_int-request>))
  "Converts a ROS message object to a list"
  (cl:list 'add_int-request
    (cl:cons ':num1 (num1 msg))
    (cl:cons ':num2 (num2 msg))
))
;//! \htmlinclude add_int-response.msg.html

(cl:defclass <add_int-response> (roslisp-msg-protocol:ros-message)
  ((sum
    :reader sum
    :initarg :sum
    :type cl:integer
    :initform 0))
)

(cl:defclass add_int-response (<add_int-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <add_int-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'add_int-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name topic_test-srv:<add_int-response> is deprecated: use topic_test-srv:add_int-response instead.")))

(cl:ensure-generic-function 'sum-val :lambda-list '(m))
(cl:defmethod sum-val ((m <add_int-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader topic_test-srv:sum-val is deprecated.  Use topic_test-srv:sum instead.")
  (sum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <add_int-response>) ostream)
  "Serializes a message object of type '<add_int-response>"
  (cl:let* ((signed (cl:slot-value msg 'sum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <add_int-response>) istream)
  "Deserializes a message object of type '<add_int-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sum) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<add_int-response>)))
  "Returns string type for a service object of type '<add_int-response>"
  "topic_test/add_intResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'add_int-response)))
  "Returns string type for a service object of type 'add_int-response"
  "topic_test/add_intResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<add_int-response>)))
  "Returns md5sum for a message object of type '<add_int-response>"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'add_int-response)))
  "Returns md5sum for a message object of type 'add_int-response"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<add_int-response>)))
  "Returns full string definition for message of type '<add_int-response>"
  (cl:format cl:nil "int32 sum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'add_int-response)))
  "Returns full string definition for message of type 'add_int-response"
  (cl:format cl:nil "int32 sum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <add_int-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <add_int-response>))
  "Converts a ROS message object to a list"
  (cl:list 'add_int-response
    (cl:cons ':sum (sum msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'add_int)))
  'add_int-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'add_int)))
  'add_int-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'add_int)))
  "Returns string type for a service object of type '<add_int>"
  "topic_test/add_int")