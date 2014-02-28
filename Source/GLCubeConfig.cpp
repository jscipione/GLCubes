#include "GLCubeConfig.h"

#include "stdio.h"

#include <CheckBox.h>
#include <Menu.h>
#include <MenuField.h>
#include <MenuItem.h>
#include <Slider.h>
#include <StringView.h>

#include "GLCubes.h"


enum {
		GLC_NUMBER_CUBES	= 'numc',
		GLC_CUBE_SIZE		= 'size',
		GLC_CUBE_SPIN		= 'spin',
		GLC_NOBOUNDS		= 'bnds',
		GLC_WIREFRAME		= 'wire',
		GLC_FOUNTAIN		= 'foun',
		GLC_LIGHTS			= 'lite',
		GLC_COLLISIONS		= 'bang',
		GLC_OPAQUE			= 'glas',
		GLC_SOLID_COLOR		= 'sold',
		GLC_PULSATE			= 'puls',
		GLC_CUBE			= 'cube',
		GLC_PYRAMID			= 'pyra',
		GLC_DIAMOND			= 'diam',
		GLC_GEM				= 'jems',
		GLC_SHAPES			= 'shap'
};


//	#pragma mark - GLCubeConfig


GLCubeConfig::GLCubeConfig(BRect frame, GLCubes* saver_in)
	:	BView(frame, "", B_FOLLOW_NONE, B_WILL_DRAW),
		saver(saver_in)
{
	AddChild(new BStringView(BRect(10, 0, 250, 12), B_EMPTY_STRING,
		"OpenGL Cubes+ v0.9g"));
	AddChild(new BStringView(BRect(14, 0, 250, 26), B_EMPTY_STRING,
		"©1999-2000 Brad Leffler"));
	
	slider = new BSlider(BRect(10,35,240,80), "cubes", "Number of Objects : ",
		new BMessage(GLC_NUMBER_CUBES), 0, 50, B_BLOCK_THUMB);
	slider->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider->SetLimitLabels("0", "50");
	slider->SetValue(saver->numcubes);
	slider->SetHashMarkCount(10);
	AddChild(slider);
	
	rslider = new BSlider(BRect(10,83,240,128), "rotate", "Rotation Speed : ",
		new BMessage(GLC_CUBE_SPIN), 0, 10, B_BLOCK_THUMB);
	rslider->SetHashMarks(B_HASH_MARKS_BOTTOM);
	rslider->SetLimitLabels("0", "10");
	rslider->SetValue(saver->cubespin);
	rslider->SetHashMarkCount(11);
	AddChild(rslider);

	nobounds = new BCheckBox(BRect(10, 160, 100, 175), "nobounds", "No Bounds",
		new BMessage(GLC_NOBOUNDS));
	AddChild(nobounds);
	if (saver->nobounds)
		nobounds->SetValue(B_CONTROL_ON);	

	if (saver->fountain)
		nobounds->SetEnabled(false);

	wireframe = new BCheckBox(BRect(10, 177, 100, 192), "wireframe",
		"Wireframe", new BMessage(GLC_WIREFRAME));
	AddChild(wireframe);
	if(saver->wireframe)
		wireframe->SetValue(B_CONTROL_ON);
		
	fountain = new BCheckBox(BRect(10, 194, 100, 209), "fountain", "Fountain",
		new BMessage(GLC_FOUNTAIN));
	AddChild(fountain);
	if(saver->fountain)
		fountain->SetValue(B_CONTROL_ON);
			
	lights = new BCheckBox(BRect(10, 211, 100, 226), "lights", "Lights",
		new BMessage(GLC_LIGHTS));
	AddChild(lights);

	if (saver->opaque) {
		lights->SetValue(B_CONTROL_ON);
		lights->SetEnabled(false);
	}
	if(saver->lights)
		lights->SetValue(B_CONTROL_ON);
		
	opaque = new BCheckBox(BRect(10, 228, 100, 243), "opaque", "Transparent",
		new BMessage(GLC_OPAQUE));
	AddChild(opaque);
	if (saver->opaque)
		opaque->SetValue(B_CONTROL_ON);

	solidcolor = new BCheckBox(BRect(120, 160, 220, 175), "solidcolor",
		"Solid Colors", new BMessage(GLC_SOLID_COLOR));
	AddChild(solidcolor);
	solidcolor->SetEnabled(false);
	if (saver->solidcolor)
		solidcolor->SetValue(B_CONTROL_ON);

	pulsate = new BCheckBox(BRect(120, 177, 220, 192), "pulsate", "Pulsate",
		new BMessage(GLC_PULSATE));
	AddChild(pulsate);
	if (saver->pulsate)
		pulsate->SetValue(B_CONTROL_ON);

	collisions = new BCheckBox(BRect(120, 194, 220, 209), "collisions",
		"Collisions", new BMessage(GLC_COLLISIONS));
	AddChild(collisions);
	if (saver->collisions)
		collisions->SetValue(B_CONTROL_ON);
	if (saver->fountain)
		collisions->SetEnabled(false);

	menu = new BMenu(" Shapes ");
	BMenuField *shapes = new BMenuField(BRect(10,135,120,155), "SelectPopUp",
		"Shape", menu);
	shapes->SetDivider (35);
	AddChild(shapes);
	menu->SetRadioMode(true);
	menu->SetLabelFromMarked(true);
	cube = new BMenuItem("Cube", new BMessage(GLC_CUBE));
	menu->AddItem(cube);
	pyramid = new BMenuItem("Pyramid", new BMessage(GLC_PYRAMID));
	menu->AddItem(pyramid);
	gem = new BMenuItem("Gem", new BMessage(GLC_GEM));
	menu->AddItem(gem);
	diamond = new BMenuItem("Diamond", new BMessage(GLC_DIAMOND));
	menu->AddItem(diamond);

	if (saver->shape == 0)
		cube->SetMarked(true);
	else if (saver->shape == 1)
		pyramid->SetMarked(true);
	else if (saver->shape == 2)
		gem->SetMarked(true);
	else if (saver->shape == 3)
		diamond->SetMarked(true);
}


void
GLCubeConfig::AttachedToWindow()
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

	slider->SetTarget(this);
	slider->Invoke(new BMessage(GLC_NUMBER_CUBES));
	rslider->SetTarget(this);
	rslider->Invoke(new BMessage(GLC_CUBE_SPIN));
	nobounds->SetTarget(this);
	wireframe->SetTarget(this);
	fountain->SetTarget(this);
	lights->SetTarget(this);
	opaque->SetTarget(this);
	solidcolor->SetTarget(this);
	pulsate->SetTarget(this);
	collisions->SetTarget(this);
	menu->SetTargetForItems(this);
}


void
GLCubeConfig::MessageReceived(BMessage* message)
{	
	char	label[30];
	int32	value;
	
	switch(message->what) {
		case GLC_NUMBER_CUBES:
			value = slider->Value();
			sprintf(label, "Number of Objects: %li", value);
			slider->SetLabel(label);
			saver->numcubes = slider->Value();
			break;			

		case GLC_CUBE_SPIN:
			value = rslider->Value();
			sprintf(label, "Rotation Speed: %li", value);
			rslider->SetLabel(label);
			saver->cubespin = rslider->Value();
			break;

		case GLC_NOBOUNDS:
			if (nobounds->Value() == B_CONTROL_ON)
				saver->nobounds = true;
			else
				saver->nobounds = false;

			break;

		case GLC_WIREFRAME:
			if (wireframe->Value() == B_CONTROL_ON)
				saver->wireframe = true;
			else
				saver->wireframe = false;
			break;

		case GLC_FOUNTAIN:
			if (fountain->Value() == B_CONTROL_ON) {
				nobounds->SetEnabled(false);
				collisions->SetEnabled(false);				
				saver->fountain = true;
			} else {
				saver->fountain = false;
				collisions->SetEnabled(true);
				nobounds->SetEnabled(true);
			}
			break;

		case GLC_LIGHTS:
			if (lights->Value() == B_CONTROL_ON)
				saver->lights = true;
			else
				saver->lights = false;
			break;

		case GLC_OPAQUE:
			if (opaque->Value() == B_CONTROL_ON) {
				saver->opaque = true;
				saver->lights = true;
				lights->SetValue(B_CONTROL_ON);
				lights->SetEnabled(false);
			} else {
				saver->opaque = false;
				lights->SetEnabled(true);
			}
			break;

		case GLC_SOLID_COLOR:
			if (solidcolor->Value() == B_CONTROL_ON)
				saver->solidcolor = true;
			else 
				saver->solidcolor = false;

			break;

		case GLC_PULSATE:
			if (pulsate->Value() == B_CONTROL_ON)
				saver->pulsate = true;
			else 
				saver->pulsate = false;

			break;

		case GLC_COLLISIONS:
			if (collisions->Value() == B_CONTROL_ON)
				saver->collisions = true;
			else 
				saver->collisions = false;

			break;

		case GLC_CUBE:
			saver->shape = 0;
			break;

		case GLC_PYRAMID:
			saver->shape = 1;
			break;

		case GLC_GEM:
			saver->shape = 2;
			break;

		case GLC_DIAMOND:
			saver->shape = 3;
			break;

		default:
			BView::MessageReceived(message);
			break;
	}
}
