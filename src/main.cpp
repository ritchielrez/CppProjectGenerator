#include "myheader.h"

#define STRING_SIZE_NAME_MAX 256

const bool debug = false;

int main(int argc, char *argv[]) {
  char cmd[STRING_SIZE_NAME_MAX] = "mkdir ";
  char cCurrentPath[STRING_SIZE_NAME_MAX];
  char projectPath[STRING_SIZE_NAME_MAX] = "";
  char buildPath[STRING_SIZE_NAME_MAX] = "";
  char linuxBuildPath[STRING_SIZE_NAME_MAX] = "";
  char windowsBuildPath[STRING_SIZE_NAME_MAX] = "";
  char srcPath[STRING_SIZE_NAME_MAX] = "";
  char includePath[STRING_SIZE_NAME_MAX] = "";

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
  char *srcFileName;

  srcFileName = (char *)malloc(sizeof(char) * STRING_SIZE_NAME_MAX);

  strcat(srcFileName, "");
  strcat(srcFileName, srcPath);
  strcat(srcFileName, "/main.cpp");

  srcFile = fopen(srcFileName, "w");

  fprintf(srcFile, "#include \"myheader.h\"\n\n");
  fprintf(srcFile, "int main(){\n");
  fprintf(srcFile, "\treturn 0;\n");
  fprintf(srcFile, "}\n");

  fclose(srcFile);
  free(srcFileName);

  FILE *includeFile;
  char *includeFileName;

  includeFileName = (char *)malloc(sizeof(char) * STRING_SIZE_NAME_MAX);

  strcat(includeFileName, "");
  strcat(includeFileName, includePath);
  strcat(includeFileName, "/myheader.h");

  includeFile = fopen(includeFileName, "w");

  fprintf(includeFile, "#include <iostream>\n");
  fprintf(includeFile, "#include <vector>\n");
  fprintf(includeFile, "#include <cmath>\n");
  fprintf(includeFile, "#include <map>\n");
  fprintf(includeFile, "#include <cstring>\n");
  fprintf(includeFile, "#include <cstdio>\n\n");
  fprintf(includeFile, "#ifdef WINDOWS\n");
  fprintf(includeFile, "\t#include <dirent.h>\n");
  fprintf(includeFile, "\t#include <windows.h>\n");
  fprintf(includeFile, "#else\n");
  fprintf(includeFile, "\t#include <unistd.h>\n");
  fprintf(includeFile, "\t#include <signal.h>\n");
  fprintf(includeFile, "#endif");


  fclose(includeFile);

  if (debug) {
#ifdef WINDOWS
    system("rmdir /s main");
#else
    system("rm -r -v main");
#endif

    return 0;
  }
}
