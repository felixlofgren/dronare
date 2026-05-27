#ifndef MOTOR_HEADER
#define MOTOR_HEADER

#include <stdint.h>

typedef enum {
    MOTOR_OFF = 0,
    MOTOR_ON = 1,
    MOTOR_ERROR = 7
} MotorTillstånd;

// Motor struct med status, rpm och id
typedef struct {
    uint16_t id;
    uint16_t rpm;
    MotorTillstånd status;
} Motor;

void motor_init(Motor *m, uint16_t id);
void motor_on(Motor *m);
void motor_off(Motor *m);
void motor_set_rpm(Motor *m, uint16_t rpm);
void motor_error(Motor *m);
void motor_print(const Motor* m);
void motor_set_id(Motor *m, uint16_t id);

#endif