// MSFTNetCfgTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <netcfgx.h>

int main()
{
	HRESULT hr = E_FAIL;
	
	hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);

	if (FAILED(hr)) {
		printf("Error 0x%08x\n", hr);
	}
	else
	{
		OLECHAR * wGuidString = NULL;
		::StringFromCLSID(CLSID_CNetCfg, &wGuidString);

		printf("CoCreateInstance - %ls\n", wGuidString);

		if (wGuidString != NULL) ::CoTaskMemFree(wGuidString);

		INetCfg * pNetCfg = NULL;
		hr = ::CoCreateInstance(CLSID_CNetCfg, NULL, CLSCTX_INPROC_SERVER, IID_INetCfg, (LPVOID *)&pNetCfg);

		if (FAILED(hr)) {
			printf("Error 0x%08x\n", hr);
		}
		else
		{
			printf("Created INetCfg * %08p\n", pNetCfg);

			if (NULL != pNetCfg)
			{
				printf("Releasing INefCfg\n");
				pNetCfg->Release();				
			}
		}
	}

    return 0;
}

