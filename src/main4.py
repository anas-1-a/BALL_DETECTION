import cv2
import numpy as np
import serial
import time
cap = cv2.VideoCapture(0)
#ser = serial.Serial('COM4', 9600)
time.sleep(2)  
if not cap.isOpened():
    print("Error: Could not open webcam")
    exit()
while True:
    ret, frame = cap.read()
    if not ret:
        print("Error: Failed to capture image")
        break
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blurred = cv2.GaussianBlur(gray, (15, 15), 0)
    circles = cv2.HoughCircles(
        blurred, cv2.HOUGH_GRADIENT, 1, minDist=80,
        param1=50, param2=30, minRadius=30, maxRadius=60
    )
    coords = None
    if circles is not None:
        circles = np.round(circles[0, :]).astype("int")
        for (x, y, r) in circles:
            cv2.circle(frame, (x, y), r, (0, 255, 0), 4)
            cv2.circle(frame, (x, y), 3, (0, 0, 255), 3)
            coords = [x, y, r]
            break 
    height, width, _ = frame.shape
    center_x = width // 2
    center_y = height // 2
    cv2.line(frame, (center_x, 0), (center_x, height), (255, 0, 0), 2)
    if coords is not None:
        x, y, rayon = coords
        diff_x = x - center_x
        diff_y = y - center_y
        if  diff_x < 0:
             print("left" : diff_x)
        else :
             print("right" : diff_x)
        if rayon < 35:
            print("far ::", rayon)
        else:
            print("close :", rayon)
        difference_x= diff_x+320
       # data_to_send = f"{difference_x},{rayon}\n"
       # ser.write(data_to_send.encode())
       # print(f"Sent: {data_to_send.strip()}")
    cv2.imshow("ccsc", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
#ser.close()
cv2.destroyAllWindows()
