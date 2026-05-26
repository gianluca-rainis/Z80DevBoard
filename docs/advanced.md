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

## 5.4 Using an Expansion Board
The Z80DevBoard exposes **two expansion connectors** described in detail in [Chapter 3 - Pinout & Connectors](pinout.md).
Both are **dual-row SMD female** connectors with ***1.27 mm* pitch**.

To use a *third-part* or *community-designed* expansion board, check that it has matching **dual-row *1.27 mm* pitch male pin headers** on its **underside** and that it is **designed for the Z80DevBoard pinout**.
Plug it directly into the connectors.
**No soldering required**.

Before powering on, verify the following:
- Check the **voltage levels** of the expansion board. Signals on the 2x20 connector are at *5V* (Z80 bus), while signals on the 2x10 connector are at *3.3V* (RP2040 GPIO). Make sure the expansion board **is designed for the correct voltage** on each connector, and use a **level shifter** if interfacing between the two.
- Check the expansion board's power requirements. The *5V* pin (pin 39 on the 2x20) and the *3.3V* pin (pin 19 on the 2x10) can supply power, but the 3.3V rail is limited by the RP2040's onboard LDO. Power-hungry boards **should be supplied independently**.
- The ADC pins are analog inputs. **Do not exceed 3.3V on these pins**.
- If the expansion board requires custom RP2040 firmware, refer to section [5.3 Writing Custom RP2040 Firmware](advanced.md#53-writing-custom-rp2040-firmware) and **flash it before use**.

## 5.5 Developing an Expansion Board

## 5.6 Debugging with SWD


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