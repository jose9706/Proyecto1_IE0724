#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#define w 400
using namespace cv;
//void MyFilledCircle( Mat img, Point center );
void MyPolygon( Mat img );
void MyLine( Mat img, Point start, Point end );

int main (void){
    char hull_window[] = "Drawing: Convex Hull";
    Mat hull_image = Mat::zeros( w, w, CV_8UC3 );
    MyLine( hull_image, Point( 0, 15*w/16 ), Point( w, 15*w/16 ) );
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