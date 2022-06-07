#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
        pid_t pid;
        int hoge = 12;

        printf("root getpid:%d\n", getpid());
        printf("root getppid:%d\n", getppid());

        pid = fork();
        if (pid < 0) {
                fprintf(stderr, "Error fork %d\n", errno);
                exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
                //子プロセス処理
                printf("child pid:%d\n", pid);
                printf("child getpid:%d\n", getpid());
                printf("child getppid:%d\n", getppid());
                printf("child hoge:%d\n", hoge); // フォークの時点で持っていた値を継承
                printf("child hoge pointer:%p\n", &hoge);
                hoge++;
                printf("child hoge:%d\n", hoge);
                printf("child hoge pointer:%p\n", &hoge);
                _exit(0); //子プロセスでは終了時には_exitを呼ぶことに注意!
        }
        else {
                //親プロセス処理
                printf("parent pid:%d\n", pid);
                printf("parent getpid:%d\n", getpid());
                printf("parent getppid:%d\n", getppid());
                printf("parent hoge:%d\n", hoge); // フォークの時点で持っていた値を継承
                printf("parent hoge pointer:%p\n", &hoge);
                hoge--;
                printf("parent hoge:%d\n", hoge);
                printf("parent hoge pointer:%p\n", &hoge);
                waitpid(pid, NULL, 0); //子プロセス終了を待つ
                //kill(pid, SIGKILL); //子プロセスにシグナルを送信する

                hoge--;
                printf("parent hoge:%d\n", hoge);
                printf("parent hoge pointer:%p\n", &hoge);
                exit(0); //親プロセスでは終了時にはexitを呼ぶ
        }

        printf("hogehoge\n");

        return 0;
}
