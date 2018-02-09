//#include"includes.h"
static struct termios initial_settings, new_settings;
static int peek_character = -1;

void init_keyboard(void)
{
  tcgetattr(0,&initial_settings);
  new_settings = initial_settings;
  new_settings.c_lflag|= ICANON;
  new_settings.c_lflag|= ECHO;
  new_settings.c_lflag|= ISIG;
  new_settings.c_cc[VMIN] = 1;
  new_settings.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &new_settings);
}

void close_keyboard(void)
{
  tcsetattr(0, TCSANOW, &initial_settings);
}

int kbhit(void)
{
  unsigned char ch;
  int nread;
  if (peek_character != -1) return 1;
  new_settings.c_cc[VMIN] = 0;
  tcsetattr(0, TCSANOW, &new_settings);
  nread = read(0, &ch, 1);
  new_settings.c_cc[VMIN] = 1;
  if(nread == 1)
  {
    peek_character = ch;
    return 1;
  }
  return 0;
}

int readch(void)
{
  char ch;
  if(peek_character != -1)
  {
    ch = peek_character;
    peek_character = -1;
    return ch;
  }
  read(0, &ch, 1);
  return ch;
}

int get_keys(void)
{
  int key;
  init_keyboard();
  kbhit();
  key = readch();
  //return 0;
  close_keyboard();
  return key;
}

int get_key(int *key)
{
    FILE *input;
    FILE *output;
    struct termios initial_settings, new_settings2;
    int inputString;

    input = fopen("/dev/tty", "r");
    output = fopen("/dev/tty", "w");
    if(!input || !output)
    {
        fprintf(stderr, "Unable to open /dev/tty\n");
        exit(1);
    }

    tcgetattr(fileno(input), &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_lflag &= ~ISIG;

    if(tcsetattr(fileno(input), TCSANOW, &new_settings) != 0)
    {
        fprintf(stderr, "Could not set attributes\n");
    }

    //while(inputString != 'c')
    //{
        do
        {
            inputString = fgetc(input);
        }while(inputString == '\n' || inputString == '\r');
        //printf("You have input : %c\n", inputString);
        //return inputString;
        *key = inputString;
    //}
    tcsetattr(fileno(input), TCSANOW, &initial_settings);           // reset the initial settings

    //exit(0);
}
