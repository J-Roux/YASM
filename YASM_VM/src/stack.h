#ifndef _STACK_H
#define _STACK_H
#include "config.h"


typedef POINTER_SIZE ptr_size;



#define STACK_START_ADDRESS -1
#ifdef __cplusplus
extern "C" {
#endif

RESULT push(uint8_t *ptr, ptr_size size);
RESULT pop(uint8_t *ptr, ptr_size size);

RESULT dub(uint16_t size);

RESULT push_byte(uint8_t value);
RESULT push_short(uint16_t value);
RESULT push_int(uint32_t value);
RESULT push_long(uint64_t value);

RESULT pop_byte(uint8_t *value);
RESULT pop_short(uint16_t *value);
RESULT pop_int(uint32_t *value);
RESULT pop_long(uint64_t *value);

ptr_size get_pointer();
uint8_t* get_head(uint8_t shift);

#ifdef __cplusplus
}
#endif
#endif
