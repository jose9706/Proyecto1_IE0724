#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

/*
Clase FileManager se encarga de todo el proceso de tomar el archivo y obtener en el formato deseado los puntos,
esta fuertemente ligado con los requerimientos del programa. Utiliza varias funciones para tomar los puntos, dividirlos en pares
y entregarlos. 
*/
class FileManager
{
private:
    std::string FilePath;
public:
    FileManager(std::string FileName);
    FileManager();
    ~FileManager();
    std::vector<std::string> split(const std::string &s, char delim);
    void printVector(std::vector<float> in);
    void FileParser(std::vector<float>& parsedPuntos, std::vector<std::string>& pairPuntos);
    void setPath(std::string);
};



