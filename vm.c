#include "stack.h"
#include "command.h"

enum STATE
{
    COMMAND,
    GET_ARG,
    TERMINATE
};

STATE state = GET_ARG;
uint16_t arg;

typedef struct  
{
    u8 * data;
    uint16_t arg;
    uint8_t command;
} data_blob;

void command_proceed(u8 command)
{
    switch(command)
    {
    
    }
}
uint64_t execute_step(data_blob data, u8* code)
{
    uint64_t pointer = 0;
    switch(state)
    {
        case GET_ARG: 
        {
            push(code, data.arg);
            state = COMMAND;
            pointer += data.arg;
            break;
        }
        case COMMAND:
        {
            
            pointer++;
            break;
        }
        case TERMINATE:
        {
            break;
        }
    }
    return pointer;
}