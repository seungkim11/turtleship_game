//Seung Kim
//303214644

#ifndef LIGHTING_H
#define LIGHTING_H

GLint lightTime;
GLdouble px[1000], pz[1000];
const float PI = 3.141592;

GLfloat lightPos[4];

void placeLight(){
	lightPos[0] = 10;
	lightPos[1] = 10;
	lightPos[2] = 10;
	lightPos[3] = 1.0f;
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

void placeLightforAnimation(){
	lightPos[0] = px[lightTime];
	lightPos[1] = 10;
	lightPos[2] = pz[lightTime];
	lightPos[3] = 1.0f;
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

void calculateOrbit(GLfloat r1, GLfloat r2){
	GLfloat n = 0;
	GLint i = 0;
	while (i < 1000){
		px[i] = 10 * r1*cos(2 * PI*n);
		pz[i] = 10 * r2*sin(2 * PI*n);
		i++;
		n += 0.001;
	}
}

void defineLightColors(){
	// define some colors
	GLfloat amb0[] = { 0.7f, 0.7f, 0.7f, 1.0 };
	GLfloat diff0[] = { 0.7f, 0.7f, 0.7f, 1.0 };
	GLfloat spec0[] = { 0.7f, 0.7f, 0.7f, 1.0 };
	// attach them to GL_LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spec0);
}


#endif