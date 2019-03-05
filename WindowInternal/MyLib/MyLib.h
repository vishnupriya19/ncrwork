#pragma once
#ifdef MYLIB_EXPORTS
#define MYLIBAPI extern "C" __declspec(dllexport)
#else
#define MYLIBAPI extern "C" __declspec(dllimport)
#endif
MYLIBAPI int add(int a, int b);
MYLIBAPI int sub(int a, int b);
MYLIBAPI int mul(int a, int b);
MYLIBAPI int division(int a, int b);
//MYLIBAPI BOOL WINAPI DllMain(HANDLE hand,DWORD msg,LPVOID res);
