//Seung Kim
//303214644

//Item Class
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>

#include "item.h"


Item::Item(){
	grabbed = 0;
}

Item::~Item(){
}


void Item::setPosition(GLdouble posX1, GLdouble posY1, GLdouble posZ1){
	pos.x = posX1;
	pos.y = posY1;
	pos.z = posZ1;
}

void Item::setPosition(Point3 p){
	pos.x = p.x;
	pos.y = p.y;
	pos.z = p.z;
}

void Item::drawBall(){
	setRedPlastic();
	glutSolidSphere(0.3, 20, 16);
}

void Item::drawDonut(){
	setRedPlastic();
	glutSolidTorus(0.1, 0.3, 20, 16);
}

void Item::drawTeapot(){
	setSilver();
	glutSolidTeapot(0.4);
}

void Item::setGrab(GLint grab){
	if (grab == 1){
		grabbed = 1;
	}
	else{
		grabbed = 0;
	}	
}

void Item::checkGrab(Robot r){
	GLfloat dd = getDistance(pos, r.pos);
	GLint grab = 0;

	if (dd <= 0.3){
		grab = 1;
	}
	else {
		grab = 0;
	}
	setGrab(grab);

}

GLfloat Item::getDistance(Point3 p1, Point3 p2){
	GLfloat dx = p1.x - p2.x;
	GLfloat dy = p1.y - p2.y;
	GLfloat dz = p1.z - p2.z;

	GLfloat dd = sqrt(dx*dx + dy*dy + dz*dz);
	return dd;
}

void Item::checkIsOnTable(){
	GLint checkX = 0;
	GLint checkZ = 0;
	GLint isOnTable = 0;

	if (pos.x < 4 && pos.x > -4){
		checkX = 1;
	}
	if ((pos.z > 22 && pos.z < 24) || (pos.z <-22 && pos.z > -24)){
		checkZ = 1;
	}

	if (checkX == 1 && checkZ == 1){
		onTable = 1;
	}
	else{
		onTable = 0;
	}
}

void Item::checkIsOnGoal(){
	GLint checkX = 0;
	GLint checkZ = 0;
	GLint isOnTable = 0;

	if (pos.x < 4 && pos.x > -4){
		checkX = 1;
	}
	if ((pos.z <-22 && pos.z > -24)){
		checkZ = 1;
	}

	if (checkX == 1 && checkZ == 1 && grabbed == 0){
		onGoal = 1;
	}
	else{
		onGoal = 0;
	}
}