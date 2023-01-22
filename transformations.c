#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

GLfloat R, px, py;
#define maxWD 640
#define maxHT 480

void Draw()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(+0.0f, +0.4f);
    glColor3f(0, 1, 0);
    glVertex2f(-0.3f, -0.4f);
    glColor3f(0, 0, 1);
    glVertex2f(+0.3f, -0.4f);
    glEnd();
    glFlush();
}

void rotationTransform(float graus)
{
   glClear(GL_COLOR_BUFFER_BIT);
   Draw();

    glRotatef(graus, 0, 0, 1);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(+0.0f, +0.4f);
    glColor3f(0, 1, 0);
    glVertex2f(-0.3f, -0.4f);
    glColor3f(0, 0, 1);
    glVertex2f(+0.3f, -0.4f);
    glEnd();
    glLoadIdentity();
    
    glFlush();
}
void translateTransform(float codx, float cody)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
    Draw();

    glTranslatef(codx, cody, 0);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(+0.0f, +0.4f);
    glColor3f(0, 1, 0);
    glVertex2f(-0.3f, -0.4f);
    glColor3f(0, 0, 1);
    glVertex2f(+0.3f, -0.4f);
    glEnd();
    glLoadIdentity();

    glFlush();
}
void scalingTransform(float x, float y, float z)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
    Draw();

    glScaled(x, y, z);

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(+0.0f, +0.4f);
    glColor3f(0, 1, 0);
    glVertex2f(-0.3f, -0.4f);
    glColor3f(0, 0, 1);
    glVertex2f(+0.3f, -0.4f);
    glEnd();
    glLoadIdentity();

    glFlush();
}

void displayTransformation(void)
{
    int i = 1;
    Draw();
    while (i)
    {
        int tipo;
        printf("Tipo de Transformação:\n");
        printf("1: Rotation\n");
        printf("2: Translate\n");
        printf("3: Scaling\n");
        printf(": ");
        scanf("%d", &tipo);
        switch (tipo)
        {
            float x, y, z;
        case 1:
            printf("Entre com Grau de rotação: ");
            scanf("%f", &R);
            rotationTransform(R);
            printf("\n");
            break;
        case 2:
            printf("Entre com Cordenadas para a translação [0.0 0.0]: ");
            scanf("%f%f", &px, &py);
            translateTransform(px, py);
            printf("\n");
            break;
        case 3:
            printf("Entre com Cordenadas para a Scalonar [0.0 0.0 1]: ");
            scanf("%f%f%f", &x, &y, &z);
            scalingTransform(x, y, z);
            printf("\n");
            break;
        default:
            printf("Tranformação inválida.");
            break;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        printf("Nova transformação:\n");
        printf("1- Sim\n");
        printf("2- Não\n");
        scanf("%d", &i);
        if (i == 1)
        {
            glClear(GL_COLOR);
            continue;
        }
        else
        {
            exit(1);
            break;
        }
    }
}

int main(int argC, char *argV[])
{
    glutInit(&argC, argV);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 150);
    glutInitWindowSize(maxWD, maxHT);
    glutCreateWindow("Triangle Rotation");
    glutDisplayFunc(displayTransformation);
    Draw();
    glutMainLoop();
    return 0;
}
