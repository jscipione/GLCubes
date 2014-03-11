#include "GLCubes.h"

#include <GL/glu.h>
#include <stdlib.h>

#include <Message.h>
#include <Rect.h>
#include <View.h>

#include "GLCubeConfig.h"
#include "GLCubeView.h"


//	#pragma mark - Instantiation function


extern "C" _EXPORT BScreenSaver* instantiate_screen_saver(BMessage* message,
	image_id image)
{
	return new GLCubes(message, image);
}


//	#pragma mark - GLCubes


GLCubes::GLCubes(BMessage* prefs, image_id image)
	:
	BScreenSaver(prefs, image),
	numcubes(25),
	cubesize(1.0),
	cubespin(1),
	nobounds(0),
	wireframe(0),
	fountain(0),
	lights(0),
	opaque(0),
	solidcolor(0),
	pulsate(0),
	collisions(0),
	shape(0)
{
	// check for preferences
	if (!prefs->IsEmpty())
		restore_state(prefs);

	srandom(system_time());
}


status_t
GLCubes::SaveState(BMessage* prefs) const
{
	// save preferences: cubes, rotation and other attributes
	prefs->AddInt32("nofcubes", numcubes);
	prefs->AddFloat("sofcubes", cubesize);
	prefs->AddInt32("rofspin", cubespin);
	prefs->AddBool("nobounds", nobounds);
	prefs->AddBool("wireframe", wireframe);
	prefs->AddBool("fountain", fountain);
	prefs->AddBool("lights", lights);
	prefs->AddBool("opaque", opaque);
	prefs->AddBool("solidcolor", solidcolor);
	prefs->AddBool("pulsate", pulsate);
	prefs->AddBool("collisions", collisions);
	prefs->AddInt32("shape", shape);

	return B_OK;
}


void
GLCubes::restore_state(BMessage* prefs)
{
	// retrieve preferences and compare them for accuracy
	int32 numcubes_temp;
	int32 cubespin_temp;
	int32 shape_temp; 
	float cubesize_temp;
	bool nobounds_temp;
	bool wireframe_temp;
	bool fountain_temp;
	bool lights_temp;
	bool opaque_temp;
	bool solidcolor_temp;
	bool pulsate_temp;
	bool collisions_temp;

	if (prefs->FindInt32("nofcubes", &numcubes_temp) == B_OK)
		numcubes = numcubes_temp;

	if (prefs->FindFloat("sofcubes", &cubesize_temp) == B_OK)
		cubesize = cubesize_temp;

	if (prefs->FindInt32("rofspin", &cubespin_temp) == B_OK)
		cubespin = cubespin_temp;

	if (prefs->FindBool("nobounds", &nobounds_temp) == B_OK)
		nobounds = nobounds_temp;

	if (prefs->FindBool("wireframe", &wireframe_temp) == B_OK)
		wireframe = wireframe_temp;

	if (prefs->FindBool("fountain", &fountain_temp) == B_OK)
		fountain = fountain_temp;

	if (prefs->FindBool("lights", &lights_temp) == B_OK)
		lights = lights_temp;

	if (prefs->FindBool("opaque", &opaque_temp) == B_OK)
		opaque = opaque_temp;

	if (prefs->FindBool("solidcolor", &solidcolor_temp) == B_OK)
		solidcolor = solidcolor_temp;

	if (prefs->FindBool("pulsate", &pulsate_temp) == B_OK)
		pulsate = pulsate_temp;

	if (prefs->FindBool("collisions", &collisions_temp) == B_OK)
		collisions = collisions_temp;

	if (prefs->FindInt32("shape", &shape_temp) == B_OK)
		shape = shape_temp;
}


void
GLCubes::StartConfig(BView* view)
{
	BRect bounds = view->Bounds();
	GLCubeConfig* setup = new GLCubeConfig(bounds, this);
	view->AddChild(setup);
}


status_t
GLCubes::StartSaver(BView* view, bool preview)
{
	if (preview) {
		viewport = 0;
		return B_ERROR;
	} else {
		SetTickSize(50000);

		viewport = new GLCubeView(view->Bounds(), "objectView",
			B_FOLLOW_NONE, BGL_RGB | BGL_DEPTH | BGL_DOUBLE, this);
		view->AddChild(viewport);

		return B_OK;
	}
}


void
GLCubes::StopSaver()
{
	if (viewport != NULL)
		viewport->EnableDirectMode(false);
}


void
GLCubes::DirectConnected(direct_buffer_info* info)
{
	if (viewport != NULL) {
		viewport->DirectConnected(info);
		viewport->EnableDirectMode(true);
	}
}


void
GLCubes::DirectDraw(int32 frame)
{
	viewport->Advance();
}
