#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>

int file_exists(char *file) {
  struct stat buf;
  int res = stat(file, &buf);
  if (res)
    return true;
  else switch (errno) {
    case ENOENT:
    case ENOTDIR:
      return false;
    default:
      return true;
  }
}

int is_link(char *file) {
  struct stat buf;
  if (lstat(file, &buf) == 0) {
    return S_ISLNK(buf.st_mode);
  }
}
