#ifndef IPC_SHM_H
#define IPC_SHM_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>


typedef struct 
{
    uint16_t index;
} ipc_data_t;

void ipc_shm_write(uint16_t index);
uint16_t ipc_shm_read(void);
void ipc_shm_close(void);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif

