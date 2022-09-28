/*
g++ main.cpp -o vai -lglut -lGL -lGLEW -lGLU
*/

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "snake.cpp"
#include "display.cpp"

void KeyboardManage(unsigned char key, int x, int y);
void Timer(int value);
void Initialize();
void DrawManage();
void Margem(int windowX, int windowY);

Snake* snake;

int main(int argc, char**argv)
{
    //Cria um janela na tela
    //---
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(430, 130);
    glutCreateWindow("snake_game");
    //---

    //Passa infos do buffer do teclado para KeyboardManage
    //glutKeyboardFunc(KeyboardManage);

    //Frame 
    //glutTimerFunc(60, Timer, 1);

    glutDisplayFunc(DrawManage);
    Initialize();
    glutMainLoop();

    return 0;
}

void DrawManage()
{
    //snake->draw();
    Margem(500, 500);
}

void KeyboardManage(unsigned char key, int x, int y)
{
    switch (key) {
        case 'w':
        case 'W':
            snake->changeDirection(Direction());
            break;

        case 's':
        case 'S':
            snake->changeDirection(Direction());
            break;
        
        case 'a':
        case 'A':
            snake->changeDirection(Direction());
            break;
        
        case 'd':
        case 'D':
            snake->changeDirection(Direction());
            break;
    }
}

void Margem(int windowX, int windowY)
{
    glViewport(0, 0, windowX, windowY);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(0, 500);
    glVertex2i(500, 500);
    glVertex2i(0, 500);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(10, 10);
    glVertex2i(10, 490);
    glVertex2i(490, 490);
    glVertex2i(10, 490);
    glEnd();

    glFlush();
}