#include <stdio.h>
 #include <stdlib.h>
 #include <linux/input.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <errno.h>
 int getch()
 {
         struct input_event key = {{0}, 0};
         // 声明一个事件结构体
        const char* file_name = "/dev/input/event0";
          // 设置键盘设备

        int fd = open(file_name, O_RDWR);
         // 打开

        if(fd > 0) {
          // 如果打开成功

                system("stty -echo");

                 while(1)
                 {
                         usleep(10000); // 可有可无,增效率
                        int ret = read(fd, &key, sizeof(key));  // 读取
                        if(ret == sizeof(key) && key.value == 1) { // 分析
                                break;
                         }
                 }

                 system("stty echo");
                 close(fd);
                 // 关闭设备

                return key.code; // 返回键值
        }

         perror("Error : Open file : '/dev/input/event0'");
         return -1;
 // 打开失败
}
