/**
* @file objectDetection_img.cpp
* @author:wepon 
* @blog: http://2hwp.com
* ���demoʹ��opencvʵ��ͼƬ��������⡢�Լ��滭�����������ȡ�����ȹ��ܡ�
* ÿ������д��һ��������������ֲʹ�á�
* �ο���opencv�����滭��������ģ���ĵ���
*/

#include "opencv2\core\core.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include"opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"

using namespace cv;


/*---- detectFaces���� -------
���Ҷ�ͼƬ�е�����������������������(x,y,width,height)
��Ϊ���ܼ���������������Է�������Ϊvetor<Rect>
------------------------------------------------------*/
vector<Rect> detectFaces(Mat img_gray){
	CascadeClassifier face_cascade;
	face_cascade.load("haarcascade_frontalface_alt.xml");
	vector<Rect> faces;
	face_cascade.detectMultiScale(img_gray,faces,1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
	return faces;
}


/*----  drawFaces���� -------
��ԭʼͼƬ������Բ��Ȧ������
------------------------------------------------------*/
void drawFaces(Mat img,vector<Rect> faces){
	namedWindow("draw faces");
	for(size_t i=0;i<faces.size();i++){
		//��ȷ������������������,�ٸ��ݸ����껭��Բ
		Point center(faces[i].x + faces[i].width/2,faces[i].y + faces[i].height/2);
		ellipse(img,center,Size(faces[i].width/2,faces[i].height/2),0,0,360,(255,0,0),2,8,0);
	}
	imshow("draw faces",img);
}



int main(){
	//��ȡͼ��ת��Ϊ�Ҷ�ͼ���ٽ���ֱ��ͼ���⻯
	Mat img = imread("obama.jpg");
	Mat img_gray;
	cvtColor(img,img_gray,COLOR_BGR2GRAY );
	equalizeHist(img_gray,img_gray);
	//�����������������
	vector<Rect> faces = detectFaces(img_gray);
	drawFaces(img,faces);
	waitKey(0);
	return 0;
}







