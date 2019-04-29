import serial
import math

def gotoAngle(shoulderAngle, forearmAngle):
    if shoulderAngle < 0 or shoulderAngle > 90:
        print("Given shoulder angle is outside range (0 to 90 degrees)")
        return
    if forearmAngle < 0 or forearmAngle > 180:
        print("Given forearm angle is outside range (0 to 180 degrees)")
        return
    out(bytes([math.ceil(shoulderAngle), math.ceil(forearmAngle), math.ceil(0)]))

def out(message):
    print(message.hex())
    #ser.write(message)

# ser = serial.Serial('/dev/ttyACM0', 9600)
#
# print(ser.name)

u = 6.5
f = 7.0

while(True):
    command = input("\nEnter command: ")
    splitcommand = command.split(' ')

    if "exit" == splitcommand[0]:
        print("Goodbye")
        exit()

    if "help" == splitcommand[0] or "h" == splitcommand[0]:
        print("Commands: r to send raw, a to send angles, and c to calculate angles for a given coord. Pass -h to any command for more specific help.")
        continue

    if "r" == splitcommand[0]:
        if "-h" in command:
            print("Pass a string to this command to send that string to the PSoC.")
            continue

        out(command[2:])
        continue

    if "a" == splitcommand[0]:
        if "-h" in command:
            print("Pass in the desired shoulder angle, then the desired forearm angle. Uses degrees.")
            continue
        if len(splitcommand) < 3:
            print("Not enough arguments")
            continue
        gotoAngle(float(splitcommand[1]), float(splitcommand[2]))
        continue

    if "c" == splitcommand[0]:
        if "-h" in command:
            print("Pass in the desired X coord, then the desired Y coord. Uses inches")
            continue
        if len(splitcommand) < 3:
            print("Not enough arguments")
            continue

        x = float(splitcommand[1])
        y = float(splitcommand[2])

        w = math.sqrt((x ** 2) + (y ** 2))

        if(x < 0 or y < 0):
            print("Cannot go to negative coords")
            continue
        if(w <= f - u):
            print("Given coord is to close to base")
            continue
        if(w >= f + u):
            print("Given coord is outside reach of arm")
            continue
        if(math.sqrt((x ** 2) + ((u - y) ** 2)) <= f):
            print("Given coord cannot be reached without bending back")
            continue

        wristAngle = math.atan(y / x)
        shoulderAngle = math.acos(((u ** 2) + (w ** 2) - (f ** 2)) / (2 * w * u)) + wristAngle
        forearmAngle = math.acos(((u ** 2) + (f ** 2) - (w ** 2)) / (2 * f * u))

        gotoAngle(shoulderAngle, forearmAngle)
        continue

    print("Unrecognized command try help for help")
