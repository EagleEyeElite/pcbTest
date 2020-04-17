/*
 * main.c
 *
 * Created: 26.03.2018 17:29:50
 * Author : Conrad
 */

#include <avr/io.h>
#include <util/delay.h>

int main() {
    // Hex Numbers from 0 to F for 7 Segment Display
    const unsigned char number[16] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101,
                                      0b01111101, 0b00000111, 0b01111111, 0b01101111, 0b01110111, 0b01111100,
                                      0b00111001, 0b01011110, 0b01111001, 0b01110001};

    DDRB |= (1u << 0u) | (1u << 1u) | (1u << 2u);   // output 3 led counter
    DDRD = 0b11111111; // output 7 segment display

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (1) {
        for (unsigned char i = 0; i < 0x10; i++) {
            PORTB = i;
            PORTD = number[i];
            _delay_ms(300);
        }
    }
}
