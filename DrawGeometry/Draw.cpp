

#include"stdafx.h"
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc.hpp"

using namespace cv;

#define  w 400  


int main(int argc, char **argv){

	 
	char window[] = "Draw";

	//创建一个空白的mat类型对象image来显示图像
	Mat image = Mat::zeros(w, w, CV_8UC3);

	//画两个交叉的椭圆
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


	//画一个圆

	circle(image,
		Point(w / 2.0, w / 2.0),
		w /2.0,
		Scalar(0, 100, 0),
		1,
		8,
		0);
	//画条线
	line(image,
		Point(w / 4,w / 4),
		Point(w/ 4, 3*w / 4),
		Scalar(100, 0, 0)
		);

	
	//在windows中显示
	imshow(window, image);
	cvMoveWindow(window, 0, 200);

	waitKey(0);
	return(0);
}





