//jcat.c
#include <zlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char *filename = NULL;
    gzFile *gzfp;
    char buf[128];

    if (argc != 2) {
        printf("jcat [파일 이름] 형태로 사용하세요\n");
        return 0;
    }
    filename = argv[1];

    if ((gzfp = gzopen(filename, "rb")) == NULL) {
				printf("압축 파일을 여는 데 실패했습니다.\n");
        return 0;
    }

    while(gzgets(gzfp, buf, 127) != NULL) {
        printf("%s", buf);
    }
    gzclose(gzfp);
}