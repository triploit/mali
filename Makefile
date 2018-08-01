ASM=nasm -f elf64

compile:
	$(ASM) boot.asm -o bin/boot.o
	$(ASM) multiboot.asm -o bin/multiboot.o

	g++ -std=gnu99 -ffreestanding -O2 -Wall -Wextra -c main.cpp -nostdlib -o bin/xkernel.o
	ld -n -o bin/kernel -T linker.ld bin/multiboot.o bin/boot.o bin/xkernel.o

	cp bin/kernel bin/boot/kernel.bin
	if [ -f "bin/kernel.iso" ]; then rm bin/kernel.iso; fi

	rm bin/*.o
	grub-mkrescue bin --output=bin/kernel.iso

test: compile
	@qemu-system-x86_64 -cdrom bin/kernel.iso
	@echo ""

run: test
	@echo ""

clean:
	rm bin/*
