# 0x614140 Win32FileType::Function614140

<!-- tags: abi/calling-convention, method/diagnostic -->

- Function: 0x614140 Win32FileType::Function614140
- Label: GUESS(low)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: local native Windows PASS, 42/42 bytes; first draft 34/42 aligned matching bytes
- Attempts: 2

## What differed

For build sse-steam-1-7-104, the handwritten callback helper initially declared its fifth argument as `bool`. The candidate was 39 bytes against the target's 42 bytes. The argument-width observation, rather than the boolean interpretation of its value, constrained the declaration. The receiver identity remains a stand-in; the community-generated name hint is not identity evidence.

## Spellings tried that did not help

The initial `bool` callback parameter and `true` call argument produced the near miss. No register permutations or unrelated source variants were tried. Retrieved calling-convention lessons did not supply this particular fix.

## Spelling that fixed it

Declare the callback's fifth parameter as `std::uint32_t` and pass the integer flag value. That change alone closed the native Windows comparison at 42/42 bytes on attempt two. This is one local comparison result, not acceptance. Source exposure: mixed; pinned-image observations and CRASHLOGGER_PDB(59818@2026.10.24) naming hints; no sibling body adapted. Drafted 2026-11-25 with the assigned gpt-6.1-sol workflow.
