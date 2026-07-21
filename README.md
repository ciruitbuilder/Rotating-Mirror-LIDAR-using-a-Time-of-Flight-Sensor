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

RAY OPTICS:

Visulizing how the diverging beam of IR from the VL53L0X sensor hits the mirror, gets reflected and keeps diverging.
image 1

<img width="1283" height="819" alt="image 1" src="https://github.com/user-attachments/assets/2f7c6442-0be0-41ab-905d-f94ecd703fa7" />

image 2

<img width="893" height="677" alt="image 2" src="https://github.com/user-attachments/assets/9b09be77-49fe-4a3d-9511-64f9cf86b66a" />

graph link:

https://www.desmos.com/3d/aw1s0kakht

The diverging beam of transmitter IR(looks like a cone of ) is incident on the mirror which makes an angle with the axis of the cone with vertex angle of 25 degrees, but i'm using 35 degrees as recommended by the VL53L0X datasheet for less interference in reading. This incident cone creates a ellipse of light rays in the plane of mirror.

<img width="848" height="615" alt="Screenshot 2026-07-21 084713" src="https://github.com/user-attachments/assets/285077d7-6653-41a9-a682-99c3d9c165e4" />

ellipse:

<img width="759" height="547" alt="Screenshot 2026-07-21 084726" src="https://github.com/user-attachments/assets/99ef5299-3f90-495a-a8cd-4cfa308e1a1c" />

this angle is used to decide the distance at which we need to keep the mirror from the sensor and which ultimately for a fixed size of mirror decides the un measurable lost region due to the sensor hiding the reflected transmitted beam.

calculation of distance between ToF sensor and centre of mirror:



