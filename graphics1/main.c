//
//  main.c
//  graphics1
//
//  Created by Ihor Krush on 9/26/15.
//  Copyright © 2015 Ihor Krush. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 500
#define WINDOW_LEFT 100
#define WINDOW_TOP 100

#define PI 3.14159265

double xStart = 200.0, yStart = 200.0;

void renderScreen();
void handleKeyboard(int key, int x, int y);

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(WINDOW_LEFT, WINDOW_TOP);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE | GLUT_MULTISAMPLE);
    
    glutCreateWindow("Lesson 1");
    
    glutDisplayFunc(renderScreen);
    glutSpecialFunc(handleKeyboard);
    glutIdleFunc(renderScreen);
    
    glutMainLoop();
    
    return 0;
}

void renderScreen(int width, int height)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    double radius = 20.0;
    double angel = 18;
    double lineWidth = 100.0;
    
    glBegin(GL_POLYGON);
        glVertex2d(xStart - radius / 2.0, yStart - radius);
        glVertex2d(xStart - radius, yStart - radius / 2.0);
        glVertex2d(xStart - radius, yStart + radius / 2.0);
        glVertex2d(xStart - radius / 2.0, yStart + radius);
    
        glVertex2d(xStart + radius / 2.0, yStart + radius);
        glVertex2d(xStart + radius, yStart + radius / 2.0);
        glVertex2d(xStart + radius, yStart - radius / 2.0);
        glVertex2d(xStart + radius / 2.0, yStart - radius);
    glEnd();
    
    glBegin(GL_LINES);
        glVertex2d(xStart + radius / 2.0, yStart - radius);
        glVertex2d(xStart + radius / 2.0 + lineWidth, yStart - radius - lineWidth * sin(angel * PI / 180));
    glEnd();
    
    glBegin(GL_LINES);
        glVertex2d(xStart + radius, yStart - radius / 2.0);
        glVertex2d(xStart + radius + lineWidth, yStart - radius / 2.0 - lineWidth * sin((angel - 15) * PI / 180));
    glEnd();
    
    glBegin(GL_LINES);
        glVertex2d(xStart + radius, yStart + radius / 2.0);
        glVertex2d(xStart + radius + lineWidth, yStart + radius / 2.0 + lineWidth * sin((angel - 15) * PI / 180));
    glEnd();
    
    glBegin(GL_LINES);
        glVertex2d(xStart + radius / 2.0, yStart + radius);
        glVertex2d(xStart + radius / 2.0 + lineWidth, yStart + radius + lineWidth * sin(angel * PI / 180));
    glEnd();
    
    glutSwapBuffers();
}

void handleKeyboard(int key, int x, int y)
{
    if(key == GLUT_KEY_UP) {
        xStart += 20.0;
        yStart -= 20.0;
    } else if (key == GLUT_KEY_DOWN) {
        xStart -= 20.0;
        yStart += 20.0;
    }
    
    printf("%lf %lf \n", xStart, yStart);
}
