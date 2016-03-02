//Seung Kim
//303214644

#ifndef COLLISION_H
#define COLLISION_H

#include "Point3.h"
#include "Vector3.h"

static Point3 myTranslate(Point3 p, GLfloat dx, GLfloat dy, GLfloat dz){
	Point3 q;
	q.x = p.x + dx;
	q.y = p.y + dy;
	q.z = p.z + dz;
	return q;
}

static Point3 myXroll(Point3 p, GLfloat angle){
	Point3 q;
	GLfloat sn = (float) sin(angle*3.14159265 / 180);
	GLfloat cs = (float) cos(angle*3.14159265 / 180);
	q.x = p.x;
	q.y = p.y*cs - p.z*sn;
	q.z = p.y*sn + p.z*cs;
	return q;
}

static Point3 myYroll(Point3 p, GLfloat angle){
	Point3 q;
	GLfloat sn = (float) sin(angle*3.14159265 / 180);
	GLfloat cs = (float) cos(angle*3.14159265 / 180);
	q.x = p.x*cs + p.z*sn;
	q.y = p.y;
	q.z = -p.x*sn + p.z*cs;
	return q;
}

static Point3 myZroll(Point3 p, GLfloat angle){
	Point3 q;
	GLfloat sn = (float) sin(angle*3.14159265 / 180);
	GLfloat cs = (float) cos(angle*3.14159265 / 180);
	q.x = p.x*cs - p.y*sn;
	q.y = p.x*sn + p.y*cs;
	q.z = p.z;
	return q;
}

#endif