#include <GL/glut.h> ///第18行留下來，使用GLUT外掛
#include <stdio.h>
float teapotX=0,teapotY=0;
void mouse(int button,int state,int x,int y)
{
    teapotX=(x-150)/150.0;
    teapotY=-(y-150)/150.0;
}
void display()
{///偷範例的第46行glClear()、49行、54行
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX,teapotY,0);///自己寫
        glutSolidTeapot(0.3);
    glPopMatrix();///第54行
    glutSwapBuffers();
}
int main(int argc, char *argv[])///第138行，main()函式
{
    glutInit(&argc, argv);///第140行，開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///143行，設定顯示模式
    glutCreateWindow("week03_mouse");///145行，開一個GLUT視窗
    glutDisplayFunc(display);///148行，要用()函式來畫圖
    glutMouseFunc(mouse);

    glutMainLoop();///174行，主要的迴圈，在這裡一直運作不結束
}
