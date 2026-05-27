#include "flight.h"
#include <stdio.h>

void dronare_init(Dronare *d, uint16_t motor_id, uint16_t can_id) {
    d->mode = FLIGHT_MODE_IDLE;
    motor_init(&d->motor, motor_id);
    can_init(&d->can, can_id);
}

void dronare_takeoff(Dronare *d) {
    d->mode = FLIGHT_MODE_TAKEOFF;
    motor_on(&d->motor);
    motor_set_rpm(&d->motor, 3000);
    can_packa_motor(&d->can, &d->motor);
}

void dronare_hover(Dronare *d) {
    d->mode = FLIGHT_MODE_HOVER;
    motor_set_rpm(&d->motor, 5000);
    can_packa_motor(&d->can, &d->motor);
}

void dronare_land(Dronare *d) {
    d->mode = FLIGHT_MODE_LAND;
    motor_set_rpm(&d->motor, 1000);
    can_packa_motor(&d->can, &d->motor);
    motor_off(&d->motor);
    can_packa_motor(&d->can, &d->motor);
}

void dronare_error(Dronare *d) {
    d->mode = FLIGHT_MODE_ERROR;
    motor_error(&d->motor);
    can_packa_motor(&d->can, &d->motor);
}

void dronare_print(const Dronare *d) {
    printf("\n=== Drönarstatus ===\n");
    printf("Flygläge: ");
    switch (d->mode) {
        case FLIGHT_MODE_IDLE:      printf("IDLE\n");       break;
        case FLIGHT_MODE_TAKEOFF:   printf("TAKEOFF\n");    break;
        case FLIGHT_MODE_HOVER:     printf("HOVER\n");      break;
        case FLIGHT_MODE_LAND:      printf("LAND\n");       break;
        case FLIGHT_MODE_ERROR:     printf("ERROR\n");      break;
        default:                    printf("OKÄNT\n");      break;
    }
    motor_print(&d->motor);
    can_print(&d->can);
}