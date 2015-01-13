TSC = tsc
RM 	= rm -rf

DIR_JS	= ./js

TS_SOURCES = $(shell find $(DIR_JS) -type f -iname '*.ts')
TS_TARGETS = $(patsubst %.ts, %.js, $(TS_SOURCES))


.PHONY: all clean

all: build

build: ts

ts: $(TS_SOURCES)
	$(TSC) $(TS_SOURCES)

clean:
	$(RM) $(TS_TARGETS)
