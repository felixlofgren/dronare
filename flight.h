#ifndef FLIGHT_HEADER
#define FLIGHT_HEADER

#include "motor.h"
#include "can.h"

typedef enum {
    FLIGHT_MODE_IDLE,
    FLIGHT_MODE_TAKEOFF,
    FLIGHT_MODE_HOVER,
    FLIGHT_MODE_LAND,
    FLIGHT_MODE_ERROR,
    FLIGHT_MODE_COUNT
} FlightMode;

typedef struct {
    FlightMode mode;
    Motor motor;
    CAN_Meddelande can;
} Dronare;

void dronare_init(Dronare *d, uint16_t motor_id, uint16_t can_id);
void dronare_takeoff(Dronare *d);
void dronare_hover(Dronare *d);
void dronare_land(Dronare *d);
void dronare_error(Dronare *d);
void dronare_print(const Dronare *d);

#endif