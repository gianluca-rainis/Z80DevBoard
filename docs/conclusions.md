# Chapter 8 - Conclusions

## 8.1 What You Have Learned
If you have worked through this documentation and run your first programs on the Z80DevBoard, you have touched on a remarkable amount of **fundamental computer science and electronics**, knowledge that goes far beyond the Z80 itself.

### Computer Architecture
The *Z80* sits at the **root of decades of processor design**.

Understanding how it fetches instructions, manages its registers, and communicates over its buses gives you **a foundation that transfers directly to modern CPU architectures**: the same core concepts of instruction cycles, addressing modes, and bus protocols still underpin the processors running in today's computers and embedded systems.
Having worked with a real, observable Z80, you now have the conceptual tools to **understand how any computer actually works** beneath its layers of abstraction.

### Programming at the Lowest Level
You have **written, assembled, and executed real Z80 assembly**: moving data between registers and memory, implementing sorting algorithms, handling interrupts, and controlling I/O directly through hardware ports.
These are **the same fundamental operations every higher-level programming language** ultimately compiles down to: you have seen, firsthand, **what a computer is truly doing** when it runs a program.

### Electronics and PCB Design
By studying the **technical documentation** in depth (the schematics, the PCB layout, the design choices behind every component), you have also **gained insight into how the board itself was engineered**.
Concepts like voltage level shifting, bus arbitration, decoupling, and layer stack-up are not just abstract electronics theory here; they are the real reasons specific components were chosen and specific traces were routed the way they were on the board in front of you.

### The Educational Value of Hands-On Hardware
> *This is what the Z80DevBoard was built for: not just to run code, but to make the invisible visible.*

Watching a real address bus toggle on the LED matrices, stepping through a real clock cycle, and tracing a signal from its schematic symbol to its physical pin on the board **turns abstract textbook concepts into something you can see**, touch, and **understand at a level that no simulator alone could fully provide**.

## 8.2 Where to Go Next
The Z80DevBoard is a starting point, not a destination. Here are some directions worth exploring:

### On the software side:
- Implement a small operating system kernel, even a simple task switcher teaches a great deal
- Write a *BASIC* interpreter in Z80 assembly, the same approach *Microsoft* took for early 8-bit computers
- Write a custom interpreter in Z80 assembly, (more creative than a *BASIC* interpreter)
- Explore the *undocumented Z80 opcodes*, the processor has hidden instructions that most official documentation omits

### On the hardware side:
- Design and build your own expansion board, putting [5.5 Developing an Expansion Board](advanced.md#55-developing-an-expansion-board) into practice
- Write custom *RP2040 firmware* to implement new serial commands or virtual peripherals
- Add a real-time clock, a display, or an SD card interface via the expansion connectors
- Study the *KiCad* files in depth and propose your own improvements to the hardware design

### On the theory side:
- Study the Z80 machine cycle timing diagrams in the official datasheet: every nanosecond is specified
- Read about historical Z80-based systems: the *ZX Spectrum*, the *TRS-80*, the *Amstrad CPC*, the *MSX* standard
- Compare the Z80's architecture to a modern processor and identify what changed, and what didn't

## 8.3 Contributing
The Z80DevBoard is released under open licenses: the hardware under **CERN OHL S v2.0**, and the firmware and documentation under the **MIT License**.

This means:
- You are free to use, study, modify, and manufacture the hardware
- If you distribute modified versions of the hardware, you must release your changes under the same CERN OHL S v2.0 terms
- The firmware and documentation can be freely reused, modified, and redistributed under the MIT License
- Attribution to the original project is appreciated

Contributions are welcome via the GitHub repository:
- **Bug reports and corrections** - open an issue
- **Hardware improvements** - submit a pull request against the KiCad project
- **Firmware features** - submit a pull request against the firmware source
- **Documentation additions** - submit a pull request against the documentation

Repository: [github.com/gianluca-rainis/Z80DevBoard](https://github.com/gianluca-rainis/Z80DevBoard)

## 8.4 Acknowledgements
The Z80DevBoard draws on decades of publicly available documentation, open-source tooling, and community knowledge:

- **Zilog** - for producing and documenting the Z80 so thoroughly
- **Raspberry Pi Ltd** - for the RP2040 and the Pico SDK
- **The KiCad team** - truly excellent open-source PCB design software, free for everyone
- **Hack Club** - for fostering a community of young makers and giving projects like this a place to grow
- **Every student, teacher, and hobbyist** who kept 8-bit computing alive and worth caring about

> *A special thanks goes to* **[PCBWay](https://www.pcbway.com)***, whose sponsorship made the manufacturing of this board possible in the first place.*
> [![PCBWay](/images/pcbway.png)](https://www.pcbway.com)
> *Their precision, reliability, and genuinely helpful technical staff turned a KiCad design file into a real, working board. Without them, this project would still be a set of schematics on a screen.*

This documentation, and the board it describes, would not exist in this form without all of the above.

---

<div>
  <p align="left">
    <em>
      <b>
        <a href="/docs/technicalInfo.md">
          ← Back
        </a>
      </b>
    </em>
  </p>
</div>

---

<p align="center">
    <em>Open source, Open Education - Z80DevBoard</em>
</p>