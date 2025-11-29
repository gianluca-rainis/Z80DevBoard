# Z80DevBoard
An advanced development board for the Z80 (Specific model: Z8400).

It's powered by an RP2040.
It have a flash memory where you can write the RP2040 firmware and the Z80 program.
The RP2040 load in the RAM the Z80 program and the Z80 run it.
The leds allow you to see the real time actions of the Z80.

<img src="./images/screenshot_circuits.png" alt="Scheme image">

## Author
Gianluca Rainis (gianluca-rainis on GitHub)

## License
The whole project is under the MIT License.

## Developing tools
- KiCad

## Components
- Z8400
- RP2040
- HM62256BLP (RAM)
- W25Q32JVSS (Flash)
- Crystal oscillator
- AMS1117-3.3 (5V to 3v3)
- 74HC595 (Serial to 8 bit)
- 74HC165 (8 bit to Serial)
- SN74LVC245APW (Bus to handle the voltage differences)
- USB C 2.0 port
- Buttons
- Leds
- Resistors 0 ohm
- Resistors 220 ohm
- Resistors 5k ohm
- Resistors 10k ohm
- Capacitors 0.1uF
- Capacitors 1uF
- Capacitors 10uF
- Fuse 500mA

## Images
### Scheme (A2 format)
<img src="./images/screenshot_circuits.png" alt="Scheme image">

### Z80 scheme
<img src="./images/screenshot_circuits_z80.png" alt="Z80 scheme image">

### RP2040 scheme
<img src="./images/screenshot_circuits_rp2040.png" alt="RP2040 scheme image">
