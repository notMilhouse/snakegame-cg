#include <GL/freeglut_std.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 600

void KeyboardManage(unsigned char key, int x, int y);
void Timer(int value);
void Initialize();
void Draw();

int main(int argc, char**argv)
{
    //Cria um janela na tela
    //---
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(430, 130);
    glutCreateWindow("snake-game");
    //---

    //Passa infos do buffer do teclado para KeyboardManage
    glutKeyboardFunc(KeyboardManage);

    //Frame 
    glutTimerFunc(60, Timer, 1);

    glutDisplayFunc(Draw);
    Initialize();
    glutMainLoop();

    return 0;
}

void Inicialize()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glLineWidth(3.0);
    gluOrtho2D(0.0, 500.0, 500.0, 0.0);
}