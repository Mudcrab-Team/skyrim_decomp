# 0xf164b0 NiSpotLight::ctor

<!-- tags: construct/constructor, construct/float, wall/register-schedule, wall/inlining -->

- Function: 0xf164b0 NiSpotLight::ctor
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: instruction-order
- Best score: local comparator PASS; full 69-byte extent covered
- Attempts: 4 counted compares; one bounded single-worker permutation search

## What differed

The initial aggregate assignment of the direction created a temporary and compiled to 92 bytes rather than 69, measuring 37/69 aligned matching bytes. Direct component assignments reached 58/69 with the correct size and one reordered instruction pair. Both callees and data references were bound throughout.

## Spellings tried that did not help

Direct assignments and a real base-class constructor with aggregate member initialization both retained distance 0.5. A 73-candidate single-worker permutation search exhausted its pool at the same distance.

## Spelling that fixed it

Give the three-component direction subobject an ordinary inline three-argument constructor, then initialize it from the spotlight constructor's initializer list. Keep the real base constructor and the remaining scalar initializers. Compare 4 passed with cookbook rule 31 recorded. This extends that rule's subobject-constructor scheduling observation to a direction vector initialized with one and two zero components; no extra source stores or padding fields are needed.
