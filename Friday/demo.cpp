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
//    // 确保路径不为空
//    if (filepath.empty()) {
//        throw std::invalid_argument("文件路径不能为空");
//    }
//
//    // 创建一个字符串流，并将文件路径放入其中
//    std::istringstream path_stream(filepath);
//
//    // 使用getline读取路径中的最后一个部分，即文件名
//    // 第三个参数为'\0'，表示到达文件路径结束的分隔符时停止读取
//    // 默认情况下，getline会以'\n'作为分隔符，但在Windows中，文件路径的分隔符为'\\'
//    // 因此，我们使用strrchr来找到最后一个'\\'或'/'字符
//    const char* last_slash = strrchr(filepath.c_str(), '\\');
//    if (!last_slash) {
//        last_slash = strrchr(filepath.c_str(), '/');
//    }
//
//    std::string filename;
//    if (last_slash) {
//        // 如果找到了分隔符，则从它之后开始读取到末尾作为文件名
//        filename = std::string(last_slash + 1);
//    }
//    else {
//        // 如果没有找到分隔符，那么整个路径就是文件名
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
//	// 使用 _t 宏前缀可以同时支持 ANSI 和 Unicode
//	DWORD result = MoveFile(sourcePath, destinationPath);
//
//	if (result == 0) {
//		std::cerr << "文件移动失败，错误码: " << GetLastError() << std::endl;
//	}
//	else {
//		std::cout << "文件移动成功！" << std::endl;
//	}
//}
////
//int main() {
////    //try {
////    //    // 设置源文件和目标文件的路径
////    //    std::string source = "C:/Users/HUANG/Desktop/data/test/(4FE1L}1T3JHYU0MN[}UM`D.png";
////    //    std::string destination = "C:/Users/HUANG/Desktop/data/test0";
////
////    //    // 检查源文件是否存在
////    //    if (!std::filesystem::exists(source)) {
////    //        std::cerr << "源文件不存在: " << source << std::endl;
////    //        return 1;
////    //    }
////
////    //    // 移动文件
////    //    std::filesystem::rename(source, destination);
////    //    std::cout << "文件已成功移动到: " << destination << std::endl;
////
////    //    return 0;
////    //}
////    //catch (const std::filesystem::filesystem_error& e) {
////    //    std::cerr << "文件操作错误: " << e.what() << std::endl;
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
////	// 使用 _t 宏前缀可以同时支持 ANSI 和 Unicode
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
//				std::cerr << "发生错误: " << e.what() << std::endl;
//			}
//			cout << filename << endl;//调试输出filename
//			path = "C:/Users/HUANG/Desktop/data/test1/" + filename;
//			cout << "path" << endl;
//			cout << path << endl;//调试输出path
//			movefiles(files[1].c_str(), path.c_str());
//		
//    
//	//DWORD result = MoveFile(sourcePath,path.c_str());
//
//	//if (result == 0) {
//	//	std::cerr << "文件移动失败，错误码: " << GetLastError() << std::endl;
//	//}
//	//else {
//	//	std::cout << "文件移动成功！" << std::endl;
//	//}
//    
////	 
////        //try {
////        //    std::string filename = get_filename("C:Users/HUANG/Desktop/data/WeiXin/mmexport1695020461560.jpg");
////        //    std::cout << "文件名: " << filename << std::endl;
////        //}
////        //catch (const std::exception& e) {
////        //    std::cerr << "发生错误: " << e.what() << std::endl;
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
