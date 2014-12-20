// LibAsioTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "LibAsioTest.h"
#include "IAsioFacade.h"
#pragma  comment(lib,"LibAsio.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣


		std::map<std::string,std::map<std::string,std::string> > cmdParam;
		cmdParam["listen"]["io_service_pool_size"] = "4";
		cmdParam["listen"]["speed_threads_for_a_io_service"] = "4";
		cmdParam["network"]["io_service_pool_size"] = "4";
		cmdParam["network"]["speed_threads_for_a_io_service"] = "4";
		cmdParam["timer"]["io_service_pool_size"] = "4";
		cmdParam["timer"]["speed_threads_for_a_io_service"] = "4";
		cmdParam["host"]["address"] = "127.0.0.1";
		cmdParam["host"]["port"] = "20000";



		GetFacadeInstance(ServerFacade).Configure(cmdParam);


	}

	return nRetCode;
}
