#include<iostream>
#include"opencv2\core\core.hpp"
#include"opencv2\highgui\highgui.hpp"
using namespace cv;
using namespace std;

int main(){
	/*opencv2�汾������ṹMat������imread(),nameWindow(),imshow()*/
	Mat img1=imread("D:\\1.jpg");   
	if(!img1.data) {cout<<"error1";return -1;}  
	namedWindow("ͼƬ1");
	imshow("ͼƬ1",img1);
        waitKey(10);

	/*opencv�ϰ汾�����ݽṹIplImage������cvLoadImage(),cvNamedWindow(),cvShowImage()*/
	IplImage* img2=cvLoadImage("D:\\2.jpg");
	if(!img2)  {cout<<"error2";return -1;} 
	cvNamedWindow("ͼƬ2");
	cvShowImage("ͼƬ2",img2);
        cvWaitKey(10);
	cvReleaseImage(&img2);
	cvDestroyWindow("ͼƬ2");   
	
	return 0;
}

