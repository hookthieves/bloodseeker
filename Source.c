#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <windows.h>

int main() {
    FILE* regFile;
    char* currentDir = _getcwd(NULL, 0); // Get the current working directory

    if (currentDir == NULL) {
        printf("Error getting current working directory.\n");
        return 1;
    }

    // Change the working directory to where you want to create the .reg file
    if (_chdir(currentDir) != 0) {
        printf("Error changing working directory.\n");
        free(currentDir);
        return 1;
    }

    free(currentDir);

    printf("\t\t\t ###########################################################\n");
    printf("\t\t\t #         Bloodseeker - Designed By Cuong Nguyen          #\n");
    printf("\t\t\t ###########################################################\n");
    printf("[i] Press <Enter> to start program");
    getchar();
    printf("[i] Creating registry hive in location: HKEY_CURRENT_USER\\Software\\Classes\\\n");
    printf("[i] Press <Enter> to continue");
    getchar();

    // Open the .reg file for writing
    regFile = fopen("bloodseeker.reg", "w");

    if (regFile == NULL) {
        printf("Error opening .reg file for writing.\n");
        return 1;
    }

    // Write the registry key information to the file
    fprintf(regFile, "[HKEY_CURRENT_USER\\Software\\Classes\\bloodseeker]\n");
    fprintf(regFile, "@=\"URL:bloodseeker Protocol\"\n");
    fprintf(regFile, "\"URL Protocol\"=\"\"\n");
    fprintf(regFile, "\n");
    fprintf(regFile, "[HKEY_CURRENT_USER\\Software\\Classes\\bloodseeker\\shell]\n");
    fprintf(regFile, "\n");
    fprintf(regFile, "[HKEY_CURRENT_USER\\Software\\Classes\\bloodseeker\\shell\\open]\n");
    fprintf(regFile, "\n");
    fprintf(regFile, "[HKEY_CURRENT_USER\\Software\\Classes\\bloodseeker\\shell\\open\\command]\n");
    fprintf(regFile, "@=\"cmd /k whoami && timout /t 10\"\n");

    // Close the .reg file
    fclose(regFile);

    printf("[*] Registry key created succesfully!\n");
    printf("[i] Press <Enter> to add registry key to hive");
    getchar();
    
    // Execute the bloodseeker.reg file
    system("regedit /s bloodseeker.reg");
    printf("[*] Registry key added to registry hive!\n");
    printf("[i] Press <Enter> to execute protocol handler");
    getchar();
    // Prompt and execute "cmd.exe /k explorer bloodseeker://test"
    system("cmd.exe /k explorer bloodseeker://test");
    printf("[i] Press <Enter> to close program");
    getchar();


    return 0;
}
