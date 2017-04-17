# MINI SUMO
Create autonmous robot that can find other robots in the ring and push them off.

A [link](https://en.wikipedia.org/wiki/Robot-sumo "Sumo wiki").


# TODO
* ~~Figure out Motor control~~
* Figure out Motor PWM speed
* Figure out Distance sensor HC-SR04
* Figure out line sensor 
* Fit everything inside 10 x 10 cm base


## Technical info L293D

| Enable | Input 1 | Input 2 | Function   |
| ------ | ------- | ------- | ---------- |
| H      | L 	   | H       | Turn Right |
| H      | H       | L       | Turn Left  |
| H		 | L       | L 		 | Fast stop  |
| H		 | H       | H 		 | Fast stop  |
| L		 | X       | X 		 | Fast stop  |
