#include<iostream>
#include"opencv2\core\core.hpp"
#include"opencv2\highgui\highgui.hpp"
using namespace cv;
using namespace std;

int main(){
	/*opencv2�汾������ṹMat������imread(),nameWindow(),imshow()*/
	Mat img1=imread("D:\\1.jpg");   //ע����˫��б��,���������ͼƬ
	if(!img1.data) {cout<<"error1";return -1;}   //�����û�ж���ͼƬ
	namedWindow("ͼƬ1");//�������������ڶ�����Ĭ���β�
	imshow("ͼƬ1",img1);

	/*opencv�ϰ汾�����ݽṹIplImage������cvLoadImage(),cvNamedWindow(),cvShowImage()*/
	IplImage* img2=cvLoadImage("D:\\2.jpg");
	if(!img2)  {cout<<"error2";return -1;} 
	cvNamedWindow("ͼƬ2");
	cvShowImage("ͼƬ2",img2);

	waitKey(0);
	return 0;
}

