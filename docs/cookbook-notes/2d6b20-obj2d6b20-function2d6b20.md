# 0x2d6b20 Obj2d6b20::Format

<!-- tags: wall/inlining, abi/calling-convention -->

- Function: 0x2d6b20 Obj2d6b20::Format
- Label: GUESS(low)
- Outcome: fixed
- Cause: calling-convention
- Best score: 86/86 (aligned_matching_bytes)
- Attempts: 4

## What differed

Calling `__stdio_common_vsprintf` directly in the variadic wrapper left the format pointer on the stack across the stdio-options call because `va_start` took its address, saving two callee-saved registers instead of three. Moving the call into a local helper matched the three saves but swapped the format and buffer registers. Switching to `std::vsprintf` from `<cstdio>` fixed the registers, but returning `int` kept the CRT's negative-result clamp at the epilogue.

## Spellings tried that did not help

- Direct call to `__stdio_common_vsprintf` inside the variadic function: saved two callee-saved registers and reloaded the format pointer after the options call.
- Calling a custom file-local `va_list` helper: saved three callee-saved registers in the right frame size, but swapped the registers holding the buffer and format pointers.
- Calling `std::vsprintf` from `<cstdio>` with an `int` return type: matched register allocation, but kept an extra negative-result clamp before returning.

## Spelling that fixed it

Declare the variadic wrapper as returning `void` and call `std::vsprintf` from `<cstdio>` so the compiler uses the standard inline wrapper and eliminates the unused negative-result clamp:

```cpp
void Obj2d6b20::Format(char* a_buffer, const char* a_format, ...)
{
    std::va_list args;
    va_start(args, a_format);
    std::vsprintf(a_buffer, a_format, args);
    va_end(args);
}
```
