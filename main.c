#include <stdio.h>      /* for printf and stderr */
#include <string.h>     /* for strerror */
#include <dirent.h>     /* for DIR, opendir, readdir, and dirent */
#include <errno.h>      /* for errno */
#include <sys/stat.h>   /* for stat */

int main(int argc, char **argv)
{
    DIR*           FD;        /* represent the directory */
    struct dirent* in_file;   /* represent the file */
    char*          target_dir = "."; /* current directory */

    /* Scanning the target directory */
    FD = opendir(target_dir);
    if (FD == NULL)
    {
        fprintf(stderr, "Error: Failed to open input directory - %s\n", strerror(errno));
        return 1;
    }

    /* Reading object (files, directories ...) from the folder */
    while ((in_file = readdir(FD)))
    {
        struct stat buffer;
        int         status;

        status = stat(in_file->d_name, &buffer);
        /* check status */
        if (status == -1)
        {
            fprintf(stderr, "Error: Failed to stat item - %s\n", strerror(errno));
            return 1;
        }
        /* check result */
        if ( buffer.st_mode & S_IFREG )
        {
            printf("%s is file \n", in_file->d_name);
        }
    }

    /* Close the directory */
    closedir(FD);

    return 0;
}
