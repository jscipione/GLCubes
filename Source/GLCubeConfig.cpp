#include "GLCubeConfig.h"

#include "stdio.h"

#include <CheckBox.h>
#include <LayoutBuilder.h>
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
	:
	BView(frame, B_EMPTY_STRING, B_FOLLOW_NONE, B_WILL_DRAW),
	saver(saver_in),
	fTitleLine1(new BStringView(B_EMPTY_STRING,
		"OpenGL Cubes+ v0.9g")),
	fTitleLine2(new BStringView(B_EMPTY_STRING,
		"©1999-2000 Brad Leffler")),
	fNumberOfObjectsSlider(new BSlider("cubes", "Number of Objects : ",
		new BMessage(GLC_NUMBER_CUBES), 0, 50, B_HORIZONTAL)),
	fRotationSpeedSlider(new BSlider("rotate", "Rotation Speed : ",
		new BMessage(GLC_CUBE_SPIN), 0, 10, B_HORIZONTAL)),

	menu(new BMenu("Shapes")),
	shapes(new BMenuField("SelectPopUp", "Shape:", menu)),

	cube(new BMenuItem("Cube", new BMessage(GLC_CUBE))),
	pyramid(new BMenuItem("Pyramid", new BMessage(GLC_PYRAMID))),
	gem(new BMenuItem("Gem", new BMessage(GLC_GEM))),
	diamond(new BMenuItem("Diamond", new BMessage(GLC_DIAMOND))),

	nobounds(new BCheckBox("nobounds", "No Bounds",
		new BMessage(GLC_NOBOUNDS))),
	wireframe(new BCheckBox("wireframe", "Wireframe",
		new BMessage(GLC_WIREFRAME))),
	fountain(new BCheckBox("fountain", "Fountain",
		new BMessage(GLC_FOUNTAIN))),
	lights(new BCheckBox("lights", "Lights", new BMessage(GLC_LIGHTS))),
	opaque(new BCheckBox("opaque", "Transparent", new BMessage(GLC_OPAQUE))),
	solidcolor(new BCheckBox("solidcolor", "Solid Colors",
		new BMessage(GLC_SOLID_COLOR))),
	pulsate(new BCheckBox("pulsate", "Pulsate", new BMessage(GLC_PULSATE))),
	collisions(new BCheckBox("collisions", "Collisions",
		new BMessage(GLC_COLLISIONS)))
{
	fNumberOfObjectsSlider->SetHashMarks(B_HASH_MARKS_BOTTOM);
	fNumberOfObjectsSlider->SetLimitLabels("0", "50");
	fNumberOfObjectsSlider->SetValue(saver->numcubes);
	fNumberOfObjectsSlider->SetHashMarkCount(10);

	fRotationSpeedSlider->SetHashMarks(B_HASH_MARKS_BOTTOM);
	fRotationSpeedSlider->SetLimitLabels("0", "10");
	fRotationSpeedSlider->SetValue(saver->cubespin);
	fRotationSpeedSlider->SetHashMarkCount(11);

	menu->SetRadioMode(true);
	menu->SetLabelFromMarked(true);
	menu->AddItem(cube);
	menu->AddItem(pyramid);
	menu->AddItem(gem);
	menu->AddItem(diamond);

	if (saver->shape == 0)
		cube->SetMarked(true);
	else if (saver->shape == 1)
		pyramid->SetMarked(true);
	else if (saver->shape == 2)
		gem->SetMarked(true);
	else if (saver->shape == 3)
		diamond->SetMarked(true);

	if (saver->nobounds)
		nobounds->SetValue(B_CONTROL_ON);

	if (saver->fountain)
		nobounds->SetEnabled(false);

	if (saver->wireframe)
		wireframe->SetValue(B_CONTROL_ON);

	if(saver->fountain)
		fountain->SetValue(B_CONTROL_ON);

	if (saver->opaque) {
		lights->SetValue(B_CONTROL_ON);
		lights->SetEnabled(false);
	}

	if(saver->lights)
		lights->SetValue(B_CONTROL_ON);

	if (saver->opaque)
		opaque->SetValue(B_CONTROL_ON);

	solidcolor->SetEnabled(false);
	if (saver->solidcolor)
		solidcolor->SetValue(B_CONTROL_ON);

	if (saver->pulsate)
		pulsate->SetValue(B_CONTROL_ON);

	if (saver->collisions)
		collisions->SetValue(B_CONTROL_ON);

	if (saver->fountain)
		collisions->SetEnabled(false);

	BLayoutBuilder::Group<>(this, B_VERTICAL, 0)
		.Add(fTitleLine1)
		.Add(fTitleLine2)
		.AddStrut(B_USE_DEFAULT_SPACING)
		.Add(fNumberOfObjectsSlider)
		.AddStrut(B_USE_SMALL_SPACING)
		.Add(fRotationSpeedSlider)
		.AddStrut(B_USE_SMALL_SPACING)
		.AddGroup(B_HORIZONTAL, B_USE_SMALL_SPACING)
			.Add(shapes->CreateLabelLayoutItem())
			.Add(shapes->CreateMenuBarLayoutItem())
			.End()
		.AddStrut(B_USE_SMALL_SPACING)
		.AddGrid(B_USE_DEFAULT_SPACING, 0)
			.Add(nobounds, 0, 0).Add(solidcolor, 1, 0)
			.Add(wireframe, 0, 1).Add(pulsate, 1, 1)
			.Add(fountain, 0, 2).Add(collisions, 1, 2)
			.Add(lights, 0, 3).Add(opaque, 1, 3)
			.End()
		.SetInsets(B_USE_DEFAULT_SPACING)
		.End();
}


void
GLCubeConfig::AttachedToWindow()
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

	fNumberOfObjectsSlider->SetTarget(this);
	fNumberOfObjectsSlider->Invoke(new BMessage(GLC_NUMBER_CUBES));
	fRotationSpeedSlider->SetTarget(this);
	fRotationSpeedSlider->Invoke(new BMessage(GLC_CUBE_SPIN));
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
			value = fNumberOfObjectsSlider->Value();
			sprintf(label, "Number of Objects: %li", value);
			fNumberOfObjectsSlider->SetLabel(label);
			saver->numcubes = fNumberOfObjectsSlider->Value();
			break;			

		case GLC_CUBE_SPIN:
			value = fRotationSpeedSlider->Value();
			sprintf(label, "Rotation Speed: %li", value);
			fRotationSpeedSlider->SetLabel(label);
			saver->cubespin = fRotationSpeedSlider->Value();
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
