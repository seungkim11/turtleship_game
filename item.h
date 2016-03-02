//Seung Kim
//303214644

#ifndef ITEM_H
#define ITEM_H

#include "Point3.h"
#include "Vector3.h"
#include "robot.h"
#include "material.h"
#include "collision.h"

class Item{
private:
		
public:
	Item(); // default constructor
	~Item();
	GLint grabbed;
	GLint onTable, onGoal;
	Point3 pos;

	void setPosition(GLdouble posX, GLdouble posY, GLdouble posZ);
	void setPosition(Point3 p);
	void drawBall();
	void drawTeapot();
	void drawDonut();
	void setGrab(GLint grab);
	void checkGrab(Robot r);
	GLfloat getDistance(Point3 p1, Point3 p2);
	void checkIsOnTable();
	void checkIsOnGoal();
};

#endif