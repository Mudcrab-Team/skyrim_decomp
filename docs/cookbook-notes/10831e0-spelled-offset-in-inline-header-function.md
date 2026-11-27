# 0x10831e0 Func0090ad80_Class::Func0090ad80

<!-- tags: method/sibling, sibling/f3, wall/layout -->

- Function: 0x10831e0 f3m_0090ad80::task0983::Func0090ad80_Class::Func0090ad80
- Label: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
- Outcome: fixed
- Cause: struct-layout
- Best score: one displacement hunk left before the fix (54 of 61 bytes aligned), pass after
- Attempts: 2

## What differed
One member read uses the sibling's offset where the target reads another. The sibling spells the access as pointer arithmetic
(`reinterpret_cast<char*>(this) + 0x24c`), so there is no member to move; the number itself must change. The statement sits in an
inline function of the unit's class text, not in the compiled function's body.

## Spellings tried that did not help
- Patching only the unit's body text: the offset lives in the header's inline accessor, so the body patch found nothing and the
  unit compiled with the sibling's number.

## Spelling that fixed it
Replace the spelled offset on the fact's source line wherever that line occurs, in the body or in the header, and refuse the unit when
the line is found nowhere (a silent no-op leaves a one-hunk near miss that looks like a compiler problem).
