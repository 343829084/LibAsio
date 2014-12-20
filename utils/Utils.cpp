#include "StdAfx.h"
#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ

#include "Utils.h"
/////////////////////////////////////////////////////////////////////////////////////////////

std::string GBToUTF8(const char* str)
{
	std::string result;
	WCHAR *strSrc;
	TCHAR *szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	//strSrc  = (WCHAR *)alloca((i+1)*sizeof(WCHAR));
	strSrc = new WCHAR[i+1];
	MultiByteToWideChar(CP_ACP, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_UTF8, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new TCHAR[i+1];
	//szRes  = (TCHAR *)alloca((i+1)*sizeof(TCHAR));

	int j=WideCharToMultiByte(CP_UTF8, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete []strSrc;
	delete []szRes;

	return result;
}

std::string UTF8ToGB(const char* str)
{
	std::string result;
	WCHAR *strSrc;
	TCHAR *szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i+1];
	//strSrc  = (WCHAR *)alloca((i+1)*sizeof(WCHAR));

	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new TCHAR[i+1];
	//szRes  = (TCHAR *)alloca((i+1)*sizeof(TCHAR));
	int j=WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete []strSrc;
	delete []szRes;

	return result;
}

/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
