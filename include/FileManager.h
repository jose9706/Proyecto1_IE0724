#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

class FileManager
{
private:
    std::string FilePath;
    std::string PATH;
public:
    FileManager(std::string FileName);
    FileManager();
    ~FileManager();

    std::vector<std::string> split(const std::string &s, char delim);

    void printVector(std::vector<float> in);

    void FileParser(std::vector<float>& parsedPuntos, std::vector<std::string>& pairPuntos);

    void setPath(std::string);
};



