# Chapter 1 - Introduction & Project History

## 1.1 What Is the Z80DevBoard?
The **Z80DevBoard** is an open-source single-board computer that pairs a **Zilog Z80 CPU**, one of the most iconic and revolutionary 8-bit processors ever built, with an **RP2040 microcontroller**, the modern dual-core chip designed by *Raspberry Pi* that powers most of the most modern projects.

The idea is simple: the Z80 operates as it would in **its original environment**, while the RP2040 handles all interaction between the developer and the board.
The Z80 still **runs real code**, asserts real signal lines, and *behaves exactly as it did in 1976*, but the world it communicates with is managed by a modern chip running firmware that enables advanced features: loading programs over USB-C, serial communication, real-time RAM access, and the flexibility to deploy custom firmware for more complex projects.

This makes the Z80DevBoard both a **retrocomputing gem** and a **powerful educational tool**: you can study Z80 bus cycles firsthand, write and run real assembly code, and observe authentic hardware behavior, all without the complexity of building the surrounding support circuitry from scratch. Whether you are a *student* exploring **how computers truly work** at the lowest level, or an *enthusiast* who simply appreciates the **elegance of classic 8-bit architecture**, this board was built with you in mind.

## 1.2 Why Z80 + RP2040?
### The Z80: A Processor Worth Knowing
The **Zilog Z80** was developed in 1976 by **Federico Faggin** (the same engineer who designed the *Intel 4004* and *8080*). It later powered the *ZX Spectrum*, the *MSX family*, countless embedded systems, and even the *Game Boy*, which used a specially modified version of the Z80.

Despite being 50 years old, the Z80 remains an **excellent architecture to study**:
- Its instruction set is *rich yet regular*, making it *accessible*.
- Its bus protocol is *well documented* and *easy to observe* with a logic analyzer.
- It has influenced virtually *every modern CPU architecture*, including *x86* and *ARM*.
- Writing Z80 assembly code teaches you exactly *what a processor does*, without layers of abstraction.

In short, the Z80 is a museum piece today, but its impact on the history of computing was profound, and its assembly language remains one of the best windows into the real workings of a CPU.

### The RP2040: a modern microcontroller
The RP2040 is a *dual-core ARM Cortex-M0+* microcontroller developed by **Raspberry Pi** and released in 2021.
Despite its low cost, it packs a number of features that make it exceptionally well suited for this project, most notably its Programmable I/O (*PIO*) subsystem: a set of small, deterministic state machines capable of handling **GPIO** pins with precision.

In the Z80DevBoard, the RP2040 takes on the role of the primary interface between **the developer** and **the hardware**: it stores the assembled program in flash, loads it into the onboard 64K asynchronous *SRAM* at boot, handles I/O bus cycles in real time, and exposes a USB serial interface for communication with the host computer.
The expansion header additionally makes the board ready for more advanced use cases, from custom peripherals to deeper firmware experimentation.

## 1.3 Project Goals
The Z80DevBoard was designed with **three goals** in mind.

### Education first
Every **design decision is documented and explainable**. There are no obscure components: every chip on the board exists for a clear, teachable reason.
The Z80DevBoard was born as an **educational tool first**: the LED matrices and the serial connection with the RP2040 allow you to **observe Z80 operations in real time**, making it possible to **learn**, **debug**, and **truly understand** what your program is doing at every step.
The board is designed to **grow with the student**: starting from basic *Z80 assembly*, which maps directly onto topics covered in *computer architecture* and *systems* courses, all the way up to *writing custom RP2040 firmware* for **more complex, ambitious and independent projects**.

### Real hardware, real behavior
**The Z80 is not simulated.** It receives a real clock, drives real address and data buses, and asserts real control signals. You can watch *your code* execute on a *real processor*, in *real time* and *physically interact* with it.

### Open source
All *KiCad design* files are published under the **CERN OHL S v2.0** license; the *firmware* source code and this *documentation* are published under the **MIT License**.
Anyone can *manufacture the board*, *modify it*, or use it as a *starting point for their own project*, provided derivative works comply with the respective license terms. For **students** who want to *go deeper*, having access to the **full sources**, **schematics**, and **documentation** is itself a **powerful learning resource**.

## 1.4 Project History
The Z80DevBoard started from a simple desire: to **learn Z80 assembly** and **truly understand how a CPU works**.
Existing **emulators were not enough**: while functionally accurate, they could **never replicate the feeling of watching real code execute on real silicon**.
The goal became building a board that would make that possible: not just a personal learning tool, but something that could make the **study of computer architecture** more *tangible*, more *immediate*, and ultimately more *rewarding* for anyone who picks it up.

### Version 0.1.0 (Pre-release)
- Added the main components.
- Started working on the connections.
- Connected the Z80 to the RAM module.
- Created some led matrix to see the live activity of the Z80.
- Added some leds to see the bits the Z80 are writing or reading.
- Added the Wait and the Reset buttons.

### Version 0.9.0 (Pre-release)
- Fixed the connections.
- Finished all the scematics.
- Finished the pcb.
- Added the 2 layers connections on the pcb.
- Added the graphics to the pcb.
- Fixed the pcb for the 3D view.

### Version 1.0.0
- Fixed all the clocks.
- Added the manual clock for the Z80.
- Added the SWCLK and SWD pins for debug.
- Added other 2 layers.
- Added the GND layer.
- Added the Vcc and 3v3 layer.
- Fixed the borders of the board.
- Fixed some connections.

### Version 1.2.0
- Added debouncer.
- Fixed board size.
- Added the info about the leds on the front silkscreen.
- Updated the back silkscreen.
- Changed the capacitors footprint.
- Changed the switch (manual - auto clock selector).
- Fixed SWD and SCLK pins.
- Fixed the crystal and the capacitors for the RP2040 clock.
- Fixed the data bus clock.
- Made a new automatic slow clock generator for the Z80.
- Fixed some connections.

### Version 1.5.0
- Added second SRAM to have 64Kb instead of 32Kb.
- Remade the led matrix.
- Added 74HTC574 as buffers for the led matrix.
- Added one 74HC00.
- Added the components informations in the silkscreen.
- Optimized the space.
- Fixed some DRC rules violations.
- Updated the documentation.
- Updated the CERN license.

### Version 1.6.0
- Added two pin sockets for Expansion boards or more advanced progects.
- Fixed the bus clock.
- Fixed some resistors.
- Added the names of the expansion pins.
- Added the names of the Z80 pins.
- Added the debouncer for the Reset and for the Wait buttons.
- Added a TXS0102DCT for the connections between the RP2040 and the Z80 BUSREQ and BUSACK.
- Fixed some capacitors values.
- Fixed the footprint of the fuse.
- Made a custom footprint for the switch.
- Added some graphics and funny phrases.
- Fixed the sizes of the Expansion pin's names and of the Z80 pin's names.
- Changed the footprint of the capacitors.

### Version 1.7.0 *(current)*
- Fixed the alimentation of the RP2040.
- Fixed the footprints of the two pin extension's sockets.
- Fixed the size of the board.
- Now the project is sponsorized by PCBWay!

## 1.5 What You Can Do With This Board
The Z80DevBoard lets you:
- **Run Z80 assembly programs** loaded over USB from a host computer
- **Study computer architecture** with a real, inspectable system rather than a textbook diagram
- **Observe bus activity** in real time through the onboard LED matrices, watching every read, write, and control signal as it happens
- **Step through your program manually** using the manual clock input, running the Z80 at your own pace, one cycle at a time if needed
- **Read and write RAM** in real time via the serial connection with the RP2040, inspecting and modifying memory while the Z80 is running
- **Expand the board** by connecting your own components to the expansion pin sockets, from simple peripherals to complete daughter boards
- **Write custom RP2040 firmware** to implement advanced features, experiment with the bus protocol, or build projects that go well beyond a standard development board

---

<div>
  <p align="left">
    <em>
      <b>
        <a href="/docs/index.md">
          ← Back
        </a>
      </b>
    </em>
  </p>

  <p align="right">
    <em>
      <b>
        <a href="/docs/hardware.md">
          Next Section →
        </a>
      </b>
    </em>
  </p>
</div>

---

<p align="center">
    <em>Open source, Open Education - Z80DevBoard</em>
</p>