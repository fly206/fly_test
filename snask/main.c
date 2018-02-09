#include"includes.h"
//void display(void);
int main()
{
  int flags;
  flags = 1;
  initmap();
  while(flags)
  {
    int key=0;
    system("clear");
    //get_key(&key);
    display();
    flags=is_end();
    usleep(100);
    system("\n");
  }
  //init_keyboard();
  //close_keyboard();
  //get_keys();
  return 0;
}
