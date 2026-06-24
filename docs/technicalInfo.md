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

## 7.3 PCB Layout

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