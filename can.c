#include "can.h"
#include <stdio.h>

void can_init(CAN_Meddelande* c, uint16_t id){
    c->id = id;
    c->längd = 0;
    for (int i = 0; i<8 ; i++){
        c->data[i] = 0;
    }
}

void can_print(const CAN_Meddelande* c) {
    printf("CAN id: 0x%x | Längd: %d | Data: ", c->id, c->längd);
    for (int i = 0; i < c->längd; i++) {
        printf("%d ", c->data[i]);
    }
    printf("\n");
}

void can_packa_motor(CAN_Meddelande* c, const Motor* m){
    c->längd = 5;
    c->data[0] = m->id & 0xFF;          // id låg byte
    c->data[1] = (m->id >> 8) & 0xFF;   // id hög byte
    c->data[2] = m->rpm & 0xFF;         // rpm låg byte
    c->data[3] = (m->rpm >> 8) & 0xFF;  // rpm hög byte
    c->data[4] = m->status;             // status
}