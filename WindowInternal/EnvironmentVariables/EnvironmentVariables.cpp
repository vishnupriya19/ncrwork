#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<exception>
#include<iostream>
using namespace std;
void DumpEnvString(PTSTR pEnvBlock[])
{
	int count = 0;
	PTSTR curr = NULL;
	PTSTR *pEle = pEnvBlock;
		while (pEle != NULL)
		{
			curr = *pEle;
			if (curr != NULL)
			{
				count++;
				cout << count << " ";
				_tprintf(_T("%S\n"), curr);
			}
			pEle++;
		}
	
}
int main(int argc, TCHAR *argv[], TCHAR *env[])
{
	//DumpEnvString(env);
	TCHAR enV[] = TEXT("%SystemRoot%");
	TCHAR buff[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(enV, buff, MAX_PATH);
	if (!ret)
	{
		cout << GetLastError();
		getchar();
		return 0;
	}
	else
		wcout << buff;
	return 0;
}