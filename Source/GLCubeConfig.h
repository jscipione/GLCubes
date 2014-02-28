#ifndef GL_CUBE_CONFIG_H
#define GL_CUBE_CONFIG_H


#include <View.h>


class BCheckBox;
class BMenu;
class BMenuField;
class BMenuItem;
class BSlider;
class BStringView;
class GLCubes;

class GLCubeConfig: public BView {
public:
								GLCubeConfig(BRect frame, GLCubes* saver);

			void				AttachedToWindow();
			void				MessageReceived(BMessage* message);

private:
			GLCubes*			saver;

			BStringView*		fTitleLine1;
			BStringView*		fTitleLine2;

			BSlider*			fNumberOfObjectsSlider;
			BSlider*			fRotationSpeedSlider;

			BMenu*				menu;
			BMenuField*			shapes;
			BMenuItem*			cube;
			BMenuItem*			pyramid;
			BMenuItem*			gem;
			BMenuItem*			diamond;

			BCheckBox*			nobounds;
			BCheckBox*			wireframe;
			BCheckBox*			fountain;
			BCheckBox*			lights;
			BCheckBox*			opaque;
			BCheckBox*			solidcolor;
			BCheckBox*			pulsate;
			BCheckBox*			collisions;
};


#endif	// GL_CUBE_CONFIG_H
