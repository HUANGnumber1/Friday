#include <stdio.h>  
#include <time.h>  
#include <opencv2/opencv.hpp>  
 
#include <iostream> 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <format>
#include <filesystem>
#include <Windows.h>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/core/utils/logger.hpp>
#include <opencv2/ml/ml.hpp>  
#include <io.h>
#include<fstream>
 
using namespace std;
using namespace cv;
using namespace cv::ml;
 

void getFiles(string path, vector<string>& files)
{
	long long  hFile = 0;
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("/").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("/").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
}


void movefiles(const char* sourcePath ,const char* destinationPath)
{

      

	// 使用 _t 宏前缀可以同时支持 ANSI 和 Unicode
	DWORD result = MoveFile(sourcePath, destinationPath);

	if (result == 0) {
		std::cerr << "文件移动失败，错误码: " << GetLastError() << std::endl;
	}
	else {
		std::cout << "文件移动成功！" << std::endl;
	}
}

std::string get_filename(const std::string& filepath) {
	// 确保路径不为空
	if (filepath.empty()) {
		throw std::invalid_argument("文件路径不能为空");
	}

	// 创建一个字符串流，并将文件路径放入其中
	std::istringstream path_stream(filepath);

	// 使用getline读取路径中的最后一个部分，即文件名
	// 第三个参数为'\0'，表示到达文件路径结束的分隔符时停止读取
	// 默认情况下，getline会以'\n'作为分隔符，但在Windows中，文件路径的分隔符为'\\'
	// 因此，我们使用strrchr来找到最后一个'\\'或'/'字符
	const char* last_slash = strrchr(filepath.c_str(), '\\');
	if (!last_slash) {
		last_slash = strrchr(filepath.c_str(), '/');
	}

	std::string filename;
	if (last_slash) {
		// 如果找到了分隔符，则从它之后开始读取到末尾作为文件名
		filename = std::string(last_slash + 1);
	}
	else {
		// 如果没有找到分隔符，那么整个路径就是文件名
		filename = filepath;
	}

	return filename;
}

int main()
{
	int result = 0;
	string filePath = "//此处放入需要进行分类的源文件的文件夹路径";
	vector<string> files;
	getFiles(filePath, files);
	int number = files.size();
	cout << "总共" << endl;
	cout << number << endl;
	string modelpath = "friday.xml";
	cv::Ptr<cv::ml::SVM> svm;
	svm = cv::Algorithm::load<cv::ml::SVM>(modelpath);
	Mat inMat;
 
	/*CvSVM svm;
	svm.clear();
	string modelpath = "svm.xml";
	FileStorage svm_fs(modelpath, FileStorage::READ);
	if (svm_fs.isOpened())
	{
		svm.load(modelpath.c_str());
	}*/
	for (int i = 0; i < number; i++)
	{
		
			inMat = imread(files[i].c_str());
			cout << files[i].c_str() << endl;
			cout << inMat.size() << endl;
			if (inMat.empty())
		{
				cout << "未正常传入" << endl;
				continue;
				
		}
		//异常引发处理措施
			Mat resizeMat;
			Mat cvt;
			Mat gus;
			Mat canny;
		resize(inMat, resizeMat, Size(256, 256));//图像大小处理
		cvtColor(resizeMat, cvt, COLOR_RGB2GRAY, 0);//转为单通道
		GaussianBlur(cvt, gus, Size(3, 3), 0, 0);//高斯模糊
		//Canny(gus, canny, 50, 150);//边缘检测算法
		Mat p = gus.reshape(1, 1);
		p.convertTo(p, CV_32FC1);
		int response = (int)svm->predict(p);
		std::string filename;
		std::string path;
		if (response == 0)//要预测1，如果用0来做测试集就改成response == 0
		{
			result++;
			//cout << files[i] << endl;
			
			try {
				filename = get_filename(files[i].c_str());
				cout << "filename" << endl;
			}
			catch (const std::exception& e) {
				std::cerr << "发生错误: " << e.what() << std::endl;
			}
			cout << filename << endl;//调试输出filename
			
			path = "C:/Users/HUANG/Desktop/data/test0/" + filename;
			cout << "path" << endl;
			cout << path << endl;//调试输出path
			movefiles(files[i].c_str(), path.c_str());
		}
		else
		{
			//cout << files[i] << endl;
			std::string filename;
			try {
				 filename = get_filename(files[i].c_str());
				cout << "filename" << endl;
				
			}
			catch (const std::exception& e) {
				std::cerr << "发生错误: " << e.what() << std::endl;
			}
			cout << filename << endl;//调试输出filename
			path = "C:/Users/HUANG/Desktop/data/test1/" + filename;
			cout << "path" << endl;
			cout << path << endl;//调试输出path
			movefiles(files[i].c_str(), path.c_str());
		}
	}
	cout << "执行完毕" << endl;
	cout << result << endl;
	getchar();
	return  0;
}