#include <stdio.h>
#include "flight.h"

int main() {
    Dronare d;
    dronare_init(&d, 1, 0x100);

    printf("=== Drönarsimuleringsstart ===\n");
    dronare_print(&d);

    printf("\n--- Takeoff ---");
    dronare_takeoff(&d);
    dronare_print(&d);

    printf("\n--- Hovrar ---");
    dronare_hover(&d);
    dronare_print(&d);

    printf("\n--- Ökar höjd ---");
    motor_set_rpm(&d.motor, 7000);
    can_packa_motor(&d.can, &d.motor);
    dronare_print(&d);

    printf("\n--- Fel uppstår ---");
    dronare_error(&d);
    dronare_print(&d);

    printf("\n--- Återställer och landar ---");
    dronare_init(&d, 1, 0x100);
    dronare_takeoff(&d);
    dronare_land(&d);
    dronare_print(&d);

    return 0;
}