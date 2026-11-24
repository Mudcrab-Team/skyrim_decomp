# 0x237a20 TESObjectREFR::RemoveFavorite

- Function: 0x237a20 TESObjectREFR::RemoveFavorite
- Label: none
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: not re-run; this note adds corpus evidence for cookbook rule 13
- Attempts: 0 new

## What differed
Rule 13 records a prologue that stores the exception-state slot (minus two) and saves callee-saved
registers eagerly although the unwind info has no handler. This note records what the Fallout 3 and New
Vegas x64 builds say about that shape. Their listings cover 31,359 compiled functions that store the
slot, built with the same compiler and flags as the recipe. Every one of them also has a C++ exception
handler in its unwind data, and no function has a handler without the store. A shape with the store and
no handler therefore never comes out of ordinary source under this recipe.

## Spellings tried that did not help
- Toy functions with a destructor-bearing local around a call: a throwing callee gives the store and
  a handler; a callee declared `noexcept` or `throw()`, or an early return before the local, gives
  neither.
- The same toy under `/EHa`, `/EHs`, `/O1`, `/Os` and `/Gz`: `/EHa` keeps the handler with the store;
  none gives the store alone. A `/GL` build writes no listing to read.

## Spelling that fixed it
none. The evidence points away from a source spelling: the cause is more likely a build difference
(flags, or a link-time step that removes the handler after code generation) than something to write
differently. Spending more attempts on spellings for this shape has no support in the corpus.
