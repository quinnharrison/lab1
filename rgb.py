#!/usr/bin/python

import pygame, sys
from pygame.locals import*

def main():   # starts main function, don't use naked code!

  pygame.init()
  FPS = 30  #set FPS to 30
  fpsClock = pygame.time.Clock()
  DISPLAYSURF = pygame.display.set_mode((400, 300))
  #also possible to use pygame.Rect to create a rectangle
  while True:
    
  #find way to import color readings into variables r_led, etc.
    
    pygame.Color(r_led,g_led,b_led)	 #how colors are used in pygame
    
    
    for event in pygame.event.get():
      if event.type == QUIT:
        pygame.quit()
        sys.exit()
    pygame.display.update()
    fpsClock.tick(FPS)
