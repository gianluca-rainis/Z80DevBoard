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
The Z80DevBoard mount two *HM62256BLP* chips as its main memory: a classic **32KB × 8-bit Asynchronous Static RAM**.
Mounted **in parallel**, the two chips provide **a combined address space** of *64KB*, which is **the maximum the Z80 can directly address** with its 16-bit address bus.

Unlike Dynamic RAM (*DRAM*), Static RAM **does not require periodic refresh cycles** to retain its contents.
This **simplifies the board design** considerably: there is **no need for a dedicated refresh controller**, and the Z80's `/RFSH` pin, which would normally **trigger DRAM refresh**, is simply **left unused**.
As long as the board is powered, the memory contents remain intact.

The *HM62256BLP* is an **asynchronous device**, meaning **it does not rely on a shared clock** signal to coordinate read and write operations.
Instead, timing is governed entirely by the Z80's control signals: `/MREQ`, `/RD`, and `/WR`, which the SRAM monitors directly.
A **read cycle** completes as soon as **the address has been stable** for the chip's access time; a **write cycle** latches the data **on the rising edge of `/WR`**.

At boot, the **RP2040 takes control of the bus** and **writes the compiled Z80 program** into *SRAM* before releasing the CPU from reset.
From that point on, the Z80 reads instructions and data, and writes results back, to these two chips for the entire duration of program execution.

## 2.5 The Flash Memory
The *W25Q32JVSS* is a *32Mbit* (*4MB*) ***SPI* *NOR* flash memory** chip, used on the Z80DevBoard as **persistent storage for the RP2040 firmware and the Z80 program**.
Unlike *SRAM*, flash memory **retains its contents** when the board is powered off, making it the natural choice for **storing code** that needs to survive **between sessions**.

The RP2040 communicates with the flash chip over **a dedicated *SPI* bus**.
At boot, it **reads the compiled Z80 program from flash** and transfers it into *SRAM* before releasing the Z80 from reset.
The RP2040's own firmware is also stored on the same chip, following the standard *Raspberry Pi Pico* architecture where the **RP2040 boots directly from an *external SPI flash***.

From the Z80's perspective, **the flash memory is completely invisible**: the CPU only ever interacts with the *SRAM*.
The flash is **exclusively managed by the RP2040**, which handles all read and write operations transparently in the background.

## 2.6 The LED Matrices
The Z80DevBoard features ***40 LEDs* organized in matrices**, one of the most distinctive and educationally valuable aspects of the board.
Each LED reflects **the real-time state of a specific signal or data line**, giving an **immediate visual representation** of **what the Z80 is doing** at any given moment, without the need for an oscilloscope or a logic analyzer.

The LEDs are driven by *74HCT574* *octal D-type flip-flop buffers*, which latch the current state of the bus.
Without buffering, the signals on a running Z80 bus change far too rapidly to be perceived directly, at even a modest clock frequency, individual bus cycles last only a few hundred nanoseconds.
The buffers solve this by capturing a snapshot of the bus state and holding it stable until the next update.

This is where the **manual clock mode becomes particularly powerful**: by stepping through the program one clock cycle at a time, **the LEDs update with each step**, allowing you to **follow the execution of every instruction in real time** and **observe exactly how the Z80 reads from and writes to memory**.
Combined with the serial connection to the RP2040, this makes the Z80DevBoard a **genuinely transparent system**: one where **the internal state of the CPU is always visible** and never hidden.

## 2.7 The Expansion Pins
The Z80DevBoard exposes **two expansion connectors** designed to make the board the foundation of a larger system, rather than a closed, self-contained unit.

The first is a *2×20 pin connector* that breaks out **all 40 pins of the Z80**: address bus, data bus, and control signals; giving direct access to the full CPU interface.
This connector is intended for daughter boards that **extend the Z80's environment**: additional memory, custom peripherals, or any hardware that needs to interact directly with the Z80 bus.

The second is a *2×10 pin connector* that exposes **a selection of RP2040** signals: the **3.3V and GND power** rails, the **two *ADC*** inputs (*ADC0* and *ADC1*), and *GPIO10* through *GPIO25*.
This connector is oriented towards **more advanced projects** where the **RP2040 itself needs to interact with external hardware**: sensors, displays, communication modules, or custom firmware **experiments that go beyond the standard board functionality**.

Together, the two connectors cover **both sides of the system**: the **Z80's classic parallel bus interface** and the **RP2040's modern programmable I/O**, making it possible to build virtually **any extension imaginable** on top of the Z80DevBoard.

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