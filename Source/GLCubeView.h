#ifndef GL_CUBE_VIEW_H
#define GL_CUBE_VIEW_H


#include <GLView.h>


class BBitmap;
class GLCubes;

class GLCubeView: public BGLView {
public:
								GLCubeView(BRect frame, const char* name,
									ulong resizingMode, ulong options,
									GLCubes* saver);

	virtual	void				Draw();
	virtual	void				Advance();

			GLfloat				xpos[51];
			GLfloat				ypos[51];
			GLfloat				xdir[51];
			GLfloat				ydir[51];
			GLfloat				xrot[51];
			GLfloat				yrot[51];
			GLfloat				size[51];

private:
			GLCubes*			saver;
		
			int					j;
			float				scale[51];
			GLint				numcubes;
			float				cubesize;
			GLint				cubespin;	
			bool				nobounds;
			bool				wireframe;
		
			BBitmap*			texture_bits;
};


#endif	// GL_CUBE_VIEW_H
