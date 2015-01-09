# name of your application
APPLICATION = cowbus

# If no BOARD is found in the environment, use this default:
BOARD ?= stm32f3discovery-diy
#BOARD ?= cowbus-one

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../../RIOT/


USEMODULE += nrf24l01p
USEMODULE += uart0



# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
#CFLAGS += -DDEVELHELP 
CFLAGS += -marm -mthumb-interwork


# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

include $(RIOTBASE)/Makefile.include
