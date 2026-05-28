#ifndef CAN_HEADER
#define CAN_HEADER

#include "motor.h"

typedef struct {
    uint16_t id;
    uint8_t längd;
    uint8_t data[8];
} CAN_Meddelande;

void can_init(CAN_Meddelande* c, uint16_t id);
void can_print(const CAN_Meddelande* c);
void can_packa_motor(CAN_Meddelande* c, const Motor* m);
void can_reset(CAN_Meddelande* c)

#endif