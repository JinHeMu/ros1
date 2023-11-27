;; Auto-generated. Do not edit!


(when (boundp 'test_srv::AddInts)
  (if (not (find-package "TEST_SRV"))
    (make-package "TEST_SRV"))
  (shadow 'AddInts (find-package "TEST_SRV")))
(unless (find-package "TEST_SRV::ADDINTS")
  (make-package "TEST_SRV::ADDINTS"))
(unless (find-package "TEST_SRV::ADDINTSREQUEST")
  (make-package "TEST_SRV::ADDINTSREQUEST"))
(unless (find-package "TEST_SRV::ADDINTSRESPONSE")
  (make-package "TEST_SRV::ADDINTSRESPONSE"))

(in-package "ROS")





(defclass test_srv::AddIntsRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod test_srv::AddIntsRequest
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

(defclass test_srv::AddIntsResponse
  :super ros::object
  :slots (_sum ))

(defmethod test_srv::AddIntsResponse
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

(defclass test_srv::AddInts
  :super ros::object
  :slots ())

(setf (get test_srv::AddInts :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get test_srv::AddInts :datatype-) "test_srv/AddInts")
(setf (get test_srv::AddInts :request) test_srv::AddIntsRequest)
(setf (get test_srv::AddInts :response) test_srv::AddIntsResponse)

(defmethod test_srv::AddIntsRequest
  (:response () (instance test_srv::AddIntsResponse :init)))

(setf (get test_srv::AddIntsRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get test_srv::AddIntsRequest :datatype-) "test_srv/AddIntsRequest")
(setf (get test_srv::AddIntsRequest :definition-)
      "int32 num1
int32 num2
---
int32 sum
")

(setf (get test_srv::AddIntsResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get test_srv::AddIntsResponse :datatype-) "test_srv/AddIntsResponse")
(setf (get test_srv::AddIntsResponse :definition-)
      "int32 num1
int32 num2
---
int32 sum
")



(provide :test_srv/AddInts "4781436a0c2affec8025955a6041e481")


