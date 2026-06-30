# Chapter 7 - Schematics & KiCad Reference

## 7.1 PCB Overview
The Z80DevBoard is a **4-layer PCB** measuring *219 × 108.5 mm*, designed to be both functional and readable.

Component placement follows a logical layout: the Z80 occupies the center of the board, the RP2040 module sits to the top-right, and the two SRAM chips are placed directly above the Z80.
The USB-C connector is located in the top-left corner.
The LED matrices are distributed around the Z80: the data bus matrices (read and write) are to the left, the address bus matrices run along the right side, and the control signal LEDs (such as MREQ, M1, and HALT) are placed close to their respective Z80 pins for clarity.
The expansion connectors are located on the bottom-right, keeping them accessible for daughter boards.

![Top view of the Z80DevBoard](/images/Z80DevBoard_FinishedBoard.png)  
*Top view of the Z80DevBoard*

The silkscreen includes labels for every Z80 pin, every expansion pin, and all the onboard buttons and switches, making the board self-documenting and easy to use without referring to this manual.

![Bottom view of the Z80DevBoard](/images/Z80DevBoard_FinishedBoard_Back.png)  
*Bottom view of the Z80DevBoard*

## 7.2 Schematic
The full schematic is available in `Z80DevBoard.kicad_sch` and can be opened with KiCad 10.0 or later.
The images below show the main sections of the schematic for reference.

![Full schematic](/images/screenshot_circuits.png)  
*Full schematic*

![Z80 CPU](/images/screenshot_circuits_z80.png)  
*Z80 CPU*

![RP2040](/images/screenshot_circuits_rp2040.png)  
*RP2040*

![Power supply and clock](/images/power_clock_circuits.png)  
*Power supply and clock*

![Shift registers and Data bus](/images/shift_registers_data_bus_circuits.png)  
*Shift registers and Data bus*

![SRAM and flash](/images/sram_flash_circuits.png)  
*SRAM and flash*

## 7.3 PCB Layout
The PCB layout was designed in KiCad with attention to **signal integrity**, **routing clarity**, and **ease of hand-assembly**.
The board uses **4 layers**: *F.Cu* and *B.Cu* for general signal routing, *In1.Cu* for the power distribution network (5V and 3.3V), and *In2.Cu* as a solid ground plane.

![Front copper layer (F.Cu)](/images/screenshot_pcb_FCu.png)  
*Front copper layer (F.Cu)*

![Inner layer In1.Cu](/images/screenshot_pcb_In1Cu.png)  
*Inner layer In1.Cu*

![Inner layer In2.Cu](/images/screenshot_pcb_In2Cu.png)  
*Inner layer In2.Cu*

![Back copper layer (B.Cu)](/images/screenshot_pcb_BCu.png)  
*Back copper layer (B.Cu)*

![All layers combined](/images/screenshot_pcb_only_layers.png)  
*All layers combined*

## 7.4 3D Render
KiCad's built-in 3D viewer was used to generate a render of the assembled board, useful for previewing component placement before manufacturing and for visualizing the board without needing a physical unit on hand.

![3D render - top view](/images/screenshot_3d_front.png)  
*3D render - top view*

![3D render - bottom view](/images/screenshot_3d_back.png)  
*3D render - bottom view*

## 7.5 The Real Board
Photos of the assembled, manufactured Z80DevBoard, shown here for reference alongside the 3D render and schematics.

![Assembled Z80DevBoard - top view](/images/Z80DevBoard_FinishedBoard.png)  
*Assembled Z80DevBoard - top view*

![Assembled Z80DevBoard - bottom view](/images/Z80DevBoard_FinishedBoard_Back.png)  
*Assembled Z80DevBoard - bottom view*

## 7.6 Design Choices
This section explains the reasoning behind some of the key hardware decisions made on the Z80DevBoard.

### Why the Z84C00?
The *CMOS* variant of the Z80 was chosen specifically because **it supports full static operation**, meaning **the clock can be slowed down** to DC without losing register state.
This is **what makes manual clocking possible**: stepping through a program one cycle at a time would simply **not work with the original *NMOS Z80***, which requires a **minimum clock frequency to function** correctly.

### Why asynchronous SRAM?
Asynchronous *SRAM* was chosen for **simpler, more direct memory access from both the Z80 and the RP2040**.
Since it doesn't rely on a shared clock to coordinate read and write operations, both processors can access it independently, each governed by its own timing: the Z80 through its native bus protocol, and the RP2040 through the shift registers.

### Why the RP2040?
The RP2040 was chosen as a **modern microcontroller** that offers a **rich set of advanced features** (PIO, dual cores, ample SRAM, USB) at a low cost, making it an ideal companion processor for managing the Z80 environment without requiring custom ASICs or excessive support circuitry.

### Why shift registers and bus transceivers?
**Shift registers** allow the RP2040 to control the full Z80 address bus and data bus **using only a handful of GPIO pins**, instead of dedicating 24 pins directly to bus signals.
**Bus transceivers** handle the **voltage difference between the Z80's *5V* logic and the RP2040's *3.3V* logic**, allowing the two to communicate safely.

### Why the LED matrices?
The LED matrices let you **observe the Z80's bus activity in real time**, without needing a computer, an oscilloscope, or a logic analyzer connected.
This was a deliberate choice to **keep the board self-contained and immediately readable**.

### Why the buttons?
- *Z80BOOT* - Enters mass storage mode to load a new Z80 program.
- *RP2040BOOT* - Enters mass storage mode to flash custom RP2040 firmware.
- *Z80RESET* - Manually resets the CPU without need to reload the program.
- *Z80WAIT* - Halts the Z80 mid-execution, useful when running on the automatic clock.
- *Z80CLOCK* - Manually advances the clock by one cycle, used in manual clock mode.

### Why SWD and SWCLK?
The ***SWD* debug interface** enables **advanced debugging of the RP2040** like setting breakpoints, inspecting memory and stepping through code, which becomes **essential for custom firmware development**.

### Why expansion pins?
The expansion connectors are there to **support advanced projects** beyond the board's default functionality: custom I/O handling, hardware actions triggered by interrupts, or entirely new peripherals built on top of the existing platform.

### Why USB-C?
USB-C is the modern standard, present on virtually every laptop and workstation today, eliminating the need for adapters or legacy cables.

---

<div>
  <p align="left">
    <em>
      <b>
        <a href="/docs/z80Assembly.md">
          ← Back
        </a>
      </b>
    </em>
  </p>

  <p align="right">
    <em>
      <b>
        <a href="/docs/conclusions.md">
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