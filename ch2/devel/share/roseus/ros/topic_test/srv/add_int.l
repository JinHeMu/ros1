;; Auto-generated. Do not edit!


(when (boundp 'topic_test::add_int)
  (if (not (find-package "TOPIC_TEST"))
    (make-package "TOPIC_TEST"))
  (shadow 'add_int (find-package "TOPIC_TEST")))
(unless (find-package "TOPIC_TEST::ADD_INT")
  (make-package "TOPIC_TEST::ADD_INT"))
(unless (find-package "TOPIC_TEST::ADD_INTREQUEST")
  (make-package "TOPIC_TEST::ADD_INTREQUEST"))
(unless (find-package "TOPIC_TEST::ADD_INTRESPONSE")
  (make-package "TOPIC_TEST::ADD_INTRESPONSE"))

(in-package "ROS")





(defclass topic_test::add_intRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod topic_test::add_intRequest
  (:init
   (&key
    ((:num1 __num1) 0)
    ((:num2 __num2) 0)
    )
   (send-super :init)
   (setq _num1 (round __num1))
   (setq _num2 (round __num2))
   self)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:serialization-length
   ()
   (+
    ;; int32 _num1
    4
    ;; int32 _num2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num1
       (write-long _num1 s)
     ;; int32 _num2
       (write-long _num2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num1
     (setq _num1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _num2
     (setq _num2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass topic_test::add_intResponse
  :super ros::object
  :slots (_sum ))

(defmethod topic_test::add_intResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass topic_test::add_int
  :super ros::object
  :slots ())

(setf (get topic_test::add_int :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get topic_test::add_int :datatype-) "topic_test/add_int")
(setf (get topic_test::add_int :request) topic_test::add_intRequest)
(setf (get topic_test::add_int :response) topic_test::add_intResponse)

(defmethod topic_test::add_intRequest
  (:response () (instance topic_test::add_intResponse :init)))

(setf (get topic_test::add_intRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get topic_test::add_intRequest :datatype-) "topic_test/add_intRequest")
(setf (get topic_test::add_intRequest :definition-)
      "int32 num1
int32 num2
---
int32 sum
")

(setf (get topic_test::add_intResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get topic_test::add_intResponse :datatype-) "topic_test/add_intResponse")
(setf (get topic_test::add_intResponse :definition-)
      "int32 num1
int32 num2
---
int32 sum
")



(provide :topic_test/add_int "4781436a0c2affec8025955a6041e481")


