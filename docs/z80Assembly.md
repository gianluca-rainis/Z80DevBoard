# Chapter 6 - Z80 Assembly Programming

## 6.1 Introduction to Z80 Assembly
**Assembly language** is the human-readable form of a **processor's machine code**.
Each line corresponds directly to **one instruction the CPU executes**, without compiler; runtime; or framework between you and the hardware.

Writing Z80 assembly means writing exactly **what the processor will do**, one operation at a time: load a value into a register, add two numbers, jump to a different part of the program.
There is **no abstraction**, **no hidden behavior**, and **no overhead**.

> *What you write is what runs.*

This directness is what makes assembly both **challenging** and deeply **educational**.
Understanding Z80 assembly means understanding **how any CPU works** at its most fundamental level: how instructions are fetched and decoded, how memory is addressed, how control flow is implemented in hardware.

These concepts underlie **every programming language** and **every processor architecture** in use today.
The Z80 is one of the **best architectures to learn assembly** on: its **instruction set is rich but regular**, its **documentation is thorough**, and its **behavior is entirely predictable**.

> *Once you understand the Z80, the principles transfer directly to other architectures.*

## 6.2 The Z80 Register Set
The *Z80 CPU* contains *208 bits* of **read/write memory**, configured as **eighteen *8-bit* registers** and **four *16-bit* registers**.
There are **two sets of six general-purpose registers**, **two sets of Accumulator and Flag registers**, and **six special-purpose registers**.

### Main Register Set
|Accumulator|Flags|
|---|---|
|A|F|
|B|C|
|D|E|
|H|L|

### Alternate Register Set
|Accumulator|Flags|
|---|---|
|A'|F'|
|B'|C'|
|D'|E'|
|H'|L'|

### Special Purpose Registers
|Interrupt Vector|Memory Refresh|
|---|---|
|I|R|
|||
|Index Register|IX|
|Index Register|IY|
|Stack Pointer|SP|
|Program Counter|PC|

## 6.3 The Flag Register

## 6.4 Addressing Modes

## 6.5 Core Instructions

## 6.6 Subroutines and the Stack

## 6.7 Interrupts

## 6.8 Assembler Directives

## 6.9 Your First Program

## 6.10 Recommended Resources


---

<div>
  <p align="left">
    <em>
      <b>
        <a href="/docs/advanced.md">
          ← Back
        </a>
      </b>
    </em>
  </p>

  <p align="right">
    <em>
      <b>
        <a href="/docs/technicalInfo.md">
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