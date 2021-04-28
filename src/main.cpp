#include <iostream>
#include <fstream>
#include <vector>

std::vector<string> parseLine(std::string Line) {
    
}


void FileManager(std::string FileName) {
    std::fstream f(FileName);
    std::string text;
    std::vector<string> parsedPuntos;
    while (getline(f, text)) {
        std::cout << text;
        parseLine(text);
        parsedPuntos.push_back();
    }
}



int FileChose() {
   return 0; 
}


int main(int argc, const char** argv) {
    if (argc > 1)
    {
        std::string FILENAME = argv[1];
        std::cout << "File input \n";
        std::cout << FILENAME << "\n";
        FileManager(FILENAME);
    }
    else {
        FileChose();
    }
    
    return 0;
}