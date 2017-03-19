#include "stdafx.h"
#include<opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main()
{
	Mat input_image;
	int imrows = input_image.rows;
	int imcols = input_image.cols;
	Mat out(imrows,imcols, COLORMAP_HSV);

	//获得摄像流
	VideoCapture cam(0);
	if (!cam.isOpened()) exit(0);

	//创建窗口
	namedWindow("input image");
	

	//在指定的窗口显示视频
	while (1) {
		//获得摄像头的一帧
		cam >> input_image;
		//将每帧图像转换成HSV格式
		cvtColor(input_image, out, CV_BGR2HSV,3);
		//分离通道
		/*vector <Mat>  channel;
		split(out, channel);
		Mat hchannel = channel.at(0);
		Mat schannel = channel.at(1);
		Mat vchannel = channel.at(2);*/
		//遍历像素
		
		for (int i = 0; i < imrows; i++)
		{
			for (int j = 0; j < imcols; j++)
			{
				CvScalar s = cvGet2D(&out, i, j);
				/*opencv 的H范围是0~180，红色的H范围大概是(0~8)∪(160, 180)
					S是饱和度，一般是大于一个值, S过低就是灰色（参考值S>80)，
					V是亮度，过低就是黑色，过高就是白色(参考值220>V>50)。*/
				if (((s.val[0]>0 && s.val[0]<10 )|| (s.val[0]>143 && s.val[0] < 180))
					&& (s.val[1]>43 && s.val[1]<255) && (s.val[2]>46&&s.val[2]<220)
					)
				{
					s.val[0] = 0;
					s.val[1] = 0;
					s.val[2] = 255;
					

				
				}
				else
				{
					s.val[0] = 255;
					s.val[1] = 255;
					s.val[2] = 255;
				}


			}
		
		
		}


		//识别出所有的红色

		//在指定窗体中显示图像
		imshow("input image",out );

		//如果30ms没有按键，返回-1，按下esc，返回27
		if (27 == waitKey(30))
			break;
	}

	cvDestroyWindow("input image");
    ;
}
