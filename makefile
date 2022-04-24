#lista obiektow
OBJECTS = main.o converter.o

#katalog plikow .o
ODIR = obj

#lokalizacja plikow *.o
OBJECTSDIR = $(ODIR)\main.o $(ODIR)\converter.o $(ODIR)\daneCzlowieka.o $(ODIR)\Klasy.o

CppFlags = -Wall -g -c

main.exe: $(OBJECTSDIR)
	g++ -o main.exe $(OBJECTSDIR)
	echo "Komipilacja zakonczona"

$(ODIR)\main.o: main.cpp headers\main.hpp headers\converter.hpp headers\daneCzlowieka.hpp headers\Klasy.hpp
	g++ $(CppFlags) main.cpp -o $(ODIR)\main.o
	echo "compiled main.o"

$(ODIR)\converter.o: cfiles\converter.cpp headers\converter.hpp
	g++ $(CppFlags) cfiles\converter.cpp -o $(ODIR)\converter.o
	echo "compiled converter.o"
	
$(ODIR)\daneCzlowieka.o: cfiles\daneCzlowieka.cpp headers\daneCzlowieka.hpp
	g++ $(CppFlags) cfiles\daneCzlowieka.cpp -o $(ODIR)\daneCzlowieka.o
	echo "compiled daneCzlowieka.o"
	
$(ODIR)\Klasy.o: cfiles\Klasy.cpp headers\Klasy.hpp
	g++ $(CppFlags) cfiles\Klasy.cpp -o $(ODIR)\Klasy.o
	echo "compiled Klasy.o"
	
.PHONY: clean
clean:
	-rm $(ODIR)