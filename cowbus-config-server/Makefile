# The recommended compiler flags for the Raspberry Pi
CCFLAGS = -Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s \
			-std=gnu++11 -D_WEBSOCKETPP_CPP11_STL_

LDFLAGS	= -lboost_system -lboost_thread -lpthread -lrf24-bcm

RF24_PATH = ../../RF24/
WSPP_PATH = ../../websocketpp/


# define all programs
PROGRAMS = cowbus-config-server
SOURCES = ${PROGRAMS:=.cpp}

all: ${PROGRAMS}


${PROGRAMS}: ${SOURCES}
	g++ ${CCFLAGS} -Wall -I$(WSPP_PATH) -I$(RF24_PATH) \
		$@.cpp -o $@ ${LDFLAGS}


clean:
	rm -rf $(PROGRAMS)

