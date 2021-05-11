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

char hull_window[] = "Drawing: Convex Hull";
class ImageGenerator
{
private:
    Mat hull_image;
    vector <float> puntos;
    vector <float> hull_puntos;
    vector <string> string_points;
    vector <float> normVect;
    vector <float> normHullVect;
public:
    ImageGenerator(vector<float>& points, vector<float>& hull_points, vector<string>& String_points);
    ~ImageGenerator();
    void MyLine(Point start, Point end );
    void MyPoints(vector<float>& puntos);
    const vector<float> NormalizedVector(vector<float>& points);
    void DrawLines(vector<float>& hull_puntos);
    void WritePoints(vector<float>& Normpoints);
    void BuildImage();
};
