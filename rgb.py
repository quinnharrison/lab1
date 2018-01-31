#!/usr/bin/python

import serial
import pygame, sys
from pygame.locals import*


s = serial.Serial("/dev/ttyACM0")	#serial port that we read from
def main():   # starts main function, don't use naked code!

  pygame.init()
  FPS = 30  #set FPS to 30
  fpsClock = pygame.time.Clock()
  DISPLAYSURF = pygame.display.set_mode((400, 300))
  #also possible to use pygame.Rect to create a rectangle
  while True:
    

    l = s.readline()			#l reads from arduino code imported from serial (s.)
    x = l.rstrip().split(",")		#splits values separated by commas
    try:				#tells loop to try condition
      rgb = [int(val) for val in x]	#passes in rgb values 

      #help received from 1/C Davidson
      screen.fill(rgb)			#screen fill turns the screen a color rgb
      #pygame.display.flip()		#updates to new screen	  
    
  #while True:    
    for event in pygame.event.get():	#records "events" in pygame (keyboard, clicks, etc)
      if event.type == QUIT:		#If event is close the window, quit the game	
        pygame.quit()
        sys.exit()
    pygame.display.update()		#update screen with new values
    fpsClock.tick(FPS)
