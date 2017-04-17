# MINI SUMO
Create autonmous robot that can find other robots in the ring and push them off.

[Sumo wiki](https://en.wikipedia.org/wiki/Robot-sumo "Sumo wiki").


# TODO
* ~~Figure out Motor control L293D~~
* Figure out Motor PWM speed
* ~~Figure out Distance sensor HC-SR04~~
* ~~Figure out line sensor~~
* Fit everything inside 10 x 10 cm base
* Basic test keep robot in ring
* Basic test seek and destroy

## Datasheets
* [L293D datasheet](https://www.arduino.cc/documents/datasheets/H-bridge_motor_driver.PDF "L293D datasheet")
* [HCSR04 datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf "HCSR04 datasheet")

## Technical info L293D

| Enable | Input 1 | Input 2 | Function   |
| ------ | ------- | ------- | ---------- |
| H      | L 	   | H       | Turn Right |
| H      | H       | L       | Turn Left  |
| H		 | L       | L 		 | Fast stop  |
| H		 | H       | H 		 | Fast stop  |
| L		 | X       | X 		 | Fast stop  |
