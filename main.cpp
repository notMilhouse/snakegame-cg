/*
g++ *.cpp -o vai -lglut -lGL -lGLEW -lGLU
*/
#include "display.hpp"
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "snake.cpp"

void KeyboardManage(unsigned char key, int x, int y);
void Timer(int value);
void DrawManage();
void Margem(int windowX, int windowY);

Snake* snake;

int main(int argc, char**argv)
{
    //Cria um janela na tela
    //---
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(430, 130);
    glutCreateWindow("snake_game");
    //---

    //Passa infos do buffer do teclado para KeyboardManage
    glutKeyboardFunc(KeyboardManage);

    //Frame 
    glutTimerFunc(60, Timer, 1);

    glutDisplayFunc(DrawManage);
    Initialize();
    glutMainLoop();

    return 0;
}

void DrawManage()
{
    //snake->draw();
    chess();
}

void KeyboardManage(unsigned char key, int x, int y)
{
    switch (key) {
        case 'w':
        case 'W':
            snake->changeDirection(DirectionState::UP);
            break;

        case 's':
        case 'S':
            snake->changeDirection(DirectionState::DOWN);
            break;
        
        case 'a':
        case 'A':
            snake->changeDirection(DirectionState::LEFT);
            break;
        
        case 'd':
        case 'D':
            snake->changeDirection(DirectionState::RIGHT);
            break;
    }
}

void Timer(int value)
{
    
}