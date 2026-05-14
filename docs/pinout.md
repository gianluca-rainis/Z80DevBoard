# Chapter 3 - Pinout & Connectors

## 3.1 Z80 Pinout
The *Z84C00* is available in a **40-pin DIP package**.
The pinout below reflects the official Zilog datasheet.

```
              ┌───────────────────┐
       A11 ⬅ │  1             40 │ ⮕ A10
       A12 ⬅ │  2     Z80     39 │ ⮕ A9
       A13 ⬅ │  3             38 │ ⮕ A8
       A14 ⬅ │  4             37 │ ⮕ A7
       A15 ⬅ │  5             36 │ ⮕ A6
       CLK ⮕ │  6             35 │ ⮕ A5
        D4 ⬌ │  7             34 │ ⮕ A4
        D3 ⬌ │  8             33 │ ⮕ A3
        D5 ⬌ │  9             32 │ ⮕ A2
        D6 ⬌ │ 10             31 │ ⮕ A1
       Vcc ⮕ │ 11             30 │ ⮕ A0
        D2 ⬌ │ 12             29 │ ⬅ GND
        D7 ⬌ │ 13             28 │ ⮕ /RFSH
        D0 ⬌ │ 14             27 │ ⮕ /M1
        D1 ⬌ │ 15             26 │ ⬅ /RESET
      /INT ⮕ │ 16             25 │ ⬅ /BUSRQ
      /NMI ⮕ │ 17             24 │ ⬅ /WAIT
     /HALT ⬅ │ 18             23 │ ⮕ /BUSACK
     /MREQ ⬅ │ 19             22 │ ⮕ /WR
     /IORQ ⬅ │ 20             21 │ ⮕ /RD
              └───────────────────┘
```

|Symbol|Pin|Direction|Description|
|---|---|---|---|
|A0–A15|30-40, 1–5|Output|16-bit address bus|
|D0–D7|14, 15, 12, 8, 7, 9, 10, 13|Bidirectional|8-bit data bus|
|CLK|6|Input|System clock|
|/MREQ|19|Output|Memory request (active low)|
|/IORQ|20|Output|I/O request (active low)|
|/RD|21|Output|Read operation indicator (active low)|
|/WR|22|Output|Write operation indicator (active low)|
|/M1|27|Output|With /MREQ indicates op code fetch cycle, with /IORQ indicates interrupt acknowledge cycle (active low)|
|/RFSH|28|Output|DRAM refresh cycle (active low)|
|/HALT|18|Output|CPU halted (active low)|
|/WAIT|24|Input|Insert wait states (active low)|
|/INT|16|Input|Maskable interrupt request (active low)|
|/NMI|17|Input|Non-maskable interrupt request (active low)|
|/RESET|26|Input|Reset (active low)|
|/BUSRQ|25|Input|Bus request (active low)|
|/BUSACK|23|Output|Bus acknowledge (active low)|
|Vcc|11|Power|+5V supply|
|GND|29|Power|Ground|

## 3.2 RP2040 Pinout
The *RP2040* is available in a **56-pin QFN package**.
The pinout below reflects the official Raspberry Pi datasheet.

```
QSPI_SS_N QSPI_SD1 QSPI_SD2 QSPI_SD0 QSPI_SCLK QSPI_SD3 DVDD IOVDD USB_VDD USB_DP USB_DM VREG_VIN VREG_VOUT ADC_AVDD
       ┌───────────────────────────────────────────────┐
       │   56 55 54 53 52 51 50 49 48 47 46 45 44 43   │
       │                                               │
 IOVDD │  1                                         42 │ IOVDD
 GPIO0 │  2                                         41 │ GPIO29/ADC3
 GPIO1 │  3                                         40 │ GPIO28/ADC2
 GPIO2 │  4                                         39 │ GPIO27/ADC1
 GPIO3 │  5              ┌───────────┐              38 │ GPIO26/ADC0
 GPIO4 │  6              │           │              37 │ GPIO25
 GPIO5 │  7              │    GND    │              36 │ GPIO24
 GPIO6 │  8              │           │              35 │ GPIO23
 GPIO7 │  9              └───────────┘              34 │ GPIO22
 IOVDD │ 10                                         33 │ IOVDD
 GPIO8 │ 11                                         32 │ GPIO21
 GPIO9 │ 12                                         31 │ GPIO20
GPIO10 │ 13                                         30 │ GPIO19
GPIO11 │ 14                                         29 │ GPIO18
       │                                               │
       │   15 16 17 18 19 20 21 22 23 24 25 26 27 28   │
       └───────────────────────────────────────────────┘
GPIO12 GPIO13 GPIO14 GPIO15 TESTEN XIN XOUT IOVDD DVDD SWCLK SWDIO RUN GPIO16 GPIO17
```

|Symbol|Pin|Direction|Description|
|---|---|---|---|
|GPIO0–GPIO25|2-9, 11-18, 27-32, 34-37|Configurable|General purpose I/O|
|GPIO26/ADC0|38|Configurable|GPIO or ADC (Analog to Digital Converter) channel 0|
|GPIO27/ADC1|39|Configurable|GPIO or ADC (Analog to Digital Converter) channel 1|
|GPIO28/ADC2|40|Configurable|GPIO or ADC (Analog to Digital Converter) channel 2|
|GPIO29/ADC3|41|Configurable|GPIO or ADC (Analog to Digital Converter) channel 3|
|XIN|20|Input|Crystal oscillator input (12 MHz)|
|XOUT|21|Output|Crystal oscillator output|
|USB_DP|47|Bidirectional|USB D+ (27Ω resistor required)|
|USB_DM|46|Bidirectional|USB D− (27Ω resistor required)|
|SWCLK|24|Input|SWD clock (debug)|
|SWDIO|25|Bidirectional|SWD data (debug)|
|RUN|26|Input|Reset (active low)|
|VREG_VIN|45|Power|Voltage regulator input (1.8V to 3.3V) (1uF capacitor required)|
|VREG_VOUT|44|Power|Voltage regulator output (1.1V core) (1uF capacitor required)|
|IOVDD|1, 10, 22, 33, 42, 49|Power|GPIO supply (1.8V to 3.3V)|
|DVDD|23, 50|Power|Digital core supply (1.1V)|
|ADC_AVDD|43|Power|ADC analog supply (3.3V)|
|USB_VDD|48|Power|USB PHY supply (3.3V)|
|GND|Center Pad|Power|Ground|
|QSPI_*|51–56|Bidirectional|Interface to a SPI flash (Usable also as GPIO)|

## 3.3 Expansion Connector 2x20 (Z80 Bus)
The *Expansion Connector (Z80 Bus)* is a **2×20 pin connector** located on the bottom-right of the Z80DevBoard.
It exposes all **Z80 bus signals**, providing direct access to the CPU interface for daughter boards and external hardware.

```
 D0 D2 D4 D6 HALT RST BREQ INT M1 IORQ A0 A2 A4 A6 A8 A10 A12 A14 WR Vcc
  1  3  5  7  9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39
┌────────────────────────────────────────────────────────────┐
│ ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ● │
│ ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ●  ● │
└────────────────────────────────────────────────────────────┘
  2  4  6  8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40
 D1 D3 D5 D7 WAIT CLK BACK NMI RFSH MREQ A1 A3 A5 A7 A9 A11 A13 A15 RD GND
```

|Symbol|Pin|Direction|Description|
|---|---|---|---|
|D0–D7|1-8|Bidirectional|8-bit data bus|
|HALT|9|Output|CPU halted (active low)|
|WAIT|10|Input|Insert wait states (active low)|
|RST|11|Input|Reset (active low)|
|CLK|12|Input|System clock|
|BREQ|13|Input|Bus request (active low)|
|BACK|14|Output|Bus acknowledge (active low)|
|INT|15|Input|Maskable interrupt request (active low)|
|NMI|16|Input|Non-maskable interrupt request (active low)|
|M1|17|Output|With MREQ indicates op code fetch cycle, with IORQ indicates interrupt acknowledge cycle (active low)|
|RFSH|18|Output|DRAM refresh cycle (active low)|
|IORQ|19|Output|I/O request (active low)|
|MREQ|20|Output|Memory request (active low)|
|A0–A15|21-36|Output|16-bit address bus|
|WR|37|Output|Write operation indicator (active low)|
|RD|38|Output|Read operation indicator (active low)|
|Vcc|39|Power|+5V supply|
|GND|40|Power|Ground|

## 3.4 Expansion Connector 2x10 (RP2040)
The *Expansion Connector (RP2040)* is a **2×10 pin connector** located on the bottom-right of the Z80DevBoard.
It exposes GPIO pins 10 through 25, two ADC pins, and the 3v3 power rail, allowing the development of more advanced projects on expansion boards with custom firmware.

```
 GPIO10 GPIO12 GPIO14 GPIO16 GPIO18 GPIO20 GPIO22 GPIO24 ADC0 3v3
  1  3  5  7  9 11 13 15 17 19
┌──────────────────────────────┐
│ ●  ●  ●  ●  ●  ●  ●  ●  ●  ● │
│ ●  ●  ●  ●  ●  ●  ●  ●  ●  ● │
└──────────────────────────────┘
  2  4  6  8 10 12 14 16 18 20
 GPIO11 GPIO13 GPIO15 GPIO17 GPIO19 GPIO21 GPIO23 GPIO25 ADC1 GND
```

|Symbol|Pin|Direction|Description|
|---|---|---|---|
|GPIO10-GPIO25|1-16|Configurable|General purpose I/O|
|ADC0-ADC1|17-18|Configurable|GPIO or ADC (Analog to Digital Converter) channel 0 and 1|
|3v3|19|Power|+3.3V supply|
|GND|20|Power|Ground|

## 3.5 SWD Debug Connector


---

<div>
  <p align="left">
    <em>
      <b>
        <a href="/docs/hardware.md">
          ← Back
        </a>
      </b>
    </em>
  </p>

  <p align="right">
    <em>
      <b>
        <a href="/docs/quickstart.md">
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