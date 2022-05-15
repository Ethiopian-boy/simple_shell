
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *fileName = argv[1];
    if (fileName == NULL)
    {
        return 0;
    }

    char cwd[1024];
    struct dirent *de; // Pointer for directory entry

    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(".");

    if (dr == NULL) // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory");
        return 0;
    }

    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    // for readdir()
    while ((de = readdir(dr)) != NULL)
    {
        if (strcmp(de->d_name, fileName) == 0)
        {
            getcwd(cwd, sizeof(cwd));
            printf("%s/%s\n", cwd, de->d_name);
        }
    }

    closedir(dr);
    return 0;
}
