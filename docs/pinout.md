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
                    56  QSPI_SS_N
                    55  QSPI_SD1
                    54  QSPI_SD2
                    53  QSPI_SD0
                    52  QSPI_SCLK
                    51  QSPI_SD3
                    50  DVDD
                    49  IOVDD
                    48  USB_VDD
                    47  USB_DP
                    46  USB_DM
                    45  VREG_VIN
                    44  VREG_VOUT
                    43  ADC_AVDD
         ┌───────────────────────────────────────────────┐
         │   56 55 54 53 52 51 50 49 48 47 46 45 44 43   │
IOVDD  1 │  1                                         42 │ 42  IOVDD
GPIO0  2 │  2                                         41 │ 41  GPIO29/ADC3
GPIO1  3 │  3                                         40 │ 40  GPIO28/ADC2
GPIO2  4 │  4                                         39 │ 39  GPIO27/ADC1
GPIO3  5 │  5                                         38 │ 38  GPIO26/ADC0
GPIO4  6 │  6                                         37 │ 37  GPIO25
GPIO5  7 │  7                   GND                   36 │ 36  GPIO24
GPIO6  8 │  8                                         35 │ 35  GPIO23
GPIO7  9 │  9                                         34 │ 34  GPIO22
IOVDD 10 │ 10                                         33 │ 33  IOVDD
GPIO8 11 │ 11                                         32 │ 32  GPIO21
GPIO9 12 │ 12                                         31 │ 31  GPIO20
GPIO10 13│ 13                                         30 │ 30  GPIO19
GPIO11 14│ 14                                         29 │ 29  GPIO18
         │   15 16 17 18 19 20 21 22 23 24 25 26 27 28   │
         └───────────────────────────────────────────────┘
                    15  GPIO12
                    16  GPIO13
                    17  GPIO14
                    18  GPIO15
                    19  TESTEN
                    20  XIN
                    21  XOUT
                    22  IOVDD
                    23  DVDD
                    24  SWCLK
                    25  SWDIO
                    26  RUN
                    27  GPIO16
                    28  GPIO17
```

## 3.3 Expansion Connector 2x20 (Z80 Bus)

## 3.4 Expansion Connector 2x10 (RP2040)

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