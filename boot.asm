global loader ; Unser Einsprungspunkt 
extern xkernel ; xkernel() aus main.cpp 
extern initialiseConstructors ; aus init.cpp

FLAGS equ 0 
MAGIC equ 0x1BADB002 ; Magicnumber - Erkennungsmerkmal für GRUB 
CHECKSUM equ -(MAGIC + FLAGS) ; Checksum

section .text 
align 4 
MultiBootHeader:
	dd MAGIC       				; Magic number
	dd FLAGS       				; Flags
	dd CHECKSUM    				; Checksum

loader:
	mov esp,0x200000 				; Stack an die 2MB-Grenze platzieren
	push eax         				; Multiboot-Magicnumber auf den Stack legen
	push ebx         				; Adresse der Multiboot-Structure auf den Stack legen
	call initialiseConstructors   	; Konstruktoren aufrufen
	call xkernel     				; kernelMain aufrufen

stop:
	jmp stop					; Endlosschleife nach Beendigung unseres Kernels

