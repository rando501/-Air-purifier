##  Air purifier  

A smart air purifier designed to monitor and clean the air in a room

<img width="707" height="852" alt="image" src="https://github.com/user-attachments/assets/87eceb55-9a1e-43f2-ac9b-2c19dcbb5f93" />

Watch it in action->https://drive.google.com/file/d/1L3WZ2v1iozQc8GksmH0fdQR3Dinw4Paa/view?usp=sharing
##  Hardware
* ESP32
* I2C OLED display
* PMS7003 particulate matter sensor
* 4 Pin PWN fan
* 3 push buttons
* 12V power supply
* 12v to 5v buck convertor
* wires and connectors
##  Software
1. Install Visual Studio Code
2. Install the PlatformIO extension
3. Clone this repository
4. Open the project in VS Code
5. Connect the ESP32
6.  Upload the project using PlatformIO

##  Features 
* The purifier is modular
* OLED interface
* Three-button navigation
* Manual fan control
* Automatic fan control
* It has a removable/replacable filter
* It can adapt to the air quality to better clean the room
* It can be manually controlled

## How it Works 
The ESP32 is the central controller of the Air Purifier.
The OLED display shows fan information and air quality information. The three buttons allow for navigation of the 3 information pages. It also allows you to pick between manual and auto mode.
In auto mode, the ESP adjusts the fan speed based on the PMS7003 air quality sensor PM2.5 readings. 
In manual mode, you can pick between 0%, 25%, 50%, 75%, and 100%

### Screens 
<img width="867" height="488" alt="image0" src="https://github.com/user-attachments/assets/4f248722-2166-4fba-89b1-1d9fdc4f74ed" />
<img width="778" height="423" alt="image1" src="https://github.com/user-attachments/assets/c63a48fa-edc6-43dd-a005-3def5ccc41e5" />
<img width="836" height="472" alt="image2" src="https://github.com/user-attachments/assets/11213801-143e-4e15-80fa-d89149a13043" />
