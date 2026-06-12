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

## 6.5 Instruction Set
### 6.5.1 Data Transfer
Data transfer instructions move data between registers, memory, and I/O ports.

```asm
; Register to register
LD A, B           ; A <- B
LD H, L           ; H <- L

; Immediate to register
LD A, 0x42        ; A <- 0x42
LD HL, 0x4000     ; HL <- 0x4000

; Register to memory
LD (HL), A        ; memory[HL] <- A
LD (0x4000), A    ; memory[0x4000] <- A

; Memory to register
LD A, (HL)        ; A <- memory[HL]
LD A, (0x4000)    ; A <- memory[0x4000]

; Stack
PUSH BC           ; Push BC onto stack (SP -= 2)
POP HL            ; Pop stack into HL (SP += 2)

; Exchange
EX DE, HL         ; Swap DE <-> HL
EX AF, AF'        ; Swap A,F <-> A',F'
EXX               ; Swap BC,DE,HL <-> BC',DE',HL'
```

### 6.5.2 Arithmetic
```asm
; 8-bit
ADD A, B          ; A <- A + B
ADD A, 0x10       ; A <- A + 0x10
ADC A, B          ; A <- A + B + Carry
SUB B             ; A <- A - B
SBC A, B          ; A <- A - B - Carry
INC A             ; A <- A + 1 (Carry not affected)
DEC B             ; B <- B - 1 (Carry not affected)

; 16-bit
ADD HL, BC        ; HL <- HL + BC
ADC HL, DE        ; HL <- HL + DE + Carry
SBC HL, DE        ; HL <- HL - DE - Carry
INC HL            ; HL <- HL + 1
DEC DE            ; DE <- DE - 1
```

### 6.5.3 Logic
```asm
AND B             ; A <- A AND B  (P/V = parity)
OR C              ; A <- A OR  C
XOR D             ; A <- A XOR D
CP E              ; Flags <- (A - E), A unchanged
CPL               ; A <- NOT A  (complement)
NEG               ; A <- 0 - A  (two's complement negate)
```

### 6.5.4 Bit Manipulation
```asm
BIT 3, A          ; Test bit 3 of A  -> sets Z flag
SET 7, B          ; Set bit 7 of B to 1
RES 0, C          ; Reset bit 0 of C to 0

; Rotate and shift
RLCA              ; Rotate A left  (bit 7 -> Carry -> bit 0)
RRCA              ; Rotate A right (bit 0 -> Carry -> bit 7)
RLA               ; Rotate A left  through Carry
RRA               ; Rotate A right through Carry
RLC r             ; Rotate register r left
RRC r             ; Rotate register r right
SLA r             ; Shift r left  arithmetic (LSB <- 0)
SRA r             ; Shift r right arithmetic (MSB preserved)
SRL r             ; Shift r right logical    (MSB <- 0)
RL r              ; Rotate register r left through Carry
RR r              ; Rotate register r right through Carry
RLD               ; Rotate left digit: high nibble of (HL) <-> low nibble of A
RRD               ; Rotate right digit: low nibble of A <-> high nibble of (HL)
```

### 6.5.5 Control Flow
```asm
; Unconditional
JP 0x0100         ; Jump to 0x0100
JR LABEL          ; Relative jump (-128 to +127 bytes)
DJNZ LABEL        ; B--; jump if B != 0 (loop counter)

; Conditional jumps (cc = Z, NZ, C, NC, PE, PO, M, P)
JP Z, LABEL       ; Jump if Zero flag set
JP NZ, LABEL      ; Jump if Zero flag clear
JP C, LABEL       ; Jump if Carry set
JP NC, LABEL      ; Jump if Carry clear
JR Z, LABEL       ; Relative jump if Zero
JR NZ, LABEL      ; Relative jump if Zero clear
JR C, LABEL       ; Relative jump if Carry
JR NC, LABEL      ; Relative jump if Carry clear

; Restart (Modified Page Zero)
RST 0x08          ; Call subroutine at 0x0008
```

### 6.5.6 Subroutines and the Stack
The Z80 uses a **descending stack**: it grows toward lower addresses.
`SP` always points to the last byte pushed.

`CALL` pushes the return address onto the stack and jumps to the subroutine.
`RET` pops the return address and jumps back.

```asm
    LD SP, 0xFFFF   ; Initialize stack pointer to top of RAM

MAIN:
    LD A, 0x41      ; 'A' in ASCII
    CALL PRINT      ; Call subroutine
    HALT

PRINT:
    OUT (0x00), A   ; Send character to UART TX
    RET             ; Return to caller
```

Conditional calls and returns are also supported:

```asm
CALL Z,  LABEL    ; Call if Zero flag set
CALL NZ, LABEL    ; Call if Zero flag clear
RET Z             ; Return if Zero flag set
RET C             ; Return if Carry set
```

### 6.5.7 Block Instructions
Block instructions operate on ranges of memory or I/O ports in a single instruction, replacing multi-instruction loops.

```asm
LDIR    ; Copy (HL)->(DE), HL++, DE++, BC--; repeat until BC=0
LDDR    ; Same but HL--, DE-- (copy backward)
CPIR    ; Compare A with (HL), HL++, BC--; stop on match or BC=0
CPDR    ; Same but HL-- (search backward)
INIR    ; Input from port C to (HL), HL++, B--; repeat until B=0
OTIR    ; Output (HL) to port C, HL++, B--; repeat until B=0
LDI     ; Copy (HL)->(DE), HL++, DE++, BC-- (single step, no repeat)
LDD     ; Copy (HL)->(DE), HL--, DE--, BC-- (single step, no repeat)
CPI     ; Compare A with (HL), HL++, BC-- (single step, no repeat)
CPD     ; Compare A with (HL), HL--, BC-- (single step, no repeat)
INI     ; Input from port C to (HL), HL++, B-- (single step)
IND     ; Input from port C to (HL), HL--, B-- (single step)
INDR    ; Same as IND but repeat until B=0
OUTI    ; Output (HL) to port C, HL++, B-- (single step)
OUTD    ; Output (HL) to port C, HL--, B-- (single step)
```

### 6.5.8 I/O Instructions
The Z80 has a dedicated I/O space of 256 ports, accessed with `IN` and `OUT` instructions, separate from the memory address space.

```asm
OUT (0x00), A     ; Output A to I/O port 0x00
IN A, (0x01)      ; Read I/O port 0x01 into A
OUT (C), B        ; Output B to port number in C
IN B, (C)         ; Read port in C into B
```

> On the Z80DevBoard, port `0x00` is the **UART TX** virtual peripheral.
> Writing to it sends a character to the USB serial console.

### 6.5.9 Interrupts
The Z80 supports two types of interrupt: **maskable** (`/INT`) and **non-maskable** (`/NMI`).

```asm
EI          ; Enable maskable interrupts
DI          ; Disable maskable interrupts
```

**Non-maskable interrupts** (`/NMI`) are always serviced, regardless of the `EI`/`DI` state.
The CPU saves the current PC on the stack and jumps to the fixed address `0x0066`.

**Maskable interrupts** (`/INT`) are only serviced when interrupts are enabled (`EI`).

The Z80 supports three interrupt modes:

| Mode | Instruction | Behaviour |
|---|---|---|
| 0 | `IM 0` | External device places an opcode on the data bus |
| 1 | `IM 1` | CPU always jumps to fixed address `0x0038` |
| 2 | `IM 2` | Vectored: address = `(I << 8) \| (data bus byte)` |

**IM 1** is the simplest and recommended for beginners:
```asm
    LD SP, 0xFFFF
    IM 1            ; Use interrupt mode 1
    EI              ; Enable maskable interrupts
    ; ... main code ...
    HALT

    ORG 0x0038      ; IM 1 interrupt service routine
ISR:
    ; Handle interrupt here
    EI              ; Re-enable interrupts
    RETI            ; Return from interrupt (restores IFF flags)
```

Return instructions for interrupts:
```asm
RETI    ; Return from maskable interrupt (signals I/O devices)
RETN    ; Return from non-maskable interrupt (restores IFF1 from IFF2)
```

### 6.5.10 Miscellaneous
```asm
NOP     ; No operation (4 cycles)
HALT    ; Stop execution, wait for interrupt
SCF     ; Set Carry flag
CCF     ; Complement Carry flag
DAA     ; Decimal adjust A after BCD arithmetic
```

## 6.6 Assembler Directives
Assembler directives are not Z80 instructions, they are commands to the assembler itself, controlling how the source code is translated into machine code.

Remember that the assembler directives may be different between different assemblers.

|Directive|Example|Description|
|---|---|---|
|`ORG`|`ORG 0x0000`|Set the address|
|`DEFB` / `DB`|`DEFB 0xFF, 0x00`|Emit one or more literal bytes|
|`DEFW` / `DW`|`DEFW 0x1234`|Emit a 16-bit word|
|`DEFS` / `DS`|`DEFS 16`|Reserve N zero-filled bytes|
|`DEFM` / `DM`|`DEFM "Hello"`|Emit a string as raw bytes|
|`EQU`|`UART_TX EQU 0x00`|Define a symbolic constant|
|`INCLUDE`|`INCLUDE "utils.asm"`|Include another source file|
|`END`|`END`|Mark the end of the source file|

## 6.7 Your First Program
### 6.7.1 Hello World
This program prints a greeting message over the UART, demonstrating basic data movement, the indirect addressing mode, and a simple loop with a string terminator.

```asm
ORG 0x0000

UART_TX EQU 0x00

START:
    LD HL, MSG          ; HL points to the start of the message

LOOP:
    LD A, (HL)          ; Load the next character into A
    OR A                ; Check if A is zero (string terminator)
    JR Z, DONE          ; If zero, the string is finished

    OUT (UART_TX), A    ; Send the character to the UART
    INC HL              ; Move to the next character
    JR LOOP             ; Repeat

DONE:
    HALT                ; Stop execution

MSG:    DEFM "Hello, World!", 0x0D, 0x0A, 0x00

    END
```

The program uses `HL` as a pointer that walks through the `MSG` string, one byte at a time.

Each character is loaded into `A` with `LD A, (HL)`, this is register indirect addressing: the address to read from is held inside `HL`, not written literally in the instruction.

The `OR A` instruction is a common check: ORing a register with itself doesn't change its value, but it updates the flags based on that value.
If `A` is `0x00`, the *Zero flag* is set, and `JR Z, DONE` jumps to the end of the program.

If the character isn't the terminator, it's sent to the *UART* with `OUT (UART_TX), A`, `HL` is incremented to point at the next character, and the loop repeats with `JR LOOP`.

The message itself is defined with `DEFM`, which emits each character as a raw byte, followed by `0x0D` (carriage return), `0x0A` (line feed), and `0x00` (the null terminator for the loop check).

## 6.8 Recommended Resources


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