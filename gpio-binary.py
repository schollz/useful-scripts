import RPi.GPIO as GPIO 
import time
import sys

GPIO.setwarnings(False)

#A | GPIO | PIN NAME | WIRE COLOR
#0    17       11        Yellow
#1    22       15        Green
#2    23       16        Blue
#3    24       18        Purple
#4    25       22        Gray
#5    27       13        White

pins = [11,15,16,18,22,13]
binaryPins = [11,15,16,18,22]
sendPin = 13

GPIO.setmode(GPIO.BOARD)
for i in range(len(pins)):
	GPIO.setup(pins[i], GPIO.OUT) 
	GPIO.output(pins[i],False) 

num = int(sys.argv[1])
binaryString = '{0:05b}'.format(num)[::-1]
for i in range(len(binaryString)):
	if "1" in binaryString[i]:
		GPIO.output(binaryPins[i],True)
	else:
		GPIO.output(binaryPins[i],False)
	

GPIO.output(sendPin,True)
time.sleep(.5)
GPIO.output(sendPin,False)

for i in range(len(pins)):
	GPIO.output(pins[i],False) 


