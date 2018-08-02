ASM=nasm -f elf32
GXX=g++ -c -m32 -fno-stack-protector -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wall -Wextra -pedantic-errors -c

compile:
	$(ASM) boot.asm -o bin/boot.o

	$(GXX) xkernel.cpp -o bin/xkernel.o
	$(GXX) xinit.cpp -o bin/xinit.o
	$(GXX) lib/video.cpp -o bin/video.o

	ld -n -o bin/kernel -T linker.ld bin/boot.o bin/xkernel.o bin/video.o bin/xinit.o

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
	rm bin/kernel*
	rm bin/*.o
