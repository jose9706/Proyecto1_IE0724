//Cambiar esto a la hora de hacer cmake
#include "include\ImageGenerator.h"

ImageGenerator::ImageGenerator(/* args */)
{
}

ImageGenerator::~ImageGenerator()
{
}

const float ImageGenerator::getMaxValue(const vector<float>& inputVector) const 
{
    return *max_element(inputVector.begin(), inputVector.end());    
}

const float ImageGenerator::getMinValue(const vector<float>& inputVector) const 
{
    return *min_element(inputVector.begin(), inputVector.end());    
}

void ImageGenerator::myLine(Mat& img, Point& start, Point& end) {
    int thickness = 2;
    int lineType = LINE_8;
    line( img,
        start,
        end,
        Scalar( 0, 255, 0 ),
        thickness,
        lineType );
}

const vector<float> ImageGenerator::normalizeVector(vector<float>& inputVector, const float& min, const float& max) 
{
    vector<float> normalizedVector;
    for (size_t i = 0; i < inputVector.size(); i++)     
    {
        float tempNormalizedValue = (inputVector[i] - min) / (max - min);
        normalizedVector.push_back(tempNormalizedValue);
    }
    return normalizedVector;
}

void ImageGenerator::createLines(Mat& hullImage, vector<float>& points) 
{
    for (int i=0; i < points.size();i=i+2){
      if (i != points.size()-2) {
        myLine(hull_image, Point(points[i], w - points[i+1]), 
        Point(points[i+2] , w - points[i+3]));
      }
      else
        myLine(hull_image, Point(points[i], w - points[i+1]), 
        Point(points[0], w - points[1]));
    }
}

void constructImage()
{
    imshow( hull_window, hull_image );
    moveWindow( hull_window, 0, 200 );
    waitKey( 0 );
}