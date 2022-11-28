#include <iostream>
#include <fstream>
#include <string.h>


bool FilesAreEqueal (std::fstream *, std::fstream *);
int SizeOfFile (std::fstream *);
bool DataBlocksAreEqual (char *, char *, int);


/* program porownuje ze soba dwa pliki */
int main (int argc, char *argv[])
{
    if (argc != 3)
    {
        #ifdef _DEBUG_SW
        std::cout << "Niewlasciwa ilosc parametrow : " << (argc-1) << std::endl;
        #endif
        return -1;
    }
    int tReturn = 0;
    const char * filename1 = argv[1];
    const char * filename2 = argv[2];
    std::fstream file1 , file2;
    std::cout << filename1 << std::endl;
    std::cout << filename2 << std::endl;
    
    file1.open(filename1, std::ios::binary | std::ios::in);
    file2.open(filename2, std::ios::binary | std::ios::in);

    if (file1.is_open() && file2.is_open())
    {
        if (FilesAreEqueal(&file1, &file2) == true)
        {
            #ifdef _DEBUG_SW
            std::cout << "pliki sa takie same! " << std::endl;
            #endif
            tReturn = 1;
        }
        else
        {
            #ifdef _DEBUG_SW
            std::cout << "pliki sa rozne! " <<std::endl;
            #endif
            tReturn = 0;
        }
    }
    else
    {
        #ifdef _DEBUG_SW
        std::cout << "nie mozna otworzyc plikow! " << std::endl;
        #endif
        tReturn = -2;
    }

    /* Log result */
    std::fstream resultFile;
    resultFile.open("result.txt", std::ios::out | std:: ios::trunc);
    if (resultFile.is_open())
    {
        if ( tReturn < 0 )
        {
            resultFile << "Error code = " << tReturn;
        }
        else
        {
            resultFile << tReturn;
        }
    }

    return tReturn;
}

bool FilesAreEqueal(std::fstream * A, std::fstream * B)
{
    int sizeOfA = SizeOfFile(A);
    int sizeOfB = SizeOfFile(B);
    #ifdef _DEBUG_SW
    std::cout << "Rozmiar pliku A = " << sizeOfA << " Rozmiar pliku B = " << sizeOfB << std::endl;
    #endif
    bool tReturn = false;
    if ( sizeOfA == sizeOfB )
    {
        int BUFFER_SIZE;
        if ( sizeOfA > 1024) BUFFER_SIZE = 1024;
        else BUFFER_SIZE = sizeOfA;

        int iteratorDo = 0;

        char * bufferFileA = new char [BUFFER_SIZE];
        char * bufferFileB = new char [BUFFER_SIZE];

        do
        {
            #ifdef _DEBUG_SW
            std::cout << "interator DO = " << iteratorDo++ << std::endl;
            #endif
            A->read(bufferFileA, BUFFER_SIZE);
            B->read(bufferFileB, BUFFER_SIZE);
            if ( DataBlocksAreEqual(bufferFileA, bufferFileB, BUFFER_SIZE) == false)
            {
                #ifdef _DEBUG_SW
                std::cout << "pliki sa rozne" << std::endl;
                #endif
                tReturn = false;
                break;
            }
            tReturn = true;
        } while ( A->good() && B->good());
        delete []bufferFileA;
        delete []bufferFileB;
        #ifdef _DEBUG_SW
        std::cout << " F interator DO = " << iteratorDo << " return value = " << tReturn << std::endl;
        #endif
    }
    else
    {
        tReturn = false;
    }

    return tReturn;
}

int SizeOfFile (std::fstream * file) 
{
    int temp = 0;
    file->seekg(0, std::ios::end);
    temp = file->tellg();
    file->seekg(0, std::ios::beg);
    return temp;
}

bool DataBlocksAreEqual (char * pA, char * pB, int size)
{
    bool tReturn = false;
    char * tempA = pA;
    char * tempB = pB;
    
    for (int i = 0; i < size; i++)
    {
        if (pA[i] == EOF || pB[i] == EOF) break;
        if (pA[i] != pB[i])
        {
            #ifdef _DEBUG_SW
            std::cout << pA[i] << " != " << pB[i] << std::endl;
            #endif
            tReturn = false;
            break;
        }
        tReturn = true;
    }
    return tReturn;
}