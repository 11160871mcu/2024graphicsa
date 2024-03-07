#include <GL/glut.h> ///第18行留下來，使用GLUT外掛
#include <stdio.h>
float teapotX=0,teapotY=0;
float angle=0;
int method=1;
int oldX=0,oldY=0;

void mouse(int button,int state,int x,int y)
{
    oldX=x;///teapotX=(x-150)/150.0;
    oldY=y;///teapotY=-(y-150)/150.0;
}
void display()
{///偷範例的第46行glClear()、49行、54行
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX,teapotY,0);
        glRotatef(angle,0,0,1);///對z軸轉
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}

void motion(int x,int y)
{

    if(method==1){
        angle+=x-oldX;
    }else if(method==2){
        teapotX+=(x-oldX)/150.0;
        teapotY-=(y-oldY)/150.0;
    }
    oldX=x;
    oldY=y;
    display();
}

void keyboard(unsigned char key,int x,int y)
{
    if(key=='e')    method=1;///轉動
    if(key=='w')    method=2;///移動
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03_mouse rotate");///145行，開一個GLUT視窗
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);///motion的細節
    glutKeyboardFunc(keyboard);///按鍵

    glutMainLoop();
}
