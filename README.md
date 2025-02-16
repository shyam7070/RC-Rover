# RC-Rover
This project demonstrates an RC-controlled car built with three NodeMCU modules for seamless wireless communication and control. The car is controlled via Wi-Fi, with one NodeMCU acting as the controller and the other two handling motor control and additional functionalities.

# Project Overview
The RC-controlled car is designed to be operated wirelessly using NodeMCU boards and the ESP8266 Wi-Fi module. The project utilizes three NodeMCU modules:
Controller NodeMCU: Acts as a remote control, sending commands wirelessly.
Motor Control NodeMCU: Receives control signals to drive the motors.
Peripheral NodeMCU: Handles additional functionalities such as sensors, lights, or other modules.

# Features
Wireless control using Wi-Fi (ESP8266 modules).
Dual motor control for car movement (forward, backward, left, right).
Integration of additional modules like sensors or lights.
Real-time communication between the three NodeMCUs.
Custom-designed PCB layout in KiCad for efficient connections.

# Hardware Components
3x NodeMCU (ESP8266)
L298N Motor Driver Module
DC Motors with wheels
LiPo Battery (or power supply)
Chassis for RC car
LEDs for lights (optional)
Ultrasonic sensor (optional for obstacle detection)
Jumper wires and connectors
PCB designed in KiCad (optional)

# Circuit Schematic and PCB Layout
The circuit schematic and PCB layout were designed in KiCad, ensuring proper connections between NodeMCUs, motor drivers, and power sources.

# Software and Libraries
Arduino IDE for programming NodeMCU.
WiFi Library for ESP8266 communication.
Motor Driver Library for motor control.
KiCad for schematic and PCB design.

# How It Works
1. Controller NodeMCU: Sends movement commands based on input from buttons, a mobile app, or a joystick.
2. Motor Control NodeMCU: Receives commands and drives the motors through the L298N module.
3. Peripheral NodeMCU: Manages sensors, lights, or additional features and communicates with the motor control unit.

Installation and Setup

1. Clone this repository:
   git clone https://github.com/shyam7070/RC-Rover.git
2. Upload the provided Arduino sketches to each NodeMCU using the Arduino IDE.
3. Assemble the car according to the schematic provided.
4. Power up the system and control the car wirelessly.

# Future Improvements
Adding a camera module for FPV (First Person View) driving.
Implementing Bluetooth control as an alternative.
Integrating GPS for location tracking.

# Author

Narasingarao K
+917075025629
knrkondapalli123@gmail.com
