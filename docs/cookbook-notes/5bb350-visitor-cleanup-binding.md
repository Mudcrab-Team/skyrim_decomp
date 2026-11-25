# 0x5bb350 ActiveEffect::CheckDisplacementSpellOnTarget

<!-- tags: abi/exception, construct/constructor, construct/destructor, method/binding, wall/callee -->

- Function: 0x5bb350 ActiveEffect::CheckDisplacementSpellOnTarget
- Label: SYMBOLS(tesv-2013-map)
- Outcome: unsolved
- Cause: vtable-or-virtual
- Best score: 88/88 aligned code bytes; comparator FAIL, unresolved-symbol in exception cleanup
- Attempts: 1 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The first compiled visitor used an implicit derived destructor and scored 23/88 matching bytes, with a shorter body and a missing exception-state slot. An explicit empty derived virtual destructor produced 88/88 aligned code bytes, but the comparator could not resolve the destructor referenced by its exception cleanup. The assigned pack contains no reference binding for that destructor. Code alignment does not establish the exception metadata match or a comparator pass.

## Spellings tried that did not help

- The implicit derived destructor omitted the required exception-state setup.
- Explicitly defining the empty derived destructor closed the code alignment but left the cleanup binding unresolved.
- The initial offset assertions needed messages under the pinned language mode; that invocation did not compare.

## Spelling that fixed it

None. The best source is retained privately, withheld from passing-source paths. The lead needs an authorized complete cleanup reference before further comparison. Cookbook rule 13 helped classify the initial exception-state difference; no passing rule hit is claimed.
