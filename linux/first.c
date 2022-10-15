//
// Created by B1GGersnow on 2022/9/30.
//

#include "stdio.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd,loc1,loc2;
    char ch;
    // 以只读形式打开文件infile
    fd = open("infile",O_RDONLY,0);
    // 文件定位从当前开始位置往后位移10字节
    loc1 = lseek(fd, 10, SEEK_CUR);
    // 读取一个字节到ch
    read(fd, &ch, 1);
    // 文件定位从文件最后
    loc2 = lseek(fd, 0, SEEK_END);
    printf("loc1=%d ch%c,loc2=%d\n",loc1,ch,loc2);
    lseek(fd, -2, SEEK_END);
    int k = read(fd, &ch, 1);
    printf("%d ch:%c",k, ch);

}
//#include "stdio.h"
//int main(){
//    freopen("infile","w",stdout);
//    for(int i = 0;i < 26;i++){
//        printf("%c",'a' + i);
//    }
//    printf("\n");
//}