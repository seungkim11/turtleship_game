//Seung Kim
//303214644

#ifndef MAINHEADER_H
#define MAINHEADER_H

#include "Point3.h"

GLfloat calculateX(GLfloat r, GLfloat t);
GLfloat calculateZ(GLfloat r, GLfloat t);
GLfloat getDistance(Point3 p1, Point3 p2);
void setShape(float vAng, float asp, float nearD, float farD);
void checkGameLose();
void checkDropItem();
void checkGameWin();
GLfloat lerp(GLfloat p1, GLfloat p2, GLfloat t);
#endif