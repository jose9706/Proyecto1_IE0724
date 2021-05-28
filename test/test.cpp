#include "FileManager.h"
#include "gtest/gtest.h"
#include "ConvexHull.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using std::cout, std::endl;
TEST(FileInput, positive) {
    int status = 0;
    FileManager FileProcessor("entrada1.txt");
    std::vector<float> parsedPuntos, outputPoints;
    std::vector<std::string> stringParsedPuntos;
    status = FileProcessor.FileParser(parsedPuntos, stringParsedPuntos);
    ASSERT_EQ(status, 1);
}

TEST(ConvexHull, positive) {
    srand((unsigned) time(0));
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}