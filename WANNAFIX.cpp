#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <Windows.h>
#include <Winuser.h>


int main()
{
    char first;
    char answer;


    printf("\n \tDo you want to disable SMB? (Y/N)");
    scanf("%c", &answer);

    if(answer == 'y' || answer == 'Y')
    {
        system("powershell.exe Set-ItemProperty -Path \"HKLM:\\SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters\" SMB1 -Type DWORD -Value 0 -Force");
    }

    printf("\n \tDo you want to add the kill switch domains to your host file? (Y/N)");
    scanf(" %c", &answer);
    
    if(answer == 'y' || answer == 'Y')
    {

	    char domainone[500]="\n216.58.197.132 iuqerfsodp9ifjaposdfjhgosurijfaewrwergwea.com";
	    char domaintwo[500]="\n216.58.197.132 www.iuqerfsodp9ifjaposdfjhgosurijfaewrwergwea.com";;
        FILE *fptr;

        fptr = fopen("C:\\Windows\\System32\\drivers\\etc\\hosts", "a");

        fprintf(fptr,"%s", domainone);
        fprintf(fptr,"%s", domaintwo);
        fclose(fptr);
    }
    
    printf("\n \tDo you want to spawn the MUTEX to prevent WANNACRY from running? (Y/N)");
    
    answer = 'n';
    scanf(" %c", &answer);
    
    
    if(answer == 'Y' || answer == 'y')
    {
    	HANDLE mutexObj  = CreateMutex(NULL,TRUE,"Global\\MsWinZonesCacheCounterMutexA0");
    	if(GetLastError() == ERROR_ALREADY_EXISTS){
    		printf("\n \tFATAL: There was an error creating the MUTEX, your machine is already infected or you have run this script previously! Error code: %d", GetLastError());
    		while(1){
    			Sleep(10000);
    		}
    	}
    	printf("\n \tMUTEX spawned, press any key to leave it running in the background!");
    	
        scanf("\n\n");
        HWND hWnd = GetConsoleWindow(); 
        ShowWindow(hWnd, SW_HIDE);
    	while(1){
    		Sleep(10000);
    	}
    }
    
   return 0;
}