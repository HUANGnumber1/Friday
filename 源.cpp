//
//#include <stdio.h>  
//#include <time.h>  
//#include <opencv2/opencv.hpp>  
//
//#include <iostream> 
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include "opencv2/imgcodecs.hpp"
//#include <opencv2/core/utils/logger.hpp>
//#include <opencv2/ml/ml.hpp>  
//#include <io.h>
//
//using namespace std;
//using namespace cv;
//using namespace cv::ml;
//
//void getFiles(string path, vector<string>& files);
//void get_1(Mat& trainingImages, vector<int>& trainingLabels);
//void get_0(Mat& trainingImages, vector<int>& trainingLabels);
//
//int main()
//{
//	//获取训练数据
//	Mat classes;
//	Mat trainingData;
//	Mat trainingImages;
//	vector<int> trainingLabels;
//	get_1(trainingImages, trainingLabels);
//	//waitKey(2000);
//	get_0(trainingImages, trainingLabels);
//	Mat(trainingImages).copyTo(trainingData);
//	trainingData.convertTo(trainingData, CV_32FC1);
//	Mat(trainingLabels).copyTo(classes);
//	//配置SVM训练器参数
//	Ptr<SVM> svm = SVM::create();
//	svm->setType(SVM::C_SVC);
//	svm->setKernel(SVM::LINEAR);
//	svm->setDegree(0);
//	svm->setGamma(1);
//	svm->setCoef0(0);
//	svm->setC(10);
//	svm->setNu(0);
//	svm->setP(0);
//	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 1000, 0.01));
//	//训练
//	svm->train(trainingData, ROW_SAMPLE, classes);
//	//保存模型
//	svm->save("friday.xml");
//
//	cout << "训练好了！！！" << endl;
//
//	getchar();
//	return 0;
//}
//void getFiles(string path, vector<string>& files)
//{
//	long long  hFile = 0;
//	struct _finddata_t fileinfo;
//	string p;
//	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
//	{
//		do
//		{
//			if ((fileinfo.attrib & _A_SUBDIR))
//			{
//				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
//					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
//			}
//			else
//			{
//				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
//			}
//		} while (_findnext(hFile, &fileinfo) == 0);
//
//		_findclose(hFile);
//	}
//}
//
//void get_1(Mat& trainingImages, vector<int>& trainingLabels)
//{
//	string filePath = "//此处放是表情包的数据的训练样本的文件路径";
//	cout << "获取D:\\data\\1" << endl;
//	vector<string> files;
//	getFiles(filePath, files);
//	int number = files.size();
//	for (int i = 0; i < number; i++)
//	{
//		Mat  SrcImage = imread(files[i].c_str());
//		Mat canny;
//		//cout << SrcImage.size() << endl;
//		Mat resizeMat;
//		Mat cvt;
//		Mat gus;
//		resize(SrcImage, resizeMat, Size(256, 256));
//		cvtColor(resizeMat, cvt, COLOR_RGB2GRAY, 0);
//		GaussianBlur(cvt, gus, Size(3, 3), 0, 0);//高斯模糊
//		//Canny(gus, canny, 50, 150);
//		canny = gus.reshape(1, 1);
//		trainingImages.push_back(canny);
//		trainingLabels.push_back(1);
//	}
//}
//void get_0(Mat& trainingImages, vector<int>& trainingLabels)
//{
//	string filePath = "//此处放不是表情包的数据的样本文件路径";//获取训练文件
//	cout << "获取D:\\data\\0" << endl;
//	vector<string> files;
//	getFiles(filePath, files);//返回文件的数量大小数据
//	int number = files.size();
//	for (int i = 0; i < number; i++)//依据文件数量大小进行接下来的标签打印
//	{
//		Mat  SrcImage = imread(files[i].c_str());
//		Mat canny;
//		if (SrcImage.empty())
//		{   
//			break;
//		}
//		else {
//			Mat resizeMat;
//			Mat cvt;
//			Mat gus;
//			
//			resize(SrcImage, resizeMat, Size(256, 256));
//			cvtColor(resizeMat, cvt, COLOR_RGB2GRAY, 0);
//			GaussianBlur(cvt, gus, Size(3, 3), 0, 0);//高斯模糊
//			//Canny(gus, canny, 50, 150);//边缘检测
//			canny = gus.reshape(1, 1);
//			trainingImages.push_back(canny);
//			trainingLabels.push_back(0);
//		}
//	}
//}

