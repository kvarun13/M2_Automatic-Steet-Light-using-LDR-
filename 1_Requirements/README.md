# Description
* It automatically switches the lights ON when the sunlight goes below the visible region of our eyes. This is done by a sensor called Light Dependant Resistor (LDR) which senses the light actually like our eyes. It automatically switches OFF lights whenever the sunlight comes visible to the sensor. 

# Requirements
* Visual Studio Code, AVR compiler, SimulIDE, Make Installer, Doxygen, Linux OS, Windows OS

# Features
* It enables detection of light within the defined range of the working area or public area.
* This system can include N number of led light and has a ability of covering 100's of kilometers.
* Daylight Monitoring plays a vital role in contributing towards making the system energy-efficient.
   
# Highlevel Requirements
|HLR_ID|Description|Status|
|:--:|:--:|:--:|
|HLR_1|This project ensures detection of sunlight in the prediscribed area|Implemented|
|HLR_2|This project facilitates Daylight Monitoring|Implemented|
|HLR_3|This project ensures turning on the bulb if there isn't enough daylight and detection is ascertained|Implemented|
|HLR_4|This project aims to cover most of the liighting appliances|Future|

    
# Lowlevel Requirements
|HLR_ID|LLR_ID|Description|Status|
|:--:|:--:|:--:|:--:|
|HLR_1|LLR_01|The detection is performed using LDR sensor|Implemented|
|HLR_2|LLR_01|The Daylight Monitoring is facilitated by LCD display which tells us no of led on at that time|Implemented|
|HLR_3|LLR_01|Control signal is given to controller which facilitates turning on/off the bulb|Implemented|


# 4W's & 1H
* **What**  : Automatic Street Light using LDR and microcontroller Atmega328.
* **When**  : When there is a need to automate the mechanization processes on public environments.
* **Where** : It can be incorporated seamlessly in any working area or public area.
* **Why**   : To vouch towards energy conservation, automation of individual working area or public area and thus improving the standard of living.
* **How**   : By developing an embedded system using LDR with Atmega328 being the microcontroller.

# References
https://www.learnelectronicsindia.com/post/smart-street-light-project-using-arduino-uno-ldr-and-led

