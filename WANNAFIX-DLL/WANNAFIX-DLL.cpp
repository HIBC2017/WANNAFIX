#include <stdio.h>
#include <stdlib.h>
#include <string>
// I use mingw... sorry...
// #include <Windows.h>
// #include <Winuser.h>
// build instructions under linux:
// $> i686-w64-mingw32-g++ -c -DBUILDING_EXAMPLE_DLL WANNAFIX-DLL.cpp 
// $> i686-w64-mingw32-g++ -shared -o WANNAFIX.dll WANNAFIX-DLL.o -Wl,--out-implib,WANNAFIX-DLL.a
// dependencies: sudo dnf install mingw32-winpthreads* mingw32-gcc-c++.x86_64 
#include <windows.h>
#include <winuser.h>


int addDomainsToHost()
{
    // FIXME add conditional to check that these are already in place... 
    char domainone[500]="\n216.58.197.132 iuqerfsodp9ifjaposdfjhgosurijfaewrwergwea.com";
    char domaintwo[500]="\n54.153.0.145 ifferfsodp9ifjaposdfjhgosurijfaewrwergwea.com";
    char domainthree[500]="\n207.154.243.152 ayylmaotjhsstasdfasdfasdfasdfasdfasdfasdf.com";
    char domainfour[500]="\n217.182.141.137 iuqssfsodp9ifjaposdfjhgosurijfaewrwergwea.com";
    char domainfive[500]="\n216.58.197.132 iuqerfsodp9ifjaposdfjhgosurijfaewrwergwea.com";
    FILE *fptr;
    fptr = fopen("C:\\Windows\\System32\\drivers\\etc\\hosts", "a");
    fprintf(fptr,"%s", domainone);
    fprintf(fptr,"%s", domaintwo);
    fprintf(fptr,"%s", domainthree);
    fprintf(fptr,"%s", domainfour);
    fprintf(fptr,"%s", domainfive);
    fclose(fptr);
}

int disableSMBv1()
{
    // FIXME add conditional to *not* do this if SMBv1 is disabled
    system("powershell.exe Set-ItemProperty -Path \"HKLM:\\SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters\" SMB1 -Type DWORD -Value 0 -Force");
    // commented this out so as to not continually restart machines... 
    //system("shutdown -r -t 15");
}

int createMutex()
{
    HANDLE mutexObj  = CreateMutex(NULL,TRUE,"Global\\MsWinZonesCacheCounterMutexA0");
    if(GetLastError() == ERROR_ALREADY_EXISTS){
        return 0;
    }
    HWND hWnd = GetConsoleWindow(); 
    ShowWindow(hWnd, SW_HIDE);
    while(1){
        Sleep(10000);
    }
    // FIXME this will probably never run, owing to the mutex being in place...
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason, LPVOID lpvReserved)
{
    // what does this do?
    char first;
    // two can play at this game...
    char moar_magic;
    disableSMBv1();
    addDomainsToHost();
    createMutex();
    return 0;
}
