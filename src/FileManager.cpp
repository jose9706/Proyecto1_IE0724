#include "FileManager.h"
FileManager::FileManager() {

}
/*
* Constructor toma el cmino al archivo que se ve a parsear 
* @param FileNamePath string que contiene el path al archivo a utilizar 
*/
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
/*
* Funcion toma un vector de entrada y lo imprime en consola
* @param in vector a imprimir
*/
void FileManager::printVector(std::vector<float> in)
{
    for (auto i = in.begin(); i != in.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}
/*
* Funcion parsea el archivo de entrada utilizando varias funciones, genera exception el archivo no existe. 
* @param parsedPuntos referencia al vector donde se van a guardar todos puntos separados
* @param pairPuntos referencia a un vector donde se guardan los pares de puntos en formato string
*/
int FileManager::FileParser(std::vector<float>& parsedPuntos, std::vector<std::string>& pairPuntos)
{
    std::fstream f(FilePath);
    if (f.is_open())
    {
        std::string text;
        while (getline(f, text))
        {
            if(text.length() > 1) {
                text.erase(remove(text.begin(), text.end(), ' '), text.end());
                pairPuntos.push_back(text);
                std::vector<std::string> tempParsedPuntos = split(text, ',');
                if (text.find(',') != std::string::npos)
                    try{
                        parsedPuntos.push_back(std::stof(tempParsedPuntos[0])); 
                        parsedPuntos.push_back(std::stof(tempParsedPuntos[1]));
                    }
                    catch (const std::invalid_argument& ia){
                        std::cout << "Dato ingresado no es valido\n";
                        return -1;
                    }
                else{ 
                    std::cout << "Dato ingresado no es valido\n";
                    return -1;
                    }    
            }
        }
        if (parsedPuntos.size() < 6){
            return -1;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

