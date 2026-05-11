# Chapter 3 - Pinout & Connectors

## 3.1 Z80 Pinout
The *Z84C00* is available in a **40-pin DIP package**.
Pin 1 is located at the top-left of the notch; numbering proceeds counter-clockwise.

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