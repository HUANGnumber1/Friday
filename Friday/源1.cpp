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

      

	// ʹ�� _t ��ǰ׺����ͬʱ֧�� ANSI �� Unicode
	DWORD result = MoveFile(sourcePath, destinationPath);

	if (result == 0) {
		std::cerr << "�ļ��ƶ�ʧ�ܣ�������: " << GetLastError() << std::endl;
	}
	else {
		std::cout << "�ļ��ƶ��ɹ���" << std::endl;
	}
}

std::string get_filename(const std::string& filepath) {
	// ȷ��·����Ϊ��
	if (filepath.empty()) {
		throw std::invalid_argument("�ļ�·������Ϊ��");
	}

	// ����һ���ַ������������ļ�·����������
	std::istringstream path_stream(filepath);

	// ʹ��getline��ȡ·���е����һ�����֣����ļ���
	// ����������Ϊ'\0'����ʾ�����ļ�·�������ķָ���ʱֹͣ��ȡ
	// Ĭ������£�getline����'\n'��Ϊ�ָ���������Windows�У��ļ�·���ķָ���Ϊ'\\'
	// ��ˣ�����ʹ��strrchr���ҵ����һ��'\\'��'/'�ַ�
	const char* last_slash = strrchr(filepath.c_str(), '\\');
	if (!last_slash) {
		last_slash = strrchr(filepath.c_str(), '/');
	}

	std::string filename;
	if (last_slash) {
		// ����ҵ��˷ָ����������֮��ʼ��ȡ��ĩβ��Ϊ�ļ���
		filename = std::string(last_slash + 1);
	}
	else {
		// ���û���ҵ��ָ�������ô����·�������ļ���
		filename = filepath;
	}

	return filename;
}

int main()
{
	int result = 0;
	string filePath = "//�˴�������Ҫ���з����Դ�ļ����ļ���·��";
	vector<string> files;
	getFiles(filePath, files);
	int number = files.size();
	cout << "�ܹ�" << endl;
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
				cout << "δ��������" << endl;
				continue;
				
		}
		//�쳣���������ʩ
			Mat resizeMat;
			Mat cvt;
			Mat gus;
			Mat canny;
		resize(inMat, resizeMat, Size(256, 256));//ͼ���С����
		cvtColor(resizeMat, cvt, COLOR_RGB2GRAY, 0);//תΪ��ͨ��
		GaussianBlur(cvt, gus, Size(3, 3), 0, 0);//��˹ģ��
		//Canny(gus, canny, 50, 150);//��Ե����㷨
		Mat p = gus.reshape(1, 1);
		p.convertTo(p, CV_32FC1);
		int response = (int)svm->predict(p);
		std::string filename;
		std::string path;
		if (response == 0)//ҪԤ��1�������0�������Լ��͸ĳ�response == 0
		{
			result++;
			//cout << files[i] << endl;
			
			try {
				filename = get_filename(files[i].c_str());
				cout << "filename" << endl;
			}
			catch (const std::exception& e) {
				std::cerr << "��������: " << e.what() << std::endl;
			}
			cout << filename << endl;//�������filename
			
			path = "C:/Users/HUANG/Desktop/data/test0/" + filename;
			cout << "path" << endl;
			cout << path << endl;//�������path
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
				std::cerr << "��������: " << e.what() << std::endl;
			}
			cout << filename << endl;//�������filename
			path = "C:/Users/HUANG/Desktop/data/test1/" + filename;
			cout << "path" << endl;
			cout << path << endl;//�������path
			movefiles(files[i].c_str(), path.c_str());
		}
	}
	cout << "ִ�����" << endl;
	cout << result << endl;
	getchar();
	return  0;
}