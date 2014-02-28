#ifndef GL_CUBE_CONFIG_H
#define GL_CUBE_CONFIG_H


#include <View.h>


class BCheckBox;
class BMenu;
class BMenuField;
class BMenuItem;
class BSlider;
class GLCubes;

class GLCubeConfig: public BView {
public:
								GLCubeConfig(BRect frame, GLCubes* saver);

			void				AttachedToWindow();
			void				MessageReceived(BMessage* message);

private:
			GLCubes*			saver;

			uint32				window_flags;

			BSlider*			slider;
			BSlider*			sslider;
			BSlider*			rslider;
			BCheckBox*			nobounds;
			BCheckBox*			wireframe;
			BCheckBox*			fountain;
			BCheckBox*			lights;
			BCheckBox*			opaque;
			BCheckBox*			solidcolor;
			BCheckBox*			pulsate;
			BCheckBox*			collisions;
			BMenuField*			shapes;
			BMenu*				menu;
			BMenuItem*			cube;
			BMenuItem*			pyramid;
			BMenuItem*			gem;
			BMenuItem*			diamond;
};


#endif	// GL_CUBE_CONFIG_H
