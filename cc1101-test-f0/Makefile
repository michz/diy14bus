# name of your application
APPLICATION = cc1101-test-f0

# If no BOARD is found in the environment, use this default:
BOARD ?= stm32f0discovery-diy
#BOARD ?= native

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../../RIOT/


USEMODULE += cc110x_spi
USEMODULE += cc110x_legacy


# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
#CFLAGS += -DDEVELHELP 
CFLAGS += -marm -mthumb-interwork


# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

include $(RIOTBASE)/Makefile.include
