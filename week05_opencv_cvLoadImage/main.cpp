#include <GL/glut.h> ///��18��d�U�ӡA�ϥ�GLUT�~��
#include <opencv/highgui.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BITS);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char *argv[])///��138��Amain()�禡
{
    IplImage * img = cvLoadImage("c:/image.jpg");
    cvShowImage("week05",img);
    glutInit(&argc, argv);///��140��A�}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///143��A�]�w��ܼҦ�
    glutCreateWindow("week05");///145��A�}�@��GLUT����
    glutDisplayFunc(display);///148��A�n��()�禡�ӵe��

    glutMainLoop();///174��A�D�n���j��A�b�o�̤@���B�@������
}
