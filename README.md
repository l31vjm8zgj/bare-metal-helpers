# bare-metal-helpers

Collection of C functions, classes, modules, etc, that help creating bare-metal projects.

## date-time
Date and time handling

## fixed-point-int
Basic functions for fixed-point integer calculations

## Ideas for implementing in the future
- CRC16, CRC32; maybe with compile-time table generator with C++? or a Python-Script, that generates C-Files?
- MD5 sum: to check integrity of serialized data
- sha checksum: this would be nice; maybe too complex?
- AES? maybe too complex?
- intel-hex: useful for updating eg. from SD-Card or over serial interface etc.
- modbus frames: for industrial controllers, this is most likely needed
- low-pass filter etc. and other filters (python, numpy, matplotlib for testing... possible in devcontainer?)
- PID: at least a template could be useful
