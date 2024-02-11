obj-m := passing_param.o  passing_param_array.o

all:
	make -C /lib/modules/`uname -r`/build/ M=${PWD} modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=${PWD} clean


