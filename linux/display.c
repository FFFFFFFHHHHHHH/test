#include "search.h"

int main(int argc, char** argv){
  if (argc < 2) {
    puts("please input search path and key word");
    return 0;
  }

  const char* path = argv[1];
  const char* key_word = argc > 1 ? argv[2] : NULL;

  char** files;
  int file_num;
  files = search_file(path, key_word, &file_num);

  if (file_num == -1) {
    puts("path error");
  } else {
    printf("-- %d results found with key word (%s) in path (%s) --\n", file_num, key_word, path);
    for (int i = 0; i < file_num; i++) {
      printf("%s\n", files[i]);
      free(files[i]);
    }
    free(files);
  }
} 
