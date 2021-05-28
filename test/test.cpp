#include "FileManager.h"
#include "gtest/gtest.h"
#include "ConvexHull.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
TEST(FileInput, positive) {
    int status = 0;
    FileManager FileProcessor("entrada1.txt");
    std::vector<float> parsedPuntos, outputPoints;
    std::vector<std::string> stringParsedPuntos;
    status = FileProcessor.FileParser(parsedPuntos, stringParsedPuntos);
    ASSERT_EQ(status, 1);
}

TEST(ConvexHull, positive) {
    std::vector<float> testList;
    ConvexHull tester;
    int listLength = 3 + (rand() % 97);
    cout << "List length " << listLength << "\n";
    for(auto i=0; i< listLength; i++) {
        testList.push_back(rand()%100);
    }
    
    std::vector<float> result;
    tester.CalculateConvexHull(testList, result);
    cout << "Result length " << result.size() << "\n"; 
    EXPECT_TRUE((result.size() > 1));
}

TEST(ConvexHull1, negative) {
    cout << "Prueba con entrada menor a 3 puntos, archivo 2nums.txt\n";
    int status = 0;
    FileManager FileProcessor("2nums.txt");
    std::vector<float> parsedPuntos, outputPoints;
    std::vector<std::string> stringParsedPuntos;
    status = FileProcessor.FileParser(parsedPuntos, stringParsedPuntos);
    ASSERT_EQ(status, -1);
}

TEST(ConvexHull2, negative) {
    cout << "Prueba con caracteres invalidos, archivo sinnums.txt\n";
    int status = 0;
    FileManager FileProcessor("sinnums.txt");
    std::vector<float> parsedPuntos, outputPoints;
    std::vector<std::string> stringParsedPuntos;
    status = FileProcessor.FileParser(parsedPuntos, stringParsedPuntos);
    ASSERT_EQ(status, -1);
}

TEST(ConvexHull3, negative) {
    cout << "Prueba con puntos sin formato adecuado, archivo invalid.txt\n";
    int status = 0;
    FileManager FileProcessor("invalid.txt");
    std::vector<float> parsedPuntos, outputPoints;
    std::vector<std::string> stringParsedPuntos;
    status = FileProcessor.FileParser(parsedPuntos, stringParsedPuntos);
    ASSERT_EQ(status, -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}