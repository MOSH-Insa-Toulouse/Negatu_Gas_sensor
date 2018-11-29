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


