# name of your application
APPLICATION = cowbus

# If no BOARD is found in the environment, use this default:
#BOARD ?= stm32f3discovery-diy
BOARD ?= cowbus-one

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../../RIOT/

# application configuration options
APP_MACROS += -DNODE_IS_ACTOR		# says that this node is a actor
APP_MACROS += -DNODE_IS_SENSOR		# says that this node is a sensor

APP_MACROS += -DPERIPH_EN_BUZZER	# enable PERIPH
APP_MACROS += -DPERIPH_EN_EEPROM	# enable PERIPH
APP_MACROS += -DPERIPH_EN_TEMP		# enable PERIPH
APP_MACROS += -DPERIPH_EN_LED		# enable PERIPH
APP_MACROS += -DPERIPH_EN_SWITCH	# enable PERIPH

USEMODULE += nrf24l01p
#USEMODULE += uart0


# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
#CFLAGS += -DDEVELHELP 
CFLAGS += -I./include/ -marm -mthumb-interwork $(APP_MACROS)
CFLAGS += -DLOG_LEVEL=LOG_ALL


# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

include $(RIOTBASE)/Makefile.include


cowbus-doc: *.c include/*.h doc/Doxyfile
	doxygen doc/Doxyfile

clean-cowbus-doc:
	rm -rf doc/html/

# some useful things...
.PHONY: todo clean-doc
GREP_ARGS = --exclude={*.tmp,*.swp,Makefile} --exclude-dir=".git" -n --color=auto
todo:
	-@grep $(GREP_ARGS) -i "TODO" ./ -R 

todo-riot:
	-@grep $(GREP_ARGS) -i "TODO" ../../RIOT/boards/*-diy/ -R 


# help vim to display this file
# vim: set noet ts=4 sw=4:
