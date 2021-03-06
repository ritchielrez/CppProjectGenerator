#include "myheader.h"

const bool debug = true;

using std::cout;

int main(int argc, char *argv[]) {
  char cmd[256] = "mkdir ";
  char cCurrentPath[256];
  char projectPath[256] = "";
  char buildPath[256] = "";
  char linuxBuildPath[256] = "";
  char windowsBuildPath[256] = "";
  char srcPath[256] = "";
  char includePath[256] = "";

  if (argc != 2) {
    printf("Invalid number of arguments provided!");
    return 1;
  }

  if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) {
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

  FILE *srcFile;
  char srcFileName[256] = "";

  strcat(srcFileName, srcPath);
  strcat(srcFileName, "/main.cpp");

  if (debug) {
    cout << srcPath;
    cout << srcFileName;
  }

  srcFile = fopen(srcFileName, "w");

  fclose(srcFile);

  if (debug) {
#ifdef WINDOWS
    system("rmdir /s main");
#else
    system("rm -r -v main");
#endif

    return 0;
  }
}
