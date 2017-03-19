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

	//���������
	VideoCapture cam(0);
	if (!cam.isOpened()) exit(0);

	//��������
	namedWindow("input image");
	

	//��ָ���Ĵ�����ʾ��Ƶ
	while (1) {
		//�������ͷ��һ֡
		cam >> input_image;
		//��ÿ֡ͼ��ת����HSV��ʽ
		cvtColor(input_image, out, CV_BGR2HSV,3);
		//����ͨ��
		/*vector <Mat>  channel;
		split(out, channel);
		Mat hchannel = channel.at(0);
		Mat schannel = channel.at(1);
		Mat vchannel = channel.at(2);*/
		//��������
		
		for (int i = 0; i < imrows; i++)
		{
			for (int j = 0; j < imcols; j++)
			{
				CvScalar s = cvGet2D(&out, i, j);
				/*opencv ��H��Χ��0~180����ɫ��H��Χ�����(0~8)��(160, 180)
					S�Ǳ��Ͷȣ�һ���Ǵ���һ��ֵ, S���;��ǻ�ɫ���ο�ֵS>80)��
					V�����ȣ����;��Ǻ�ɫ�����߾��ǰ�ɫ(�ο�ֵ220>V>50)��*/
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


		//ʶ������еĺ�ɫ

		//��ָ����������ʾͼ��
		imshow("input image",out );

		//���30msû�а���������-1������esc������27
		if (27 == waitKey(30))
			break;
	}

	cvDestroyWindow("input image");
    ;
}
