#include "stack.h"

static uint8_t data[STACK_SIZE];
static ptr_size pointer = -1;

ptr_size get_pointer() { return pointer;}


RESULT range_check(ptr_size size, ptr_size range)
{	
    if( pointer  > range - size - 1)
      return STACK_OVERFLOW;
    else
      return SUCCESS;
}


RESULT push(uint8_t *ptr, ptr_size size)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
	  result = range_check(size, STACK_SIZE);
  MEMCPY(data + ++pointer, ptr, size);
  pointer += size - 1;
  return result;
}

RESULT pop(uint8_t *ptr, ptr_size size)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
	   result = range_check( -size, 0);
  pointer -= size - 1;
  MEMCPY(ptr, data + pointer, size);
  pointer--;    
  return result;
}

RESULT push_byte(uint8_t value)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
	  result = range_check(sizeof(uint8_t), STACK_SIZE);
  data[++pointer] = value;
  return result;
}

RESULT push_short(uint16_t value)
{
  RESULT result = SUCCESS;
  result = push_byte(value);
  result += push_byte(value >> 8);
  return result;
}

RESULT push_int(uint32_t value)
{
  RESULT result = SUCCESS;
  result = push_short(value);
  result += push_short(value >> 16);
  return result;
}

RESULT push_long(uint64_t value)
{
  RESULT result = SUCCESS;
  result = push_int(value);
  result += push_int(value >> 32);
  return result;
}
RESULT pop_byte(uint8_t *value)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
    result = range_check( - sizeof(uint8_t), 0);
  *value = data[pointer--];
  return result;
}

RESULT pop_short(uint16_t *value)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
    result = range_check( - sizeof(uint16_t), 0);
  pointer -= sizeof(uint16_t) - 1;
  *value = *((uint16_t *)(data + pointer ));
  pointer--;
  return result;
}

RESULT pop_int(uint32_t *value)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
    result = range_check( - sizeof(uint32_t), 0);
  pointer -= sizeof(uint32_t) - 1;
  *value = *((uint32_t *)(data + pointer ));  
  pointer--;
  return result;
}

RESULT pop_long(uint64_t *value)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
    result = range_check( - sizeof(uint64_t), 0);
  pointer -= sizeof(uint64_t) - 1;
  *value = *((uint64_t *)(data + pointer ));  
  pointer--;
  return result;
}


