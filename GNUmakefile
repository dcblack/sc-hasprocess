#!make -f

.PHONY: default clean

default:
	rm -fr build; \
	mkdir build; \
	cd build; \
	cmake ..; \
	make; \
	env LD_LIBRARY_PATH=$(SYSTEMC_HOME)/lib DYLD_LIBRARY_PATH=$(SYSTEMC_HOME)/lib ./hasprocess.x

clean:
	rm -fr build

# The end
