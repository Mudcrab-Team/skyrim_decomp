# 0x381250 ConsoleFunc

- Function: 0x381250 ConsoleFunc
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: sim 92.1 (Sol; not a byte match)
- Attempts: 16

## What differed
Near-pilot function (the console stats command), Sonnet draft 74.5, Sol 92.1 and Opus 91.5 (not a byte match). The looked-up
reference was a raw pointer with a hand-written release at the end of the loop; the target has an unwind frame (state stores, a
frame built from a copy of the stack pointer, vector-register saves that are not shrink-wrapped), which means a local with a
destructor: a reference-counted holder. Console output went through a free print function on a global where the target loads
the singleton as part of the call expression. The handle table was walked with raw index arithmetic where the target inlines an
iterator that skips empty slots in `begin` and in `++`. Variadic print calls left the argument evaluation order implicit.

## Spellings tried that did not help
- A found-flag begin-skip loop against a branchy one, twice: MSVC normalises both; the unwind-state count in diagnostics was the
  stronger signal and was read late.
- Hoisting the smart pointer out of the loop: -0.7 and a different size.
- Replacing the whole substring search by a pointer-end template: 64.3 from 75.7. Keep the outer loop and bind each inner scan to
  its candidate pointer with explicit case folding (+2.8).
- A lookup that takes the smart pointer changes the mangled name: rebind it in the same edit.

## Spelling that fixed it
A `NiPointer`-style holder with a destructor for the looked-up reference (+11.3 Opus, +12.6 Sol as a scoped owner); an
iterator class for the handle table with the increment before the lookup (about +2); `ConsoleLog::GetSingleton()->Print(...)`
with the handle declared inside the actors block (+3.2, exact size 3065 of 3065); sequencing the player's area, coordinates and
name, and the order of the remaining print arguments (+0.3, +1.0); parsing the trophy number before calling the handler (+0.15).
Sonnet's own +10.6 was the substring scan as an index loop with the inner compare as a guarded do-while. The target's unwind table
has one more state than the candidate (3 against 2), so one more destructible object is not yet identified.

The snippet is a generic shape with invented names, not the unit's code.

```cpp
NiPointer<TESObjectREFR> ref;            // a holder, not a raw pointer released by hand
ConsoleLog::GetSingleton()->Print(fmt, a, b);   // the singleton is loaded inside the call expression
```
