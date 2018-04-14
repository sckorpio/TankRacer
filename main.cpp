#include<gl/glut.h>
#include<iostream>//for strlen
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>

int i,Q;
int score = 0;//for score counting
int screen = 0;
bool collide = false;//check if car collide to make game over
char buffer[10];

int vehicleX = 250, vehicleY = 70;
int ovehicleX[5]={250,350,450,350,250};
int ovehicleY[5]={700,860,1020,1180,1340};
int ovehicleS[5]={0,0,0,0,0};
int ovehicleL[5]={1,1,1,1,1};


int BS[5]={0,0,0,0,0};   int k;
int Bx[5]={0,0,0,0,0};
int By[5]={0,0,0,0,0};

int divx = 250, divy = 4, movd;
int lane=0;

int rate=8;
int irate=8;

void drawText(char ch[],int xpos, int ypos)//draw the text for score and game over
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <= numofchar - 1; i++)
    {

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);//font used here, may use other font also
    }
}


void drawTextNum(char ch[],int numtext,int xpos, int ypos)//counting the score
{
    int len;
    int k;
    k = 0;
    len = numtext - strlen (ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <=numtext - 1; i++)
    {
    if ( i < len )
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
        k++;
    }

    }
}


/*  void ovipos()
{
    glClearColor(0,1,0,0);   int W;
for(i = 0; i < 6; i++)
{
    W=rand();
    W=W%4;
    printf("random--%d\n",W);

    switch(W)
     {

         case 0:  ovehicleX[i] = 250;  break;
         case 1:  ovehicleX[i] = 350;  break;
         case 2:  ovehicleX[i] = 450;  break;
         case 3:  ovehicleX[i] = 550;  break;
    }

    ovehicleY[i] = 600 + i * 160;
  }
}  */


void drawRoad()
{
    glBegin(GL_QUADS);
        glColor3f(0.5,0.5,0.5);
        glVertex2f(200,0);
        glVertex2f(200,700);
        glVertex2f(600,700);
        glVertex2f(600, 0);
    glEnd();
}


void drawDivider()//black patch drawn in middle of road
{
    glLoadIdentity();
    glTranslatef(0, movd, 0);
    for(i = 1; i <= 12; i++)
    {
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(300  - 5, divy * 15 * i + 18);
        glVertex2f(300  - 5, divy * 15 * i - 18);
        glVertex2f(300  + 5, divy * 15 * i - 18);
        glVertex2f(300  + 5, divy * 15 * i + 18);
    glEnd();


    glBegin(GL_QUADS);
        glVertex2f(400  - 5, divy * 15 * i + 18);
        glVertex2f(400  - 5, divy * 15 * i - 18);
        glVertex2f(400  + 5, divy * 15 * i - 18);
        glVertex2f(400  + 5, divy * 15 * i + 18);
    glEnd();

     glBegin(GL_QUADS);
        glVertex2f(500  - 5, divy * 15 * i + 18);
        glVertex2f(500  - 5, divy * 15 * i - 18);
        glVertex2f(500  + 5, divy * 15 * i - 18);
        glVertex2f(500  + 5, divy * 15 * i + 18);
    glEnd();
    }
    glLoadIdentity();
}


void drawTANK()//car for racing
{
    /*glPointSize(10.0);
    glBegin(GL_POINTS);//CHAINS L
        glColor3f(0,0,0);
        glVertex2f(vehicleX - 15, vehicleY + 20);
        glVertex2f(vehicleX - 5, vehicleY + 20);
        glVertex2f(vehicleX - 5, vehicleY - 20);
        glVertex2f(vehicleX - 15, vehicleY - 20);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1,0,0);//middle body
        glVertex2f(vehicleX - 25, vehicleY + 20);
        glVertex2f(vehicleX - 25, vehicleY - 20);
        glVertex2f(vehicleX + 25, vehicleY - 20);
        glVertex2f(vehicleX + 25, vehicleY + 20);
    glEnd();

    glBegin(GL_QUADS);//up body
        glColor3f(0,0,1);
        glVertex2f(vehicleX - 23, vehicleY + 20);
        glVertex2f(vehicleX - 19, vehicleY + 40);
        glVertex2f(vehicleX + 19, vehicleY + 40);
        glVertex2f(vehicleX + 23, vehicleY + 20);
    glEnd();

    glBegin(GL_QUADS);//down body
        glColor3f(0,0,1);
        glVertex2f(vehicleX - 23, vehicleY - 20);
        glVertex2f(vehicleX - 19, vehicleY - 35);
        glVertex2f(vehicleX + 19, vehicleY - 35);
        glVertex2f(vehicleX + 23, vehicleY - 20);
    glEnd();
    */




    glBegin(GL_POLYGON);//CHAINS L
        glColor3f(1.000, 0.843, 0.000);
        glVertex2f(vehicleX - 30, vehicleY + 40);
        glVertex2f(vehicleX - 5, vehicleY + 40);
        glVertex2f(vehicleX - 5, vehicleY - 40);
        glVertex2f(vehicleX - 30, vehicleY - 40);
    glEnd();

     glBegin(GL_POLYGON);//CHAINS L
        glColor3f(1.000, 0.843, 0.000);
        glVertex2f(vehicleX + 5, vehicleY + 40);
        glVertex2f(vehicleX + 30, vehicleY + 40);
        glVertex2f(vehicleX + 30, vehicleY - 40);
        glVertex2f(vehicleX + 5, vehicleY - 40);
    glEnd();


    glBegin(GL_POLYGON);//middle
        glColor3f(0.420, 0.557, 0.137);
        glVertex2f(vehicleX - 20, vehicleY +30);
        glVertex2f(vehicleX + 20, vehicleY +30);
        glVertex2f(vehicleX + 20, vehicleY - 30);
        glVertex2f(vehicleX - 20, vehicleY - 30);
    glEnd();


    glBegin(GL_POLYGON);//UPPER
        glColor3f(0.333, 0.420, 0.184);
        glVertex2f(vehicleX - 5, vehicleY +20);
        glVertex2f(vehicleX + 5, vehicleY +20);
        glVertex2f(vehicleX + 10, vehicleY +5);
        glVertex2f(vehicleX + 10, vehicleY -5);
        glVertex2f(vehicleX + 5, vehicleY -20);
        glVertex2f(vehicleX - 5, vehicleY -20);
        glVertex2f(vehicleX -10, vehicleY -5);
        glVertex2f(vehicleX - 10, vehicleY +5);
    glEnd();


    glBegin(GL_POLYGON);//NOZZLE
        glColor3f(0.333, 0.420, 0.184);
        glVertex2f(vehicleX - 4, vehicleY +0);
        glVertex2f(vehicleX - 4, vehicleY +60);
        glVertex2f(vehicleX +4, vehicleY +60);
        glVertex2f(vehicleX +4, vehicleY -0 );
    glEnd();

 }


 void drawBullets()
 {
     int i;   int diff;

     for(i=0;i<5;i++)
     {
         if(BS[i]==1)


{
    glColor3f(0.0,0.5,1.0);

    glBegin(GL_POLYGON);
    glVertex2f(Bx[i]-5,By[i]-10);
    glVertex2f(Bx[i]-5,By[i]+10);
    glVertex2f(Bx[i]+5,By[i]+10);
    glVertex2f(Bx[i]+5,By[i]-10);
    glEnd();

    glColor3f(1.0,0.0,0.0);

    glBegin(GL_POLYGON);
    glVertex2f(Bx[i]-5,By[i]+10);
    glVertex2f(Bx[i]+3,By[i]+20);
    glVertex2f(Bx[i]+5,By[i]+10);
    glEnd();


    glFlush();

    By[i]+=(rate+4);

    if((ovehicleS[i]==0)&&(ovehicleL[i]==1)&&(ovehicleX[i]==Bx[i]))
   {

    if((ovehicleY[i] > By[i] - 25 - 25 && ovehicleY[i] < By[i] + 25 + 25 ))
    {

        printf("HIT\n");       glutPostRedisplay();
         BS[i]=0;
        By[i]=0;   Bx[i]=0;

        ovehicleL[i]=0;

        score=score+100;

    }

   }
    if(By[i]>700)
    {
        BS[i]=0;
        By[i]=0;   Bx[i]=0;
    }
}

         }
     }



void drawOVehicle()//other cars
{
   int W,L,S;
    for(i = 0; i < 5; i++)
    {
       if((ovehicleS[i]==0)&&(ovehicleL[i]==1))
       {

    glPointSize(10.0);
    glBegin(GL_POINTS);//tire
        glColor3f(0,0,0);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] + 16);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] + 16);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] - 16);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] - 16);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.275, 0.510, 0.706);//middle body
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] + 20);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] - 20);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] - 20);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] + 20);
    glEnd();

    glBegin(GL_QUADS);//up body
        glColor3f(0.690, 0.769, 0.871);
        glVertex2f(ovehicleX[i] - 23, ovehicleY[i] + 20);
        glVertex2f(ovehicleX[i] - 19, ovehicleY[i] + 40);
        glVertex2f(ovehicleX[i] + 19, ovehicleY[i] + 40);
        glVertex2f(ovehicleX[i] + 23, ovehicleY[i] + 20);
    glEnd();

    glBegin(GL_QUADS);//down body
        glColor3f(0.690, 0.769, 0.871);
        glVertex2f(ovehicleX[i] - 23, ovehicleY[i] - 20);
        glVertex2f(ovehicleX[i] - 19, ovehicleY[i] - 35);
        glVertex2f(ovehicleX[i] + 19, ovehicleY[i] - 35);
        glVertex2f(ovehicleX[i] + 23, ovehicleY[i] - 20);
    glEnd();

       }


       else if((ovehicleS[i]==1))
       {
           glBegin(GL_QUADS);//ANTi TANK MINE
        glColor3f(1,0,0);
        glVertex2f(ovehicleX[i] - 15, ovehicleY[i] + 15);
        glVertex2f(ovehicleX[i] - 15, ovehicleY[i] - 15);
        glVertex2f(ovehicleX[i] + 15, ovehicleY[i] - 15);
        glVertex2f(ovehicleX[i] + 15, ovehicleY[i] + 15);
    glEnd();

       }

    ovehicleY[i] = ovehicleY[i] - rate;

    if((ovehicleY[i] > vehicleY - 25 - 25 && ovehicleY[i] < vehicleY + 25 + 25 && ovehicleX[i] == vehicleX)&&(ovehicleL[i]==1))
    {
        collide = true;     Beep(250,500);
    }

    if(ovehicleY[i] < -25)
    {
         W=rand();
    L=W%4;   S=W%5;
   // printf("random--%d  %d\n",W,S);

    switch(L)
     {

         case 0:  ovehicleX[i] = 250;  break;
         case 1:  ovehicleX[i] = 350;  break;
         case 2:  ovehicleX[i] = 450;  break;
         case 3:  ovehicleX[i] = 550;  break;
    }

    if(S==1||S==4)
    ovehicleS[i]=1;

    else
        ovehicleS[i]=0;


        ovehicleY[i] = 700;    ovehicleL[i]=1;
    }
  }
}

void Specialkey(int key, int x, int y)//allow to use navigation key for movement of car
{
switch(key)
{
/*case GLUT_KEY_UP:
	for(i = 0; i <4; i++)
             {
              ovehicleY[i] = ovehicleY[i] - 10;
             }
             movd = movd - 20;
             break;
case GLUT_KEY_DOWN:
	for(i = 0; i <4; i++)
             {
              ovehicleY[i] = ovehicleY[i] + 10;
             }
             movd = movd + 20;
             break;
        */
        case GLUT_KEY_LEFT:{  if(lane>0)   lane--;  }
                                                     break;
        case GLUT_KEY_RIGHT:{  if(lane<3)   lane++;  }
                                                     break;


}


switch(lane)
{
    case 0:   vehicleX=250;   break;
    case 1:   vehicleX=350;   break;
     case 2:   vehicleX=450;   break;
    case 3:   vehicleX=550;   break;

}

glutPostRedisplay();
}

void Normalkey(unsigned char key, int x, int y)
{
    switch(key)
    {
    case '1':if(screen == 0||screen==3)
               {
                   screen=1;   score=0;  }
            break;

    case '2':if(screen == 1)
             screen=2;
             break;

    case ' ':{   if(screen==2)
                 {    //printf("\a");
                     BS[k]=1; Bx[k]=vehicleX;   By[k]=vehicleY;
                     k++;

                     if(k>4)
                      k=0;
                 }

               } break;

    case 27:  exit(0);  break;

    }
}




void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 800, 0, 700);
glMatrixMode(GL_MODELVIEW);
}


void display()
{
    if(screen == 0)
    {  glClearColor(0.000, 0.545, 0.545,0);
    glClear(GL_COLOR_BUFFER_BIT);

              int X=200;  int Y=400;   float p=0.883;  float q=0.111;                         int t;
    glColor3f(0.502, 0.502, 0.000);

    glBegin(GL_POLYGON);
    glVertex2f(180,400);
    glVertex2f(210,450);
    glVertex2f(510,450);
    glVertex2f(540,400);
    glEnd();

    glColor3f(0.420, 0.557, 0.137);
    glBegin(GL_POLYGON);
    glVertex2f(220,450);
    glVertex2f(240,490);
    glVertex2f(460,490);
    glVertex2f(480,450);
    glEnd();

     glColor3f(0.502, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(260,490);
    glVertex2f(270,530);
    glVertex2f(400,530);
    glVertex2f(440,490);
    glEnd();

    glColor3f(0.502, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(390,530);
    glVertex2f(500,590);
    glVertex2f(490,600);
    glVertex2f(350,530);
    glEnd();


float x1,y1,x2,y2;
float angle;
double radius=40;

x1=X;   y1=Y;

glColor3f(0,0,0);
    for(t=0;t<5;t++)
    {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x1,y1);

for (angle=1.0f;angle<361.0f;angle+=0.2)
{
    x2 = x1+sin(angle)*radius;
    y2 = y1+cos(angle)*radius;
    glVertex2f(x2,y2);
}

       glEnd();

       x1+=80;
    }

    glFlush();
    glutPostOverlayRedisplay();



    glColor3f(1.000, 1.000, 0.000);
    drawText("WELCOME", 170, 290);
    drawText("PLAYER", 170, 250);
    drawText("Press 1 to continue", 170, 150);

    glColor3f(1,0,0);
    drawText("CrazzY TANK !!!!!",150,550);
    glutSwapBuffers();
}
    else if(screen == 1)
    {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    drawText("#--Use SPACE to Shoot!!!!", 170, 290);
    drawText("#--Use LEFT ARROW to move left", 170, 250);
    drawText("#--Use RIGHT ARROW to move right", 170, 210);
    drawText("#--Press 2 to continue", 170, 150);
    glutSwapBuffers();
    }
    else if(screen==2)
    {
         glClearColor(0.196, 0.804, 0.196,0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawRoad();
    drawDivider();
    drawTANK();

    drawOVehicle();
    drawBullets();
    movd = movd - rate/2;
    if(movd < - 60)
    {
        movd = 0;
    }

    score = score + 1;
    glColor3f(0,0,1);
    drawText("Score:", 100,300);
    itoa (score, buffer, 10);
    glColor3f(0,0,1);
    drawTextNum(buffer, 6, 100,200);
    glutSwapBuffers();
    for(Q = 0; Q<= 10000000; Q++){;}
    if(collide == true)
    {

        Beep(200,1000);
        glColor3f(1,0,0);
        drawText("Game Over", 100,250);
        glutSwapBuffers();


        // score = 0;//for score counting
    collide = false;//check if car collide to make game over


 vehicleX = 250, vehicleY = 70;
int i;
 for(i=0;i<5;i++)
 {
    BS[i]=Bx[i]=By[i]=0;
    ovehicleL[i]=1; ovehicleS[i]=0;
 }

 ovehicleX[0]=250;
 ovehicleX[1]=350;
 ovehicleX[2]=450;
 ovehicleX[3]=350;
 ovehicleX[4]=250;

 ovehicleY[0]=650;
 ovehicleY[1]=750;
 ovehicleY[2]=850;
 ovehicleY[3]=500;
 ovehicleY[4]=650;

 divx = 250, divy = 4, movd;
 lane=0;

 rate=8;
 irate=8;

        screen=3;



    }

}


 else
    {

       glClearColor(0.000, 0.545, 0.545,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,0);
    drawText("Score:", 100,300);
    itoa (score, buffer, 10);
    glColor3f(1,0,0);
    drawTextNum(buffer, 6, 200,300);

    glColor3f(1,1,0);
    drawText("#--Press 1 to Play Again", 170, 210);
    drawText("#--Press Esc to Exit", 170, 150);
    glutSwapBuffers();
    }

}

void Timer(int value)
{
    rate=irate+score/300;   // printf("rate=%d\n",rate);
    display();
    glutTimerFunc(25,Timer,0);
}

int main(int argc,char **argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(100,0);
    glutInitWindowSize(800,700);
    glutCreateWindow("Crazzy TANK");


   // ovipos();
    init();
    glutDisplayFunc(display);
	glutSpecialFunc(Specialkey);
    glutKeyboardFunc(Normalkey);
    glutIdleFunc(display);

    glutTimerFunc(0,Timer,25);

    glutMainLoop();
return 0;
}



