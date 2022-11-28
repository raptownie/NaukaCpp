#katalog plikow .o
ODIR = obj

#katalog plikow cpp
CPPDIR = source

#lokalizacja plikow *.o
OBJECTSDIR = $(ODIR)\main.o $(ODIR)\czlowiek.o $(ODIR)\menuMiniBase.o $(ODIR)\minibaza.o

#headers dir
HEADERSDIR = headers

#g++ compiler flags
CppFlags = -Wall -g -c -I$(HEADERSDIR) 

$(CPPDIR)\main.exe: $(OBJECTSDIR)
	@g++ -o main.exe $(OBJECTSDIR)
	@echo "Komipilacja zakonczona"

$(ODIR)\main.o: $(CPPDIR)\main.cpp $(HEADERSDIR)\minibaza.hpp
	@g++ $(CppFlags) $(CPPDIR)\main.cpp -o $(ODIR)\main.o
	@echo "compiled main.o"

$(ODIR)\czlowiek.o: $(CPPDIR)\czlowiek.cpp $(HEADERSDIR)\czlowiek.hpp
	@g++ $(CppFlags) $(CPPDIR)\czlowiek.cpp -o $(ODIR)\czlowiek.o
	@echo "compiled czlowiek.o"
	
$(ODIR)\menuMiniBase.o: $(CPPDIR)\menuMiniBase.cpp $(HEADERSDIR)\menuMiniBase.hpp
	@g++ $(CppFlags) $(CPPDIR)\menuMiniBase.cpp -o $(ODIR)\menuMiniBase.o
	@echo "compiled menuMiniBase.o"
	
$(ODIR)\minibaza.o: $(CPPDIR)\minibaza.cpp $(HEADERSDIR)\minibaza.hpp $(HEADERSDIR)\menuMiniBase.hpp $(HEADERSDIR)\czlowiek.hpp
	@g++ $(CppFlags) $(CPPDIR)\minibaza.cpp -o $(ODIR)\minibaza.o
	@echo "compiled minibaza.o"

	
.PHONY: clean
clean:
	-rm $(ODIR)