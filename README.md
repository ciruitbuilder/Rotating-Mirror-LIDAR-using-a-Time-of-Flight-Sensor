# Rotating-Mirror-LIDAR-using-a-Time-of-Flight-Sensor
DESCRIPTION:


This is an attempt to build a LIDAR(Light Ditection and Ranging) using a GY-VL53L0X Time of FLight(ToF) sensor and a unipolar stepper motor. 

BUILD:


The build involves a rotating set of mirrors placed so that its centre aligns with the ToF sensor's laser emitter and photo avalanche diode array reciever.
The element responsible with the rotation of the mirror is a unipolar stepper motor. The whole setup is placed over a tin plate.

The unipolar stepper motor driver was built by me using an array of NPN transistors and turning them on and off in order using an arduino board(same one used to gather distance data from the ToF sensor)

MATERIALS REQUIRED:


28byj 48 12v unipolar stepper motor

GY-VL53L0X ToF Sensor

Pair of mirrors stuck together(on the non reflective sides) to create a reflective surface on both sides for reflection to allow the reflected ray cover all of 2D area when the mirror rotates.

Wires

4x BC547 NPN Transistor

Popsicle sticks(to support the ToF sensor).

2x Screws

CIRCUIT DIAGRAM:

<img width="1000" height="460" alt="LIDAR circuit" src="https://github.com/user-attachments/assets/8db11aa3-b440-48b3-8306-a6a1f77d7ec4" />
