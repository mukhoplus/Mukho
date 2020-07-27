import pygame
import sys

SCREEN_WIDTH = 640
SCREEN_HEIGHT = 480

white = (255, 255, 255)
black = (0, 0, 0)

pygame.init()
pygame.display.set_caption("Simple PyGame Example")
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

pos_x = 200
pos_y = 200

clock = pygame.time.Clock()

while True:
    clock.tick(60)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

    key_event = pygame.key.get_pressed()
    if key_event[pygame.K_LEFT]:
        if pos_x > -1 :
            pos_x -= 1
    if key_event[pygame.K_RIGHT]:
        if pos_x < 641:
            pos_x += 1
    if key_event[pygame.K_UP]:
        if pos_y > -1:
            pos_y -= 1
    if key_event[pygame.K_DOWN]:
        if pos_y < 481:
            pos_y += 1

    screen.fill(black)
    pygame.draw.circle(screen, white, (pos_x, pos_y), 20)
    pygame.display.update()
