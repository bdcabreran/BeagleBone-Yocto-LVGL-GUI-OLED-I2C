# Check if KERNEL_SRC is set, otherwise default to /lib/modules/$(shell uname -r)/build
ifndef KERNEL_SRC
	KERNEL_SRC := /lib/modules/$(shell uname -r)/build
endif

obj-m += ssd1306.o

# Default target to compile the module
all:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) modules

# Target to install the module (useful for direct installations on a running system)
modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) modules_install

# Clean up build artifacts
clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) clean
