bin_PROGRAMS=interp4cmds
interp4cmds_SOURCES = AbstractComChannel.cpp \
                    ComChannel.cpp \
                    Configuration.cpp \
                    Interpreter.cpp \
                    LibInterface.cpp \
                    main.cpp \
                    preprocessor.cpp \
                    Scene.cpp \
                    xmlinterp.cpp 

interp4cmds_CXXFLAGS = -I../inc -I../../../inc -std=c++17
interp4cmds_LDFLAGS = -Wl,-rpath='$(libdir)' ${LIB_DLOPEN} -lxerces-c
