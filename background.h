//Seung Kim
//303214644

#ifndef BACKGROUND_H
#define BACKGROUND_H

GLfloat waveX;
GLfloat waveY = -2.2;
GLfloat waveZ[7] = { 23.5, 16.5, 9.5, 2.5, -5.5, -12.5, -19.5 };
GLint waveDir = 0;

void drawBackgroundLines(){
	glPushMatrix();
	glLineWidth(1);
	setEmerald();
	glBegin(GL_LINES);
	for (int i = 0; i < 21; i++){
		glVertex3d(-10, 0, -10 + i);
		glVertex3d(10, 0, -10 + i);
	}
	
	for (int i = 0; i < 21; i++){
		glVertex3d(-10 + i, 0, -10);
		glVertex3d(-10 + i, 0, 10);
	}
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex3d(-10, 0, 0);
	glVertex3d(10, 0, 0);
	glVertex3d(0, 0, -10);
	glVertex3d(0, 0, 10);
	glEnd();
	glPopMatrix();
}

void drawWalls(){
	glLineWidth(1.0);
	setPearl();
	
	glBegin(GL_POLYGON);
	glVertex3d(-15, 0, -25);
	glVertex3d(-15, 0, 25);
	glVertex3d(-15, 10, 25);
	glVertex3d(-15, 10, -25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-15, 0, -25);
	glVertex3d(15, 0, -25);
	glVertex3d(15, 10, -25);
	glVertex3d(-15, 10, -25);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3d(15, 0, -25);
	glVertex3d(15, 0, 25);
	glVertex3d(15, 2, 25);
	glVertex3d(15, 2, -25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-15, 0, 25);
	glVertex3d(-15, 2, 25);
	glVertex3d(15, 2, 25);
	glVertex3d(15, 0, 25);
	glEnd();
}

void drawTable1(){
	setGold();
	glPushMatrix();
	glTranslated(0, 0, -23);
	
	glPushMatrix();
	glTranslated(-1, 0.5, 0);
	glScaled(0.1, 1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	
	//leg
	glPushMatrix();
	glTranslated(1, 0.5, 0);
	glScaled(0.1, 1, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	//flat table
	glPushMatrix();
	glTranslated(0, 1, 0);
	glScaled(4, 0.1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void drawTable2(){
	setJade();
	glPushMatrix();
	glTranslated(0, 0, 23);

	glPushMatrix();
	glTranslated(-1, 0.5, 0);
	glScaled(0.1, 1, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	//leg
	glPushMatrix();
	glTranslated(1, 0.5, 0);
	glScaled(0.1, 1, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	//flat table
	glPushMatrix();
	glTranslated(0, 1, 0);
	glScaled(4, 0.1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void drawSea(){
	setTurquoise();
	glPushMatrix();
	glTranslated(0, -1.3, 0);
	glScaled(30, 3, 50);
	glutSolidCube(1);
	glPopMatrix();
}

void drawWave(){
	setTurquoise();
	for (GLint i = 0; i < 2; i++){
		for (GLint j = 0; j < 7; j++){
			glPushMatrix();
			glTranslated(7.5 - 15*i, waveY, waveZ[j]);
			glScaled(5, 0.7, 1);
			glutSolidSphere(3, 20, 16);
			glPopMatrix();
		}
	}
	
		
	
}

#endif