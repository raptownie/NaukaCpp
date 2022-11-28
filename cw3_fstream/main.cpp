#include <iostream>
#include <fstream>

int main (void)
{
    std::fstream MyFile;
    MyFile.open("test.txt", std::ios::out | std::ios::trunc);

    if(MyFile.fail() == true)
    {
        std::cout << "cos poszlo nie tak" << std::endl;
    }
    else
    {
        int M=0;
        std::cout << "Podaj M = ";
        std::cin >> M;
        std::cout << "plik zostal otworzony" << std::endl;
        for(int i = 0; i < M; i++){
            MyFile << (i*i) << std::endl;
        }
    }

    std::streampos siezeOfFile = MyFile.tellg();
    std::cout << "rozmiar pliku " << siezeOfFile << std::endl;
    MyFile.close();

    std::fstream FileToRead;
    std::fstream FileToPaste;
    std::string buffer;
    FileToRead.open("test.txt", std::ios::in);
    FileToPaste.open("ToPaste.txt", std::ios::out | std::ios::trunc);
    if (FileToRead.fail() == true || FileToPaste.fail() == true)
    {
        std::cout << "cos poszlo nie tak" << std::endl;
    }
    else
    {
        std::cout << "Pliki zostal otworzony poprawnie" << std::endl;
        if (FileToPaste.is_open() && FileToRead.is_open()){
            std::cout << "pliki zostaly otworzone!" << std::endl;
        }
        while (std::getline(FileToRead, buffer))
        {
            FileToPaste << buffer << std::endl;
        }
        std::cout << "Copy Finished!" << std::endl;
        /*
        do{
            FileToRead >> buffer;
            std::cout << buffer << std::endl;
        }while (FileToRead.eof() == false);
        */
    }
    /*--------------------------------------------------------------*/
    /*TODO: */
    /*FIXME: */
    std::fstream Notebook;
    Notebook.open("Notebook.txt", std::ios::out | std::ios::trunc);
    std::cout << "Pisanie w roznych miejscach, start!" << std::endl;

    if (Notebook.fail() == true)
    {
        std::cout << "plik nie został otworzony" << std::endl;
    }
    else
    {
        if (Notebook.is_open() == true){
            std::cout << "plik zostal poprawnie otworzony" << std::endl;
        }
        std::streampos SizeOfNotebok = Notebook.tellg();
        int MiejsceDoPisania = 0;
        std::string bufferNotebook;
        int PiszemyDalej = 1;
        std::cout << "Rozmar na starcie " << SizeOfNotebok << std::endl;
        while (PiszemyDalej != 0)
        {
            std::cout << "W ktorym miejscu chcesz pisac? ";
            std::cin >> MiejsceDoPisania;
            Notebook.seekg(MiejsceDoPisania);
            std::cout << "\nPisz ! : ";
            std::cin >> bufferNotebook;
            Notebook << bufferNotebook; 
            std::cout << "Piszemy? 1/0 : "; 
            std::cin >> PiszemyDalej;
        }
    }


    return 0;
}


