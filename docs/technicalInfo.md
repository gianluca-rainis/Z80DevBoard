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

![Bottom view of the Z80DevBoard](/images/screenshot_3d_back.png)  
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

## 7.5 The Real Board

## 7.6 Design Choices


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