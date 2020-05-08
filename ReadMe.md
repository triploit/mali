# MaliOS - A bad operating system

This is only some testing, not really an operating system. It will be developed, because of fun.

Based on: https://www.lowlevel.eu/wiki/C%2B%2B-Kernel_mit_GRUB (German)
and: https://wiki.osdev.org/Bare_Bones#Writing_a_kernel_in_C.2B.2B (English)

## Dependencies

  * grub
  * xorriso
  * gcc
  * g++
  * qemu
  * mtools

## Installing dependencies

### Debian, Ubuntu, Linux Mint

```bash
apt-get install qemu-system-x86 # qemu
apt-get install g++ binutils # g++ and make
apt-get install nasm # nasm
apt-get install xorriso # xorriso
apt-get install grub2 # grub
apt-get install mtools # mtools for grub
```

or everything in one command: `apt-get install qemu-system-x86 binutils g++ nasm xorriso`

### Arch Linux, Manjaro Linux

```bash
pacman -S qemu # qemu
pacman -S gcc make # g++ and make
pacman -S nasm # nasm
pacman -S xorriso # xorriso
pacman -S grub # grub
pacman -S mtools # mtools for grub
```

or everything in one command: `pacman -S qemu gcc make nasm xorriso grub`

## Compiling and Testing

```bash
git clone https://github.com/triploit/mali MaliOS # cloning into a directory calles "MaliOS"
cd MaliOS # change to directory "MaliOS"
```

Compiling the project: `make compile`
Testing the project (with QEMU): `make test`
Cleaning binaries: `make clean`
