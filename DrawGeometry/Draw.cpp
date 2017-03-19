

#include"stdafx.h"
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc.hpp"

using namespace cv;

#define  w 400  


int main(int argc, char **argv){

	 
	char window[] = "Draw";

	//����һ���հ׵�mat���Ͷ���image����ʾͼ��
	Mat image = Mat::zeros(w, w, CV_8UC3);

	//�������������Բ
	ellipse(image,
		Point(w / 2.0, w / 2.0),
		Size(w / 4.0, w / 16.0),
		45,
		0,
		360,
		Scalar(0, 0, 100),
		2,
		8,
		0);
	ellipse(image,
		Point(w / 2.0, w / 2.0),
		Size(w / 4.0, w / 16.0),
		-45,
		0,
		360,
		Scalar(0, 0,100),
		2,
		8);


	//��һ��Բ

	circle(image,
		Point(w / 2.0, w / 2.0),
		w /2.0,
		Scalar(0, 100, 0),
		1,
		8,
		0);
	//������
	line(image,
		Point(w / 4,w / 4),
		Point(w/ 4, 3*w / 4),
		Scalar(100, 0, 0)
		);

	
	//��windows����ʾ
	imshow(window, image);
	cvMoveWindow(window, 0, 200);

	waitKey(0);
	return(0);
}





