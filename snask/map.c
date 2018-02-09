//#include"includes.h"
typedef struct maps
{
  char m;
  char s;
}maps;
//char map[32][64];
maps map[32][64];

void initmap(void)
{
  map[16][32].m = 'X';
  map[16][31].m = '*';
  map[16][30].m = '*';
}

void display(void)
{
  int x,y;
  char key;
  get_key(&key);
  for(y=0;y<32;y++)
  {
    for(x=0;x<64;x++)
    {
      if(map[y][x].m == 'X')
      {
        //map[y][x].s == '';
        if(key == 'w' && map[y-1][x].m != '*')
        {
          map[y+1][x].m == 'X';
          map[y][x].s == 'w';
        }
        else if(key == 's' && map[y+1][x].m != '*')
        {
          map[y-1][x].m == 'X';
          map[y][x].s == 's';
        }
        else if(key == 'd' && map[y][x-1].m != '*')
        {
          map[y][x+1].m == 'X';
          map[y][x].s == 'd';
        }
        else if(key == 'a' && map[y][x+1].m != '*')
        {
          map[y][x+1].m == 'X';
          map[y][x].s == 'a';
        }
        else
        {

        }
      }
      else if(map[y][x].m == '*')
      {

      }
      else
      {
        if(y==0||y==31)
          //printf("0");
          map[y][x].m='0';
        else if(x==0||x==63)
          //printf("0");
          map[y][x].m='0';
        else
          //printf(" ");
          map[y][x].m=' ';
      }
        //printf("\n");
    }
    for(y=0;y<32;y++)
    {
      for(x=0;x<64;x++)
        printf("%c", map[y][x].m);
      printf("\n");
    }
  }
}

int is_end(void)
{
  int key;
  get_key(&key);
  if(key == 'c')
    return 0;
  else
    return 1;
}
