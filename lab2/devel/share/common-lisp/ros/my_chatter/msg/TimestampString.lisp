; Auto-generated. Do not edit!


(cl:in-package my_chatter-msg)


;//! \htmlinclude TimestampString.msg.html

(cl:defclass <TimestampString> (roslisp-msg-protocol:ros-message)
  ((text
    :reader text
    :initarg :text
    :type cl:string
    :initform "")
   (timestamp
    :reader timestamp
    :initarg :timestamp
    :type cl:string
    :initform ""))
)

(cl:defclass TimestampString (<TimestampString>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TimestampString>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TimestampString)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_chatter-msg:<TimestampString> is deprecated: use my_chatter-msg:TimestampString instead.")))

(cl:ensure-generic-function 'text-val :lambda-list '(m))
(cl:defmethod text-val ((m <TimestampString>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_chatter-msg:text-val is deprecated.  Use my_chatter-msg:text instead.")
  (text m))

(cl:ensure-generic-function 'timestamp-val :lambda-list '(m))
(cl:defmethod timestamp-val ((m <TimestampString>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_chatter-msg:timestamp-val is deprecated.  Use my_chatter-msg:timestamp instead.")
  (timestamp m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TimestampString>) ostream)
  "Serializes a message object of type '<TimestampString>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'text))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'text))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'timestamp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'timestamp))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TimestampString>) istream)
  "Deserializes a message object of type '<TimestampString>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'text) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'text) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'timestamp) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'timestamp) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TimestampString>)))
  "Returns string type for a message object of type '<TimestampString>"
  "my_chatter/TimestampString")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TimestampString)))
  "Returns string type for a message object of type 'TimestampString"
  "my_chatter/TimestampString")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TimestampString>)))
  "Returns md5sum for a message object of type '<TimestampString>"
  "43be3b347bd7b8ae7f7eeb0cd1c841ef")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TimestampString)))
  "Returns md5sum for a message object of type 'TimestampString"
  "43be3b347bd7b8ae7f7eeb0cd1c841ef")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TimestampString>)))
  "Returns full string definition for message of type '<TimestampString>"
  (cl:format cl:nil "string text~%string timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TimestampString)))
  "Returns full string definition for message of type 'TimestampString"
  (cl:format cl:nil "string text~%string timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TimestampString>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'text))
     4 (cl:length (cl:slot-value msg 'timestamp))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TimestampString>))
  "Converts a ROS message object to a list"
  (cl:list 'TimestampString
    (cl:cons ':text (text msg))
    (cl:cons ':timestamp (timestamp msg))
))
