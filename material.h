//Seung Kim
//303214644

#ifndef MATERIAL_H
#define MATERIAL_H


static void setGold(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.24725;
	ambg = 0.1995;
	ambb = 0.0745;
	difr = 0.75164;
	difg = 0.60648;
	difb = 0.22648;
	specr = 0.628281;
	specg = 0.555802;
	specb = 0.366065;
	shine = 0.4;
	
	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setSilver(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.19225;
	ambg = 0.19225;
	ambb = 0.19225;
	difr = 0.50754;
	difg = 0.50754;
	difb = 0.50754;
	specr = 0.508273;
	specg = 0.508273;
	specb = 0.508273;
	shine = 0.4;
	
	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setObsidian(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.05375;
	ambg = 0.05;
	ambb = 0.06625;
	difr = 0.18275;
	difg = 0.17;
	difb = 0.22525;
	specr = 0.332741;
	specg = 0.328634;
	specb = 0.346435;
	shine = 0.3;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setEmerald(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.0215;
	ambg = 0.1745;
	ambb = 0.0215;
	difr = 0.07568;
	difg = 0.61424;
	difb = 0.07568;
	specr = 0.633;
	specg = 0.727811;
	specb = 0.633;
	shine = 0.6;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setYellowRubber(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.05;
	ambg = 0.05;
	ambb = 0.0;
	difr = 0.5;
	difg = 0.5;
	difb = 0.4;
	specr = 0.7;
	specg = 0.7;
	specb = 0.04;
	shine = 0.078125;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setRedPlastic(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.0;
	ambg = 0.0;
	ambb = 0.0;
	difr = 0.5;
	difg = 0.0;
	difb = 0.0;
	specr = 0.7;
	specg = 0.6;
	specb = 0.6;
	shine = 0.25;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setTurquoise(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.1;
	ambg = 0.18725;
	ambb = 0.1745;
	difr = 0.396;
	difg = 0.74151;
	difb = 0.69102;
	specr = 0.297254;
	specg = 0.30829;
	specb = 0.306678;
	shine = 0.1;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setBlackPlastic(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.0;
	ambg = 0.0;
	ambb = 0.0;
	difr = 0.01;
	difg = 0.01;
	difb = 0.01;
	specr = 0.50;
	specg = 0.50;
	specb = 0.50;
	shine = 0.25;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setBronze(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.2125;
	ambg = 0.1275;
	ambb = 0.054;
	difr = 0.714;
	difg = 0.4284;
	difb = 0.18144;
	specr = 0.393548;
	specg = 0.271906;
	specb = 0.166721;
	shine = 0.2;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setCopper(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.19125;
	ambg = 0.0735;
	ambb = 0.0225;
	difr = 0.7038;
	difg = 0.27048;
	difb = 0.0828;
	specr = 0.256777;
	specg = 0.137622;
	specb = 0.086014;
	shine = 0.1;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setGreenRubber(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.0;
	ambg = 0.05;
	ambb = 0.0;
	difr = 0.4;
	difg = 0.5;
	difb = 0.4;
	specr = 0.04;
	specg = 0.7;
	specb = 0.04;
	shine = .078125;
	
	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setBrass(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.329412;
	ambg = 0.223529;
	ambb = 0.027451;
	difr = 0.780392;
	difg = 0.568627;
	difb = 0.113725;
	specr = 0.992157;
	specg = 0.941176;
	specb = 0.807843;
	shine = 0.21794872;
	
	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setWhitePlastic(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.0;
	ambg = 0.0;
	ambb = 0.0;
	difr = 0.55;
	difg = 0.55;
	difb = 0.55;
	specr = 0.70;
	specg = 0.70;
	specb = 0.70;
	shine = 0.25;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setPearl(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.25;
	ambg = 0.20725;
	ambb = 0.20725;
	difr = 1;
	difg = 0.829;
	difb = 0.829;
	specr = 0.296648;
	specg = 0.296648;
	specb = 0.296648;
	shine = 0.088;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setJade(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.135;
	ambg = 0.2225;
	ambb = 0.1575;
	difr = 0.54;
	difg = 0.89;
	difb = 0.63;
	specr = 0.316228;
	specg = 0.316228;
	specb = 0.316228;
	shine = 0.1;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setCyanRubber(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.0;
	ambg = 0.05;
	ambb = 0.05;
	difr = 0.4;
	difg = 0.5;
	difb = 0.5;
	specr = 0.04;
	specg = 0.7;
	specb = 0.7;
	shine = 0.078125;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setCyanPlastic(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.0;
	ambg = 0.1;
	ambb = 0.06;
	difr = 0.0;
	difg = 0.50980392;
	difb = 0.50980392;
	specr = 0.50196078;
	specg = 0.50196078;
	specb = 0.50196078;
	shine = .25;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setChrome(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.25;
	ambg = 0.25;
	ambb = 0.25;
	difr = 0.4;
	difg = 0.4;
	difb = 0.4;
	specr = 0.774597;
	specg = 0.774597;
	specb = 0.774597;
	shine = .6;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}

static void setWhiteRubber(){
	GLdouble ambr = 0, ambg = 0, ambb = 0, difr = 0, difg = 0, difb = 0, specr = 0, specg = 0, specb = 0, shine = 0;
	GLfloat mat[4];

	ambr = 0.05;
	ambg = 0.05;
	ambb = 0.05;
	difr = 0.5;
	difg = 0.5;
	difb = 0.5;
	specr = 0.7;
	specg = 0.7;
	specb = 0.7;
	shine = .078125;

	mat[0] = ambr;	mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0; glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr;	mat[1] = difg; mat[2] = difb; glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb; glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
}


#endif