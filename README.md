# OS-Template
## What is this?
This is an extremely basic "operating system" boilerplate. Expand upon it to build your own operating system, without all the hassle of setting up a compiler, directory structure, makefile etc.

The template is designed to be modern: It utilises UEFI and builds for x86_64.

### What does it do?
 - Compiles and runs a simple UEFI application, which can be expanded into a bootloader.
### What doesn't it do?
 - Pretty much everything. It doesn't exit the UEFI boot services, so it is technically a UEFI application and not a bootloader.

## Notes
While any code I've written is in the public domain, some components have been "borrowed" from other sources. This means other license conditions may apply. Most notably: 
 - Topmost makefile and kernel.c: https://wiki.osdev.org/User:No92/UEFI_Bare_Bones
 - Bootloader makefile: https://stackoverflow.com/a/48267562
 - Zircon UEFI Headers (MIT License) (Mirror): https://github.com/vineyard-os/zircon-uefi
 - maybe other things...

To be honest, the makefile structure modifications I have made aren't all that good. The kernel makefile blatantly compiles all source files rather than relevant ones inferred from the #included headers. (Could perhaps use makefile/GCC dependencies, .d files) Feeling productive, may refactor later idk.

Expect to see this template improve and become more comprehensive over time.

## Getting Started
You'll need the following tools installed:
- clang and lld (specifically lld-link)
- qemu-system-x86_64
- make, git, wget

(If you're on Windows, try using Windows Subsystem for Linux or Cygwin.)

Then, run the build system: ```make```. The OS will be built and QEMU will launch.

![Image of Hello World running in QEMU](Bits/Hello.png?raw=true "Hello World running in QEMU")

To boot this on a real computer, you could probably copy the "efi" folder under "Build/HDD/efi" to the [EFI partition](https://en.wikipedia.org/wiki/EFI_system_partition) on a USB device or hard disk. Likewise, an ISO image could be created from the "HDD" folder, and then be booted on a virtual machine or distributed.
