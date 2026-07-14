# TODO
Things to fix for the **Z80DevBoard *v2.0.0***

## Critical fixes
- [ ] Fix the Clock Switch footprint
- [ ] The flash must be connected to 3v3, not Vcc

## Hardware improvements
- [ ] RP2040 alimentation capacitors close to the RP2040's pins
- [ ] RP2040 USB resistors close to the RP2040's pins
- [ ] Add more than one via for the RP2040's GND
- [ ] Improve automatic clock generator
- [ ] Made the expansion pins socket footprint bigger
- [ ] Made the SWD and SWCLK pins footprint bigger
- [ ] Add a connection between a GPIO of the RP2040 and the CLK of the Z80

## Firmware improvements
- [ ] Add a log buffer to print all the previous logs once the board is connected (TO VERIFY SIZE OF THE BUFFER - RISK TOO BIG BUFFER OR BUFFER OVERFLOW)
