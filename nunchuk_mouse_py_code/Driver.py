import serial
import sys
#import pyautogui as pag


def recive_data(ser):
    if ser.in_waiting == 0 :
        return 0
    xanalog = 0
    yanalog = 0
    zbutton = 0
    cbutton = 0
    try:
        try:
            xanalog = ser.readline(sys.getsizeof(int))
            print(xanalog)
            yanalog = ser.readline(sys.getsizeof(int))
            print(yanalog)
            zbutton = ser.readline(sys.getsizeof(int))
            print(zbutton)
            cbutton = ser.readline(sys.getsizeof(int))
            print(cbutton)
        except ValueError:
            pass
    except serial.serialutil.SerialException:
        print("connection error")

if __name__ == "__main__":
    ser = serial.Serial('COM3')
    print (ser.name)
    ser.close()
    ser.open()
    while True:
        ser.flush()
        recive_data(ser)


#pag.move(-50,0)
#pag.move(50,0)