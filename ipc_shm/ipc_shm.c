#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include "ipc_shm.h"
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE  sizeof(uint16_t)

void ipc_shm_write(uint16_t index)
{
    key_t key = ftok("/tmp", 'A');
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    char *shmaddr = shmat(shmid, NULL, 0);

    sprintf(shmaddr, "%d", index);
    shmdt(shmaddr); // 断开连接
}

uint16_t ipc_shm_read(void)
{
    uint16_t index = 0;
    key_t key = ftok("/tmp", 'A');
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    char *shmaddr = shmat(shmid, NULL, 0);

    printf("Message from shared memory: %s\n", shmaddr);
    if (*shmaddr != NULL)
    {
        index = atoi(shmaddr);
    }
    
    shmdt(shmaddr); // 断开连接
    return index;
}

void ipc_shm_close(void)
{
    key_t key = ftok("/tmp", 'A');
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    shmctl(shmid, IPC_RMID, NULL); // 删除共享内存段
}

