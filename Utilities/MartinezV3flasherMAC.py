#!/usr/bin/python
# -*- coding: utf-8 -*-


import serial
import time
import sys
import os



if len(sys.argv) == 3:
		avrdude_parameter1 = "-c stk500v2 -p m8 -v -v -P "+sys.argv[1]
		avrdude_parameter2 = " -e -U "+sys.argv[2]
		avrdude_command = "avrdude "+avrdude_parameter1+avrdude_parameter2
		os.system('cls')
		print
		print"***************************************************"
		print"*                                                 *"
		print"*                                                 *"
		print"*               Martinez V3 Flasher               *"
		print"*                                                 *"
		print"*              IM Coref und Martinez              *"
		print"*                                                 *"
		print"*                                                 *"
		print"***************************************************"
		print
		print	
		
		for x in range(2, 6):
                      
						#os.system('cls')
						print"Setting ArduinoUSBLinker to Pin PD%d" % (x)
						ser = serial.Serial(sys.argv[1],19200)
						pinChange = 16+x
						#print pinChange
						ser.write('$M<P')+pinChange
						ser.write('$M<W')
						ser.close()
						time.sleep(2)
						print "Flashing MCU%d" % (x-1)
						print avrdude_command
						#os.system (avrdude_command)
						print
						time.sleep(5)
						
                os.system('cls')
                print" MartinezV3 ist jetzt betriebsbereit!"
		
		
		
		#print sys.argv[1],sys.argv[2]
		
else:
                print
		print "Usage : "
		print "          Please specify a port and file " 
		print "          e.g.:"
		print
		print "          %s /dev/ttyUSB0 martinez.hex" % sys.argv[0]
