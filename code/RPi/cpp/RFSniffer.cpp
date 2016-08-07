/*
  RFSniffer

  Usage: ./RFSniffer [<pulseLength>]
  [] = optional

  Hacked from http://code.google.com/p/rc-switch/
  by @justy to provide a handy RF code sniffer
*/

#include "../rc-switch/RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <iostream>

RCSwitch mySwitch;

std::fstream outfile;

std::time_t current_time = std::time(NULL);
std::time_t prev_time = std::time(NULL);


int main(int argc, char *argv[]) {
  
     // This pin is not the first pin on the RPi GPIO header!
     // Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     // for more information.
     int PIN = 2;
     outfile.open("/home/pi/data.csv", std::ios_base::app);
     if(wiringPiSetup() == -1) {
       printf("wiringPiSetup failed, exiting...");
       return 0;
     }

     int pulseLength = 0;
     if (argv[1] != NULL) pulseLength = atoi(argv[1]);

     mySwitch = RCSwitch();
     if (pulseLength != 0) mySwitch.setPulseLength(pulseLength);
     mySwitch.enableReceive(PIN);  // Receiver on interrupt 0 => that is pin #2
    
     prev_time=time(NULL);
     current_time=time(NULL);

     while(1) {
      if (mySwitch.available()) {
    
        int value = mySwitch.getReceivedValue();
    
        if (value == 0) {
          printf("Unknown encoding\n");
        		} 
	else {    
   	  current_time=std::time(NULL);
	  if (current_time>prev_time+1)
	  	outfile<<current_time<<','<<value<<std::endl;
        prev_time=current_time;
	
	std::cout<<value<<std::endl;    
        mySwitch.resetAvailable();
    
      	    }
      
  
  	      }
		}
  outfile.close();
  exit(0);


}

