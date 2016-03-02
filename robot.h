//Seung Kim
//303214644

#ifndef ROBOT_H
#define ROBOT_H

#include "Point3.h"
#include "Vector3.h"
#include "material.h"
#include "collision.h"

class Robot{
private:
	GLfloat rWheel, rShoulder, rUpperArm, rLowerArm, rWrist, rHand, moveX, moveZ;
	
public:
	Robot(); // default constructor
	Robot(GLfloat rWheel, GLfloat rShoulder, GLfloat rUpperArm, GLfloat rLowerArm, GLfloat rWrist,
		GLfloat rHand, GLfloat moveX, GLfloat moveZ);
	~Robot();
	void setValues(GLfloat rWheel, GLfloat rShoulder, GLfloat rUpperArm, GLfloat rLowerArm, GLfloat rWrist,
		GLfloat rHand, GLfloat moveX, GLfloat moveZ);
	void drawRobot();
	void drawBase();
	void drawUpperArm();
	void drawLowerArm();
	void drawHand();
	void drawMisc();
	Point3 pos;
	GLint openHand, life, attackStage, attack;
	GLint itemHold[2];
	void calcPosition();
	void setPosition(GLfloat xx, GLfloat yy, GLfloat zz);
	void setPosition(Point3 p);
	void attackAnimation();
};

#endif
