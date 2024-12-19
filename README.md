Traffic Light System with Pedestrian Controls

This project demonstrates the development of a fully functioning traffic light system with integrated pedestrian lights and buttons, using the Arduino Uno microcontroller. The system is divided into two main components: the master controller (mastertask5.ino) and the slave controller (slavetask5.ino) for handling pedestrian light logic via serial communication.


Features
Traffic Light Functionality: The traffic light cycles through green, yellow, and red states, mimicking real-life traffic flow.

Pedestrian Light System: Includes pedestrian green and red lights to indicate when it is safe to cross.

Pedestrian Button: A button allows pedestrians to request crossing. Upon pressing, the traffic light switches to red, and the pedestrian light turns green.

Modular Design: Separation of traffic light and pedestrian light logic for scalability and better organization.

Realistic Timing: Implements realistic timing intervals for each light to ensure smooth operation and minimal disruption.


Components
Arduino Uno (Master)

Arduino Uno (Slave)

LEDs (Red, Yellow, Green for traffic lights; Red, Green for pedestrian lights)

Push Button

Resistors (appropriate values for LEDs and button pull-down)

Breadboard and jumper wires


Code Overview
Master (mastertask5.ino)

Manages the main traffic light sequence.

Reads the pedestrian button state to handle pedestrian requests.

Communicates with the slave controller via serial commands ('G', 'R', 'g', 'r').

Slave (slavetask5.ino)

Handles the pedestrian light states based on commands received from the master.


Commands:
'G': Turn on pedestrian green light.

'R': Turn on pedestrian red light.

'g': Turn off pedestrian green light.

'r': Turn off pedestrian red light.


Circuit Diagram
The circuit includes:

Three LEDs for the traffic light connected to digital pins on the master.

Two LEDs for the pedestrian light connected to the slave.

A push button connected to a digital input pin on the master with a pull-down resistor.
