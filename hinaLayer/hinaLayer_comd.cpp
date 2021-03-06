#include "hinaLayer.h"

#include <iostream>
#include <string>
#include<bitset>
#include<fstream>
#include <vector>
#include <algorithm>
#include <sys/stat.h>


/// <summary>
/// 在图片奇偶位上写入水印.
/// </summary>
/// <param name="in_file">要写入水印的图片文件.</param>
/// <param name="mask_file">作为水印的图片文件.</param>
/// <param name="out_file">保存结果的图片文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>int.</returns>
int en_eo_mask(char* in_file, char* mask_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_write_mask(mask_file, rgb);
	h.out_file(out_file);
	return 0;
}

/// <summary>
/// 在图片奇偶位上写入文件.
/// </summary>
/// <param name="in_file">要写入文件的图片文件.</param>
/// <param name="info_file">作为写入信息的文件.</param>
/// <param name="out_file">保存结果的图片文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>int.</returns>
int en_eo_file(char* in_file, char* info_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_write_file(info_file, rgb);
	h.out_file(out_file);
	return 0;
}

/// <summary>
/// 在图片像素低位上写入文件.
/// </summary>
/// <param name="in_file">要写入文件的图片文件.</param>
/// <param name="info_file">作为写入信息的文件.</param>
/// <param name="out_file">保存结果的图片文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>int.</returns>
int en_lsb_file(char* in_file, char* info_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.lsb_write_file(info_file, rgb);
	h.out_file(out_file);
	return 0;
}

/// <summary>
/// 在图片DTF频域上写入水印.
/// </summary>
/// <param name="in_file">要写入水印的图片文件.</param>
/// <param name="mask_file">作为水印的图片文件.</param>
/// <param name="out_file">保存结果的图片文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>int.</returns>
int en_dtf_mask(char* in_file, char* mask_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.dtf_make(3);
	h.dtf_write_mask(mask_file, rgb);
	h.dtf_inverse_make(3);
	h.out_file(out_file);
	return 0;
}



/// <summary>
/// 导出图片奇偶位水印.
/// </summary>
/// <param name="in_file">要导出水印的图片文件.</param>
/// <param name="out_file">保存导出结果的图片文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>int.</returns>
int de_eo_mask(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_to_image(rgb);
	h.out_file(out_file);
	return 0;
}

/// <summary>
/// 导出图片奇偶位文件.
/// </summary>
/// <param name="in_file">要导出文件的图片文件.</param>
/// <param name="out_file">保存导出结果的图片文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>int.</returns>
int de_eo_file(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_out_file(out_file, rgb);
	return 0;
}

/// <summary>
/// 导出图片像素低位文件.
/// </summary>
/// <param name="in_file">要导出文件的图片文件.</param>
/// <param name="out_file">保存导出结果的图片文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>int.</returns>
int de_lsb_file(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.lsb_out_file(out_file, rgb);
	return 0;
}

/// <summary>
/// 导出图片DTF频域水印.
/// </summary>
/// <param name="in_file">要导出水印的图片文件</param>
/// <param name="out_file">保存导出结果的图片文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>int.</returns>
int de_dtf_mask(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.dtf_make(rgb);
	h.dtf_print(rgb);
	h.out_file_fdomain(out_file);
	return 0;
}


/// <summary>
/// 重设图像大小（缩放）.
/// </summary>
/// <param name="in_file">要进行处理图片文件.</param>
/// <param name="out_file">保存处理结果的图片文件.</param>
/// <param name="w">图片新的宽度.</param>
/// <param name="h">图片新的高度.</param>
void resize(char* in_file, char* out_file, int w, int h)
{
	hinaLayer hl;
	hl.open_file(in_file);
	hl.resize(w, h);
	hl.out_file(out_file);
}

/// <summary>
/// 图片Y轴镜像（垂直翻转）.
/// </summary>
/// <param name="in_file">要进行处理图片文件.</param>
/// <param name="out_file">保存处理结果的图片文件.</param>
void mirrorY(char* in_file, char* out_file)
{
	hinaLayer hl;
	hl.open_file(in_file);
	hl.mirrorY();
	hl.out_file(out_file);
}

/// <summary>
/// 图片X轴镜像（水平翻转）.
/// </summary>
/// <param name="in_file">要进行处理图片文件.</param>
/// <param name="out_file">保存处理结果的图片文件.</param>
void mirrorX(char* in_file, char* out_file)
{
	hinaLayer hl;
	hl.open_file(in_file);
	hl.mirrorX();
	hl.out_file(out_file);
}

/// <summary>
/// 在窗口中预览图片的奇偶位图像.
/// </summary>
/// <param name="in_file">要查看的图片文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道).</param>
void read_eo(char* in_file, int rgb)
{
	hinaLayer hl;
	hl.open_file(in_file);
	hl.show_eo("奇偶位", rgb);
}


/// <summary>
/// 在窗口中预览图片的 DTF频域 图像.
/// </summary>
/// <param name="in_file">要查看的图片文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道).</param>
void read_dtf(char* in_file, int rgb)
{
	hinaLayer hl;
	hl.open_file(in_file);
	hl.dtf_make(rgb);
	hl.dtf_print(rgb);
	hl.show_fdomain("DTF频域"+std::to_string(rgb));
}




//=====================================================================================
//文件隐写功能：
//=====================================================================================
using namespace std;


void wstring_to_string(wstring& wstr, string& str)
{
	str = "";
	for (int i = 0; i < wstr.size(); i++)
	{
		str = str + (char)wstr[i];
	}
}

void wstring_to_file(wstring& wstr, char* filename)
{
	wstring::iterator it;
	ofstream out(filename, ios::binary);
	it = wstr.begin();
	for (; it != wstr.end(); it++)
	{
		out.put((*it));
	}
	out.close();
}

void wstring_to_file(wstring& wstr, string filename)
{
	char* cstr = const_cast<char*>(filename.c_str());
	wstring_to_file(wstr, cstr);
}



string get_path_bef(string in, string bef, bool ig = false)
{
	int i;
	i = in.rfind(bef);
	if (string::npos==i)
	{
		if (ig)
			return in;
		else
			return "";
	}
	else
	{
		return in.substr(0, i);
	}
}

string get_path_last(string in, string last, bool ig = false)
{
	int i;
	i = in.rfind(last);
	if (string::npos == i)
	{
		if (ig)
			return in;
		else
			return "";
	
	}
	else
	{
		return in.substr(i+1, in.size()-1);
	}
}

string get_path_add_bs(string in)
{
	char z;
	z = in[in.size()];
	if ('\0' == z && in.size() > 2)
	{
		z = in[in.size()-1];
	}

	if ('\\' == z)
	{
		return in;
	}
	else
	{
		return in + '\\';
	}
}






int file_test(const char* filename)
{
	struct _stat fileStat;


	if (-1 == _stat(filename, &fileStat))
		return -1;//文件或文件夹不存在

	if (fileStat.st_mode & _S_IFDIR)
		return 1;//是文件夹
	else
		return 0;//是文件
}



int re_hide_file(char* in_file, char* out_file, int rgb, string& get_name, bool get_name_only = false )
{
	if (-1 == file_test(in_file))
		return -1;//输入文件不存在错误
	
	ifstream in;
	char* ctemp="";
	
	if (1 == file_test(out_file))
	{//输出参数是目录
		string tempf = "";

		tempf = tempf+get_path_add_bs(out_file);
		
		tempf = tempf + "temp_linalayer_temp.temp";
		ctemp = const_cast<char*>(tempf.c_str());
		
		de_lsb_file(in_file, ctemp, rgb);
		in.open(ctemp, ios::binary);
		
	}
	else
	{
		de_lsb_file(in_file, out_file, rgb);
		in.open(out_file, ios::binary);
	}



	//载入文件
	if (!in)
	{
		cerr << "open error!" << endl;
		abort();
	}
	
	//文件写入 data 以供处理
	wstring data;
	for (unsigned long i=0; true != in.eof(); i++)
	{
		data.push_back(in.get());
	}


	in.close();
	if (1 == file_test(out_file))
	{
		remove(ctemp);
	}
	
	
	wstring b;
	if (255==data[0] && 254==data[1])
	{
		//读取原文件名
		wstring file_name;
		size_t pos = data.rfind({ 254, 255, 152, 10, 20, 253, 254, 255 });
		if (string::npos == pos)
			return -2; //没有结尾标记

		b = data.substr(2, pos -2);

		size_t name_beg = b.rfind({ 254, 255 });
		if (string::npos == name_beg)
			return -3; //没有文件名标记

		file_name = b.substr(name_beg + 2, b.size());
		string file_name_str;
		wstring_to_string(file_name, file_name_str);

		//只返回文件名
		get_name = file_name_str;
		if (get_name_only)
		{
			return 2;
		}


		//截取原文件数据
		b = b.substr(0, name_beg);

		//保存文件
		if (1 == file_test(out_file))
		{//要保存参数的是文件夹
			string a = out_file;
			a=get_path_add_bs(a);
			out_file = const_cast<char*>(a.c_str());
			//cout << endl << "out_file + file_name_str:" << out_file + file_name_str << endl;


			if (file_test((out_file + file_name_str).c_str()) < 0)
				wstring_to_file(b, out_file + file_name_str);
			else
			{
				file_name_str = "hina_" + file_name_str;
				wstring_to_file(b, out_file + file_name_str);
			}
			
			return 0;
		}
		
		if (0 == file_test(out_file))
		{//文件
			wstring_to_file(b, out_file);
			return 0;
		}
	}
	return 0;
}

int ins_hide_file(char* in_file, char* out_file, string& fina_name)
{

	if (-1 == file_test(in_file))
		return -1;//输入文件不存在错误

	char* ctemp;
	string tempf = "";
	if (1 == file_test(out_file))
	{//输出参数是目录

		tempf = tempf + get_path_add_bs(out_file);
		tempf = tempf + get_path_bef(get_path_last(in_file, "\\"), ".", true);
		tempf = tempf + "_INfile1." + get_path_last(get_path_last(in_file, "\\"), ".");
		ctemp = const_cast<char*>(tempf.c_str());
		out_file = ctemp;

	}

	fina_name = out_file;
	ifstream in(in_file, ios::binary);
	if (!in)
	{
		cerr << "open error!" << endl;
		abort();
	}

	ofstream out(out_file, ios::binary);
	if (!out)
	{
		cerr << "write error!" << endl;
		abort();
	}

	in.seekg(in.beg);
	out.seekp(out.beg);
	//写入头
	out.put( 255 );
	out.put( 254 );

	for (; false==in.eof();)
	{
		out.put(in.get());
	}

	out.put(254);
	out.put(255);

	out << get_path_last(in_file, "\\");

	char endend[8] = { 254, 255, 152, 10, 20, 253, 254, 255 };
	for (int i=0; i < 8; i++)
	{
		out.put(endend[i]);
	}


	in.close();
	out.close();
	return 0;
}

/// <summary>
/// 在图片中隐写文件(LSB).
/// </summary>
/// <param name="in_file">要写入内容的图片文件.</param>
/// <param name="info_file">欲写入图片的文件.</param>
/// <param name="out_file">保存处理结果的图片文件.</param>
/// <param name="rgb">用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>int.</returns>
int steg_write_file_lsb(char* in_file, char* info_file, char* out_file, int rgb)
{

	//temp file
	char* ctemp;
	string tempf = "";
	
	if (1 == file_test(out_file))
	{
		tempf = tempf + get_path_add_bs(out_file);
	}
	else
	{
		tempf = tempf + get_path_bef(out_file, "\\") + "\\";
	}
	tempf = tempf + "temp_linalayer_temp.temp";
	ctemp = const_cast<char*>(tempf.c_str());


	string fina_name;
	int a;



	a = ins_hide_file(info_file, ctemp, fina_name);

	if (a < 0)
	{
		return a;
	}

	char* fine_name_c = const_cast<char*>(fina_name.c_str());

	en_lsb_file(in_file, fine_name_c, out_file, rgb);
	remove(fine_name_c);
	return a;
}



/// <summary>
/// 获取图片中隐写的文件的文件名(LSB).
/// </summary>
/// <param name="in_file">图片文件.</param>
/// <param name="rgb">用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>string.</returns>
string steg_get_name_lsb(char* in_file, int rgb)
{
	string name="";
	char* ctemp;
	string tempf = in_file;
	tempf = get_path_bef(tempf, "\\")+"\\temp_hinaLayer_name_.temp";
	ctemp = const_cast<char*>(tempf.c_str());

	re_hide_file(in_file, ctemp, rgb, name, true);
	remove(ctemp);
	return name;
}

/// <summary>
/// 导出图片中隐写的文件(LSB).
/// </summary>
/// <param name="in_file">图片文件.</param>
/// <param name="out_file">保存导出内容的文件夹或文件.</param>
/// <param name="rgb">使用色彩通道（012顺序BGR，3为使用全部通道）.</param>
/// <returns>int.</returns>
int steg_out_file_lsb(char* in_file, char* out_file, int rgb)
{
	string name;
	return re_hide_file(in_file, out_file, rgb, name);
}



