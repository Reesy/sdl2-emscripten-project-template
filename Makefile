
all:
	g++ src/main.cpp -o example_app_2.exe -DSFML_STATIC -I \
	./external_resources/SFML/include -L \
	./external_resources/SFML/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 \
	./external_resources/SFML/extlibs/libs-mingw/x86/libfreetype.a \
	./external_resources/SFML/extlibs/libs-mingw/x86/libjpeg.a \
	-Wl,-subsystem,windows -static