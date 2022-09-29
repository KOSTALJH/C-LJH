#include <zlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    char *fileName = NULL; // 입력 받은 파일 이름
    char *gzName = NULL; // 압축 파일 이름
    gzFile *gzfp;
    int fd;
    int n;
    char buf[128];
    int lerrno;

    if(argc != 2) {
        printf("jzip [파일 이름] 형태로 사용하세요.\n");
        return 0;
    }
    fileName = argv[1];
    gzName = (char*)malloc((strlen(fileName)+5)*sizeof(char));
    sprintf(gzName, "%s.gz", fileName);
    if (access(fileName, F_OK) != 0) {
        printf("파일이 존재하지 않습니다.\n");
        return 0;
    }
    if ((fd = open(fileName, O_RDONLY)) < 0) {
        printf("파일 열기에 실패했습니다.\n");
        return 0;
    }
    if ((gzfp = gzopen(gzName, "wb")) == NULL) {
        printf("압축 파일 열기에 실패했습니다.\n");
        return 0;
    }
    while ((n = read(fd, buf, 127)) > 0) {
        if (gzwrite(gzfp, buf, n) < 0){
            printf("%s\n", gzerror(gzfp, &lerrno));
            return 0;
        }
    }
    gzclose(gzfp);
    printf("압축에 성공했습니다.\n");
    return 0;
}
