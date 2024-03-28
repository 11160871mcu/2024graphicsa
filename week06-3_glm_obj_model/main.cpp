#include <GL/glut.h> ///��18��d�U�ӡA�ϥ�GLUT�~��
#include "glm.h"
GLMmodel* pmodel = NULL;
void
drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/Al.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    drawmodel();
    glutSwapBuffers();
}
int main(int argc, char *argv[])///��138��Amain()�禡
{
    glutInit(&argc, argv);///��140��A�}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///143��A�]�w��ܼҦ�
    glutCreateWindow("week06-3_glm_obj_model");///145��A�}�@��GLUT����
    glutDisplayFunc(display);///148��A�n��()�禡�ӵe��

    glutMainLoop();///174��A�D�n���j��A�b�o�̤@���B�@������
}
