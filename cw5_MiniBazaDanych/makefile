#katalog plikow .o
ODIR = obj

#katalog plikow cpp
CPPDIR = source

#lokalizacja plikow *.o
OBJECTSDIR = $(ODIR)\main.o $(ODIR)\human_class.o $(ODIR)\mainMenu_handler.o $(ODIR)\miniDatabase_class.o

#headers dir
HEADERSDIR = headers

#g++ compiler flags
CppFlags = -Wall -g -c -I$(HEADERSDIR) 

$(CPPDIR)\main.exe: $(OBJECTSDIR)
	@g++ -o main.exe $(OBJECTSDIR)
	@echo "Komipilacja zakonczona"

$(ODIR)\main.o: $(CPPDIR)\main.cpp $(HEADERSDIR)\miniDatabase_class.hpp $(HEADERSDIR)\mainMenu_handler.hpp
	@g++ $(CppFlags) $(CPPDIR)\main.cpp -o $(ODIR)\main.o
	@echo "compiled main.o"

$(ODIR)\human_class.o: $(CPPDIR)\human_class.cpp $(HEADERSDIR)\human_class.hpp
	@g++ $(CppFlags) $(CPPDIR)\human_class.cpp -o $(ODIR)\human_class.o
	@echo "compiled human_class.o"
	
$(ODIR)\mainMenu_handler.o: $(CPPDIR)\mainMenu_handler.cpp $(HEADERSDIR)\mainMenu_handler.hpp $(HEADERSDIR)\miniDatabase_class.hpp
	@g++ $(CppFlags) $(CPPDIR)\mainMenu_handler.cpp -o $(ODIR)\mainMenu_handler.o
	@echo "compiled mainMenu_handler.o"
	
$(ODIR)\miniDatabase_class.o: $(CPPDIR)\miniDatabase_class.cpp $(HEADERSDIR)\miniDatabase_class.hpp $(HEADERSDIR)\human_class.hpp
	@g++ $(CppFlags) $(CPPDIR)\miniDatabase_class.cpp -o $(ODIR)\miniDatabase_class.o
	@echo "compiled miniDatabase_class.o"

	
.PHONY: clean
clean:
	-rm $(ODIR)