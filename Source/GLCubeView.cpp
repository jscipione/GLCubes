#include "GLCubeView.h"

#include <GL/glu.h>
#include <stdlib.h>

#include "GLCubes.h"


GLfloat red[]    = {1.0, 0.0, 0.0, 1.0};
GLfloat blue[]   = {0.0, 0.0, 1.0, 1.0};
GLfloat green[]  = {0.0, 0.5, 0.0, 1.0};
GLfloat purple[] = {1.0, 0.0, 1.0, 1.0};
GLfloat orange[] = {1.0, 0.6, 0.0, 1.0};
GLfloat yellow[] = {1.0, 1.0, 0.0, 1.0};
GLfloat cyan[]   = {0.0, 0.75, 1.0, 1.0};
GLfloat white[]  = {1.0, 1.0, 1.0, 1.0};


static void
DrawCube(void)
{
	glBegin(GL_QUAD_STRIP);
		glColor3f(0.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
		glNormal3f(+0.0, +1.0, +0.0);
		glVertex3f(+1.0, +1.0, -1.0);
		glVertex3f(-1.0, +1.0, -1.0);
		glVertex3f(+1.0, +1.0, +1.0);
		glVertex3f(-1.0, +1.0, +1.0);

		glColor3f(1.0, 0.6, 0.0 );
		glMaterialfv(GL_FRONT, GL_DIFFUSE, orange);
		glNormal3f(+0.0, +0.0, +1.0);
		glVertex3f(-1.0, +1.0, +1.0);
		glVertex3f(+1.0, +1.0, +1.0);
		glVertex3f(-1.0, -1.0, +1.0);
		glVertex3f(+1.0, -1.0, +1.0);

		glColor3f( 1.0, 0.0, 0.0 );
		glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
		glNormal3f(+0.0, -1.0, +0.0);
		glVertex3f(-1.0, -1.0, +1.0);
		glVertex3f(+1.0, -1.0, +1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(+1.0, -1.0, -1.0);
	glEnd();

	glBegin(GL_QUAD_STRIP);
		glColor3f(1.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
		glNormal3f(-1.0, +0.0, +0.0);
		glVertex3f(-1.0, +1.0, +1.0);
		glVertex3f(-1.0, -1.0, +1.0);
		glVertex3f(-1.0, +1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);

		glColor3f(0.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
		glNormal3f(+0.0, +0.0, -1.0);
		glVertex3f(-1.0, +1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(+1.0, +1.0, -1.0);
		glVertex3f(+1.0, -1.0, -1.0);

		glColor3f(1.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, purple);
		glNormal3f(+1.0, +0.0, +0.0);
		glVertex3f(+1.0, +1.0, -1.0);
		glVertex3f(+1.0, -1.0, -1.0);
		glVertex3f(+1.0, +1.0, +1.0);
		glVertex3f(+1.0, -1.0, +1.0);
	glEnd();
}


static void
DrawPyramid(void)
{
	glBegin(GL_QUADS);
		glColor3f(0.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
		glNormal3f(+0.0, -1.0, +0.0);
		glVertex3f(+1.0, -1.0, +1.0);
		glVertex3f(+1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, +1.0);
	glEnd();

	glBegin( GL_TRIANGLES);
		glColor3f(1.0, 0.6, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, orange);
		glNormal3f(+0.0, +0.0, +1.0);
		glVertex3f(+1.0, -1.0, +1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(-1.0, -1.0, +1.0);

		glColor3f(1.0, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
		glNormal3f(+0.0, +0.0, -1.0);
		glVertex3f(+1.0, -1.0, -1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(-1.0, -1.0, -1.0);

		glColor3f(1.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
		glNormal3f(-1.0, +0.0, +0.0);
		glVertex3f(-1.0, -1.0, +1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(-1.0, -1.0, -1.0);

		glColor3f(0.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
		glNormal3f(+1.0, +0.0, +0.0);
		glVertex3f(+1.0, -1.0, -1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(+1.0, -1.0, +1.0);
	glEnd();
}


static void
DrawJem(void)
{
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
		glNormal3f(+0.0, +0.0, +1.0);
		glVertex3f(+1.0, +0.0, +1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(-1.0, +0.0, +1.0);

		glColor3f(1.0, 0.6, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, orange);
		glNormal3f(+0.0, +0.0, -1.0);
		glVertex3f(+1.0, +0.0, -1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(-1.0, +0.0, -1.0);

		glColor3f( 0.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
		glNormal3f(-1.0, +0.0, +0.0);
		glVertex3f(-1.0, +0.0, +1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(-1.0, +0.0, -1.0);

		glColor3f(1.0, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
		glNormal3f(+1.0, +0.0, +0.0);
		glVertex3f(+1.0, +0.0, -1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(+1.0, +0.0, +1.0);

		glColor3f( 0.0, 1.0, 0.0 );
		glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
		glNormal3f(+0.0, +0.0, +1.0);
		glVertex3f(+1.0, +0.0, +1.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(-1.0, +0.0, +1.0);

		glColor3f(0.0, 0.75, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
		glNormal3f(+0.0, +0.0, -1.0);
		glVertex3f(+1.0, +0.0, -1.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(-1.0, +0.0, -1.0);

		glColor3f(1.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
		glNormal3f(-1.0, +0.0, +0.0);
		glVertex3f(-1.0, +0.0, +1.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(-1.0, +0.0, -1.0);

		glColor3f(1.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, purple);
		glNormal3f(+1.0, +0.0, +0.0);
		glVertex3f(+1.0, +0.0, -1.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(+1.0, +0.0, +1.0);
	glEnd();
}


static void
DrawDiamond(void)
{
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
		glNormal3f(+1.0, +0.0, +0.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(+1.0, +0.5, -0.5);
		glVertex3f(+1.0, +0.5, +0.5);

		glColor3f(1.0, 0.6, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, orange);
		glNormal3f(+1.0, +0.0, -1.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(+1.0, +0.5, -0.5);
		glVertex3f(+0.5, +0.5, -1.0);

		glColor3f(0.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
		glNormal3f(+0.0, +0.0, -1.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(+0.5, +0.5, -1.0);
		glVertex3f(-0.5, +0.5, -1.0);

		glColor3f(1.0, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
		glNormal3f(-1.0, +0.0, -1.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(-0.5, +0.5, -1.0);
		glVertex3f(-1.0, +0.5, -0.5);

		glColor3f(0.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
		glNormal3f(-1.0, +0.0, +0.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(-1.0, +0.5, -0.5);
		glVertex3f(-1.0, +0.5, +0.5);

		glColor3f(0.0, 0.75, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
		glNormal3f(-1.0, +0.0, +1.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(-1.0, +0.5, +0.5);
		glVertex3f(-0.5, +0.5, +1.0);

		glColor3f(1.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
		glNormal3f(+0.0, +0.0, +1.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(-0.5, +0.5, +1.0);
		glVertex3f(+0.5, +0.5, +1.0);

		glColor3f(1.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, purple);
		glNormal3f(+1.0, +0.0, +1.0);
		glVertex3f(+0.0, -1.0, +0.0);
		glVertex3f(+0.5, +0.5, +1.0);
		glVertex3f(+1.0, +0.5, +0.5);

		glColor3f(0.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
		glNormal3f(+1.0, +0.0, +0.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(+1.0, +0.5, -0.5);
		glVertex3f(+1.0, +0.5, +0.5);

		glColor3f(0.0, 0.75, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
		glNormal3f(+1.0, +0.0, -1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(+1.0, +0.5, -0.5);
		glVertex3f(+0.5, +0.5, -1.0);

		glColor3f(1.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
		glNormal3f(+0.0, +0.0, -1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(+0.5, +0.5, -1.0);
		glVertex3f(-0.5, +0.5, -1.0);

		glColor3f(1.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, purple);
		glNormal3f(-1.0, +0.0, -1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(-0.5, +0.5, -1.0);
		glVertex3f(-1.0, +0.5, -0.5);

		glColor3f(1.0, 1.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
		glNormal3f(-1.0, +0.0, +0.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(-1.0, +0.5, -0.5);
		glVertex3f(-1.0, +0.5, +0.5);

		glColor3f(1.0, 0.6, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, orange);
		glNormal3f(-1.0, +0.0, +1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(-1.0, +0.5, +0.5);
		glVertex3f(-0.5, +0.5, +1.0);

		glColor3f(0.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
		glNormal3f(+0.0, +0.0, +1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(-0.5, +0.5, +1.0);
		glVertex3f(+0.5, +0.5, +1.0);

		glColor3f(1.0, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
		glNormal3f(+1.0, +0.0, +1.0);
		glVertex3f(+0.0, +1.0, +0.0);
		glVertex3f(+0.5, +0.5, +1.0);
		glVertex3f(+1.0, +0.5, +0.5);
	glEnd();
}


//	#pragma mark - GLCubeView


GLCubeView::GLCubeView(BRect frame, const char* name, ulong resizingMode,
	ulong options, GLCubes* saver_in)
	:
	BGLView(frame, name, resizingMode, 0, options),
	saver(saver_in)
{
	GLfloat light_ambient[] = {0.5, 0.5, 0.5, 1.0};

	GLfloat	light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat light_position[] = { 0.0, 0.0, 5.0 };

	GLfloat light1_diffuse[]  = {  1.0,  1.0, 1.0, 1.0 };
	GLfloat light1_position[] = { 0.0, 0.0, -2.0 };

	GLfloat material_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat material_shininess[] = {60.0};

	for (int i = 0; i < saver->numcubes; i++) {
		if (!saver->fountain) {
			xpos[i] = (rand() % 50) - 25;
			ypos[i] = (rand() % 38) - 19;
		} else {
			xpos[i] = 30.0;
			ypos[i] = 30.0;
		}
		xdir[i] = ((rand() % 20) - 10) * 0.1;
		ydir[i] = ((rand() % 20) - 10) * 0.1;
		xrot[i] = rand() % 359;
		yrot[i] = rand() % 359;
		scale[i] = ((rand() % 19) + 1) * 0.01;
		if (saver->pulsate)
			size[i] = (((rand() % 20) + 10) / 2) * 0.1;
		else
			size[i] = 1.0;
	}

	LockGL();
	if (saver->lights) {
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

		glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glEnable(GL_LIGHT0);

		glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
		glEnable(GL_LIGHT1);

		glEnable(GL_LIGHTING);
	}

	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	if (saver->opaque) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	}

	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, frame.Width() / frame.Height(), 2.0, 20000.0);
	glTranslatef(0.0, 0.0, -50.0);
	glMatrixMode(GL_MODELVIEW);

	if (saver->wireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
    	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	UnlockGL();
}


void
GLCubeView::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < saver->numcubes; i++) {
		glPushMatrix();

		glTranslatef(xpos[i], ypos[i], 0.0);
		glRotatef(xrot[i] * 2, 1.0, 0.0, 0.0 );
		glRotatef(yrot[i] * 5, 0.0, 0.0, 1.0 );
		glRotatef(xrot[i], 0.0, 1.0, 0.0 );	

		if (saver->pulsate) {	
			size[i] += scale[i];
			if (size[i] >= 1.5)
				scale[i] *= -1;

			if (size[i] <= 0.5)
				scale[i] *= -1;
		}

		glScalef(size[i], size[i], size[i]);

		if (saver->shape == 0)
			DrawCube();
		else if (saver->shape == 1)
			DrawPyramid();
		else if (saver->shape == 2)
			DrawJem();
		else if (saver->shape == 3)
			DrawDiamond();

		glPopMatrix();
	}
}


void
GLCubeView::Advance()
{
	double dx;
	double dy;
	double distance;
	double r = 1.3;
	int j = 0;

	if (!saver->fountain) {
		// normal cube updates
		for (int i = 0; i < saver->numcubes; i++) {
			if (saver->nobounds) {
				if ((xpos[i] > 29.0) || (xpos[i] < -29.0))
					xpos[i] *= -1.0;

				xpos[i] += xdir[i];
			
				if ((ypos[i] > 22.0) || (ypos[i] < -22.0))
					ypos[i] *= -1.0;

				ypos[i] += ydir[i];
			} else {
				if ((xpos[i] > 25.0) || (xpos[i] < -25.0))
					xdir[i] *= -1.0;

				xpos[i] += xdir[i];
			
				if ((ypos[i] > 19.0) || (ypos[i] < -19.0))
					ydir[i] *= -1.0;

				ypos[i] += ydir[i];
			}
			
			// begin collisions
			if (saver->collisions) {
				for (j = 0; j < saver->numcubes; j++) {
					if (i != j) {
						dx = xpos[i] - xpos[j];
						dy = ypos[i] - ypos[j];
						dx = fabs(dx);
						dy = fabs(dy);
						if (dx < 2.0 && dy < 2.0) {
							dx *= dx;
							dy *= dx;
							distance = sqrt(dx+dy);
							if (r > (distance / 2)) {
								if (dx > dy) {
									xdir[i] *= -1.0;
									xdir[j] *= -1.0;
								} else {
									ydir[i] *= -1.0;
									ydir[j] *= -1.0;
								}
							}	
						}
					}
				}
			}			
			// end collisions

			xrot[i] += saver->cubespin;
			if (xrot[i] > 360.0)
				xrot[i] -= 360.0;
			
			yrot[i] += saver->cubespin;
			if (yrot[i] > 360.0)
				yrot[i] -= 360.0;
		}
	} else {
		// fountain cube updates
		for (int i = 0; i < saver->numcubes; i++) {
			if (i < j) {
				if ((xpos[i] > 29.0) || (xpos[i] < -29.0) || (ypos[i] > 22.0)
					|| (ypos[i] < -22.0)) {
					xpos[i] = 0.0;
					ypos[i] = 0.0;
					xdir[i] = (((rand() % 18) - 9) + 0.5) * 0.1;
					ydir[i] = (((rand() % 18) - 9) + 0.5) * 0.1;
				}

				xpos[i] += xdir[i];
				ypos[i] += ydir[i];

				xrot[i] += saver->cubespin;

				if (xrot[i] > 360.0)
					xrot[i] -= 360.0;

				yrot[i] += saver->cubespin;

				if (yrot[i] > 360.0)
					yrot[i] -= 360.0;
			}
		}
		if (j < saver->numcubes)
			j++;			
	}

	LockGL();
	Draw();
	SwapBuffers();
	UnlockGL();
}
