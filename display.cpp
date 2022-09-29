#include "display.hpp"
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>

int squareSide;
int displaySide;

void displayInitialize()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 500.0, 500.0, 0.0);
    
    displaySide = (WINDOW_HEIGHT > WINDOW_WIDTH) ? WINDOW_WIDTH : WINDOW_HEIGHT;

    if(displaySide % NUM_ATOM != 0)
    {
        displaySide -= displaySide % NUM_ATOM;
    }

    squareSide = displaySide/NUM_ATOM;
}

void drawSquare(int x, int y)
{
    glViewport(0, 0, displaySide, displaySide);

    glBegin(GL_POLYGON);
    glVertex2i(x*squareSide             , y*squareSide);
    glVertex2i(x*squareSide             , squareSide + y*squareSide);
    glVertex2i(squareSide + x*squareSide, squareSide + y*squareSide);
    glVertex2i(squareSide + x*squareSide, y*squareSide);
    glEnd();
    
    glFlush();
    //glutPostRedisplay();            
}

void chess()
{
    int count = 0;
    for(int i = 0; i < NUM_ATOM; i++)
    {
        for(int j = 0; j < NUM_ATOM; j++)
        {
            if (count % 2 == 0) {
                glColor3f(0.2, 0.2, 0.2);
                drawSquare(i, j);                
            }
            else{
                glColor3f(1.0, 1.0, 1.0);
                drawSquare(i, j);
            }
            count++;
        }
        count++;
    }
}