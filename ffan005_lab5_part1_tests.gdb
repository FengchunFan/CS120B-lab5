echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: ~0x00 => PORTC: 0x40"
setPINA ~0x00
continue 2
expectPORTC 0x40
checkResult

test "PINA: ~0x01 => PORTC: 0x60"
setPINA ~0x01
continue 2
expectPORTC 0x60
checkResult

test "PINA: ~0x02 => PORTC: 0x60"
setPINA ~0x02
continue 2
expectPORTC 0x60
checkResult

test "PINA: ~0x0A => PORTC: 0x3E"
setPINA ~0x0A
continue 2
expectPORTC 0x3E
checkResult

test "PINA: ~0x09 => PORTC: 0x3C"
setPINA ~0x09
continue 2
expectPORTC 0x3C
checkResult

# Add tests below

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
