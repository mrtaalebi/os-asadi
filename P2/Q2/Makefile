obj-m += simple_arithmetic/simple_arithmetic.o
obj-m += simple_arithmetic_tester/simple_arithmetic_tester.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
 
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
