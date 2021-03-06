#include "../GrTown_PCH.H"
#include "Bird.h"
#include "Utilities/Texture.H"
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>
#include <glm/glm.hpp>
#include <FL/fl_ask.H>
#include "Utilities/ShaderTools.H"

bool triedShader = false;
int shader;

Bird::Bird(float x, float y, float z, float r, float g, float b, int _ID)
	: color(r, g, b), count(count), ID(_ID)
{
	if (ID == 8){
		this->laX = this->transform[3][0];
		this->laY = this->transform[3][1]-200;
		this->laZ = 0;
		this->lfX = 00;
		this->lfY = 400;
		this->lfZ = -650;
		printf("x trans: %f\n y trans: %f\nz trans: %f\n", this->transform[3][0], this->transform[3][1], this->transform[3][2]);
	}
		count = 0;
	transMatrix(transform, x, y, z);
}

void Bird::draw(DrawingState* state){
	glPushMatrix();
	this->transform[3][0] += state->speedup*8;
	/* Make birds re-appear at other side of the environment */
	if (this->transform[3][0] > 5000 && this->ID <= 16)
		this->transform[3][0] -= 10000;
	if (this->transform[3][0] > 6420 && this->ID<= 33 && this-> ID > 16)
		this->transform[3][0] -= 12630;
	if (this->transform[3][0] > 7721 && this->ID <= 51 && this->ID > 33)
		this->transform[3][0] -= 14826;
	if (this->transform[3][0] > 5643 && this->ID <= 68 && this->ID > 51)
		this->transform[3][0] -= 11258;
	if (this->transform[3][0] > 6000 && this->ID <= 86 && this->ID > 68)
		this->transform[3][0] -= 13000;
	
	if (!triedShader) {
		triedShader = true;
		char* error;
		if (!(shader = loadShader("ShadedCubeTest.vert", "Bird.frag", error))) {
			std::string s = "Can't Load Surface Shader:";
			s += error;
			fl_alert(s.c_str());
		}
	}
	if (shader != 0){
		glUseProgram(shader);
		GLint ambientLoc = glGetUniformLocation(shader, "ambient");
		GLint lightLoc = glGetUniformLocation(shader, "light");
		glUniform4f(lightLoc, state->lightPos[0], state->lightPos[1], state->lightPos[2], state->lightPos[3]);
		glUniform1f(ambientLoc, state->ambient);
	}
	glScaled(10, 10, 10);
	glPushMatrix();
	glScaled(1, 1, 1.5);
	glColor4fv(&color.r);
	GLUquadricObj *quadric = gluNewQuadric();

	//Draw beak
	gluCylinder(quadric, .2, 0, 1, 3, 1);
	gluQuadricDrawStyle(quadric, GLU_FILL);

	//Draw head
	gluSphere(quadric, 0.5, 5, 5);
	glTranslated(0, 0, -1.1);

	//Draw body
	gluSphere(quadric, .7, 10, 5);
	glPopMatrix();


	glPushMatrix();

	glTranslated(0, 0, -3);
	gluCylinder(quadric, .05, .05, 1, 5, 1);
	glRotated(20, 0, 1, 1);
	glTranslated(-.2, 0, 0);
	gluCylinder(quadric, 0.05, .05, 1, 5, 1);
	glTranslated(.2, 0, 0);
	glRotated(-40, 0, 1, 1);
	glTranslated(.2, 0, 0);
	gluCylinder(quadric, 0.05, 0.05, 1, 5, 1);
	
	glPopMatrix();


	//Draw left wing
	glPushMatrix();

	glRotated(10*sin(count*state->speedup), 0, 0, 1);
	glTranslated(.2, 0, -2.7);
	
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(0, 0, 1);
	glVertex3f(0, 0, 2);
	glVertex3f(2, 0, 2);
	glVertex3f(1, 0, 1);
	glVertex3f(0, 0, .5);
	glVertex3f(.5, 0, 1);
	glVertex3f(.5, -.05, 1);
	glVertex3f(0, -.05, .5);
	glVertex3f(1, -.05, 1);
	glVertex3f(2, -.05, 2);
	glVertex3f(0, -.05, 2);
	glVertex3f(0, -.05, 1);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0, 0, 2);
	glVertex3f(0, -.05, 2);
	glVertex3f(2, -.05, 2);
	glVertex3f(2, 0, 2);
	glVertex3f(2, 0, 2);
	glVertex3f(2, -0.05, 2);
	glVertex3f(1, -0.05, 1);
	glVertex3f(1, 0, 1);
	glVertex3f(1, 0, 1);
	glVertex3f(1, -.05, 1);
	glVertex3f(0, -.05, 1);
	glVertex3f(0, 0, 1);
	glEnd();
	
	glPopMatrix();


	//Draw right wing
	glPushMatrix();

	glRotated(-10 * sin(count*state->speedup), 0, 0, 1);
	glTranslated(.2, 0, -2.7);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-.3, -.05, 1);
	glVertex3f(-.3, -.05, 2);
	glVertex3f(-2.3, -.05, 2);
	glVertex3f(-1.3, -.05, 1);
	glVertex3f(-.3, -.05, .5);
	glVertex3f(-.8, -.05, 1);
	glVertex3f(-.8, 0, 1);
	glVertex3f(-.3, 0, .5);
	glVertex3f(-1.3, 0, 1);
	glVertex3f(-2.3, 0, 2);
	glVertex3f(-.3, 0, 2);
	glVertex3f(-.3, 0, 1);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-2.3, 0, 2);
	glVertex3f(-2.3, -.05, 2);
	glVertex3f(-.3, -.05, 2);
	glVertex3f(-.3, 0, 2);
	glVertex3f(-1.3, 0, 1);
	glVertex3f(-1.3, -.05, 1);
	glVertex3f(-2.3, -.05, 2);
	glVertex3f(-2.3, 0, 2);
	glVertex3f(-.3, 0, 1);
	glVertex3f(-.3, -.05, 1);
	glVertex3f(-1.3, -.05, 1);
	glVertex3f(-1.3, 0, 1);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

  gluDeleteQuadric(quadric);
	
  glUseProgram(0);
	//Increment rotation of wing
	count += .4;
}