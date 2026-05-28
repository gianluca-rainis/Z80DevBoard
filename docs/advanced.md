# Chapter 5 - Advanced Guide

## 5.1 Flashing the Firmware
To flash a new firmware onto the RP2040:
1. Hold the *RP2040BOOT* button while connecting the board to your computer through the USB-C port.
2. The RP2040 will expose a **mass storage device** on your computer: it will appear as a USB drive.
3. Copy your **compiled UF2 firmware** file onto the drive.
4. The RP2040 will reset automatically and boot with the new firmware.

> The latest official firmware for the Z80DevBoard is available in the firmware folder of the repository.

## 5.2 Serial Communication with the RP2040
The RP2040 exposes a **USB CDC (Communications Device Class) serial interface** over the USB-C connector, which appears as a virtual COM port on the host computer.
This interface allows sending commands to the board and receiving output in real time, without any additional hardware.

To connect, open a serial terminal at ***115200* baud, *8N1*** (8 bit of data for each byte, No parity, 1 bit of stop) on the port assigned to the board by your operating system.

### Available Commands
`read <addrstart> [addrend]`

Reads one or more bytes from RAM and returns them as space-separated hexadecimal values.

```
read 0x0000        -> FF
read 0x0000 0x0004 -> FF A1 00 33 00
```

---

`write <addr> <value>`

Writes a single byte to the specified RAM address.
Returns the value read back from that address after the write: if it matches the value sent, the write was successful.

```
write 0x0FFF FF -> FF
```

If the readback differs from the written value, it indicates that an issue happened while writing that memory cell.

### Error Responses
All commands return an error message prefixed with ERROR: if the input is malformed:

```
read              -> ERROR: missing address
read 0xGGGG       -> ERROR: invalid address '0xGGGG'
write 0x0000      -> ERROR: missing value
unknowncmd        -> ERROR: unknown command 'unknowncmd'
```

## 5.3 Writing Custom RP2040 Firmware
> *This section is not yet available. It will be added in a future version of the documentation.*

## 5.4 Using an Expansion Board
The Z80DevBoard exposes **two expansion connectors** described in detail in [Chapter 3 - Pinout & Connectors](pinout.md).
Both are **dual-row SMD female** connectors with ***1.27 mm* pitch**.

To use a *third-part* or *community-designed* expansion board, check that it has matching **dual-row *1.27 mm* pitch male pin headers** on its **underside** and that it is **designed for the Z80DevBoard pinout**.
Plug it directly into the connectors.
**No soldering required**.

Before powering on, verify the following:
- Check the **voltage levels** of the expansion board. Signals on the 2×20 connector are at *5V* (Z80 bus), while signals on the 2×10 connector are at *3.3V* (RP2040 GPIO). Make sure the expansion board **is designed for the correct voltage** on each connector, and use a **level shifter** if interfacing between the two.
- Check the expansion board's power requirements. The *5V* pin (pin 39 on the 2×20) and the *3.3V* pin (pin 19 on the 2×10) can supply power, but the 3.3V rail is limited by the RP2040's onboard LDO. Power-hungry boards **should be supplied independently**.
- The ADC pins are analog inputs. **Do not exceed 3.3V on these pins**.
- If the expansion board requires custom RP2040 firmware, refer to section [5.3 Writing Custom RP2040 Firmware](advanced.md#53-writing-custom-rp2040-firmware) and **flash it before use**.

## 5.5 Developing an Expansion Board
Designing an expansion board for the Z80DevBoard requires attention to both **mechanical and electrical compatibility**.

### Mechanical Requirements
The two expansion connectors on the Z80DevBoard are **dual-row SMD female** connectors with ***1.27 mm* pitch**.
Your expansion board must use matching **dual-row *1.27 mm* pitch male pin headers on its underside**, aligned to the Z80DevBoard pinout as described in [Chapter 3 - Pinout & Connectors](pinout.md).
When designing the PCB, make sure the connector footprints are **placed on the bottom layer** of the expansion board, so that the board sits flat on top of the Z80DevBoard when plugged in.

### Electrical Considerations
Signals on the 2×20 connector are at **5V** (Z80 bus).
Design any circuit connected to these pins for **5V logic**, or add a **level shifter** if interfacing with **3.3V components**.

Signals on the 2×10 connector are at **3.3V** (RP2040 GPIO).
**Do not exceed 3.3V on any of these pins**.

The *ADC* pins (*ADC0*, *ADC1*) are analog inputs with a **maximum of 3.3V**.
Keep analog signals clean and **away from noisy** digital traces on your PCB.
If your board requires **more power** than the onboard rails can provide, add an **independent power input** rather than relying on the Z80DevBoard's LDO.

### PCB Design in KiCad
The Z80DevBoard is **designed in *KiCad***, and using the same tool for your expansion board ensures **full compatibility**.

The connector footprints to use are **standard *2×20* and *2×10* male pin headers with 1.27 mm pitch**: these are available in the *KiCad standard library*.

To verify alignment, import the Z80DevBoard PCB as a reference layer in your KiCad project and check that the **connector positions match** before ordering.

### RP2040 Firmware
If your expansion board uses GPIO pins from the 2×10 connector, those pins must be initialised in the RP2040 firmware.
The expansion GPIO definitions are already present in `firmware.h`:

```c
#define GPIO_EXPANSION_1  12
#define GPIO_EXPANSION_2  13
// ...
# define GPIO_EXPANSION_ADC1 27
# define GPIO_EXPANSION_ADC2 28
# define GPIO_EXPANSION_ADC3 29
```

**Uncomment** the corresponding `gpio_init` and `gpio_set_dir` calls in `setup()`, then add your logic to `loop()` or dedicated handler functions.
Refer to section [5.3 Writing Custom RP2040 Firmware](advanced.md#53-writing-custom-rp2040-firmware) for further guidance.

## 5.6 Debugging with SWD
The Z80DevBoard exposes the **RP2040's *SWD*** (*Serial Wire Debug*) interface through **two dedicated pins** located in the top-right corner of the board, as described in [Chapter 3 - Pinout & Connectors](pinout.md).

*SWD* allows **full debugging of the RP2040 firmware**: setting breakpoints, stepping through code, inspecting memory and registers, and flashing new firmware: all without pressing the *RP2040BOOT* button.

### What You Need
- A **SWD-compatible debug probe**: the official *Raspberry Pi Debug Probe* is recommended, but any *CMSIS-DAP* compatible adapter works.
- *OpenOCD* or other tools **supporting *CMSIS-DAP*** as the debug backend.
- An *IDE* with **debugging support**: *VS Code* with the *Cortex-Debug* extension is the most common choice for *Pico SDK* projects.

### Connecting the Probe
Connect the debug probe to the **two *SWD* pins** on the board:

|SWD Pin|Signal|
|---|---|
|1|*SWCLK*|
|2|*SWDIO*|

Use a **GND reference** from the **nearest GND pin on the expansion connector**.

### OpenOCD Configuration
A basic *OpenOCD* configuration for the RP2040:

```bash
sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg
```

Once connected, you can attach *GDB*:

```bash
gdb firmware/build/Z80DevBoard.elf
(gdb) target remote localhost:3333
(gdb) monitor reset init
(gdb) continue
```

For a more comfortable experience, use the *Cortex-Debug* extension in *VS Code*, which wraps *OpenOCD* and *GDB* in a **graphical interface** with breakpoints, variable inspection, and call stack view.

---

<div>
  <p align="left">
    <em>
      <b>
        <a href="/docs/quickstart.md">
          ← Back
        </a>
      </b>
    </em>
  </p>

  <p align="right">
    <em>
      <b>
        <a href="/docs/z80Assembly.md">
          Next Section ->
        </a>
      </b>
    </em>
  </p>
</div>

---

<p align="center">
    <em>Open source, Open Education - Z80DevBoard</em>
</p>