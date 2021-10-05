# **Project**: Binary Counter (Arduino)
This project implements a *binary counter* that can be adapted to how many bits the user wants to use, only being necessary to change a little piece of the code (without having to get involved in the logic process itself) and adapting the circuit assembly to the amount of bits chosen.

## The code:
The area to be adapted is right at the beginning of the code:
- **Bits Amount**: can be specified at the const *QUANT_BITS*.
   - **Bits Ports**: Specify the ports where the Leds are connected by the vector * pin_bit *, from the least significant bit (LSB) to the most significant bit (MSB).
- **Increment Time**: The *time* variable receives the time to switch from one number to another, in seconds. 
~~~
#define QUANT_BITS 8 
byte pin_bit[QUANT_BITS] = {5, 6, 7, 8, 9, 10, 11, 12}; 
float time = 0.5
~~~

## Connection Scheme:
Obs.: recommended to use resistors of 150 Ohm (Ω) or higher for common LEDs!

![Connection Scheme](images/Esquema_de_conexões-reduzido.png)

Made in [Tinkercad](https://www.tinkercad.com)
