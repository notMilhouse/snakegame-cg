#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

int squareSide;
int displaySide;
int numAtom = 20;

void Initialize()
{
    displaySide = (WINDOW_HEIGHT > WINDOW_WIDTH) ? WINDOW_WIDTH : WINDOW_HEIGHT;

    if(displaySide % numAtom != 0)
    {
        displaySide -= displaySide % numAtom;
    }

    squareSide = displaySide/numAtom;

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glLineWidth(3.0);
    gluOrtho2D(0.0, 500.0, 500.0, 0.0);
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
}