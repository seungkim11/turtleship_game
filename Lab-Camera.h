//Seung Kim
//303214644

#ifndef LAB_CAMERA_H
#define LAB_CAMERA_H

#include "Camera.h"

Camera cam; // global camera object

void moveCamera(GLdouble cx, GLdouble r){
	//moving camera
	glPushMatrix();
	glTranslated(cx, 0, 0);
	glRotated(r, 0, 1, 0);
	glPopMatrix();
}

#endif