//Seung Kim
//303214644

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>

#include "enemy.h"


Enemy::Enemy()
{
	life = 3;
}

Enemy::~Enemy()
{
}

void Enemy::setPosition(GLfloat xx, GLfloat yy, GLfloat zz){
	pos.x = xx;
	pos.y = yy;
	pos.z = zz;
}

void Enemy::setPosition(Point3 p){
	pos.x = p.x;
	pos.y = p.y;
	pos.z = p.z;
}

void Enemy::setValues(){
	
}

void Enemy::draw(){
	if (life == 3){
		setYellowRubber();
	}
	else if (life == 2){
		setCyanPlastic();
	}
	else if (life == 1){
		setRedPlastic();
	}
	else if (life == 0){
		setObsidian();
	}
	
	glutSolidSphere(1, 15, 13);
	drawEyes();
	drawWings();
}

void Enemy::drawWings(){
	glPushMatrix();
	glPopMatrix();
}

void Enemy::drawEyes(){
	//left eye
	glPushMatrix();
	setPearl(); //white eyeball
	glTranslated(0, 0.8, 0.8);
	glutSolidSphere(0.3, 20, 16);
	setBlackPlastic(); //pupil
	glTranslated(0.1, 0, 0.1);
	glutSolidSphere(0.2, 20, 16);
	glPopMatrix();

	//left eye
	glPushMatrix();
	setPearl(); //white eyeball
	glTranslated(0, 0.8, -0.8);
	glutSolidSphere(0.3, 20, 16);
	setBlackPlastic(); //pupil
	glTranslated(0.1, 0, -0.1);
	glutSolidSphere(0.2, 20, 16);
	glPopMatrix();

}


