#include <stdio.h>      /* for printf and stderr */
#include <string.h>     /* for strerror */
#include <dirent.h>     /* for DIR, opendir, readdir, and dirent */
#include <sys/stat.h>   /* for stat */


//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Reset
#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"


bool isImage(struct stat bufferStat, struct dirent *entry ) {

    char array[][6] = {".png", ".jpg", ".jpeg", ".bmp"};

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        if (strstr(entry->d_name, array[i]) != NULL) {
            return true;
        }
    }

    return false;

}
bool isSource(struct stat bufferStat, struct dirent *entry ) {

    char array[][12] = {".cs", ".c", ".cpp", "html", "js", "ts", ".json", ".r", ".java", ".ninja", ".cmake", ".gitignore"};

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        if (strstr(entry->d_name, array[i]) != NULL) {
            return true;
        }
    }

    return false;

}


int main(int argc, char *argv[]) {

    char dest[256];
    struct dirent* entry;



    if (argc >= 3) {
        fprintf(stderr, "Too many arguments\n");
        return 1;
    }

    if (argv[1] == NULL) {
        strcpy(dest, ".");
    } else {
        printf("%s\n", argv[1]);
        strcpy(dest, argv[1]);
    }

    DIR* dir = opendir(dest);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir))) {
        struct stat bufferStat;

        lstat(entry->d_name, &bufferStat);

        if (S_ISDIR(bufferStat.st_mode)) {
            printf(YEL);
            printf("📁 ");

        } else if (isImage(bufferStat, entry)) {

            printf(GRN);
            printf("🎨 ");

        } else if (isSource(bufferStat, entry)) {
            printf(CYN);
            printf("</> ");

        } else if (S_ISLNK(bufferStat.st_mode)) {
            printf("🔗 ");
            printf(BLU);
        } else {
            printf("🗒️ ");
        }


        printf("%s ", entry->d_name);


        printf(reset);
        printf("\n");


    }

    closedir(dir);


    return 0;
}

