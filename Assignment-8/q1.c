#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>
#define MQ_KEY 0x1234

typedef struct msg {
    long type;
    int a, b;
} msg_t;

int main() {
    int mqid, ret, s;
    // create message queue
    mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
    if (mqid < 0) {
        perror("msgget() failed");
        _exit(1);
    }

    ret = fork();
    if (ret == 0) {
        // child: initialize and send the message
        msg_t m1;
        m1.type = 1;
        printf("sender: enter two numbers: ");
        scanf("%d%d", &m1.a, &m1.b);
        ret = msgsnd(mqid, &m1, sizeof(m1) - sizeof(m1.type), 0);
        if (ret < 0) {
            perror("msgsnd() failed");
            _exit(1);
        }
        printf("sender: value of a = %d and b = %d\n", m1.a, m1.b);
    } else {
        // parent: receive the message and print it
        msg_t m2;
        printf("receiver: waiting for the message...\n");
        ret = msgrcv(mqid, &m2, sizeof(m2) - sizeof(m2.type), 1, 0);
        if (ret < 0) {
            perror("msgrcv() failed");
            _exit(1);
        }
        printf("receiver: message received: a = %d, b = %d\n", m2.a, m2.b);

        // wait for child and clean it up
        wait(&s);

        // destroy the message queue
        msgctl(mqid, IPC_RMID, NULL);
    }
    return 0;
}

