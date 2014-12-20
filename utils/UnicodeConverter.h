/* ----------------------------------------------------------
文件名称：UnicodeConverter.h

作者：秦建辉

MSN：splashcn@msn.com

当前版本：V1.0

历史版本：
	V1.0	2010年03月12日
			完成正式版本。

功能描述：
	Unicode内码转换器。用于utf-8、utf-16（UCS2）、utf-32（UCS4）之间的编码转换
 ------------------------------------------------------------ */
#pragma once

//#include "CompilerConfig.h"

//#include <windows.h>
#include <stdio.h>
#include <ostream>


class UnicodeConverter
{
/* -------------------------------------------------------------
					内码转换
   ------------------------------------------------------------- */
public:
	/*
	功能：将UCS4编码转换成UTF8编码
	参数：
		dwUCS4：要转换的UCS4编码
		pbUTF8：用于存储转换后的UTF8编码。设为NULL，可以获取长度信息（字节数）
	返回值：
		  0：无效的UCS4编码
		1-6：UTF8编码的有效长度
	*/
	static int UCS4_To_UTF8( unsigned dwUCS4, unsigned char* pbUTF8 );

	/*
	功能：将UTF8编码转换成UCS4编码
	参数：
		pbUTF8：要转换的UTF8编码
		dwUCS4：存储转换后的UCS4编码
	返回值：
		  0：参数错误或无效的UTF8编码
		1-6：UTF8编码的有效长度
	*/
	static int UTF8_To_UCS4( const unsigned char* pbUTF8, unsigned& dwUCS4 );

	/*
	功能：将UCS4编码转换成UTF16编码
	参数：
		dwUCS4：要转换的UCS4编码
		pwUTF16：用于存储转换后的UTF16编码。设为NULL，可以获取长度信息（字符数）
	返回值：
		0：无效的UCS4编码
		1：转换成1个UTF16编码
		2：转换成2个UTF16编码
	*/
	static int UCS4_To_UTF16( unsigned dwUCS4, unsigned short* pwUTF16 );

	/*
	功能：将UTF16编码转换成UCS4编码
	参数：
		pwUTF16：需要转换的UTF16编码
		dwUCS4：存储转换后的UCS4编码
	返回值：
		0：参数错误或无效的UTF16编码
		1：1个UTF16编码被转换
		2：2个UTF16编码被转换
	*/
	static int UTF16_To_UCS4( const unsigned short* pwUTF16, unsigned& dwUCS4 );

	/*
	功能：将UTF8字符串转换成UTF16字符串
	参数：
		pbszUTF8Str：需要转换的UTF8字符串
		pwszUTF16Str：存储转换后的UTF16字符串。设为NULL，可以获取所需长度信息（字符数）
	返回值：
		 0：转换失败
		>0：UTF16字符串长度
	*/
	static int UTF8Str_To_UTF16Str( const unsigned char* pbszUTF8Str, unsigned short* pwszUTF16Str );

	/*
	功能：将UTF16字符串转换成UTF8字符串
	参数：
		pwszUTF16Str：需要转换的UTF16字符串
		pbszUTF8Str：存储转换后的UTF8字符串。设为NULL，可以获取所需长度信息（字节数）
	返回值：
		 0：转换失败
		>0：UTF8字符串长度（不包括NULL字符）
	*/
	static int UTF16Str_To_UTF8Str( const unsigned short* pwszUTF16Str, unsigned char* pbszUTF8Str );

/* -------------------------------------------------------------
					C文件写入操作
   ------------------------------------------------------------- */
public:
	/*
	功能：向文件中写入UTF8编码
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF8_By_UCS4( FILE* out, unsigned dwUCS4 );

	/*
	功能：向文件中写入UTF16编码
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF16_By_UCS4( FILE* out, unsigned dwUCS4, bool isBigEndian = false );

	/*
	功能：将UTF16字符串以UTF8编码输出到文件中
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF8Str_By_UTF16Str( FILE* out, const unsigned short* pwszUTF16Str );
	
	/*
	功能：将UTF8字符串以UTF16编码输出到文件中
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF16Str_By_UTF8Str( FILE* out, const unsigned char* pbszUTF8Str, bool isBigEndian = false );

	/*
	功能：向文件中输出UTF8编码字节序标记
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF8_BOM( FILE* out );

	/*
	功能：向文件中输出UTF16编码字节序标记
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF16_BOM( FILE* out, bool isBigEndian = false );

/* -------------------------------------------------------------
					C++流输出操作
   ------------------------------------------------------------- */
public:
	/*
	功能：向流中写入UTF8编码
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF8_By_UCS4( std::ostream& os, unsigned dwUCS4 );

	/*
	功能：向流中写入UTF16编码
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF16_By_UCS4( std::ostream& os, unsigned dwUCS4, bool isBigEndian = false );

	/*
	功能：将UTF16字符串以UTF8编码输出到流中
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF8Str_By_UTF16Str( std::ostream& os, const unsigned short* pwszUTF16Str );
	
	/*
	功能：将UTF8字符串以UTF16编码输出到流中
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF16Str_By_UTF8Str( std::ostream& os, const unsigned char* pbszUTF8Str, bool isBigEndian = false );

	/*
	功能：向流中输出UTF8编码字节序标记
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF8_BOM( std::ostream& os );

	/*
	功能：向流中输出UTF16编码字节序标记
	返回值：
		写入的字节数
	*/
	static unsigned int Print_UTF16_BOM( std::ostream& os, bool isBigEndian = false );
};

/* ------------------------------
				END
   ------------------------------ */
