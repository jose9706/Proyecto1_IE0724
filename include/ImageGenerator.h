#include <vector>
#include <algorithm>
#include <functional>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#define w 400
using std::vector;
using namespace cv;

class ImageGenerator
{
private:
    /* data */ 
public:
    ImageGenerator(/* args */);
    ~ImageGenerator();
    const float& getMaxValue(const vector<float>& inputVector) const;
    const float& getMinValue(const vector<float>& inputVector) const;
    const vector<float>& normalizeVector(vector<float>& inputVector, const float& min, const float& max);
    void createLines(Mat& hullImage, vector<float>& points);
    void constructImage();
    void myLine(Mat& img, Point& start, Point& end);
};

ImageGenerator::ImageGenerator(/* args */)
{
}

ImageGenerator::~ImageGenerator()
{
}
