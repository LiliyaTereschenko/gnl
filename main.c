#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;
    int i;

    i = 1;
    if (argc == 1)
    {
        int k = 0;
        while (get_next_line(0, &line) > 0)
        {
            printf("line %d = %s\n", k, line);
            k++;
        }
    }
    while (i < argc)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
        fd = open(argv[i], O_RDONLY);
        printf("fd = %d\n", fd);
        if (fd == -1)
            write(1, "error file\n", 11);
        int j = 0;
        while (get_next_line(fd, &line) > 0)
        {
            printf("line %d = %s\n", j, line);
            j++;
        }
        i++;   
        close(fd);    
    }
   // printf("fd = 410, %d\n" ,get_next_line(410, &line));

    return (0);
}