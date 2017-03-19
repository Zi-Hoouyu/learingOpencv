#include<opencv2\opencv.hpp>
using namespace std;
int main()
{
	//����IplImageָ��  
	IplImage* pFrame = NULL;

	//��ȡ����ͷ  
	CvCapture* pCapture = cvCreateCameraCapture(-1);
	if ((pCapture = cvCreateCameraCapture(0)) == NULL)
	{
		printf("Camera Open Fail!Please check your Camera.");
		//char c=cvWaitKey(33);
		return 0;
	}

	//��������  
	cvNamedWindow("video", 1);
	cvWaitKey(300);
	//��ʾ����  
	while (1)
	{
		pFrame = cvQueryFrame(pCapture);
		if (!pFrame)break;
		cvShowImage("video", pFrame);
		char c = cvWaitKey(33);
		if (c == 27)break;
	}

	cvReleaseCapture(&pCapture);
	cvDestroyWindow("video");
}