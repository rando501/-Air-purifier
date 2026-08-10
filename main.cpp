#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PM25AQI.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
Adafruit_PM25AQI aqi = Adafruit_PM25AQI();
HardwareSerial pmsSerial(2);

#define Left_Button 25
#define Select_Button 26
#define Right_Button 27
float pm25 = 45.0;
float pm10 = 20.0;

int editmode = 0; // 0 for screen select, 1 for fan speed, 2 for fan mode
int Fan_Mode = 1; // 0 for manual, 1 for auto
int Fan_Speed = 50;
int screen = 0; //0 for main menu, 1 for fan control, 2 for air quality
void setup() {
 
  
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    pinMode(Left_Button, INPUT_PULLUP);
    pinMode(Select_Button, INPUT_PULLUP);
    pinMode(Right_Button, INPUT_PULLUP);

    pmsSerial.begin(9600, SERIAL_8N1, 16, 17);
    aqi.begin_UART(&pmsSerial);
    
}





void loop() { 
  PM25_AQI_Data data;
  if (aqi.read(&data)) {
    pm25 = data.pm25_standard;
    pm10 = data.pm10_standard;
  }
  if (Fan_Mode == 1) {
    if (pm25 >55) {
      Fan_Speed = 100;
    } else if (pm25 >35) {
      Fan_Speed = 75;
    } else if (pm25 >20) {
      Fan_Speed = 50;
    } else if (pm25 >12) {
      Fan_Speed = 25;
    } else {
      Fan_Speed = 10;
    }
  }
 display.clearDisplay();

 display.setTextSize(1);
 display.setTextColor(SSD1306_WHITE);
 
  if (screen == 0) {
  editmode = 0;
  display.setCursor(32, 0);
  display.println("Air Filter");
  
  display.setCursor(0, 20);
  display.print("Fan Mode: ");
  if (Fan_Mode == 0) {
  display.println("Manual");
  } else {
  display.println("Auto");}

  display.setCursor(0, 40);
  display.print("Fan: ");
  display.println(Fan_Speed);
  display.println("%");
  display.setCursor(32, 50);
    if (pm25 >55) {
      display.println("Status: Unhealthy");
    } else if (pm25 >35) {
      display.println("Status: Bad");
    } else if (pm25 >20) {
      display.println("Status: Moderate");
    } else if (pm25 >12) {
      display.println("Status: Good");
}
     else {
      display.println("Status: Excellent");
    }
  }

  if (screen == 1) {
  if (digitalRead(Select_Button) == LOW) {
   
      editmode++;
      if (editmode > 2) {
         editmode = 0; 
      }
      delay(200);
  }
   if (editmode == 1) {
      if (digitalRead(Left_Button) == LOW) {
      Fan_Speed -= 10;
      if (Fan_Speed < 0) {
        Fan_Speed = 0;
      }
      delay(200);
    } 
      if (digitalRead(Right_Button) == LOW) {
        Fan_Speed += 10;
        if (Fan_Speed > 100) {
          Fan_Speed = 100;
        }
        delay(200);
      }  
}
 if (editmode == 2) {
      if (digitalRead(Left_Button) == LOW) {
      Fan_Mode = 0;
      if (Fan_Mode < 0) {
        Fan_Mode = 0;
      }
      delay(200);
    } 
      if (digitalRead(Right_Button) == LOW) {
        Fan_Mode = 1;
        if (Fan_Mode > 1) {
          Fan_Mode = 1;
        }
        delay(200);
      } 
    }
if (editmode == 0) {
  if (digitalRead(Left_Button) == LOW) {
    screen--;
    if (screen < 0) {
      screen = 2;
    }
    delay(200);
  }

  if (digitalRead(Right_Button) == LOW) {
    screen++;
    if (screen > 2) {
      screen = 0;
    }
    delay(200);
  }
}
}
else {
  if (digitalRead(Left_Button) == LOW) {
    screen--;
    if (screen < 0) {
      screen = 2;
    }
    delay(200);
  }
    if (digitalRead(Right_Button) == LOW) {
    screen++;
    if (screen > 2) {
      screen = 0;
    }
    delay(200);
  }
  }

  
if (screen == 1) {
  display.setCursor(32, 0);
  display.println("Fan Control ");
  display.setCursor(0, 20);
  display.print("Fan: ");
  display.print(Fan_Speed);
  display.println("%");

  display.setCursor(0, 40);
  display.print("Mode:");
  if (Fan_Mode == 0) {
    display.println("Manual");
  } else {
    display.println("Auto");
  }
  
  display.setCursor(40, 55);
  if (editmode == 0) {
    display.println("SELECT");
  } else if (editmode == 1) {
    display.println("Fan speed");
  } else {
    display.setCursor(32, 55);
    display.println("Manual/Auto");
  }
}
if (screen == 2) {
    
  editmode = 0;
  display.setCursor(32, 0);
  display.println("Air Quality ");

  display.setCursor(0, 20);
  display.print("Pm2.5: ");
  display.println(pm25);

  display.setCursor(0, 40);
  display.print("Pm10: ");
  display.println(pm10);

  display.setCursor(40, 55);
  if (Fan_Mode == 1) {
    if (pm25 >55) {
      display.println("Status: Unhealthy");
    } else if (pm25 >35) {
      display.println("Status: Bad");
    } else if (pm25 >20) {
      display.println("Status: Moderate");
    } else if (pm25 >12) {
      display.println("Status: Good");
}
    } else {
      display.println("Status: Excellent");
    }
  }
  display.display();
}
  




 
