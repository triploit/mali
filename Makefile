ASM=nasm -f elf64
GXX=g++ -std=gnu99 -ffreestanding -O2 -Wall -Wextra -c

compile:
	$(ASM) boot.asm -o bin/boot.o
	$(GXX) main.cpp -nostdlib -o bin/xkernel.o
	ld -n -o bin/kernel -T linker.ld  bin/boot.o bin/xkernel.o

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
