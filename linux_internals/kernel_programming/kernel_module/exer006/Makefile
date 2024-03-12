obj-m := module_stack1.o
obj-m += module_stack2.o

all:
	make -C /lib/modules/`uname -r`/build M=${PWD}  modules
clean:
	make -C /lib/modules/`uname -r`/build M=${PWD} clean


