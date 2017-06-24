import serial
import time
#Confirms the test file opened
print ("What does the fox say?")


ser = serial.Serial('COM3',9600)
#Send Start Signal that will prompt the action
time.sleep(10)
rtn = ser.write(1)
