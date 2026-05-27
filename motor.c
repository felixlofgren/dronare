#include "motor.h"
#include <stdio.h>

void motor_init(Motor *m, uint16_t id){
    m->id = id;
    m->rpm = 0;
    m->status = MOTOR_OFF;
}

void motor_on(Motor *m){
    m->status = MOTOR_ON;
}

void motor_off(Motor *m){
    m->rpm = 0;
    m->status = MOTOR_OFF;
}

void motor_set_rpm(Motor *m, uint16_t rpm){
    if (m->status == MOTOR_ON) {
        m->rpm = rpm;
    }
}

void motor_error(Motor *m){
    m->rpm = 0;
    m->status = MOTOR_ERROR;
}

void motor_print(const Motor* m) {
    printf("Motor id: %d, rpm: %4d, status: ", m->id, m->rpm);
    switch (m->status) {
        case MOTOR_ON:      printf("PÅ\n");     break;
        case MOTOR_OFF:     printf("AV\n");     break;
        case MOTOR_ERROR:   printf("ERROR\n");  break;
        default:            printf("Okänt");    break;
    }
}