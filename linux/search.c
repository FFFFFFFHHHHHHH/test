#include "search.h"


// 检测字符串p是否为字符串s子串
int check_substr(const char* s, const char* p) {
  if (p == NULL) return 1;
  int lens = strlen(s), lenp = strlen(p);
  for (int i = 0; i < lens - lenp + 1; i++) {
    if (strncmp(s+i, p, lenp) == 0) {
      return 1;
    }
  }
  return 0;
}

char** search_file(const char *p_dir_name, const char* key_word, int *file_num) {
  char** files; // 返回文件列表
  DIR *p_dir = opendir(p_dir_name);
  if (p_dir == NULL) {
    *file_num = -1;
    return NULL;
  }
  struct dirent* p_file = NULL;
  *file_num = 0; // 返回查抄成功文件数量
  while ((p_file = readdir(p_dir)) != NULL) {
    if (strcmp(p_file->d_name, ".") != 0 &&
      strcmp(p_file->d_name, "..") != 0) {
      if (!check_substr(p_file->d_name, key_word)) continue;
      (*file_num)++;
    }
  }
  files = (char **) malloc(*file_num * sizeof (char*));
  p_dir = opendir(p_dir_name);
  int index = 0;
  while ((p_file = readdir(p_dir)) != NULL) {
    if (strcmp(p_file->d_name, ".") != 0 &&
      strcmp(p_file->d_name, "..") != 0) {
      if (!check_substr(p_file->d_name, key_word)) continue;
      files[index] = (char*) malloc((strlen(p_file->d_name) + strlen(p_dir_name) + 2) * sizeof(char));
      strcpy(files[index], p_dir_name);
      if (p_dir_name[strlen(p_dir_name)-1] != '/') {
        strcat(files[index], "/");
      }
      strcat(files[index], p_file->d_name);
      index++;
    }
  }
  closedir(p_dir);
  return files;
}
