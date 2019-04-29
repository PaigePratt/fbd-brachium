import math

x = float(input("X coord: "))
y = float(input("Y coord: "))

u = 6.5
f = 7.0
w = math.sqrt((x ** 2) + (y ** 2))

if(w <= f - u):
    print("Given coord is to close to base")
    exit()
if(w >= f + u):
    print("Given coord is outside reach of arm")
    exit()
if(math.sqrt((x ** 2) + ((u - y) ** 2)) <= f):
    print("Given coord cannot be reached without bending back")
    exit()

wristAngle = math.atan(y / x)
shoulderAngle = math.acos(((u ** 2) + (w ** 2) - (f ** 2)) / (2 * w * u)) + wristAngle
forearmAngle = math.acos(((u ** 2) + (f ** 2) - (w ** 2)) / (2 * f * u))

print("Shoulder angle: " + str(shoulderAngle * 180 / math.pi) +
    ", forearm angle: " + str(forearmAngle * 180 / math.pi))

calculatedForearmX = math.cos(shoulderAngle) * u
calculatedForearmY = math.sin(shoulderAngle) * u
#
# print("Forearm X: " + str(calculatedForearmX) +
#     ", forearm Y: " + str(calculatedForearmY))

calculatedShoulderX = calculatedForearmX + math.cos(-math.pi + shoulderAngle + forearmAngle) * f
calculatedShoulderY = calculatedForearmY + math.sin(math.pi + shoulderAngle + forearmAngle) * f


print("End X: " + str(calculatedShoulderX) +
    ", end Y: " + str(calculatedShoulderY))
