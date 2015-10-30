#include <kos.h>

#define DRAW_PIXEL(x, y, c) \
  if((x >= 0) && (x < 640) && (y >= 0) && (y < 480)) \
    vram_s[x + (y * 640)] = c;

#define PACK_PIXEL(r, g, b) ( ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3) )


KOS_INIT_FLAGS(INIT_DEFAULT | INIT_MALLOCSTATS);


int main(int argc, char **argv) {
  vid_set_mode(DM_640x480, PM_RGB888);

  puts("\n\nThis text will be on the console debug.\n");
  puts("Here, we got a black screen on the 'main' screen.\n");
  int x;
  int y;
  int r;
  int g;
  int b;
  x = 50;
  y = 200;
  r = 199;
  g = 342;
  b = 238;


  while (1)
    {
      x++;
      y++;
      r++;
      g++;
      b++;
      vram_s[x + (y * 640)] = PACK_PIXEL(r, g, b);
      if((x >= 0) && (x < 640) && (y >= 0) && (y < 480))
	vram_s[x + (y * 640)] = PACK_PIXEL(r, g, b);
    }
  return (0);
}
