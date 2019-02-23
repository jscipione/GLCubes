#ifndef GL_CUBES_H
#define GL_CUBES_H


#include <ScreenSaver.h>


class GLCubeView;

class GLCubes: public BScreenSaver {
public:
								GLCubes(BMessage* message, image_id image);

			status_t			SaveState(BMessage* prefs) const;
			void				restore_state(BMessage* prefs);

			void				StartConfig(BView* view);

			status_t			StartSaver(BView* view, bool preview);
			void				StopSaver();
			void				DirectConnected(direct_buffer_info* info);
			void				DirectDraw(int32 frame);

private:
	friend class GLCubeConfig;
	friend class GLCubeView;

			GLCubeView*			viewport;

			int32				numcubes;
			float				cubesize;
			int32				cubespin;
			bool				nobounds;
			bool				wireframe;
			bool				fountain;
			bool				lights;
			bool				opaque;
			bool				solidcolor;
			bool				pulsate;
			bool				collisions;
			int32				shape;
};


#endif	// GL_CUBES_H
