# OS-Template
Let's get started.

## What is this?
This is an extremely basic "operating system" boilerplate. Expand upon it to build your own operating system, without all the hassle of setting up a compiler, directory structure, makefile etc.

The OS is designed to be modern: It utilised UEFI and builds for x86_64.

## Notes
While this code is in the public domain, some components have been "borrowed" from other sources. This means other license conditions may apply. Most notably: 
 - Topmost makefile and kernel.c: https://wiki.osdev.org/User:No92/UEFI_Bare_Bones
 - Kernel makefile: https://stackoverflow.com/a/48267562
 - Zircon UEFI Headers (MIT License) (Mirror): https://github.com/vineyard-os/zircon-uefi
 - maybe other things...

To be honest, the makefile structure modifications I have made aren't all that good. The kernel makefile blatantly compiles all source files rather than relevant ones inferred from the #included headers. Feeling productive, may refactor later idk.

## Getting Started
You'll need the following tools installed:
- clang and lld (specifically lld-link)
- qemu-system-x86_64
- make, git, wget
If you're on Windows, try using Windows Subsystem for Linux or Cygwin.

Then, run the build system: ```make```. The OS will be built and QEMU will launch.

![Image of Hello World running in QEMU](Bits/Hello.png?raw=true "Hello World running in QEMU")
