# Arduino Shield for Gaz sensor and LORA
This project was realized for the Microcontrollers and Open-Source Hardware lecture
of the Innovative Smart Systems program at INSA Toulouse. The goal of the lecture was
to realize an electronic  board that would be able to communicate the information of a 
sensor ( gas sensor in our case) to a network (like the Lora network for example). 
This project could be divided into 2 parts : On one hand, there  is the designing 
the electronic cards on Kicad. On the other hand, there is the development of the 
code on Arduino UNO in order to send the information to the Lora network using TTN.
## Getting Started
### Prerequisites
This is what you would need in order to do the project :
<ul>
    <li>Arduino Uno</li>
    <li>Lora chip - RN2483_breakout</li>
    <li>LED</li>
    <li>Some resistances and capacitors</li>
    <li>Gas sensor ( you can use the MQ2) with the shield (T0-5)</li>
</ul>

### Installing
You have to install Kicad for the hardware designing ( http://kicad-pcb.org/download/ )
and an IDE for Arduino so that you would be able to develop your code. 
(https://www.arduino.cc/en/Main/Software )

## Deployment
### Designing the board
#### Schematic
The main goal of the project is to design a shield for the Arduino. This shield should be able to accommodate both the gas sensor and the Lora chip . 
If you look at the figure 1, the design of the shield could be divides into 5 parts :
On the top left, you have the gaz sesor that would o on a T05 case (http://fr.rsonline.com/web/p/photodiodes/7378098/). You then have a Led connected to a digitl pin on the arduino. For the Lora puce (RN2483), you only need to place a connectivity module in order to save space.  In addition, the impedance of the sensors could go up to 100 Megaohms. This forced us to implement an amplifier circuit as you can observe on the schemaic. Finally you have the arduino uno with all the conncetions on to top right.

![The Schematic](./pictures/GasSensor_schematic.PNG)

                                                 Fig 1 :The Schematic of the shield

#### PCB
Once the schematic is done, you could go on and start with the routing. Here are some tips in order to have a good PCB :
- Try to do all the routing on one side.
- Minimize the lenght of the connections. A good way to do this is to have a ground plane.
- There is minimum width on the wiring depending on your footprints and your printing machine. In my design I had a track size of 20       mil, with 24 mil isolation.

 ![The PCB](./pictures/PCB.PNG)
                                                Fig 2 : 2-D view of the PCB 

                                                 

![Front of the pcb in 3D view](./pictures/Front_pcb.PNG)

                                                Fig 3 : 3-D view of the PCB (front)


![Back of the pcb in 3D view](./pictures/back_pcb.PNG)

                                                 Fig 4 : 3-D view of the PCB (back)


### Setting up the ardiono and Lora Network

In this part, I will talk about how you can send any data from the arduino to a Network using Lora. For this project we used the the thing network because it is easy to set up and to use (https://www.thethingsnetwork.org/)
You can find the arduino code iside the Gas_sensor folder. This code has 2 objectives :
- Receive data from the the Gas sensor and send it to the the thing network
- Turn on the Led depending on the value of the gas sensor

In order for the code to work youhave to follow the commentarygiven in the code. If you have some trouble with the lora network you cna check thethethinknetwork website in which everything is explained. (https://www.thethingsnetwork.org/docs/devices/uno/quick-start.html)

## Improvements
### Hardware

It would been very intersting to measure the energy consumption of the arduino, the Lora chip and the gas Sensor. In case of a big consumption, we can modify the Arduino code in order to put the gas sensor and the Lora on sleep mode when they are not working. If this isn't enough we can implement a switch in order to disconnect the Gas sensor when we are not sending any information.

### Software

On the software part, a lot of things can be added :
-  For instance, we only have send information to the thing network (uplink). It would be great if we could control the leds for example sending information ot fro the arduino but directly fron the TTN (downlink) 
- It could alo be a good idea if we can have a interface in order too see and control the data send by the sensor. To do so, I recommend to use nodered

## FAQ


## Authors
Negatu Michael
5th year student at Insa de Toulouse majoring in automatics and electronics
Innovative Smart System

## Acknowledgments
Jean-Louis NOULLET for the design of the amplifier circuit
Jérémie GRISOLIA and Benjamin MESTRE for the lecture in which we learned  a lot on Arduino.
Arnauld BIGANZOLI for the KiCad lectures and initiation on Github
Catherine CROUZET for the wielding of the shields


