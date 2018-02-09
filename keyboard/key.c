//下面的程序主要通过修改结构体termios的值，来改变终端的参数，使得你可以在终端输入后，不需要按下Enter键，就可以直接响应。

//代码实现

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

int main(void)
{
    FILE *input;
    FILE *output;
    struct termios initial_settings, new_settings;
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

    while(inputString != 'q')
    {
        do
        {
            inputString = fgetc(input);
        }while(inputString == '\n' || inputString == '\r');
        printf("You have input : %c\n", inputString);
    }

    tcsetattr(fileno(input), TCSANOW, &initial_settings);           // reset the initial settings

    exit(0);
}

