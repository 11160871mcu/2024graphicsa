#include <GL/glut.h> ///��18��d�U�ӡA�ϥ�GLUT�~��
#include <stdio.h>
float teapotX=0,teapotY=0;
void mouse(int button,int state,int x,int y)
{
    teapotX=(x-150)/150.0;
    teapotY=-(y-150)/150.0;
}
void display()
{///���d�Ҫ���46��glClear()�B49��B54��
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX,teapotY,0);///�ۤv�g
        glutSolidTeapot(0.3);
    glPopMatrix();///��54��
    glutSwapBuffers();
}
int main(int argc, char *argv[])///��138��Amain()�禡
{
    glutInit(&argc, argv);///��140��A�}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///143��A�]�w��ܼҦ�
    glutCreateWindow("week03_mouse");///145��A�}�@��GLUT����
    glutDisplayFunc(display);///148��A�n��()�禡�ӵe��
    glutMouseFunc(mouse);

    glutMainLoop();///174��A�D�n���j��A�b�o�̤@���B�@������
}
