cmd_/home/km/kernel_module/exer006/module_stack1.ko := ld -r -m elf_x86_64 -z max-page-size=0x200000 -T ./scripts/module-common.lds --build-id  -o /home/km/kernel_module/exer006/module_stack1.ko /home/km/kernel_module/exer006/module_stack1.o /home/km/kernel_module/exer006/module_stack1.mod.o ;  true