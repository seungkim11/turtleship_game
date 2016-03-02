//Seung Kim
//303214644

#ifndef ENEMY_H
#define ENEMY_H

#include "Point3.h"
#include "Vector3.h"
#include "material.h"
#include "collision.h"

class Enemy{
private:

public:
	Enemy(); // default constructor
	~Enemy();

	Point3 pos;
	void setValues();
	void setPosition(GLfloat xx, GLfloat yy, GLfloat zz);
	void setPosition(Point3 p);
	void draw();
	void drawEyes();
	void drawWings();
	GLfloat getDistance(Point3 p1, Point3 p2);
	GLint attack, life;
	GLfloat t;
};

#endif