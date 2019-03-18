import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

print(ser.name)

s = b'hello'
ser.write(s)
print(ser.read(len(s)))

i = 0
while i < 10:
	ser.write(i)
	ser.read(1)
	i = i + 1

ser.close()
