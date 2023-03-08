object_files:=obj/main.o obj/color.o obj/window.o obj/drawing.o obj/fractalMath.o
compiler_flags:=-Wall -O3

mandelbrot_linux:$(object_files)
	g++ -o mandelbrot_linux $(object_files) `sdl2-config --cflags --libs` $(compiler_flags)

obj/main.o: main.cxx 
	g++ -o obj/main.o main.cxx -c $(compiler_flags)

obj/color.o: color.cxx color.hxx
	g++ -o obj/color.o color.cxx -c $(compiler_flags)

obj/window.o: window.cxx window.hxx
	g++ -o obj/window.o window.cxx -c $(compiler_flags)

obj/drawing.o: drawing.cxx drawing.hxx
	g++ -o obj/drawing.o drawing.cxx -c $(compiler_flags)

obj/fractalMath.o: fractalMath.cxx fractalMath.hxx
	g++ -o obj/fractalMath.o fractalMath.cxx -c $(compiler_flags)

clean:
	rm $(object_files)