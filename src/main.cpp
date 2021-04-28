#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
/*
* Funcion parte un string de entrada en base a un delimitador que uno desee
* @param s String a partir 
* @param delim Delimitador a utilizar como base, en este caso siempre es ','
* @return Vector que contiene cada parte del string separado por el delimitador
*/
std::vector<std::string> split(const std::string &s, char delim)
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

void printVector(std::vector<std::string> in)
{
    for (auto i = in.begin(); i != in.end(); i++)
    {
        std::cout << *i << " " << '\n';
    }
}

void FileManager(std::string FileName)
{
    std::fstream f(FileName);
    if (f.is_open())
    {
        std::string text;
        std::vector<std::string> parsedPuntos;
        while (getline(f, text))
        {
            std::cout << "file text "<<  text << "\n";
            text.erase(remove(text.begin(), text.end(), ' '), text.end());
            std::vector<std::string> tempParsedPuntos = split(text, ',');
            parsedPuntos.push_back(tempParsedPuntos[0]);
            parsedPuntos.push_back(tempParsedPuntos[1]);
            printVector(parsedPuntos);
            //parsedPuntos.push_back();
        }
    }
    else
    {
        throw FileName;
    }
}

int FileChose()
{
    return 0;
}

int main(int argc, const char **argv)
{
    if (argc > 1)
    {
        std::string FILENAME = argv[1];
        std::cout << "File input \n";
        std::cout << FILENAME << "\n";
        try
        {
            FileManager(FILENAME);
        }
        catch (std::string FILENAME_ERR)
        {
            std::cout << "File " << FILENAME_ERR << " does not exist." << std::endl;
        }
    }
    else
    {
        FileChose();
    }

    return 0;
}