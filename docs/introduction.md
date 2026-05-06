# Chapter 1 - Introduction & Project History

## 1.1 What Is the Z80DevBoard?
The **Z80DevBoard** is an open-source single-board computer that pairs a **Zilog Z80 CPU**, one of the most iconic and revolutionary 8-bit processors ever built, with an **RP2040 microcontroller**, the modern dual-core chip designed by Raspberry Pi that powers most of the most modern projects.

The idea is simple: the Z80 operates as it would in its original environment, while the RP2040 handles all interaction between the developer and the board.
The Z80 still runs real code, asserts real signal lines, and behaves exactly as it did in 1976, but the world it communicates with is managed by a modern chip running firmware that enables advanced features: loading programs over USB-C, serial communication, real-time RAM access, and the flexibility to deploy custom firmware for more complex projects.

This makes the Z80DevBoard both a retrocomputing gem and a powerful educational tool: you can study Z80 bus cycles firsthand, write and run real assembly code, and observe authentic hardware behavior, all without the complexity of building the surrounding support circuitry from scratch. Whether you are a student exploring how computers truly work at the lowest level, or an enthusiast who simply appreciates the elegance of classic 8-bit architecture, this board was built with you in mind.

## 1.2 Why Z80 + RP2040?
### The Z80: A Processor Worth Knowing
The Zilog Z80 was developed in 1976 by Federico Faggin (the same engineer who designed the Intel 4004 and 8080). It later powered the ZX Spectrum, the MSX family, countless embedded systems, and even the Game Boy, which used a specially modified version of the Z80.

Despite being 50 years old, the Z80 remains an excellent architecture to study:
- Its instruction set is rich yet regular, making it accessible.
- Its bus protocol is well documented and easy to observe with a logic analyzer.
- It has influenced virtually every modern CPU architecture, including x86 and ARM.
- Writing Z80 assembly code teaches you exactly what a processor does, without layers of abstraction.

In short, the Z80 is a museum piece today, but its impact on the history of computing was profound, and its assembly language remains one of the best windows into the real workings of a CPU.

### The RP2040: a modern microcontroller
