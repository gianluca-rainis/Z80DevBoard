# Z80DevBoard
![Hardware License](https://img.shields.io/github/license/gianluca-rainis/Z80DevBoard)
![Software License](https://img.shields.io/badge/license-MIT_License-grey?color=%23939393)
![GitHub Release](https://img.shields.io/github/v/release/gianluca-rainis/Z80DevBoard?logo=github&color=orange)
![GitHub Repo stars](https://img.shields.io/github/stars/gianluca-rainis/Z80DevBoard)
![GitHub watchers](https://img.shields.io/github/watchers/gianluca-rainis/Z80DevBoard)
[![Documentation](https://img.shields.io/badge/Documentation-Guides-blue?logo=markdown)](/docs/index.md)
[![Sponsor](https://img.shields.io/badge/sponsor-PCBWay-darkgreen?logo=githubsponsors&link=https%3A%2F%2Fwww.pcbway.com%2F)](https://www.pcbway.com/)

The Z80DevBoard is an advanced development board for the Z80 microprocessor, based on the RP2040.

This board combines the classic Z80 with the modern RP2040 microcontroller. The RP2040 manages the flash memory and loads programs into RAM for execution by the Z80. Real-time LED indicators provide visual feedback on the Z80's activity, making it an ideal platform for both learning and development. The board's buttons allow the user to load the Z80 program or custom firmware into memory, manually set the Z80 clock, put the Z80 into wait mode, and reset it.

Connection to the computer, used for both power and data transmission, is via a USB-C port.
Two sockets are provided for expansion boards or for advanced projects.
The SWD and SWCLK pins on the RP2040 are accessible to allow a fix for any firmware crashes that prevented the fix from loading over USB-C.

<img src="./images/Z80DevBoard_FinishedBoard.png" alt="Front view of the dev board">
<img src="./images/Z80DevBoard_FinishedBoard_Back.png" alt="Front view of the dev board">

---

<img src="./images/phisical_board.png" alt="Z80DevBoard Picture">

## Author
The author of the whole project is: 
**Gianluca Rainis** - [gianluca-rainis](https://github.com/gianluca-rainis) on GitHub.

## Sponsor
The PCB prototyping for this project is sponsored by **[PCBWay](https://www.pcbway.com)**.

The *boards* were manufactured with **high precision**, faithfully **following the PCB design down to the smallest details**.
The *silkscreen* is **crisp and perfectly readable**, with **no errors or misalignments**.
The *board edges* and corner's holes were **cut cleanly and accurately**.
The *drill holes* **match the component footprints exactly**, making placement and soldering straightforward.
The *SMD pads* are **precise and clean**, even for the most challenging footprints, and solder beautifully.

The *PCBWay website* is **intuitive, even for first-time users**.
**Placing an order is simple**, and before proceeding to payment **the design is reviewed by their technical staff**, who catch and communicate **any potential manufacturing issues** promptly and professionally, avoiding problems before production even begins.

> If you are looking for a reliable, high-quality PCB manufacturer for your own projects, **[PCBWay](https://www.pcbway.com)** is highly recommended!

[![PCBWay](images/pcbway.png)](https://www.pcbway.com)

## License
### Hardware design files (schematics, PCB, BOM):
Licensed under [CERN-OHL-S v2.0](LICENSE-CERN-OHL-S.md)

### Software and firmware:
Licensed under the [MIT License](LICENSE-MIT.md)

## AI Disclaimer
**No AI was used in the conception, design, engineering, or development of this project**.
Every circuit and every design decision is the original work of the author.

*AI tools* were used solely as a **writing assistant** for **parts of the documentation**, to help refine and organize technical explanations.
**All content has been reviewed, verified, and edited by the author.**

## Documentation
The full documentation is available in the [`docs/`](docs/index.md) folder.

## Development Tools
- **PCB Design:** KiCad
- **Documentation and code:** Visual Studio Code

## PCB Manufacturing
The Gerber files for PCB manufacturing are available in the [`gerber/`](gerber/) directory.

## Project Structure
```
Z80DevBoard/
├── customFootprints.pretty/  # Custom footprints
├── docs/                     # The documentation and the guides
├── firmware/                 # The RP2040 firmware
├── gerber/                   # PCB manufacturing files (Gerber format)
├── images/                   # Documentation images and KiCad symbols
├── .gitattributes            # Gitattributes file
├── .gitignore                # Gitignore file
├── gerber.zip                # Zip folder with all the gerber files
├── Z80DevBoard.kicad_pcb     # PCB layout file
├── Z80DevBoard.kicad_pro     # KiCad project file
├── Z80DevBoard.kicad_sch     # Schematic file
├── Z80DevBoard.step          # 3D model
├── BOM.csv                   # Bill Of Materials
├── CHANGELOG.md              # Change log of the project
├── JOURNAL.md                # Journal of the project
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
|Connector 2×20 pins|1|Data Bus|Through Holes|
|Connector 2×10 pins|1|Data Bus|Through Holes|
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

## Firmware
### Build
From the project root, make sure CMake and the ARM GNU toolchain (arm-none-eabi-gcc) are installed.

If the toolchain is not in your PATH, provide it explicitly with PICO_TOOLCHAIN_PATH:

```bash
cmake -S firmware -B firmware/build -DPICO_TOOLCHAIN_PATH=/path/to/arm-gnu-toolchain
cmake --build firmware/build --parallel
```

If the toolchain is already in your PATH, you can omit PICO_TOOLCHAIN_PATH.

#### Local build (Windows / PowerShell)
If you build locally on Windows and need UF2 generation, configure with both the ARM toolchain and a host picotool installation:

```powershell
& "path/to/cmake.exe" -S firmware -B firmware/build -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM="C:/msys64/ucrt64/bin/mingw32-make.exe" -DPICO_TOOLCHAIN_PATH="path/to/picotool"
& "path/to/cmake.exe" --build firmware/build --parallel
```

#### Output file
The file to load in the RP2040's memory after the build is `Z80DevBoard.uf2`.
You can find it in the `/firmware/build` folder.
