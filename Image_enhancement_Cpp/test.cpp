#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_binary_value = 255;
Mat src, src_gray, dst;
const char* window_name = "Threshold Demo";
const char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* trackbar_value = "Value";
static void Threshold_Demo( int, void* )
{
    /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
    */
    threshold( src_gray, dst, threshold_value, max_binary_value, threshold_type );
    imshow( window_name, dst );
}

int main()
{
    Mat img1,img2,adap_img1,adap_img2,adap_img3,final,fil_img1; //intialized Mat
    Mat trunc_img,thresh_bin;
    float** graph;
    vector<float> row_data, col_data;

    img1 = imread("/home/mudit/Desktop/DIP_coursework/all_aasign/build/input.JPG",1);   //read an image
    if(img1.empty())
    {
        std::cerr << "ERR: Unable to find image.\n" << endl;
            return -1;
    }

    int row_unscaled = img1.rows;   //number of rows before scaling
    int col_unscaled = img1.cols;   //number of cols before scaling
    float p =0.35;                   //Scaling Coefficient

    //    cout<<"number of rows unscaled --> "<<row_unscaled<<endl;
    //    cout<<"number of columns unsclaed --> "<<col_unscaled<<endl;

    //==================================BASIC OPERATIONS ON THE IMAGE==============================================================
    resize(img1,final,Size(col_unscaled*p,row_unscaled*p));   //Resize the image to reduce num_of_row&cols

//    cvtColor(final,img2,CV_BGR2GRAY);                        //Convert the color image to gray scale

//    threshold(img2,trunc_img,50,255,3);                     //Use thresholding -->3 means Truncation(thresholding value--> 160)

//    threshold(trunc_img,thresh_bin,128,255,0);               //Binarization of the image --> gives either 0 for black & 1 for white

    medianBlur(final,fil_img1,5);                       //apply median to filter out any noise
    //=============================================================================================================================

//    resize(fil_img1,final,Size(col_unscaled*p,row_unscaled*p));   //Resize the image to reduce num_of_row&cols

//============ Adaptive Thresholding using the two methods ========================================================================

//    adaptiveThreshold(img2,adap_img1,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,11,2);
//    adaptiveThreshold(img2,adap_img2,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,11,2);
//=================================================================================================================================

//=================================== Uncomment to view output pictures ===========================================================

//    imshow("Truncation_thresholding",trunc_img);
//    imshow("thresholding_binary",thresh_bin);
//    imshow("adap1",adap_img1);
//    imshow("adap2",adap_img2);
//    imshow("Input Image",img1);
//    imshow("gray Image",img2);
//    imshow("Median",fil_img1);
//    cv::waitKey(0);

//==================================================================================================================================

    imwrite("filtered_image.jpg",fil_img1);       //Save the filtered image

}

//int main( int argc, char** argv )
//{
//    String imageName("/home/mudit/Desktop/DIP_coursework/all_aasign/mudit.jpg"); // by default
//    if (argc > 1)
//    {
//        imageName = argv[1];
//    }
//    src = imread( imageName, IMREAD_COLOR ); // Load an image
//    if (src.empty())
//    {
//        cout << "Cannot read image: " << imageName << std::endl;
//        return -1;
//    }
//    cvtColor( src, src_gray, COLOR_BGR2GRAY ); // Convert the image to Gray
//    namedWindow( window_name, WINDOW_AUTOSIZE ); // Create a window to display results
//    createTrackbar( trackbar_type,
//                    window_name, &threshold_type,
//                    max_type, Threshold_Demo ); // Create Trackbar to choose type of Threshold
//    createTrackbar( trackbar_value,
//                    window_name, &threshold_value,
//                    max_value, Threshold_Demo ); // Create Trackbar to choose Threshold value
//    Threshold_Demo( 0, 0 ); // Call the function to initialize
//    cv::imshow("img",src);
//    waitKey();
//    return 0;
//}
