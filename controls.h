//Seung Kim
//303214644

#ifndef CONTROLS_H
#define CONTROLS_H

#include "robot.h"
#include "item.h"
#include "enemy.h"
#include "collision.h"

//Global Variables
const int screenWidth = 700;	   // width of screen window in pixels
const int screenHeight = 700;	   // height of screen window in pixels

GLint moveLight = 1;
GLdouble cx, r;
GLdouble mx1, my1, mx2, my2;
GLint transCam, pitchCam, zoomCam, rollCam;
GLint activated = 1;
GLint upkey, downkey, leftkey, rightkey;
GLint akey, skey, zkey, xkey, qkey, wkey, fkey, dkey;

//for robot
Robot robot1;
GLfloat rWheel, rShoulder, rUpperArm, rLowerArm, rWrist, rHand, moveX, moveZ;
GLint controlArms, controlHands, controlBodyMove, controlGrab, attackMotion;

//for items
const int numItems = 2;
Item item[numItems];

//for enemies
const int numEnemies = 2;
Enemy enem[numEnemies];

//for camera view
GLfloat eyex = 15, eyey = 15, eyez = 15, lookx, looky, lookz;
GLint camMode;


//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>>>>>>>>>
void mySpecialUp(int key, int x, int y){
	switch (key) {
	case GLUT_KEY_UP:
		if (activated == 1){
			if (upkey == 1){
				upkey = 0;
			}
		}
		break;
	case GLUT_KEY_DOWN:
		if (activated == 1){
			if (downkey == 1){
				downkey = 0;
			}
		}
		break;
	case GLUT_KEY_LEFT:
		if (activated == 1){
			if (leftkey == 1){
				leftkey = 0;
			}
		}
		break;
	case GLUT_KEY_RIGHT:
		if (activated == 1){
			if (rightkey == 1){
				rightkey = 0;
			}
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


void mySpecialKeyboard(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP:
		if (activated == 1){
			if (upkey == 0){
				upkey = 1;
			}
		}
		break;
	case GLUT_KEY_DOWN:
		if (activated == 1){
			if (downkey == 0){
				downkey = 1;
			}
		}
		break;
	case GLUT_KEY_LEFT:
		if (activated == 1){
			if (leftkey == 0){
				leftkey = 1;
			}
		}
		break;
	case GLUT_KEY_RIGHT:
		if (activated == 1){
			if (rightkey == 0){
				rightkey = 1;
			}
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void myKeyUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		if (activated == 1){
			if (akey == 1){
				akey = 0;
			}
		}
		break;
	case 's':
		if (activated == 1){
			if (skey == 1){
				skey = 0;
			}
		}
		break;
	case 'z':
		if (activated == 1){
			if (zkey == 1){
				zkey = 0;
			}
		}
		break;
	case 'x':
		if (activated == 1){
			if (xkey == 1){
				xkey = 0;
			}
		}
		break;
	case 'q':
		if (activated == 1){
			if (qkey == 1){
				qkey = 0;
			}
		}
		break;
	case 'w':
		if (activated == 1){
			if (wkey == 1){
				wkey = 0;
			}
		}
		break;
	case 'd':
		if (activated == 1){
			if (dkey == 1){
				dkey = 0;
			}
		}
		break;
	case 'f':
		if (activated == 1){
			if (fkey == 1){
				fkey = 0;
			}
		}
		break;
	default:
		break;
	}
	glutPostRedisplay(); // draw it again
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r':
		std::cout << "Camera roll counter clock-wise " << std::endl;
		cam.roll(1.0);
		break; // roll the camera 
	case 'R':
		std::cout << "Camera roll clock-wise" << std::endl;
		cam.roll(-1. - 0);
		break; // roll the camera back	
	case 'p':
		std::cout << "Camera pitch up" << std::endl;
		cam.pitch(-1.0);
		break;
	case 'P':
		std::cout << "Camera pitch down" << std::endl;
		cam.pitch(+1.0);
		break;
	case 'y':
		std::cout << "Camera yaw left" << std::endl;
		cam.yaw(1.0);
		break;
	case 'Y':
		std::cout << "Camera yaw right" << std::endl;
		cam.yaw(-1.0);
		break;
	case 'c':
		if (camMode == 0){
			camMode++;
		}
		else if (camMode == 1){
			camMode++;
		}
		else if (camMode == 2){
			camMode = 0;
		}
		break;
	case 'l':
		if (moveLight == 0){
			moveLight = 1;
		}
		else if (moveLight == 1){
			moveLight = 0;
		}
		break;
	case 'a':
		if (activated == 1){
			if (akey == 0){
				akey = 1;
			}
		}
		break;
	case 's':
		if (activated == 1){
			if (skey == 0){
				skey = 1;
			}
		}
		break;
	case 'z':
		if (activated == 1){
			if (zkey == 0){
				zkey = 1;
			}
		}
		break;
	case 'x':
		if (activated == 1){
			if (xkey == 0){
				xkey = 1;
			}
		}
		break;
	case 'q':
		if (activated == 1){
			if (qkey == 0){
				qkey = 1;
			}
		}
		break;
	case 'w':
		if (activated == 1){
			if (wkey == 0){
				wkey = 1;
			}
		}
		break;
	case 'd':
		if (activated == 1){
			if (dkey == 0){
				dkey = 1;
			}
		}
		break;
	case 'f':
		if (activated == 1){
			if (fkey == 0){
				fkey = 1;
			}
		}
		break;
	case 'o':
		if (activated == 0){
			activated = 1;
		}
		else if (activated == 1){
			activated = 0;
		}
		break;
	case 27:
		exit(0);
		break;
	case 32:
		rUpperArm = 0;
		robot1.attackStage = 0;
		robot1.attack = 1;
		break;
	default:
		break;
	}
		
	glutPostRedisplay(); // draw it again
}

void myMouse(int button, int state, int x, int y) {
	mx1 = x / (GLdouble)screenWidth*abs(10) - 5;
	my1 = (1 - y / (GLdouble)screenHeight)*abs(10) - 5;
	
	if (button == GLUT_LEFT_BUTTON){
		if (state == GLUT_DOWN){
			if (glutGetModifiers() & GLUT_ACTIVE_ALT){
				zoomCam = 1;
			}
			else if (glutGetModifiers() & GLUT_ACTIVE_SHIFT){
				 controlBodyMove = 1;
			}
			else if (glutGetModifiers() & GLUT_ACTIVE_CTRL){
				controlHands = 1;
			}
			else {
				transCam = 1;
			}
		}
		else if (state == GLUT_UP){
			controlBodyMove = 0;
			controlHands = 0;
			zoomCam = 0;
			transCam = 0;
		}
	}
	else if (button == GLUT_RIGHT_BUTTON){
		if (state == GLUT_DOWN){
			if (glutGetModifiers() & GLUT_ACTIVE_ALT){
				rollCam = 1;
			}
			else if (glutGetModifiers() & GLUT_ACTIVE_SHIFT){
				controlArms = 1;
			}
			else if (glutGetModifiers() & GLUT_ACTIVE_CTRL){
				controlGrab = 1;
			}
			else {
				pitchCam = 1;
			}
		}
		else if (state == GLUT_UP){
			controlArms = 0;
			pitchCam = 0;
			rollCam = 0;
			controlGrab = 0;
		}
	}
}

void myMotionFunc(int x, int y){
	mx2 = x / (GLdouble)screenWidth*abs(10) - 5;
	my2 = (1 - y / (GLdouble)screenHeight)*abs(10) - 5;

	if (pitchCam == 1){
		cam.slide(2 * (mx1 - mx2), 2 * (my1 - my2), 0);
		//cam.pitch((my2 - my1)/10);
		cam.yaw(-(mx1 - mx2) * 8);
		cam.pitch((my1 - my2) * 8);
	}
	else if (transCam == 1){
		cam.slide(2 * (mx1 - mx2), 2 * (my1 - my2), 0);
	}
	else if (zoomCam == 1){
		cam.slide(0, 0, 2 * (my1 - my2));
		cam.slide(0, 0, 2 * (mx1 - mx2));
	}
	else if (rollCam == 1){
		cam.roll((my1 - my2) * 8);
	}

	if (controlArms == 1){
		rUpperArm += (mx1 - mx2) * 20;
		rLowerArm += (my2 - my1) * 20;
	}

	if (controlHands == 1){
		rWrist += (my2 - my1) * 20;
	}

	if (controlBodyMove == 1){
		rWheel -= 10;
		rShoulder += (my2 - my1) * 20;
		moveX -= (mx1 - mx2) * 5 * cos(rShoulder*3.141592 / 180);
		moveZ += (mx1 - mx2) * 5 * sin(rShoulder*3.141592 / 180);
	}
	
	if (controlGrab == 1){
		rHand += (mx1 - mx2) * 20;
	}

	mx1 = mx2;
	my1 = my2;
	
	glutPostRedisplay();
}

#endif