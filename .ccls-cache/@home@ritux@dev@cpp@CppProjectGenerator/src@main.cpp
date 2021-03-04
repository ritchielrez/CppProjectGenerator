#include "myheader.h"

using std::cout;

int main(int argc, char * argv[])
{
  char cmd[FILENAME_MAX] = "mkdir ";
  char cCurrentPath[FILENAME_MAX];
  char projectPath[FILENAME_MAX] = "" ;
  char buildPath[FILENAME_MAX] = "";
  char linuxBuildPath[FILENAME_MAX] = "";
  char windowsBuildPath[FILENAME_MAX] = "";
  char srcPath[FILENAME_MAX] = "";
  char includePath[FILENAME_MAX] = "";

  if(argc != 2)
  {
    printf("Invalid number of arguments provided!");
    return 1;
  }

  if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
  {
    return errno;
  }

  cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';  

  strcat(projectPath, cCurrentPath);
  strcat(projectPath, "/");
  strcat(projectPath, argv[1]);
  strcat(cmd, projectPath);

  system(cmd);

  strcat(buildPath, projectPath);
  strcat(buildPath, "/build"); 

  strncpy(cmd, "mkdir ", sizeof(cmd));

  strcat(cmd, buildPath);

  system(cmd);
 
  strcat(linuxBuildPath, buildPath);
  strcat(linuxBuildPath, "/linux");
  
  strncpy(cmd, "mkdir ", sizeof(cmd));

  strcat(cmd, linuxBuildPath);

  system(cmd);

  strcat(windowsBuildPath, buildPath);
  strcat(windowsBuildPath, "/windows");

  strncpy(cmd, "mkdir ", sizeof(cmd));

  strcat(cmd, windowsBuildPath);

  system(cmd);
  
  strcat(srcPath, projectPath);
  strcat(srcPath, "/src");

  strncpy(cmd, "mkdir ", sizeof(cmd));

  strcat(cmd, srcPath);

  strcat(includePath, projectPath);
  strcat(includePath, "/include");

  strcat(cmd, " ");
  strcat(cmd, includePath);

  system(cmd);
  
  
#ifdef WINDOWS
  system("rmdir /s main");
#else
  system("rm -r -v main");
#endif

  return 0;
}
