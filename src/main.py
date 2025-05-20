import cv2
import numpy as np
import serial
cap = cv2.VideoCapture(0)
#ser = serial.Serial('COM4', 9600)
if not cap.isOpened():
    print("Error: Could not open webcam")
    exit()
while True :
    ret, frame = cap.read()
    if not ret:
        print("Error: Failed to capture image")
        break
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blurred = cv2.GaussianBlur(gray, (15, 15), 0)
    circles = cv2.HoughCircles(blurred, cv2.HOUGH_GRADIENT, 1, minDist=80, param1=50, param2=30, minRadius=30, maxRadius=60)
    coords = []  
    if circles is not None:
        circles = np.round(circles[0, :]).astype("int")
        for (x, y, r) in circles:
            cv2.circle(frame, (x, y), r, (0, 255, 0), 4)           
            cv2.circle(frame, (x, y), 3, (0, 0, 255), 3)  
            coords=[x, y,r]
    c=[320, 240]
    height, width, _ = frame.shape
    center_x = width // 2
    center_y = height // 2
    cv2.line(frame, (center_x, 0), (center_x, height), (255, 0, 0), 2)
    if coords:
        coords = np.array(coords)
        diff_x = coords[0] - c[0]
        diff_y = coords[1] - c[1]
        diff= [ diff_x , diff_y]
        rayon = coords[2]
        if rayon<35 :
            print("far ::",rayon )
        else :
            print("close :" , rayon)
        if diff[0]<0:
            print("left :",diff[0] )
        else :
            print("right :" , diff[0])
        difff_x= diff[0]+320
        
        #data_to_send = f"{rayon}\n"
        #ser.write(data_to_send.encode())
    cv2.imshow(" ccsc", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
