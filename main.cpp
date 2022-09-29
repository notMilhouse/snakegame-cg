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
void Initialize();
void gameInitialize();

GameObject apple;

Snake* snake = new Snake(
                    GamePos(NUM_ATOM/2+1, NUM_ATOM/2), 
                    Direction()
                    );
/*
GameMap* gamemap = new GameMap(NUM_ATOM, NUM_ATOM);
*/
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
    //glutTimerFunc(180, Timer, 1);

    glutDisplayFunc(DrawManage);
    Initialize();
    glutMainLoop();

    return 0;
}

void Initialize()
{
    displayInitialize();
    //gameInitialize();
    //gamemap->addObject(&apple);
}

void DrawManage()
{
    chess();
    glColor3f(0.0, 1.0, 0.0); snake->draw(drawSquare);
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); apple.draw(drawSquare);
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

    glutPostRedisplay();
}

void Timer(int value)
{
    /*
    GamePos nextPos = snake->getPosition(); 
    Direction direction = snake->getDirection();
    
    nextPos = *nextPos
                 .incrementX(direction.getDirX())
                ->incrementY(direction.getDirY());

    //colisão
    if(gamemap->detectObject(nextPos.getX(), nextPos.getY()))
    {
        
    }
    */
    snake->move();
    glutPostRedisplay();
    glutTimerFunc(180, Timer, value+1);
}
/*
void gameInitialize()
{
    gamemap = new GameMap(NUM_ATOM, NUM_ATOM);
    snake = new Snake(
                    GamePos(NUM_ATOM/2, NUM_ATOM/2), 
                    Direction()
                    );
    
    gamemap->addObject(&apple);
}
*/