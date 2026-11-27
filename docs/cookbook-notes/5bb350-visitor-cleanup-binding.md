# 0x5bb350 ActiveEffect::CheckDisplacementSpellOnTarget

<!-- tags: abi/exception, construct/constructor, construct/destructor, method/binding, wall/callee -->

- Function: 0x5bb350 ActiveEffect::CheckDisplacementSpellOnTarget
- Label: SYMBOLS(tesv-2013-map)
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 88/88 code bytes; comparator PASS, unwind covered
- Attempts: 1 counted comparison on the first draft after the pack was exported again

## What differed

The first compiled visitor used an implicit derived destructor and scored 23/88 matching bytes, with a shorter body and a missing exception-state slot. An explicit empty derived virtual destructor produced 88/88 aligned code bytes, but the comparator could not resolve the destructor named by the exception cleanup. The cleanup funclet has no unwind entry of its own and ends in a jump to the out-of-line destructor, and the old pack only listed targets of the function body, so no reference or hint could name it.

## Spellings tried that did not help

- The implicit derived destructor omitted the required exception-state setup.
- A hint for the destructor address worked locally, but a hint the pack does not list is not allowed, so it could not be published.

## Spelling that fixed it

No source change. Exporting the pack again lists the jump target of the cleanup funclet, the comparator binds the explicit empty derived destructor by that reference, and the unchanged draft passes with no hint file. Lesson: when code aligns fully and only an exception-cleanup symbol is unresolved, export the pack again with the current exporter before suspecting the source.
