#include <kos.h>

KOS_INIT_FLAGS(INIT_DEFAULT | INIT_MALLOCSTATS);

int main(int argc, char **argv) {
  puts("\n\nThis text will be on the console debug.\n");
  puts("Here, we got a black screen on the 'main' screen.\n");
  while (1);
  return 0;
}
