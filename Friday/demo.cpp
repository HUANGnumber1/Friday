//#include "opencv2/imgcodecs.hpp"
//#include <opencv2/core/utils/logger.hpp>
//#include <opencv2/ml/ml.hpp>  
//#include <io.h>
//#include<fstream>
//#include <stdio.h>  
//#include <time.h>  
//#include <opencv2/opencv.hpp>  
////
//#include <iostream> 
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <format>
//#include <filesystem>
//#include <Windows.h>
//using namespace std;
//
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
//					getFiles(p.assign(path).append("/").append(fileinfo.name), files);
//			}
//			else
//			{
//				files.push_back(p.assign(path).append("/").append(fileinfo.name));
//			}
//		} while (_findnext(hFile, &fileinfo) == 0);
//
//		_findclose(hFile);
//	}
//}
//
//#include <iostream>
//#include <fstream>
//#include <sstream>
//
//std::string get_filename(const std::string& filepath) {
//    // ȷ��·����Ϊ��
//    if (filepath.empty()) {
//        throw std::invalid_argument("�ļ�·������Ϊ��");
//    }
//
//    // ����һ���ַ������������ļ�·����������
//    std::istringstream path_stream(filepath);
//
//    // ʹ��getline��ȡ·���е����һ�����֣����ļ���
//    // ����������Ϊ'\0'����ʾ�����ļ�·�������ķָ���ʱֹͣ��ȡ
//    // Ĭ������£�getline����'\n'��Ϊ�ָ���������Windows�У��ļ�·���ķָ���Ϊ'\\'
//    // ��ˣ�����ʹ��strrchr���ҵ����һ��'\\'��'/'�ַ�
//    const char* last_slash = strrchr(filepath.c_str(), '\\');
//    if (!last_slash) {
//        last_slash = strrchr(filepath.c_str(), '/');
//    }
//
//    std::string filename;
//    if (last_slash) {
//        // ����ҵ��˷ָ����������֮��ʼ��ȡ��ĩβ��Ϊ�ļ���
//        filename = std::string(last_slash + 1);
//    }
//    else {
//        // ���û���ҵ��ָ�������ô����·�������ļ���
//        filename = filepath;
//    }
//
//    return filename;
//}
//
//void movefiles(const char* sourcePath, const char* destinationPath)
//{
//
//      
//
//	// ʹ�� _t ��ǰ׺����ͬʱ֧�� ANSI �� Unicode
//	DWORD result = MoveFile(sourcePath, destinationPath);
//
//	if (result == 0) {
//		std::cerr << "�ļ��ƶ�ʧ�ܣ�������: " << GetLastError() << std::endl;
//	}
//	else {
//		std::cout << "�ļ��ƶ��ɹ���" << std::endl;
//	}
//}
////
//int main() {
////    //try {
////    //    // ����Դ�ļ���Ŀ���ļ���·��
////    //    std::string source = "C:/Users/HUANG/Desktop/data/test/(4FE1L}1T3JHYU0MN[}UM`D.png";
////    //    std::string destination = "C:/Users/HUANG/Desktop/data/test0";
////
////    //    // ���Դ�ļ��Ƿ����
////    //    if (!std::filesystem::exists(source)) {
////    //        std::cerr << "Դ�ļ�������: " << source << std::endl;
////    //        return 1;
////    //    }
////
////    //    // �ƶ��ļ�
////    //    std::filesystem::rename(source, destination);
////    //    std::cout << "�ļ��ѳɹ��ƶ���: " << destination << std::endl;
////
////    //    return 0;
////    //}
////    //catch (const std::filesystem::filesystem_error& e) {
////    //    std::cerr << "�ļ���������: " << e.what() << std::endl;
////    //    return 1;
////
////    //}
//
//    string filePath = "C:/Users/HUANG/Desktop/data/test";
//    vector<string> files;
//    getFiles(filePath, files);
//    int number = files.size();
//
//	const char* sourcePath = "C:/Users/HUANG/Desktop/data/test/(4FE1L}1T3JHYU0MN[}UM`D.png";
////	const char* destinationPath = "C:/Users/HUANG/Desktop/data/test0/(4FE1L}1T3JHYU0MN[}UM`D.png";
////
////	// ʹ�� _t ��ǰ׺����ͬʱ֧�� ANSI �� Unicode
////
//     std::string filename = get_filename(files[1].c_str());
//     std::string path;
//    cout << filename << endl;
//    path = "C:/Users/HUANG/Desktop/data/test0/" + filename;
//    cout << path << endl;
//
//			try {
//				 filename = get_filename(files[1].c_str());
//				cout << "filename" << endl;
//				
//			}
//			catch (const std::exception& e) {
//				std::cerr << "��������: " << e.what() << std::endl;
//			}
//			cout << filename << endl;//�������filename
//			path = "C:/Users/HUANG/Desktop/data/test1/" + filename;
//			cout << "path" << endl;
//			cout << path << endl;//�������path
//			movefiles(files[1].c_str(), path.c_str());
//		
//    
//	//DWORD result = MoveFile(sourcePath,path.c_str());
//
//	//if (result == 0) {
//	//	std::cerr << "�ļ��ƶ�ʧ�ܣ�������: " << GetLastError() << std::endl;
//	//}
//	//else {
//	//	std::cout << "�ļ��ƶ��ɹ���" << std::endl;
//	//}
//    
////	 
////        //try {
////        //    std::string filename = get_filename("C:Users/HUANG/Desktop/data/WeiXin/mmexport1695020461560.jpg");
////        //    std::cout << "�ļ���: " << filename << std::endl;
////        //}
////        //catch (const std::exception& e) {
////        //    std::cerr << "��������: " << e.what() << std::endl;
////        //}
////
////        //return 0;
////    
////
////		//MoveFile("C:/Users/HUANG/Desktop/data/test/(4FE1L}1T3JHYU0MN[}UM`D.png", "C:/Users/HUANG/Desktop/data/test0");
////		//
////		//return GetLastError();
////	
////
////	//string filePath = "C:/Users/HUANG/Desktop/data/test";
////	//	vector<string> files;
////	//getFiles(filePath, files);
////	//int number = files.size();
////	//for (int i = 0; i < number; i++)
////	//{
//////	//	cout << files[i] << endl;
//////	//}
//}
