# 0x2397c0 InventoryChanges::GetWornApparelCountWithKeyword

<!-- tags: abi/exception, abi/virtual, construct/constructor, construct/destructor, method/binding, wall/control-flow -->

- Function: 0x2397c0 InventoryChanges::GetWornApparelCountWithKeyword
- Label: SYMBOLS(tesv-2013-map)
- Outcome: fixed
- Cause: branch-layout
- Best score: comparator PASS, 78/78 bytes, unwind covered
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The early null return placed the fallback before the visitor branch, giving 69/78 matching bytes and an exception-reference mismatch. The nonnull visitor branch belongs first, followed by the zero return. The local visitor has an explicit empty derived virtual destructor, and its exception cleanup needs the decorated plain-destructor binding.

## Spellings tried that did not help

- An early null return before visitor construction gave the wrong branch layout and exception-state boundary.
- A human-readable destructor hint did not resolve the emitted decorated cleanup symbol; the explicit decorated hint did.

## Spelling that fixed it

Put visitor construction, visitation and the result return inside the nonnull branch, then return zero afterward. With the local table and plain destructor bound to pack references, the unchanged comparator passed. A final name-provenance correction was compared separately. The sibling-symbol method name remains a naming lead, not identity evidence.
