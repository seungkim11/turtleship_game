//Seung Kim
//303214644
//HW3

#include <windows.h>  //suitable when using Windows 95/98/NT
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>

#include "Lab-Camera.h"
#include "material.h"
#include "controls.h"
#include "mainHeader.h"
#include "lighting.h"
#include "background.h"
#include "robot.h"
#include "item.h"
#include "collision.h"
#include "enemy.h"


Point3 pRobot;
Point3 pBase;

//<<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>
void myInit()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);

	defineLightColors(); // lighting.h
	calculateOrbit(1, 1); // light orbit 

	setShape(50.0f, 48.0f / 48.0f, 0.5f, 200.0f); // ang, ratio, near, far

	//initiallize object positions
	robot1.setPosition(0.93f, 3.02f, 0.0f);
	item[0].setPosition(1.0f, 1.35f, 23.0f);
	item[1].setPosition(-1.5f, 1.4f, 23.3f);
	enem[1].t = 0.5;

	//make the initial camera
	
	cam.set(Point3(16, 16, 35), Point3(-2,0,0), Vector3(0, 1, 0));

	rHand = 41;
}


//<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Point3 rBody;
	rBody.set(myTranslate(rBody, -.3, 0.2, 0));
	rBody.set(myYroll(rBody, rShoulder));
	rBody.set(myTranslate(rBody, moveX, 0, moveZ));

	if (camMode == 0){ // third person view, cam follows robot
		Camera cam;

	}
	else if (camMode == 1){ // first person view
		Point3 lookTo;
		lookTo.set(myTranslate(lookTo, -4, 2, 0));
		lookTo.set(myYroll(lookTo, rShoulder));
		lookTo.set(myTranslate(lookTo, moveX, 0, moveZ));
		glLoadIdentity();
		gluLookAt(lookTo.x, lookTo.y, lookTo.z, 
			lookTo.x + 0.5*cos(rShoulder*3.141592 / 180), lookTo.y , lookTo.z - 0.5*sin(rShoulder*3.141592 / 180), 
			0.0, 1.0, 0.0);
	}
	else if (camMode == 2){ 
		glLoadIdentity();
		gluLookAt(15, 15, 1, rBody.x, rBody.y, rBody.z, 0.0, 1.0, 0.0);
	}

	//draw background
	drawSea();
	drawWave();
	drawWalls();
	drawTable1();
	drawTable2();
	
	// light animation
	if (moveLight == 0){
		placeLight();
	}
	else if (moveLight == 1){
		placeLightforAnimation();
	}

	glPushMatrix();
	if (robot1.life > 0){
		robot1.setValues(rWheel, rShoulder, rUpperArm, rLowerArm, rWrist, rHand, moveX, moveZ);
		robot1.calcPosition();
		robot1.drawRobot();
	}
	glPopMatrix();
	
	//check collision and draw items
	for (GLint i = 0; i < numItems; i++){
		if (item[i].grabbed == 1){
			item[i].setPosition(robot1.pos);
		}
		glPushMatrix();
		glTranslated(item[i].pos.x, item[i].pos.y, item[i].pos.z);
		
		if (i == 0){
			item[0].drawDonut();
		}
		else if (i == 1){
			item[1].drawTeapot();
		}
		glPopMatrix();
		item[i].checkGrab(robot1);
		item[i].checkIsOnTable();
		item[i].checkIsOnGoal();
	}	
	// check if mouth is open and item should be dropped
	checkDropItem();
	

	//enemies

	for (GLint i = 0; i < numEnemies; i++){
		if (enem[i].life > 0){
			glPushMatrix();
			glTranslated(enem[i].pos.x, enem[i].pos.y, enem[i].pos.z);
			if (enem[i].attack == 0){
				if (i == 0){
					enem[i].setPosition(calculateX(5, enem[i].t), 10, calculateZ(10, enem[i].t));
				}if (i == 1){
					enem[i].setPosition(calculateX(10, enem[i].t), 5, calculateZ(13, enem[i].t));
				}
				
			}
			else if (enem[i].attack == 1){
				enem[i].setPosition(lerp(enem[i].pos.x, rBody.x, enem[i].t/10), lerp(enem[i].pos.y, rBody.y, enem[i].t/10),
					lerp(enem[i].pos.z, rBody.z, enem[i].t/10));
			}

			// if enemy hits robot, robot loses life
			if (getDistance(enem[i].pos, rBody) < 0.3){
				robot1.life--;
				enem[i].attack = 0;
				enem[i].t = 0;
			}
			// if robot hits target with head, enemy loses life
			else if ((getDistance(enem[i].pos, robot1.pos) < 0.7)){
				enem[i].life--;
				enem[i].attack = 0;
				enem[i].t = 0;
			}
			if (enem[i].life > 0){
				enem[i].draw();
			}
			glPopMatrix();
		}
	}

	checkGameLose();
	checkGameWin();
	glutSwapBuffers();
}

void myIdle(){
	if (upkey == 1){
		rWheel -= 10;
		moveX += 0.2*cos(rShoulder*3.141592 / 180);
		moveZ -= 0.2*sin(rShoulder*3.141592 / 180);
	}

	if (downkey == 1){
		rWheel += 10;
		moveX -= 0.2 * cos(rShoulder*3.141592 / 180);
		moveZ += 0.2 * sin(rShoulder*3.141592 / 180);
	}
	
	if (leftkey == 1){
		rShoulder += 3;
	}
	if (rightkey == 1){
		rShoulder -= 3;
	}
	if (akey == 1){
		rUpperArm -= 2;
	}
	if (skey == 1){
		rUpperArm += 2;
	}
	if (zkey == 1){
		rLowerArm -= 2;
	}
	if (xkey == 1){
		rLowerArm += 2;
	}
	if (qkey == 1){
		rWrist -= 2;
	} 
	if (wkey == 1){
		rWrist += 2;
	}
	if (dkey == 1){
		rHand += 2;
	}
	if (fkey == 1){
		rHand -= 2;
	}
	if (moveLight == 1){
		if (lightTime >= 1000){
			lightTime = 0;
		}
		lightTime = lightTime + 1;
		Sleep(1);
	}
	
	for (GLint i = 0; i < numItems; i++){
		// if item is not grabbed, drop them
		if (item[i].grabbed == 0){

			//for tables
			if (item[i].onTable == 1){
				if (item[i].pos.y > 1.3){
					item[i].pos.y -= 0.1;
				}
			}
			//for ground
			else if (item[i].onTable == 0){
				if (item[i].pos.y > 0.2){
					item[i].pos.y -= 0.1;
				}
			}
		}
	}

	for (GLint i = 0; i < numEnemies; i++){
		//enemy orbit
		if (enem[i].t >= 1){
			// if one cycle rotated, attack
			if (enem[i].attack == 0){
				enem[i].attack = 1;
			}
			else if (enem[i].attack == 1){
				enem[i].attack = 0;
			}
			enem[i].t = 0;
		}
		else {
			enem[i].t += 0.001;
		}
	}
	
	// attack animation
	if (robot1.attack == 1){
		if (robot1.attackStage == 0){
			if (rUpperArm < 10){
				rUpperArm += 3;
			}
			else if (rUpperArm >= 10){
				robot1.attackStage++;
			}
		}
		else if (robot1.attackStage == 1){
			if (rUpperArm > -90){
				rUpperArm -= 5;
			}
			else if (rUpperArm <= -90){
				robot1.attackStage++;
			}
		}
		else if (robot1.attackStage == 2){
			if (rUpperArm < 0){
				rUpperArm += 3;
			}
			else if (rUpperArm >= 0){
				robot1.attack = 0;
				robot1.attackStage = 0;
			}
		}
		
	}

	//wave control
	for (GLint i = 0; i < 7; i++){
		if (waveZ[i] > -25){
			waveZ[i] -= 0.05;
		}
		else if (waveZ[i] <= -25){
			waveZ[i]= 23.5;
		}
	}

	if (waveY < -1.4 && waveDir == 0){
		waveY += 0.005;
	}
	else if (waveY < -1 && waveDir == 1 && waveY > -2.2){
		waveY -= 0.005;
	}
	else if (waveY >= -1.4){
		waveDir = 1;
	}
	else if (waveY <= -2.2){
		waveDir = 0;
	}
	Sleep(1);
	glutPostRedisplay();

}

GLfloat lerp(GLfloat p1, GLfloat p2, GLfloat t){
	return p1*(1 - t) + p2*t;
}

GLfloat calculateX(GLfloat r1, GLfloat t1){
	return r1*cos(2 * 3.141592*t1);
}

GLfloat calculateZ(GLfloat r1, GLfloat t1){
	return r1*sin(2 * 3.141592*t1);
}

GLfloat getDistance(Point3 p1, Point3 p2){
	GLfloat dx = p1.x - p2.x;
	GLfloat dy = p1.y - p2.y;
	GLfloat dz = p1.z - p2.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

void checkDropItem(){
	if (rHand > 40){
		for (GLint i = 0; i < numItems; i++){
			if (item[i].grabbed == 1) {
				item[i].setGrab(0); 
			}
		}
	}
}

void checkGameWin(){
	if (item[0].onGoal == 1 && item[1].onGoal == 0){
		std::cout << "ball is moved Correctly. Move teapot" << std::endl;
	}
	else if ((item[0].onGoal == 0 && item[1].onGoal == 1)){
		std::cout << "Teapot is moved Correctly. Move ball" << std::endl;
	}
	else if ((item[0].onGoal == 1 && item[1].onGoal == 1)){
		std::cout << "Items moved. Game win!" << std::endl;
	}
}

void checkGameLose(){
	if (robot1.life <= 3){
		std::cout << "Life is low. You are in danger!!" << std::endl;
	}
	else if (robot1.life == 0){
		std::cout << "You lose." << std::endl;
		exit(0);
	}
}

void setShape(float vAng, float asp, float nearD, float farD)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(vAng, asp, nearD, farD);
	glMatrixMode(GL_MODELVIEW);
}

//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char **argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(0, 0); // set window position on screen
	glutCreateWindow("HW3: King of the Lake"); // open the screen window

	myInit();

	//	register callback functions
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);
	glutKeyboardUpFunc(myKeyUp);
	glutSpecialFunc(mySpecialKeyboard);
	glutSpecialUpFunc(mySpecialUp);
	glutMouseFunc(myMouse);
	glutMotionFunc(myMotionFunc);
	glutIdleFunc(myIdle);
	
	glutMainLoop();

	return(0);
}