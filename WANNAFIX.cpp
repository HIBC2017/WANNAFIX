#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include <Winuser.h>


int main()
{
    char first;
    char answer;
    bool mutex = false;


    printf("        ,      ,\n");
    printf("        /(.-""-.)\\ \n");
    printf("   |\\  \\/      \\/  /| \n");
    printf("   | \\ / =.  .= \\ / | \n");
    printf("   \\( \\   o\\/o   / )/ \n");
    printf("    \\_, '-/  \\-' ,_/ \n");
    printf("      /   \\__/   \\ \n");
    printf("      \\ \\__/\\__/ /     \"WANNAFIX, MAKING WANNACRY, CRY!\" \n");
    printf("    ___\\ \\|--|/ /__ \n");
    printf("  /`    \\      /    `\\ \n");
    printf(" /       '----'       \\\n");
    printf("\n");

    printf("\n Do you want to add the kill switch domains to your host file?\n (Y/N) ");
    scanf("%c", &answer);
    
    if(answer == 'y' || answer == 'Y')
    {

        char domainone[500]="\n216.58.197.132 iuqerfsodp9ifjaposdfjhgosurijfaewrwergwea.com";
        char domaintwo[500]"\n54.153.0.145 ifferfsodp9ifjaposdfjhgosurijfaewrwergwea.com";
        char domainthree[500]"\n207.154.243.152 ayylmaotjhsstasdfasdfasdfasdfasdfasdfasdf.com";
        char domainfour[500]="\n216.58.197.132 iuqerfsodp9ifjaposdfjhgosurijfaewrwergwea.com";;
        FILE *fptr;

        fptr = fopen("C:\\Windows\\System32\\drivers\\etc\\hosts", "a");

        fprintf(fptr,"%s", domainone);
        fprintf(fptr,"%s", domaintwo);
        fprintf(fptr,"%s", domainthree);
        fprintf(fptr,"%s", domainfour);
        fclose(fptr);
    }
    
    printf("\n Do you want to spawn the MUTEX to prevent WANNACRY from running?\n (Y/N) ");
    
    answer = 'n';
    scanf(" %c", &answer);
    
    
    if(answer == 'Y' || answer == 'y')
    {
        mutex = true;
    }

    printf("\n Do you want to disable SMB? (note that this option requires a reboot, all other options do not!) \n (Y/N) ");
    scanf(" %c", &answer);

    if(answer == 'y' || answer == 'Y')
    {
        system("powershell.exe Set-ItemProperty -Path \"HKLM:\\SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters\" SMB1 -Type DWORD -Value 0 -Force");
        printf("\n Do you want to reboot now? (make sure you spawn the MUTEX again after reboot!) \n (Y/N) ");
        scanf(" %c", &answer);

        if(answer == 'y' || answer == 'Y')
            system("shutdown -r -t 15");
    }

    if(mutex == true)
    {
        HANDLE mutexObj  = CreateMutex(NULL,TRUE,"Global\\MsWinZonesCacheCounterMutexA0");
        if(GetLastError() == ERROR_ALREADY_EXISTS){
            printf("\n FATAL: There was an error creating the MUTEX, your machine is already infected or you have run this script previously! Error code: %d", GetLastError());
            while(1){
                Sleep(10000);
            }
        }

        HWND hWnd = GetConsoleWindow(); 
        ShowWindow(hWnd, SW_HIDE);
        while(1){
            Sleep(10000);
        }
    }
    
   return 0;
}
