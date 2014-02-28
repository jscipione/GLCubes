NAME= GLCubes
TYPE= SHARED
SRCS= Source/GLCubes.cpp Source/GLCubeConfig.cpp Source/GLCubeView.cpp
RSRCS= Resources/GLCubes.rsrc
LIBS= /boot/system/develop/lib/libroot.so /boot/system/develop/lib/libbe.so /boot/system/develop/lib/libGL.so /boot/system/develop/lib/libscreensaver.so /boot/system/develop/lib/libGLU.so
LIBPATHS=
SYSTEM_INCLUDE_PATHS= /boot/system/develop/headers/be /boot/system/develop/headers/cpp /boot/system/develop/headers/posix
LOCAL_INCLUDE_PATHS= Source Resources
OPTIMIZE=NONE
#	specify any preprocessor symbols to be defined.  The symbols will not
#	have their values set automatically; you must supply the value (if any)
#	to use.  For example, setting DEFINES to "DEBUG=1" will cause the
#	compiler option "-DDEBUG=1" to be used.  Setting DEFINES to "DEBUG"
#	would pass "-DDEBUG" on the compiler's command line.
DEFINES=
#	specify special warning levels
#	if unspecified default warnings will be used
#	NONE = supress all warnings
#	ALL = enable all warnings
WARNINGS =
# Build with debugging symbols if set to TRUE
SYMBOLS=
COMPILER_FLAGS=
LINKER_FLAGS=

## include the makefile-engine
include $(BUILDHOME)/etc/makefile-engine
