
| **Funtion**    | **Description** |
| -------------- | --------------- |
| fopen()        |                 |
| fclose()       |                 |
| fputc()        |                 |
| fgetc()        |                 |
| fprintf()      |                 | 
| fscanf()       |                 |
| [[#fseek()]]   |                 |
| fputw()        |                 |
| fgetw()        |                 |
| [[#ftell()]]   |                 |
| [[#rewind()]]  |                 |
| [[#getline()]] |                 |
|                |                 |

# fseek()
~~~c
// whence: SEEK_SET、SEEK_CUR、SEEK_END
int fseek(FILE *stream, long int offset, int whence)

ex:
#include <stdio.h>
int main()
{
    FILE *fp = NULL;
    char buff[255];
    fp = fopen("test.txt", "w+");
    fputs("This is javatpoint", fp);  
    fseek( fp, 0, SEEK_END );  
    fputs("sonoo jaiswal", fp);  
    fclose(fp);
    return 0;
}
~~~

# rewind()
~~~c
void rewind(FILE *stream)

ex:
#include <stdio.h>
int main()
{
    FILE *fp = NULL;
    char c;
    fp = fopen("test.txt", "r+");

    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }
    rewind(fp); // moves the file pointer at beginning of the file
    while ((c = fgetc(fp)) != EOF)
    {
	    printf("%c", c);
    }
    fclose(fp);
    return 0;
}
~~~

# ftell()
~~~c
long int ftell(FILE *stream)

ex:
#include <stdio.h>
int main()
{
    FILE *fp = NULL;
    int length;
    
    fp = fopen("test.txt", "r+");
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);

    fclose(fp);
    printf("Size of file: %d bytes", length);
    return 0;
}
~~~

# getline()
~~~c
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = NULL;
    char *line = NULL;
    int length;
    size_t read;
  

    fp = fopen("test.txt", "r+");
    while ((read = getline(&line, &length, fp)) != EOF)
    {
       printf("read=%d: %s", read, line);
    }
    fclose(fp);
    return 0;
}
~~~