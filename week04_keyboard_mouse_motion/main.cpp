#include <GL/glut.h> ///第18行留下來，使用GLUT外掛
#include <stdio.h>
float angle=0,oldX=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    oldX=x;///當mouse按下時，記錄他的位置
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    display();
}
void keyboard(unsigned char key,int x,int y)
{
    printf("key:%c x:%d y:%d\n",key,x,y);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 keyboard mouse motion");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///這一行
    glutMouseFunc(mouse);///再加這一行
    glutMotionFunc(motion);///再加這一行

    glutMainLoop();
}
