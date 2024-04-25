# Solar Tracker using Arduino | Dual Axis Solar Tracker
in this project, we use four LDR and two servo motors (make dual-axis), these four LDR rotate the two servo motors with respect to the intensity of the light. when there is a light source then it will automatically align to the light.
## MG995 Servo is a continuous servo and not a positioning type.
You can only control its speed and direction.

servo.write(value);

where value
0 = clockwise full speed
90 = stop
180 = anticlockwise full speed

## Circuit
![wiring-c](https://github.com/aimedidierm/solar-tracker/assets/73910734/04860d7a-2f9d-46c8-b08e-8dd0f8345cbf)
