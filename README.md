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

The diverging beam of transmitter IR(looks like a cone) is incident on the mirror which makes an angle with the axis of the cone ,with vertex angle of 25 degrees, but i'm using 35 degrees as recommended by the VL53L0X datasheet for less interference in reading. This incident cone creates a ellipse of light rays in the plane of mirror.

<img width="848" height="615" alt="Screenshot 2026-07-21 084713" src="https://github.com/user-attachments/assets/285077d7-6653-41a9-a682-99c3d9c165e4" />

ellipse:

<img width="759" height="547" alt="Screenshot 2026-07-21 084726" src="https://github.com/user-attachments/assets/99ef5299-3f90-495a-a8cd-4cfa308e1a1c" />

this angle is used to decide the distance at which we need to keep the mirror from the sensor and which ultimately for a fixed size of mirror decides the un measurable lost region due to the sensor hiding the reflected transmitted beam.

The beam keeps diverging even after reflection, it is because the reflected rays diverge away(see images 1 and 2 made by me in desmos3d for visualization)

calculation of distance between ToF sensor and centre of mirror:

<img width="1080" height="960" alt="radius finding" src="https://github.com/user-attachments/assets/24b42af6-d953-454d-bb7e-5ac64eca82eb" />

Visualization of LIDAR scanning full 360 degrees:

<img width="1428" height="645" alt="LIDAR 360 scan visualization" src="https://github.com/user-attachments/assets/c4e92d62-4920-4161-8b71-070b8c43cabe" />

link: https://www.desmos.com/3d/27ven6rfr8

The reflected ray doesnt make the same angle with the x axis as the plane makes at any point of time, derivation of relation between the angle made by reflected ray with x axis to the angle made by plane with x axis:

<img width="733" height="1123" alt="angle relation lidar" src="https://github.com/user-attachments/assets/d1707fcd-7eb1-4f67-987b-1e14a03ae77f" />

x -> angle made by mirror with y axis = angle made by normal with x axis.

as x = θ, using the diagram in above image, angle made by reflected ray with x axis(in image, +x axis is pointing downwards, towards sensor/source) is twice that of angle made by the normal with x axis : angle of reflected ray with x axis = 2x

Hence for a 360 degree scan, the mirror has to rotate only by 180 degrees per sweep.

CODE AND WORKING OF LIDAR:

configuration of VL53L0X, input output pins and Serial monitor has been done in void setup.

The code for this project has five functions:

1. get_distance() ---> measures and returns the sum, distance between the LIDAR mirror + distance between mirror and TOF sensor. Return value is an unsigned int

2. fwd() ----> runs the for loop to turn on transistor array for the stepper motor to step forward.the loop itself consist of 4 steps per loop. Returns none, gets int as number of steps

3. bwd() ----> runs loop for backward stepper spin. Returns none, gets number of steps.

4. set_low() ----> sets all stepper motor transistor array pins low.

5. stepper() ---- > combines fwd() and bwd().  updates a count to keep track of number of times 4 seps has been taken(for angle calculation).
   the count is used int calculating angle by multiplying the ratio of number of 4 steps taken to number of 4 steps in a full 360 degree spin(2048 steps in full rotation) = 2048/4 = 512 sets of 4 steps, ratio : (count/512). multiplying ratio with 2*pi will give the angle at that point of time in radians

Void loop calls these functions in order of :
1. getting the distance
2. calculating the coordinates
3. printing coordinates to serial monitor
4. moving the stepper 4 steps forward
5. waiting 300ms.

OUTPUT:
