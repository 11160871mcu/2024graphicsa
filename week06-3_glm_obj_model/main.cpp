#include <GL/glut.h> ///第18行留下來，使用GLUT外掛
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
int main(int argc, char *argv[])///第138行，main()函式
{
    glutInit(&argc, argv);///第140行，開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///143行，設定顯示模式
    glutCreateWindow("week06-3_glm_obj_model");///145行，開一個GLUT視窗
    glutDisplayFunc(display);///148行，要用()函式來畫圖

    glutMainLoop();///174行，主要的迴圈，在這裡一直運作不結束
}
