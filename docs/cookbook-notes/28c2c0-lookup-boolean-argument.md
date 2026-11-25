# 0x28c2c0 TESObjectWEAP::GetFireNode

<!-- tags: abi/calling-convention, method/diagnostic -->

- Function: 0x28c2c0 TESObjectWEAP::GetFireNode
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: calling-convention
- Best score: PASS, 97/97 bytes; prior best 91/97 matching bytes
- Attempts: 4

## What differed
The first draft initialized the default name before the conditional selection, extending its lifetime and increasing the function size. Branch-local name selection reduced the candidate to 91 bytes against the 97-byte target. The remaining difference came from the lookup helper's third boolean argument.

## Spellings tried that did not help
Initializing the name to the default before the conditional produced a 106-byte candidate with 55 matching bytes. Branch-local selection alone reached 89 matching bytes. Declaring the third argument but passing false reached 91 matching bytes and still failed.

## Spelling that fixed it
Choose the custom or default name inside the branches, declare the lookup helper's boolean mode, and pass true to both lookup calls. The fourth PC comparison passed. The general lesson is to inspect small boolean argument setup as well as full-width argument values before treating a small size gap as register allocation.
