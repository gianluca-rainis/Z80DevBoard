---
title: "Z80DevBoard"
author: "Gianluca Rainis"
description: "An advanced development board for the Z80 microprocessor, powered by an RP2040."
created_at: "2025-11-27"
---

# November 27th 2025: Project start
First commit.
Added the Z80 (Z84C00) to the schematic, the RAM, the first LEDs and some buttons.
Started thinking about how the Z80 would interact with a modern companion chip for program loading and debugging.

**Total time spent: ~3h**

# November 28th-29th 2025: Schematic progresses
Added the RP2040 and the flash memory.
Designed the first version of the LED matrix to visualize live bus activity.
Added shift registers (74HC595, 74HC165, SN74LVC245APW) to handle the large number of signals.
Started the footprints and the connections between components.

**Total time spent: ~12h**

# December 1st-5th 2025: First PCB layout
Finished the schematic connections and moved to the PCB layout.
Routed all connections on 2 layers, defined the board borders, added the Z80DevBoard logo and graphics to the silkscreen, and generated the first Gerber files.

Added component values to the silkscreen, button labels, author and GitHub info to the back.
Updated the README with the component list.

**Total time spent: ~10h**

# December 15th-16th 2025: License update
Updated the USB-C connector.
Fixed the board borders.
Updated the LICENSE to CERN OHL W.
Updated the README and regenerated the Gerber files.

**Total time spent: ~2h**

# December 19th 2025: Added two new layers
Upgraded the board from 2 to 4 layers.
Adding dedicated Vcc + 3v3, and GND layers.
This simplify power distribution and reduced the noise.

Fixed the oscillators, the crystal, and the connections between the RP2040 and the Flash.

**Total time spent: ~6h**

# December 21st-24th 2025: Clock, Debouncer and other generic fixes
Added the manual clock button for the Z80 and fixed all the components.
Replaced the old Z80 crystal oscillator with a new automatic slow clock generator, making it easier to switch between manual and automatic clocking.

Added a hardware debouncer to clean up button signals.
Updated the SWD and SCLK debug pins.
Fixed the RP2040 crystal capacitors, the data bus clock, and the GND layer.
Changed the capacitor footprints and updated the back silkscreen.
Fixed the size of the board.

**Total time spent: ~14h**

# February 6th 2026: Second SRAM
Added a second SRAM chip, doubling the available memory from 32KB to 64KB (the maximum amount the Z80 can directly index).
Fixed the connections to the first RAM and routed the connections to the second one.

**Total time spent: ~7h**

# March 1st-4th 2026: New LED matrix
Remade the LED matrix.
Added two 74HCT574 as output buffers and one 74HC00 NAND to solve signal issues, causing incorrect LED readings.
Finished all the address LED matrix connections and optimized the board space.

Fixed several DRC rule violations, updated the CERN license (CERN OHL S), regenerated the Gerber files.

**Total time spent: ~12h**

# March 5th 2026: Expansion Pins
Added two pin socket headers to support expansion boards and external devices.
Prepared the RP2040 pins for the socket connections.

**Total time spent: ~8h**

# March 10th 2026: Expansion pins completed
Finished the connections between the expansion pins and the Z80.
The board now exposes the Z80 bus signals on two pin headers, making it possible to connect external devices and future expansion boards, allowing also support to more advanced projects.

![screenshot_pcb](/images/journal/10-3-26_pcb.png)
![screenshot_3d_front](/images/journal/10-3-26_3d.png)

**Total time spent: ~2h**

# March 11th 2026: Expansion pin labels and silkscreen
Added pin name labels to the expansion connector in the front silkscreen. Fixed several small details on the PCB.

![expansion_pins](/images/journal/11-3-26_pins.png)

**Total time spent: ~1h**

# March 24th-26th 2026: Clock fix and generic updates
Fixed the RP2040 crystal load capacitors from 33pF to 15pF, following the RP2040 datasheet.
Added 27.4Ω resistors on the XIN and XOUT pins, as recommended by the official documentation.
Updated the bus clock frequency from 2MHz to 8MHz.
Fixed some resistors values, now the board hasn't resistors of 220 ohm anymore.
Added Z80 pin labels to the silkscreen.
Fixed expansion pin labels that were hidden under traces.
Added debouncers for the Reset and Wait buttons.
Added a TXS0102DCT 2-bit bidirectional level shifter between the RP2040 and the Z80 to handle BUSREQ and BUSACK.

![screenshot_3d_front](/images/journal/24-3-26_3d.png)

**Total time spent: ~5h**

# March 30th 2026: Finished the TXS0102DCT connections
Added the Hack Club flag to the back silkscreen and some fun phrases to the front.
Created a custom footprint for the manual clock switch.
Fixed capacitor sizes and the fuse footprint.

Finished the connections between the TXS0102DCT, the RP2040, and the Z80.

![rp2040_flash_txs0102dct](/images/journal/30-3-26_rp2040png.png)

**Total time spent: ~2h**

# March 31st 2026: Fixed the size of the text, started the firmware and prepaded the gerber files
Set minimum text height/width to 0.8mm and minimum line thickness to 0.15mm.
Fixed the Z80 and expansion pin label boxes dimensions.
Rotated the expansion pin names.
Fixed the distance between the four buttons.
Fixed capacitor and switch footprints.

Made the Bill Of Materials (BOM).
Updated the USB-C connector footprint.
Replaced the TXS0102DCT with a TXS0104EPW (4 pins).

Started writing the first version of the RP2040 firmware.

Prepared the STEP file.
Prepared the GERBER files.

![screenshot_pcb_no_drawings](/images/journal/31-3-26_pcb.png)

**Total time spent: ~7h**

# April 13th-19th 2026: Hardware revision and PCB conclusions
Fixed the RP2040 power supply, the Flash alimentation, the firmware loading connections, and the crystal.
Updated the expansion pin footprints to be SMD.
Reconnected the RP2040, cleaned up all traces, and placed the remaining resistors and capacitors.

Finished all component placement and connections.
Updated the Gerber files.

**Total time spent: ~9h**

# April 21st 2026: PCBWay sponsorship
Updated the BOM prices and links.
Added the sponsor section to the README.

**[PCBWay](https://www.pcbway.com) became the official sponsor of the Z80DevBoard project!**

![screenshot_pcb](/images/journal/21-4-26_pcb.png)

[![pcbway](/images/pcbway.png)](https://www.pcbway.com)

**Total time spent: ~5h**

# April 27th 2026: First firmware version
Wrote the firmware functions to access the RAM and the Flash from the RP2040.
Compiled the project successfully for the first time.

**Total time spent: ~3h**

# May 5th-8th 2026: Started the official documentation
Created the file structure for the official documentation.
Added navigation between pages.
Wrote the introduction.

**Total time spent: ~6h**

# May 11th-14th 2026: Hardware architecture and Quickstart guide
Finished the Z80 and RP2040 pinout chapters, including a full pinout scheme for the RP2040.
Wrote the Z80 and RP2040 expansion pins chapters and the SWD connector chapter.

Started the quickstart guide: wrote the first chapters covering board setup, loading a program, running it, using the manual clock, and reading the LED matrices.

Added an advanced guide structure with chapter titles.

**Total time spent: ~10h**

# May 19th-26th 2026: Quickstart, Advanced guide and serial communication
Finished the quickstart guide and wrote the "Flashing the firmware" chapter for the advanced guide.
Wrote the expansion board and "developing an expansion board" chapters.

Added serial communication support to the firmware.
Wrote the serial communication chapter in the documentation.

**Total time spent: ~7h**

# May 28th-29th 2026: Z80 assembly documentation
Started the Z80 assembly chapter.
Wrote the introduction to Z80 assembly, the Z80 register set chapter, and the flag register chapter.

**Total time spent: ~4h**

# June 7th 2026: Addressing modes chapter, changelog and journal
Wrote the addressing modes chapter for the Z80 assembly guide.

Created the `CHANGELOG.md` file.
Created the `JOURNAL.md` file.

**Total time spent: ~2h**

# June 8th-30th: Wrote the documentation
Finished the full documentation for the Z80DevBoard, structured as a multi-chapter book designed for educational kits.

Finished the *Chapter 6 - Z80 Assembly Programming*.
Wrote the *Chapter 7 - Schematics & KiCad Reference*.
Wrote the *Chapter 8 - Conclusions*.

Added Chapter *5.3 Writing Custom RP2040 Firmware*.

Implemented `uart.c` and `uart.h` for the firmware: *USB CDC* serial interface, *command parser*, `read` and `write` handlers.

**Total time spent: ~15h**

# July 9-13: Intensive Debugging and issue diagnostic
Created a pdf of the whole documentation in A5 format.

Added the option to force the execution of a command from serial.
Fixed several bugs in the firmware, like the somethimes never released BUSREQ.
Remade the whole send BUSREQ / await BUSACK / release BUSREQ logics.
Removed the force option from the serial commands.
Reorganized some comments.

Discovered some hardware issues after a lot of hardware debug, like the flash connected to 5V instead to 3v3, the wrong footprint for the switch and the misconnected manual clock for the Z80.
Also, most some of these with temporary connections and signal bypasses.

Created the `TODO.md` file to have a list of the fixes to do for the *Z80DevBoard v2.0.0*.

**Total time spent: ~20h**
