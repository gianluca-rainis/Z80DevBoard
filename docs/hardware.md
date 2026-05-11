# Chapter 2 - Hardware Architecture

## 2.1 System Overview
The Z80DevBoard is a **4-layer PCB** measuring *219 × 108.5 mm*, designed around two central processing units: the **Z84C00** (Z80) and the **RP2040**.
The board operates at **5V** via USB-C, with an onboard *AMS1117-3.3* regulator supplying the **3.3V** rail to the RP2040 and the supporting logic.

The Z80 is the execution core: it runs assembly programs stored in the two onboard *HM62256BLP* SRAM chips, which together provide **64 KB of addressable memory**.

The RP2040 acts as the interface layer **between the developer and the board**: it reads the compiled program from the *W25Q32JVSS* flash memory and loads it into SRAM before releasing the Z80.

The data bus is managed by a set of *SN74LVC245APW* bus transceivers, which handle the **voltage difference** between the **Z80's 5V logic** and the **RP2040's 3.3V logic**.

Three *74HC595* shift registers allow the RP2040 to drive the bus over a serial interface, while the *74HC165* reads it back. A dedicated oscillator drives the Z80 clock, selectable between manual and automatic mode via an onboard switch; the RP2040 runs off a **12 MHz crystal**.

Forty LEDs, organized in matrices and driven by *74HCT574* buffers, provide **real-time visual feedback** of Z80 bus activity.

Two expansion connectors expose additional signals for daughter boards and custom projects.

## 2.2 The Z80 CPU
The Z80 is an **8-bit microprocessor** designed by ***Zilog*** and first introduced in 1976.
Despite its age, it remains one of the **most studied and documented CPU** architectures ever produced, and its influence can still be traced in modern instruction set designs.

The specific model used on the Z80DevBoard is the *Z84C00*: the ***CMOS* variant** of the original Z80.
Compared to the original *NMOS* version, the *Z84C00* offers several practical advantages: significantly **lower power consumption**, **full static operation** (meaning the clock can be slowed down to DC without losing register contents), and better **noise immunity** thanks to the wider logic voltage margins typical of *CMOS* technology.
It is also considerably easier to source today than original *NMOS* parts.

The *Z84C00* operates with a **5V supply** and communicates with the rest of the board through three buses: a **16-bit address bus**, an **8-bit bidirectional data bus**, and a set of control signals that coordinate every memory and I/O operation.
With 16 address lines, the CPU can directly address **up to 64 KB** of memory: exactly the amount provided by the onboard SRAM.

## 2.3 The RP2040
The RP2040 is a dual-core ARM Cortex-M0+ **microcontroller** developed by ***Raspberry Pi*** and released in 2021.
It runs at up to *133MHz*, integrates *264KB of SRAM*, and includes a rich set of peripherals, among which the most relevant is the *Programmable I/O* (*PIO*): a set of small, deterministic state machines capable of handling **GPIO pins** with cycle-accurate timing.

On the Z80DevBoard, the RP2040 serves as the primary interface between **the developer and the hardware**.
At boot, it **reads the compiled Z80 program** from the onboard flash memory and **transfers it into SRAM**, where the Z80 will execute it.
During execution, it monitors the Z80 control signals in real time, handles I/O bus cycles, and maintains the serial connection with the host computer over USB.

The RP2040 runs at **3.3V**, while the Z80 operates at **5V**.
All signals exchanged between the two pass through *level shifters* and *bus transceivers* that **handle the voltage difference** transparently.
Communication with the *shift registers*, used to **extend the RP2040's effective GPIO count**, happens over a **fast serial interface**, keeping the pin usage manageable without sacrificing bus performance.

The RP2040 also exposes its ***SWD* debug interface** on dedicated pins, allowing firmware to be **developed and debugged with standard tools** such as a ***Raspberry Pi Debug Probe*** or **any compatible SWD adapter**.

## 2.4 The SRAM

## 2.5 The Flash Memory

## 2.6 The LED Matrices

## 2.7 The Expansion Pins

## 2.8 The USB-C

## 2.9 How It All Connects


---

<div>
  <p align="left">
    <em>
      <b>
        <a href="/docs/introduction.md">
          ← Back
        </a>
      </b>
    </em>
  </p>

  <p align="right">
    <em>
      <b>
        <a href="/docs/pinout.md">
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