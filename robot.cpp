//Seung Kim
//303214644

//Robot Class
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>

#include "robot.h"


Robot::Robot()
{
	openHand = 0;
	life = 10;
}

Robot::Robot(GLfloat rWheel1, GLfloat rShoulder1, GLfloat rUpperArm1, GLfloat rLowerArm1, GLfloat rWrist1,
	GLfloat rHand1, GLfloat moveX1, GLfloat moveZ1)
{
	rWheel = rWheel1;
	rShoulder = rShoulder1;
	rUpperArm = rUpperArm1;
	rLowerArm = rLowerArm1;
	rWrist = rWrist1;
	rHand = rHand1;
	moveX = moveX1;
	moveZ = moveZ1;
}

Robot::~Robot()
{
}

void Robot::setValues(GLfloat rWheel1, GLfloat rShoulder1, GLfloat rUpperArm1, GLfloat rLowerArm1, GLfloat rWrist1,
	GLfloat rHand1, GLfloat moveX1, GLfloat moveZ1){
	rWheel = rWheel1;
	rShoulder = rShoulder1;
	rUpperArm = rUpperArm1;
	rLowerArm = rLowerArm1;
	rWrist = rWrist1;
	rHand = rHand1;
	moveX = moveX1;
	moveZ = moveZ1;
}

void Robot::setPosition(GLfloat xx, GLfloat yy, GLfloat zz){
	pos.x = xx;
	pos.y = yy;
	pos.z = zz;
}

void Robot::setPosition(Point3 p){
	pos.x = p.x;
	pos.y = p.y;
	pos.z = p.z;
}

void Robot::calcPosition(){
	Point3 pi;
	setPosition(myTranslate(pi, 0.25, 0, 0));
	setPosition(myZroll(pos, rWrist));
	setPosition(myTranslate(pos, -0.05, 1.15, 0));
	setPosition(myZroll(pos, rLowerArm));
	setPosition(myTranslate(pos, 0, 1.37, 0));
	setPosition(myZroll(pos, rUpperArm));
	setPosition(myTranslate(pos, 0.73, 0.5, 0));
	setPosition(myYroll(pos, rShoulder));
	setPosition(myTranslate(pos, moveX, 0, moveZ));
}

void Robot::drawRobot(){
	drawBase();
	drawUpperArm();
	drawLowerArm();
	drawHand();
	drawMisc();
}

void Robot::drawBase(){
	glTranslated(moveX, 0, moveZ); // move entire figure
	glRotated(rShoulder, 0, 1, 0); // rotate entire figure

	//turtle base
	setGold();
	glPushMatrix();
	glTranslated(-0.5, 0.25, 0);
	glScaled(2.4, 0.75, 1.5);

	glutSolidCube(1);
	glPopMatrix();

	//turtle house
	if (life > 3){
		setGreenRubber();
	}
	else if (life <= 3){
		setRedPlastic();
	}
	glPushMatrix();
	glTranslated(0, 0.5, 0);
	for (GLint i = 0; i < 19; i++){
		glTranslated(-0.05, 0, 0);
		glutSolidSphere(0.75, 20, 16);
	}

	//thorns
	setBlackPlastic();
	for (GLint i = 0; i < 4; i++){
		for (GLint j = 0; j < 5; j++){
			glPushMatrix();
			glRotated(70 - 35 * j, 1, 0, 0);
			glTranslated(1.2 - 0.475*i, 0.7, 0);
			glRotated(-90, 1, 0, 0);
			glutSolidCone(0.08, 0.3, 20, 16);
			glPopMatrix();
		}
	}

	// tails===========
	setBronze();
	glPushMatrix();
	glTranslated(-0.8, 0, 0);
	// tail bottom
	glPushMatrix();
	glScaled(1, 6, 1);
	glutSolidCube(0.1);
	glPopMatrix();
	// tail top
	glPushMatrix();
	glColor3f(1.0f, 0.3f, 0.0f);
	glTranslated(0, 0.6, 0);
	glScaled(0.15, 0.6, 0.1);
	glutSolidSphere(1, 20, 16);
	glPopMatrix();
	glPopMatrix();
	//=======================

	//for rows===============
	setCopper();
	for (GLint i = 0; i < 6; i++){
		glPushMatrix();
		glTranslated(1 - 0.3*i, -0.3, 0.7);
		glRotated(80 + rWheel, 0.25, 0, 1);
		glTranslated(0, 0, 0.4);
		glScaled(0.05, 0.05, 1.7);
		glutSolidCube(1);
		glPopMatrix();
	}
	//row end================

	//for rows on right==============
	for (GLint i = 0; i < 6; i++){
		glPushMatrix();
		glTranslated(1 - 0.3*i, -0.3, -0.7);
		glRotated(80 + rWheel, -0.25, 0, 1);
		glTranslated(0, 0, -0.4);
		glScaled(0.05, 0.05, 1.7);
		glutSolidCube(1);
		glPopMatrix();
	}
	//rows on right=================
	glPopMatrix();
}

void Robot::drawUpperArm(){
	glTranslated(0.73, 0.5, 0);
	glRotated(rUpperArm, 0, 0, 1); // rotating upperarm

	glPushMatrix();
	//upperarm base
	setBrass();
	glutSolidSphere(0.15, 20, 16);


	GLint colorSwitch = 0;
	//upper arm
	for (GLint i = 0; i < 16; i++){
		glTranslated(0, 0.08, 0);
		if (colorSwitch == 0){
			setBlackPlastic();
			colorSwitch = 1;
		}
		else if (colorSwitch == 1){
			setBrass();
			colorSwitch = 0;
		}
		glutSolidSphere(0.1, 20, 16);
	}

	glPopMatrix();
}

void Robot::drawLowerArm(){
	glTranslated(0, 1.37, 0);
	glRotated(rLowerArm, 0, 0, 1);

	glPushMatrix();
	// draw elbow
	setBlackPlastic();
	glutSolidSphere(0.125, 20, 16);

	//draw lower arm
	setBrass();
	glPushMatrix();
	for (GLint i = 0; i < 14; i++){
		glTranslated(0, 0.08, 0);
		glutSolidSphere(0.1, 20, 16);
	}
	glPopMatrix();

	glPopMatrix();
}

void Robot::drawHand(){
	glTranslated(-0.05, 1.15, 0);
	glRotated(rWrist, 0, 0, 1);
	glTranslated(0.15, 0, 0);

	glPushMatrix();
	glRotated(-rHand, 0, 0, 1);
	glTranslated(0.14, 0, 0);

	glScaled(1.2, 1.2, 1.2); // scale everything by a lil
	//lower teeth
	setWhitePlastic();
	for (GLint i = 0; i < 2; i++){
		glPushMatrix();
		glTranslated(0.12, 0.045, 0.075 - i*0.15);
		glRotated(-90, 1, 0, 0);
		glutSolidCone(0.04, 0.1, 20, 16);
		glPopMatrix();
	}

	//draw face
	setCopper();
	glPushMatrix();
	glScaled(3, 0.75, 2.5);
	glutSolidCube(0.1);
	glPopMatrix();

	glScaled(3, 0.75, 2.5);
	glutSolidCube(0.1);
	glPopMatrix();

	//backhead
	glPushMatrix();
	glTranslated(-0.1, 0.09, 0);
	glScaled(2, 2.8, 2.5);

	glutSolidCube(0.1);
	glPopMatrix();

	//draw horns
	for (GLint i = 0; i < 2; i++){
		glPushMatrix();
		glTranslated(-0.15, 0.2, 0.075 - i*0.15);
		glRotated(rHand, 0, 0, 1);
		glRotated(-90, 1, 0, 0);
		glutSolidCone(0.1, 0.3, 20, 16);
		glPopMatrix();
	}

	//upper lip
	glTranslated(0, 0.15, 0);
	glRotated(rHand, 0, 0, 1);
	glPushMatrix();
	glTranslated(0.175, 0.05, 0);

	//lower teeth
	setWhitePlastic();
	for (GLint i = 0; i < 2; i++){
		glPushMatrix();
		glTranslated(0.12, -0.05, 0.075 - i*0.15);
		glRotated(90, 1, 0, 0);
		glutSolidCone(0.04, 0.1, 20, 16);
		glPopMatrix();
	}

	setCopper();

	glScaled(3.5, 0.75, 2.5);
	glutSolidCube(0.1);
	glPopMatrix();

}

void Robot::drawMisc(){
	//left eye
	glPushMatrix();
	setPearl(); //white eyeball
	glTranslated(0, 0.15, 0.10);
	glutSolidSphere(0.085, 20, 16);

	setBlackPlastic(); //pupil
	glTranslated(0.04, 0, 0.03);
	glutSolidSphere(0.05, 20, 16);

	//right eye
	setPearl(); // white eyeball
	glTranslated(-0.04, 0, -0.23);
	glutSolidSphere(0.085, 20, 16);

	setBlackPlastic(); // pupil
	glTranslated(0.04, 0, -0.03);
	glutSolidSphere(0.05, 20, 16);
	glPopMatrix();
}
/*
void Robot::attackAnimation(){
	// attack animation

	if (attackStage == 0){
		if (rUpperArm < 10){
			rUpperArm += 3;
		}
		else if (rUpperArm >= 10){
			attackStage++;
		}
	}
	else if (attackStage == 1){
		if (rUpperArm > -90){
			rUpperArm -= 5;
		}
		else if (rUpperArm <= -90){
			attackStage++;
		}
	}
	else if (attackStage == 2){
		if (rUpperArm < 0){
			rUpperArm += 3;
		}
		else if (rUpperArm >= 0){
			attack = 0;
			attackStage = 0;
		}
	}
}*/