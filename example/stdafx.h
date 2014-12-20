
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ��� 
// ���Ǿ���ʹ�õ��������ĵ� 
// �ض�����Ŀ�İ����ļ� 

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ����� 
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ�� 

#ifndef UNICODE
#define CGRIDLISTCTRLEX_GROUPMODE
#endif


#pragma warning( disable:4514 )	// warning C4514: unreferenced inline function has been remove
#pragma warning( disable:4710 )	// warning C4710: function not inlined
#pragma warning( disable:4711 )	// warning C4711: function selected for automatic inline expansion
#pragma warning( disable:4820 )	// warning C4820: X bytes padding added after data member

#pragma warning( push )
#pragma warning( disable:4548 )	// warning C4548: expression before comma has no effect; expected expression with side-effect
#pragma warning( disable:4812 )	// warning C4812: obsolete declaration style: please use '_CIP<_Interface,_IID>::_CIP' instead
#pragma warning( disable:4996 )	// warning C4996: This function or variable may be unsafe.
#pragma warning( disable:4005 )	// warning C4005: '_WIN32_WINDOWS' : macro redefinition
#pragma warning( disable:4668 )	// warning C4668: '__midl' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
#pragma warning( disable:4820 )	// warning C4820: X bytes padding added after data member
#pragma warning( disable:4619 )	// warning C4619: #pragma warning : there is no warning number
#pragma warning( disable:4625 )	// warning C4625: copy constructor could not be generated because a base class copy constructor is inaccessible
#pragma warning( disable:4626 )	// warning C4626: assignment operator could not be generated because a base class assignment operator is inaccessible
#pragma warning( disable:4365 )	// warning C4365: '=' : conversion from 'int' to 'size_t', signed/unsigned mismatch
#pragma warning( disable:4244 )	// warning C4244: 'return' : conversion from 'const time_t' to 'LONG_PTR', possible loss of data
#pragma warning( disable:4263 )	// warning C4263: member function does not override any base class virtual member function
#pragma warning( disable:4264 )	// warning C4264: no override available for virtual member function from base; function is hidden
#pragma warning( disable:4917 )	// warning C4917: a GUID can only be associated with a class, interface or namespace
#pragma warning( disable:4555 )	// warning C4555: expression has no effect; expected expression with side-effect
#pragma warning( disable:4640 )	// warning C4640: construction of local static object is not thread-safe
#pragma warning( disable:4571 )	// warning C4571: Informational: catch(...) semantics changed since Visual C++ 7.1; structured exceptions (SEH) are no longer caught


// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������ 
#define _AFX_ALL_WARNINGS

#include <windows.h> 

#if 0
#include <afxwin.h>         // MFC ��������ͱ�׼��� 
#include <afxext.h>         // MFC ��չ 
#include <afxcview.h>


#include <afxdisp.h>        // MFC �Զ����� 



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧�� 
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC �� Windows �����ؼ���֧�� 
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // �������Ϳؼ����� MFC ֧�� 

#include <atlbase.h>
#endif
#pragma warning( pop )




#define RapidJson

#ifdef _DEBUG
	//#pragma comment(lib, "libtcmalloc_minimal-debug.lib")

	#ifdef _MT
		#ifdef _DLL
			//#define BOOST_THREAD_USE_DLL
			//#define _AFXDLL
			#pragma comment(lib, "pugixmlsd_mdd.lib")
			#ifdef RapidJson
			#else
				#pragma comment(lib, "json_vc9_libmdd.lib")
			#endif
		#else
			#pragma comment(lib, "pugixmlsd_mtd.lib")
			#ifdef RapidJson
			#else
				#pragma comment(lib, "json_vc9_libmtd.lib")
			#endif
		#endif
	#endif
#else
	//#pragma comment(lib, "libtcmalloc_minimal.lib")

	#ifdef _MT
		#ifdef _DLL
			//#define BOOST_THREAD_USE_DLL
			//#define _AFXDLL
			#pragma comment(lib, "pugixmls_md.lib")
			#ifdef RapidJson
			#else
				#pragma comment(lib, "json_vc9_libmd.lib")
			#endif
		#else
			#pragma comment(lib, "pugixmls_mt.lib")
			#ifdef RapidJson
			#else
				#pragma comment(lib, "json_vc9_libmt.lib")
			#endif
		#endif
	#endif

#endif


#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#else
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


