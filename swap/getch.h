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
         // ����һ���¼��ṹ��
        const char* file_name = "/dev/input/event0";
          // ���ü����豸

        int fd = open(file_name, O_RDWR);
         // ��

        if(fd > 0) {
          // ����򿪳ɹ�

                system("stty -echo");

                 while(1)
                 {
                         usleep(10000); // ���п���,��Ч��
                        int ret = read(fd, &key, sizeof(key));  // ��ȡ
                        if(ret == sizeof(key) && key.value == 1) { // ����
                                break;
                         }
                 }

                 system("stty echo");
                 close(fd);
                 // �ر��豸

                return key.code; // ���ؼ�ֵ
        }

         perror("Error : Open file : '/dev/input/event0'");
         return -1;
 // ��ʧ��
}
