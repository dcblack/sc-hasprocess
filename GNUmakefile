#!make -f

.PHONY: default clean


ifndef SYSTEMC_HOME
 ifdef SYSTEMC
   export SYSTEMC_HOME=${SYSTEMC}
 else
  $(error Must define SYSTEMC or SYSTEMC_HOME to point at a valid SystemC installation of at least version 2.3.2 with cmake support)
 endif
endif
VER_H := $(wildcard ${SYSTEMC_HOME}/include/sysc/kernel/sc_ver.h)
ifeq "${VER_H}" ""
  $(error SYSTEMC_HOME does not appear to point to a valid SystemC installation)
endif

default:
	@rm -fr build/* build; \
	mkdir -p build;
	cd build && \
	cmake ..; \
	make && \
	env LD_LIBRARY_PATH=$(SYSTEMC_HOME)/lib DYLD_LIBRARY_PATH=$(SYSTEMC_HOME)/lib ./hasprocess.x

clean:
	rm -fr build

# The end
