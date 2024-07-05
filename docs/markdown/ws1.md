<!-- link list -->
[0]: https://os.mbed.com/platforms/ST-Nucleo-F446RE/

# Workshop 1

The first workshop aims to introduce the Nucleo-F446RE microcontroller. We will familiarize ourselfs with the Mbed Studio development environment, in IDE for coding and software/firmware development. The workshop will start by analysing a given ***main.cpp*** file, it's structure, and the implementation of basic commands.

Participants will explore hardware utilization, specifically the IR Sensor and a calibration process. To optimize the calibration parameters we will use Matlab.

## Hardware

>Part 1:
> - NUCLEO-F446RE board
> - Mini USB cable for flashing and serial communication
> - LED diode
> - Jumper wires

>Part 2:
> - NUCLEO-F446RE board
> - Mini USB cable
> - IR sensor (check which one you have in your kit, the model name is on the side, it will determine the maximum range of the suported measurements)
> - Additional wires to connect the sensor to the NUCLEO board
> - Paper tape
> - Length measuring tape

### Assignment

We assume that you already have all necessary accounts set-up and software installed to conduct the workshop. If not, go to: [Course Setup](../markdown/general_info.md), and follow the instructions there.

Furthermore, ensure that you are familiar with the general structure of the board. If not, refer to: [Nucleo F446RE](../../README.md#nucleo-f446re)

## Part 1

The first task will be to run a test program using an additional LED.

1. Connect the LED to the pin **PB_9** and ground to the corresponding pin, see [Nucleo Board Pinmap][0]
2. After connecting the additional LED, connect the board to the computer or laptop using the mini USB cable. Immediately after connecting, a console window should appear in Mbed Studio.
3. Make sure you see the active program and the connection to the board in the upper left corner of the screen. If so, you can flash the compiled programm to the microcontroller using the **Play** button.
4. Monitor the progress in the bottom left corner of the screen, where the OS will display information about the uploading process. The big LED on the NUCLEO board will blink with green and red during the flashing process and stay continuously lit once the process is complete.
5. The small LED should be blinking fast now, indicating how many times the program runs per second.
6. Now click the blue **USER** button while watching the additional LED.
7. Now click the blue **USER** button once again, what happends with the additional LED diode?

After finishing the task read through the code, read the comments and try to understand it. Discuss the basic program in the group. 

**If you have any questions, just ask them : - ), always!**

## Part 2

The second task will be carried out using an IR distance sensor. This task will be to calibrate the sensor so that it can be used to measure distances in centimeters. We want to learn more about how sensors are used, including different situations they might be used in, unusual situations, and what they can't do. This helps us understand sensors better as a whole system, so we know what to watch out for as engineers.

1. Read the IR sensor manual. There you can find technical infromation about the sensor and instructions for the connection to the Nucleo board. Perform the calibration according to the hardware tutorial:
   
    > [IR Sensor Tutorial](../markdown/ir_sensor.md)

## Summary

In this workshop, participants were introduced to the Nucleo-F446RE board, acquiring familiarity with the Mbed Studio IDE and basic usage of objects in C++. The workshop included understanding of the ***main.cpp*** file, comprehension of its structure, defining and working with objects and the implementation of essential commands. Additionally, exploration of hardware utilization, particularly an IR sensor, and the corresponding calibration using Matlab were conducted. This first workshop aimed to put basic steps in using the system, laying the groundwork for further exploration for the development of robotics- and mechatronics-systems.

## Solution

- [Workshop 1](../solutions/main_ws1.cpp)

<p align="center">
    <img src="../images/ir_sensor_eval.png" alt="IR Sensor Evaluation" width="950"/> </br>
    <i>IR Sensor Evaluation</i>
</p>