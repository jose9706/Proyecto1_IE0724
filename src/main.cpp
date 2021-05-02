//#pragma once 
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "include/FileManager.h"


int main(int argc, const char **argv)
{
    if (argc > 1)
    {
        std::string FILENAME = argv[1];
        std::cout << "File input \n";
        std::cout << FILENAME << "\n";
        try
        {
            FileManager FileProcessor(FILENAME);
            std::vector<float> parsedPuntos;
            FileProcessor.FileParser(parsedPuntos);
            FileProcessor.printVector(parsedPuntos);
        }
        catch (std::string FILENAME_ERR)
        {
            std::cout << "File " << FILENAME_ERR << " does not exist." << std::endl;
        }
    }
    else
    {
        std::cout << "Por favor ingrese un archivo valido o el Path a dicho archivo" << std::endl;
    }

    return 0;
}