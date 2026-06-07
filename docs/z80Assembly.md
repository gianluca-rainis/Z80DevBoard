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
|Use|Register|
|---|---|
|Interrupt Vector|I|
|Memory Refresh|R|
|||
|Index Register|IX|
|Index Register|IY|
|Stack Pointer|SP|
|Program Counter|PC|

## 6.3 The Flag Register
The **Flag Registers** (**F** and **F'**) are two *8-bit* registers automatically updated by the CPU after arithmetic and logic operations.
Each bit represents a specific condition, used by conditional instructions to decide whether to jump, call, or return.

|Bit|Flag|Name|Set when|
|---|---|---|---|
|7|S|Sign|Result is negative (bit 7 of result = 1)|
|6|Z|Zero|Result is zero|
|5|X|Not used|—|
|4|H|Half Carry|Carry from bit 3 to bit 4 (used by DAA)|
|3|X|Not used|—|
|2|P/V|Parity / Overflow|Even parity (logic ops) or signed overflow (> +128 or < -128)|
|1|N|Add / Subtract|Last operation was a subtraction (N = 1) or an addition (N = 0)|
|0|C|Carry|Result produced a carry or borrow|

The Flag Register cannot be written directly, it is only modified as a side effect of instructions.
It can however be saved and restored via the stack using `PUSH AF` and `POP AF`, or via the alternate register with `EX AF, AF'`.

## 6.4 Addressing Modes
Addressing modes define how an instruction locates its operands.
The Z80 supports the following addressing modes.

### Immediate
The byte immediately following the opcode in memory contains the operand.

```asm
LD A, 42          ; A <- 42
```

### Immediate Extended
The two bytes following the opcode are the operand, forming a 16-bit value.

```asm
LD HL, 0x8000     ; HL <- 0x8000
```

### Modified Page Zero
A single-byte `RST` instruction calls one of eight fixed locations in *Page 0* of memory, saving memory space for commonly-used subroutines.

```asm
RST 0x08          ; Call subroutine at 0x0008
```

### Relative
A signed 8-bit displacement is added to the address of the following instruction to form a jump target.
Allows relocatable code and saves memory space compared to extended jumps.

```asm
JR Z, LABEL       ; Relative jump to LABEL if Zero flag set
```

### Extended
Two bytes of address are included in the instruction, used as a pointer to a memory location or as a jump destination.

```asm
LD A, (0x4000)    ; A <- memory[0x4000]
JP 0x0100         ; Jump to 0x0100
```

### Indexed
A signed 8-bit displacement is added to an index register (IX or IY) to form a pointer to memory.
The index register itself is not modified.

```asm
LD A, (IX+5)      ; A <- memory[IX + 5]
LD (IY-2), B      ; Memory[IY - 2] <- B
```

### Register
The operand is a CPU register, specified by bits in the opcode.

```asm
LD A, B           ; A <- B
ADD A, C          ; A <- A + C
```

### Implied
The operand is implicitly defined by the opcode, no explicit address is needed.

```asm
RLCA              ; Rotate A left (A is implied)
DAA               ; Decimal adjust A (A is implied)
```

### Register Indirect
A 16-bit register pair is used as a pointer to a memory location.

```asm
LD A, (HL)      ; A <- memory[HL]
LD (HL), B      ; Memory[HL] <- B
```

### Bit Addressing
Used by bit set, reset, and test instructions.
Three bits in the opcode specify which of the eight bits to manipulate, while the operand is addressed via register, register indirect, or indexed modes.

```asm
BIT 3, A        ; Test bit 3 of A
SET 7, (HL)     ; Set bit 7 of memory[HL]
```

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