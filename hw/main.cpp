///先把 week08-1_glm_gundam 的程式貼上來
///等一下, 要再加貼圖的 18行程式
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"

GLMmodel *pmodel = NULL;
GLMmodel *body = NULL;
GLMmodel *right_shoulder = NULL;
GLMmodel *right_forearm = NULL;
GLMmodel *left_shoulder = NULL;
GLMmodel *left_forearm = NULL;
GLMmodel *head = NULL;

void drawBody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_MATERIAL);


}
void drawRightShoulder(void)///右邊肩膀
{
    {
        if (!right_shoulder) {
        right_shoulder = glmReadOBJ("data/right_shoulder.obj");
        if (!right_shoulder) exit(0);
        glmUnitize(right_shoulder);
        glmFacetNormals(right_shoulder);
        glmVertexNormals(right_shoulder, 90.0);
        }

        glmDraw(right_shoulder, GLM_SMOOTH | GLM_MATERIAL);
    }
}

void drawRightForearm(void)///右邊小臂
{
    {
        if (!right_forearm) {
        right_forearm = glmReadOBJ("data/right_forearm.obj");
        if (!right_forearm) exit(0);
        glmUnitize(right_forearm);
        glmFacetNormals(right_forearm);
        glmVertexNormals(right_forearm, 90.0);
        }

        glmDraw(right_forearm, GLM_SMOOTH | GLM_MATERIAL);
    }
}

void drawLeftShoulder(void)///右邊肩膀
{
    {
        if (!left_shoulder) {
        left_shoulder = glmReadOBJ("data/left_shoulder.obj");
        if (!left_shoulder) exit(0);
        glmUnitize(left_shoulder);
        glmFacetNormals(left_shoulder);
        glmVertexNormals(left_shoulder, 90.0);
        }

        glmDraw(left_shoulder, GLM_SMOOTH | GLM_MATERIAL);
    }
}

void drawLeftForearm(void)///右邊小臂
{
    {
        if (!left_forearm) {
        left_forearm = glmReadOBJ("data/left_forearm.obj");
        if (!left_forearm) exit(0);
        glmUnitize(left_forearm);
        glmFacetNormals(left_forearm);
        glmVertexNormals(left_forearm, 90.0);
        }

        glmDraw(left_forearm, GLM_SMOOTH | GLM_MATERIAL);
    }
}

void drawHead(void)///右邊小臂
{
    {
        if (!head) {
        head = glmReadOBJ("data/head.obj");
        if (!head) exit(0);
        glmUnitize(head);
        glmFacetNormals(head);
        glmVertexNormals(head, 90.0);
        }

        glmDraw(head, GLM_SMOOTH | GLM_MATERIAL);
    }
}

void myBody(){///我的身體
    glPushMatrix();
        glColor3f(1,0,0);
        glutSolidCube(0.6);

    glPopMatrix();
}

///float angle = 0, da=1; ///剛剛的舊程式碼
float angle[20]={};///20個角度都改成0
int angleID=0;///可以是角度0、角度1、角度2
int oldX=0,oldY=0;
#include <stdio.h>
FILE * fin =NULL;
FILE * fout =NULL;
void motion(int x,int y){///加入mouse motion對應函式
    angle[angleID]+=y-oldY;
    oldX=x;
    oldY=y;
    glutPostRedisplay();
    if(fout==NULL)    fout=fopen("angle.txt","w+");
    for(int i=0;i<20;i++){
        printf("%.1f ",angle[i]);
        fprintf(fout,"%.1f",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
void mouse(int button,int state,int x,int y){
    oldX=x;
    oldY=y;
}

void keyboard(unsigned char key ,int x,int y){
    if(key=='r'){
        if(fout==NULL)    fout=fopen("angle.txt","r");
        for(int i=0;i<20;i++){
        fscanf(fin,"%f",angle[i]);
        }
    glutPostRedisplay();
    }
    if(key=='0')    angleID=0;
    if(key=='1')    angleID=1;
    if(key=='2')    angleID=2;
    if(key=='3')    angleID=3;
    if(key=='4')    angleID=4;
    if(key=='5')    angleID=5;
    if(key=='6')    angleID=6;
    if(key=='7')    angleID=7;
    if(key=='8')    angleID=8;
    if(key=='9')    angleID=9;
}///記得在int main()裡面加glutKeyBoardFunc(keyboard)

void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glRotatef(angle[0],0,1,0);
        glScalef(0.6,0.6,0.6);
        drawBody();

        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1);

        glPushMatrix();///右邊
            glTranslatef(-0.38,0.83,0);///位置
            glRotatef(angle[1],0,1,0);
            glRotatef(angle[2],1,0,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(-0.1,-0.05,0);///旋轉軸
            glScalef(1.3,1.3,1.3);///放大
            drawRightShoulder();///肩膀
            glPushMatrix();
                glTranslatef(-0.2,-0.15,0);///位置
                glRotatef(angle[4],1,0,0);
                glTranslatef(0.1,-0.2,0);///旋轉軸
                drawRightForearm();///小臂
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.38,0.83,0);///位置
            glRotatef(angle[5],0,1,0);
            glRotatef(angle[6],1,0,0);
            glRotatef(angle[7],0,0,1);
            glTranslatef(0.1,-0.05,0);///旋轉軸
            glScalef(1.3,1.3,1.3);///放大
            drawLeftShoulder();///肩膀
            glPushMatrix();
                glTranslatef(0,-0.15,0);///位置
                glRotatef(angle[8],1,0,0);
                glTranslatef(0.1,-0.2,0);///旋轉軸
                drawLeftForearm();///小臂
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0,0.925,-0.1);
            glRotatef(angle[9],1,0,0);
            glTranslatef(0,0.2,0);
            glScalef(1.8,1.8,1.8);///放大
            drawHead();
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("hw");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutMouseFunc(mouse);///大象放到冰箱
    glutMotionFunc(motion);///滑鼠控制
    glutKeyboardFunc(keyboard);///week13-1新加的

    //myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
