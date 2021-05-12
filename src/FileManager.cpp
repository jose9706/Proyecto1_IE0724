#include "FileManager.h"
FileManager::FileManager() {

}
FileManager::FileManager(std::string FileNamePath)
{
    FilePath = FileNamePath;
}

FileManager::~FileManager()
{
}

/*
* Funcion parte un string de entrada en base a un delimitador que uno desee
* @param s String a partir 
* @param delim Delimitador a utilizar como base, en este caso siempre es ','
* @return Vector que contiene cada parte del string separado por el delimitador
*/
std::vector<std::string> FileManager::split(const std::string &s, char delim)
{

    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

void FileManager::printVector(std::vector<float> in)
{
    for (auto i = in.begin(); i != in.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}

void FileManager::FileParser(std::vector<float>& parsedPuntos, std::vector<std::string>& pairPuntos)
{
    std::fstream f(FilePath);
    if (f.is_open())
    {
        std::string text;
        while (getline(f, text))
        {
            if(text.length() > 1) {
                std::cout << "file text " << text << "\n";
                text.erase(remove(text.begin(), text.end(), ' '), text.end());
                pairPuntos.push_back(text);
                std::vector<std::string> tempParsedPuntos = split(text, ',');
                parsedPuntos.push_back(std::stof(tempParsedPuntos[0])); //Guardo los dos puntos parseados en forma de float 
                parsedPuntos.push_back(std::stof(tempParsedPuntos[1]));
                //printVector(parsedPuntos);
                //parsedPuntos.push_back();
            }
        }
    }
    else
    {
        throw FilePath;
    }
}

