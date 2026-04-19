# Z80DevBoard
![License](https://img.shields.io/github/license/gianluca-rainis/Z80DevBoard)
![GitHub Repo stars](https://img.shields.io/github/stars/gianluca-rainis/Z80DevBoard)
![GitHub watchers](https://img.shields.io/github/watchers/gianluca-rainis/Z80DevBoard)
[![Sponsor](https://img.shields.io/badge/sponsor-PCBWay-green?link=https%3A%2F%2Fwww.pcbway.com%2F)](https://www.pcbway.com/)

The Z80DevBoard is an advanced development board for the Z80 microprocessor, based on the RP2040.

This board combines the classic Z80 with the modern RP2040 microcontroller. The RP2040 manages the flash memory and loads programs into RAM for execution by the Z80. Real-time LED indicators provide visual feedback on the Z80's activity, making it an ideal platform for both learning and development. The board's buttons allow the user to load the Z80 program or custom firmware into memory, manually set the Z80 clock, put the Z80 into wait mode, and reset it.

Connection to the computer, used for both power and data transmission, is via a USB-C port.
Two sockets are provided for expansion boards or for advanced projects.
The SWD and SWCLK pins on the RP2040 are accessible to allow a fix for any firmware crashes that prevented the fix from loading over USB-C.

<img src="./images/Z80DevBoard.png" alt="Z80DevBoard Logo" style="background-color: white;">

---

<img src="./images/screenshot_3d_front.png" alt="Front view of the dev board">

## Author
The author of the whole project is: 
**Gianluca Rainis** - [gianluca-rainis](https://github.com/gianluca-rainis) on GitHub.

## License
### Hardware design files (schematics, PCB, BOM):
Licensed under [CERN-OHL-S v2.0](LICENSE-CERN-OHL-S.md)

### Software and firmware:
Licensed under the [MIT License](LICENSE-MIT.md)

## AI Disclaimer
No AI was used in this project. Everything was designed by the author.

## Development Tools
- **PCB Design:** KiCad
- **Documentation and code:** Visual Studio Code

## PCB Manufacturing
The Gerber files for PCB manufacturing are available in the [`gerber/`](gerber/) directory.

## Project Structure
```
Z80DevBoard/
├── customFootprints.pretty/  # Custom footprints
├── firmware/                 # The RP2040 firmware
├── gerber/                   # PCB manufacturing files (Gerber format)
├── images/                   # Documentation images and KiCad symbols
├── .gitattributes            # Gitattributes file
├── .gitignore                # Gitignore file
├── gerber.zip                # Zip folder with all the gerber files
├── Z80DevBoard.kicad_pcb     # PCB layout file
├── Z80DevBoard.kicad_pro     # KiCad project file
├── Z80DevBoard.kicad_sch     # Schematic file
├── BOM.csv                   # Bill Of Materials
├── LICENSE-CERN-OHL-S.md     # CERN-OHL-S License
├── LICENSE-MIT.md            # MIT License
└── README.md                 # This file
```

## Images
### Schematic Diagrams
#### Complete Schematic (A2 format)
<img src="./images/screenshot_circuits.png" alt="Complete schematic">

#### Z80 Section
<img src="./images/screenshot_circuits_z80.png" alt="Z80 subsystem schematic">

#### RP2040 Section
<img src="./images/screenshot_circuits_rp2040.png" alt="RP2040 subsystem schematic">

### PCB Layout
#### Without Silkscreen
<img src="./images/screenshot_pcb_no_drawings.png" alt="PCB layout without silkscreen">

#### With Silkscreen
<img src="./images/screenshot_pcb.png" alt="PCB layout with silkscreen">

### 3D Renders
#### Front View
<img src="./images/screenshot_3d_front.png" alt="3D render - front view">

#### Back View
<img src="./images/screenshot_3d_back.png" alt="3D render - back view">

## Technical Details
- **Size**: 219mm x 108.5mm
- **Layers**: 4
- **Supply Voltage**: 5V, 3v3

## Components Table
|Name|Quantity|Class|Type|
|--|--|--|--|
|Z84C00|1|Microprocessor|Through Holes|
|RP2040|1|Microprocessor|SMD|
|||||
|HM62256BLP|2|Memory|Through Holes|
|W25Q32JVSS|1|Memory|SMD|
|||||
|AMS1117-3.3|1|Power Management|SMD|
|||||
|USB C 2.0 port|1|Data Bus|Through Holes|
|74HC595|3|Data Bus|Through Holes|
|74HC155|1|Data Bus|Through Holes|
|74HCT574|4|Data Bus|Through Holes|
|SN74LVC245APW|3|Data Bus|SMD|
|TXS0104EPW|1|Data Bus|SMD|
|Connector 2 pins|1|Data Bus|Through Holes|
|Connector 2x20 pins|1|Data Bus|Through Holes|
|Connector 2x10 pins|1|Data Bus|Through Holes|
|||||
|Crystal 12MHz 20pF|1|Clock|Through Holes|
|Oscillator 8MHz|1|Clock|SMD|
|||||
|74HC14|1|Support components|Through Holes|
|74HC04|1|Support components|Through Holes|
|74HC00|1|Support components|Through Holes|
|||||
|Resistor 0 ohm|1|Resistor|Through Holes|
|Resistor 27.4 ohm|2|Resistor|Through Holes|
|Resistor 1k ohm|36|Resistor|Through Holes|
|Resistor 3.3k ohm|6|Resistor|Through Holes|
|Resistor 5k ohm|2|Resistor|Through Holes|
|Resistor 10k ohm|13|Resistor|Through Holes|
|Resistor 470k ohm|1|Resistor|Through Holes|
|||||
|Capacitors 15pF|2|Capacitor|Through Holes|
|Capacitors 0.1uF|13|Capacitor|Through Holes|
|Capacitors 1uF|4|Capacitor|Through Holes|
|Capacitors 10uF|2|Capacitor|Through Holes|
|||||
|Button|5|Other|Through Holes|
|Switch|1|Other|Through Holes|
|LED|40|Other|SMD|
|Diodes|24|Other|SMD|
|Fuse 500mA|1|Other|SMD|

## Components List
### Microprocessors
- 1 Z84C00
- 1 RP2040

### Memory
- 2 HM62256BLP (RAM)
- 1 W25Q32JVSS (Flash)

### Power Management
- 1 AMS1117-3.3 (5V to 3v3)

### Data Bus
- 1 USB C 2.0 port
- 3 74HC595 (Serial to 8 bit)
- 1 74HC155 (8 bit to Serial)
- 4 74HCT574 (8 bit Buffer)
- 3 SN74LVC245APW (Bus to handle the voltage differences)
- 1 TXS0104EPW (Bus to handle the voltage differences)
- 1 Connector 2 pins
- 1 Connector 2x20 pins
- 1 Connector 2x10 pins

### Clock
- 1 Crystal 12MHz 20pF
- 1 Oscillator 8MHz

### Support components
- 1 74HC14
- 1 74HC04
- 1 74HC00

### Resistors
- 1 Resistor 0 ohm
- 2 Resistors 27.4 ohm
- 34 Resistors 1k ohm
- 6 Resistors 3.3k ohm
- 2 Resistors 5k ohm
- 12 Resistors 10k ohm
- 1 Resistor 470k ohm

### Capacitors
- 2 Capacitors 15pF
- 8 Capacitors 0.1uF
- 3 Capacitor 1uF
- 2 Capacitors 10uF

### Other
- 5 Buttons
- 1 Switch
- 40 LEDs
- 24 Diodes
- 1 Fuse 500mA

## Firmware
### Build
From the project root, run:

```bash
cmake -S firmware -B firmware/build
cmake --build firmware/build -j
```