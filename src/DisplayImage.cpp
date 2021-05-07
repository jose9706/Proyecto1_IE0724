#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <algorithm>
//#define w 400
using namespace cv;
using std::vector;
using std::string;
//void MyFilledCircle( Mat img, Point center );
void MyLine( Mat img, Point start, Point end );

int main (void){
    char hull_window[] = "Drawing: Convex Hull";
    vector <float> puntos(8) = {0, 0, 10, 0, 10, 10, 0, 10};
    int w = *max_element(puntos.begin(), puntos.end())+10;
    Mat hull_image = Mat::zeros( w, w, CV_8UC3 );
    for (int i=0; i < puntos.size();i=i+2){
      if (i != puntos.size()-2) {
        MyLine( hull_image, Point( puntos[i], puntos[i+1] ), Point( puntos[i+2], puntos[i+3] ) );
      }
      else
        MyLine( hull_image, Point( puntos[i], puntos[i+1] ), Point( puntos[0], puntos[1] ) );
    }
      
    imshow( hull_window, hull_image );
    moveWindow( hull_window, 0, 200 );
    waitKey( 0 );
    return(0);
}

void MyLine( Mat img, Point start, Point end )
{
  int thickness = 2;
  int lineType = LINE_8;
  line( img,
    start,
    end,
    Scalar( 0, 255, 0 ),
    thickness,
    lineType );
}
