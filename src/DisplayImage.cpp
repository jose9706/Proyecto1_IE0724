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
    MyPolygon(hull_image);
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

void MyPolygon( Mat img, Point poly_points[][] )
{
  int lineType = LINE_8;
  Point rook_points[1][20];
  rook_points[0][0]  = Point(    w/4,   7*w/8 );
  rook_points[0][1]  = Point(  3*w/4,   7*w/8 );
  rook_points[0][2]  = Point(  3*w/4,  13*w/16 );
  rook_points[0][3]  = Point( 11*w/16, 13*w/16 );
  rook_points[0][4]  = Point( 19*w/32,  3*w/8 );
  rook_points[0][5]  = Point(  3*w/4,   3*w/8 );
  rook_points[0][6]  = Point(  3*w/4,     w/8 );
  rook_points[0][7]  = Point( 26*w/40,    w/8 );
  rook_points[0][8]  = Point( 26*w/40,    w/4 );
  rook_points[0][9]  = Point( 22*w/40,    w/4 );
  rook_points[0][10] = Point( 22*w/40,    w/8 );
  rook_points[0][11] = Point( 18*w/40,    w/8 );
  rook_points[0][12] = Point( 18*w/40,    w/4 );
  rook_points[0][13] = Point( 14*w/40,    w/4 );
  rook_points[0][14] = Point( 14*w/40,    w/8 );
  rook_points[0][15] = Point(    w/4,     w/8 );
  rook_points[0][16] = Point(    w/4,   3*w/8 );
  rook_points[0][17] = Point( 13*w/32,  3*w/8 );
  rook_points[0][18] = Point(  5*w/16, 13*w/16 );
  rook_points[0][19] = Point(    w/4,  13*w/16 );
  const Point* ppt[1] = { rook_points[0] };
  int npt[] = { 20 };
  fillPoly( img,
        ppt,
        npt,
        1,
        Scalar( 255, 255, 255 ),
        lineType );
}