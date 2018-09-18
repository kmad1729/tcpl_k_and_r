CC=gcc
C_Flags=-Wall -Werror

_ALL=ch_ex_2_1 ch_section_23
all: $(_ALL)

ch_ex_2_1: ch_ex_2_1.c
	$(CC) -o $@ $(C_Flags) $^

ch_section_23: ch_section_23.c
	$(CC) -o $@ $(C_Flags) $^

.PHONY: clean
clean:
	rm -rf $(_ALL)
