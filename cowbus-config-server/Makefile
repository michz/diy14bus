# The recommended compiler flags for the Raspberry Pi
CCFLAGS = -Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s \
			-std=gnu++11 -D_WEBSOCKETPP_CPP11_STL_ -I./include/


RF24_PATH = ../../RF24/
WSPP_PATH = ../../websocketpp/

# default is empty prefix
PREFIX =
CCFLAGS2 =
LDFLAGS	= -lboost_system -lboost_thread -lpthread -lrf24-bcm

### Croos-Compiler Setup ###
CROSS_PREFIX = arm-linux-gnueabihf-
CROSS_CCFLAGS2 = -I$${RPI_ROOT}/include -I$${RPI_ROOT}/local/include \
				 -I$${RPI_ROOT}/local/include/RF24 -Wno-unused-local-typedefs \
				 -Wno-unused-variable
CROSS_LDFLAGS = -lboost_system -lboost_thread -lpthread -l:librf24-bcm.so.1.0 \
				 -L$${RPI_ROOT}/lib -L$${RPI_ROOT}/local/lib



# define all programs
PROGRAMS = cowbus-config-server
SOURCES = ${PROGRAMS:=.cpp}

all: ${PROGRAMS}


${PROGRAMS}: ${SOURCES}
	$(PREFIX)g++ ${CCFLAGS} ${CCFLAGS2} -Wall -I$(WSPP_PATH) -I$(RF24_PATH) \
		$@.cpp -o $@ ${LDFLAGS}

cross:
	$(MAKE) PREFIX=$(CROSS_PREFIX) CCFLAGS2='$(CROSS_CCFLAGS2)' LDFLAGS='$(CROSS_LDFLAGS)'


clean:
	rm -rf $(PROGRAMS)

