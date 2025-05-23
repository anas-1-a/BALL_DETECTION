# BALL_DETECTOR Robot
 This project implements a ball-detector robot using computer vision to detect balls, with real-time debug visualization and Arduino-based motor control. The robot processes camera input to detect balls.

## Project Overview
 The robot uses OpenCV to process video frames, detecting ball (main path)  . A calibration system allows to detect balls(by selecting the max and the min radius ...). Commands are sent to an Arduino to control motors based on navigation decisions.

## Setup Instructions
# 1. Clone the Repository
Clone or download the project to your local machine:
```bash
git clone https://github.com/anas-1-a/BALL_DETECTION
cd BALL_DETECTION
```
# 2. Create a Virtual Environment
Create and activate a virtual environment to isolate dependencies:
### Windows
``` bash
python -m venv venv
venv\Scripts\activate
```
You should see (venv) in your terminal prompt.
# 3. Install Dependencies
Install the required Python packages:
```bash
pip install opencv-python pyserial numpy
```
opencv-python: For image processing and visualization.
pyserial: For Arduino communication.
numpy: For array operations.


# HOW IT WORKS :
## Main.py: 


### THIS HOW CODE MAIN.PY WORK :

![image](https://github.com/user-attachments/assets/1b8fff3e-836a-48c0-a733-b14cd712207c)

## Arduino.ino:


### THIS HOW CODE ARDUINO.INO WORK :

![image](https://github.com/user-attachments/assets/28eeb253-dd2a-4382-a19f-9eb1586266bd)

