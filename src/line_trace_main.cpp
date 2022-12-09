#include <Arduino.h>
#include "trace_car.h"

TraceCar *car;

const int delay_millis = 10;
const int reflector_theta = 500;

void setup() {
    car = new TraceCar(
            new Motor(2, 3, 10),
            new Motor(4, 5, 11),
            new PhotoReflector(A0, reflector_theta),
            new PhotoReflector(A1, reflector_theta),
            new PhotoReflector(A2, reflector_theta)
    );
}

void loop() {
    /* TODO: アルゴリズム実行 */
    delay(delay_millis);
}