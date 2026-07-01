# Changelog
All notable changes to this project will be documented in this file.

## Unreleased
### Added
- Added the pdf file of the Schematics.
- Added the pdf file of the PCB Layout.
- Created a video presentation for the Official Firmware Demo.
- Added the help command in the firmware.

### Fixed

### Changed

### Removed

## v1.8.0 - 2026-07-01
### Added
- Wrote the whole documentation.
- Created the CHANGELOG file.
- Created the JOURNAL file.

### Changed
- Updated the firmware.
- Updated the README file.

## v1.7.0 - 2026-04-22
### Added
- Now the project is sponsorized by [PCBWay](https://www.pcbway.com/)!

### Fixed
- Fixed the alimentation of the RP2040.
- Fixed the footprints of the two pin extension's sockets.
- Fixed the size of the board.

## v1.6.0 - 2026-03-31
### Added
- Added two pin sockets for Expansion boards or more advanced progects.
- Added the names of the expansion pins.
- Added the names of the Z80 pins.
- Added the debouncer for the Reset and for the Wait buttons.
- Added a TXS0102DCT for the connections between the RP2040 and the Z80 BUSREQ and BUSACK.
- Added some graphics and funny phrases.

### Fixed
- Fixed the bus clock.
- Fixed some resistors.
- Fixed some capacitors values.
- Fixed the footprint of the fuse.
- Fixed the sizes of the Expansion pin's names and of the Z80 pin's names.

### Changed
- Made a custom footprint for the switch.
- Changed the footprint of the capacitors.

## v1.5.0 - 2026-03-04
### Added
- Added second SRAM to have 64Kb instead of 32Kb.
- Added 74HTC574 as buffers for the led matrix.
- Added one 74HC00.
- Added the components informations in the silkscreen.
- Updated the documentation.

### Fixed
- Optimized the space.
- Fixed some DRC rules violations.

### Changed
- Remade the led matrix.
- Updated the CERN license.

## v1.2.0 - 2025-12-24
### Added
- Added debouncer.
- Added the info about the leds on the front silkscreen.
- Made a new automatic slow clock generator for the Z80.

### Fixed
- Fixed the board size.
- Fixed SWD and SCLK pins.
- Fixed the crystal and the capacitors for the RP2040 clock.
- Fixed the data bus clock.
- Fixed some connections.

### Changed
- Updated the back silkscreen.
- Changed the capacitors footprint.
- Changed the switch (manual - auto clock selector).

### Removed
- Removed the old crystal for the Z80's clock.

## v1.0.0 - 2025-12-22
### Added
- Added the manual clock for the Z80.
- Added the SWCLK and SWD pins for debug.
- Added other 2 layers.
- Added the GND layer.
- Added the Vcc and 3v3 layer.

### Fixed
- Fixed all the clocks.
- Fixed the borders of the board.
- Fixed some connections.

## v0.9.0 (Pre-release) - 2025-12-05
### Added
- Added the connections on 2 layers.
- Added the graphics to the pcb.

### Fixed
- Fixed some connections.
- Fixed the pcb for the 3D view.

### Changed
- Finished all the scematics.
- Finished the pcb.

## v0.1.0 (Pre-release) - 2025-11-29
### Added
- Added the main components.
- Started the connections.
- Connected the Z80 to the RAM module.
- Created some led matrix to see the live activity of the Z80.
- Added some leds to see the bits the Z80 are writing or reading.
- Added the Wait and the Reset buttons.
