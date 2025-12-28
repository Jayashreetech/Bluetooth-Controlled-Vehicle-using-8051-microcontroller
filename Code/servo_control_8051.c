#include <reg52.h>

sbit SERVO_LEFT  = P1^0;
sbit SERVO_RIGHT = P1^1;

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void servo_pulse(sbit servo, unsigned int on_time) {
    unsigned int i;
    for(i = 0; i < 50; i++) {
        servo = 1;
        delay_ms(on_time);
        servo = 0;
        delay_ms(20 - on_time);
    }
}

void main() {
    while(1) {
        // Forward
        servo_pulse(SERVO_LEFT, 1);
        servo_pulse(SERVO_RIGHT, 1);

        // Left 90-degree turn
        servo_pulse(SERVO_LEFT, 0);
        servo_pulse(SERVO_RIGHT, 1);

        // Right 90-degree turn
        servo_pulse(SERVO_LEFT, 1);
        servo_pulse(SERVO_RIGHT, 0);
    }
}
