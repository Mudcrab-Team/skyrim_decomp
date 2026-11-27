# 0xcd7a60 BSXAudio2Audio::ReleaseGameSound

<!-- tags: abi/exception, method/binding, construct/destructor -->

- Function: 0xcd7a60 BSXAudio2Audio::ReleaseGameSound
- Label: CRASHLOGGER_PDB(59818@2026.10.24); COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); GUESS(low)
- Outcome: fixed
- Cause: other
- Best score: comparator PASS; 91/91 code bytes, unwind, EH data and funclets covered
- Attempts: 4 counted comparisons; 8 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The original allocation-context scope guard from cookbook rule 21 already reached zero instruction distance. The compiler also emitted an out-of-line destructor reference for exception cleanup. That reference required a binding to the cleanup routine present in the assigned pack. The helper names remain guesses; the method name is community declaration evidence; this is local evidence for sse-steam-1-7-104, not acceptance.

## Spellings tried that did not help

The anonymous helper produced a different decorated destructor name in separate attempt directories, so exact-name hints from preceding attempts did not bind it. Moving the helper to ordinary namespace scope stabilized that name. A qualified-name hint remained unresolved in this environment. Two other permitted cleanup references failed relocation comparison; neither failure was discarded.

## Spelling that fixed it

Keep the original saved-value scope guard and its ordinary namespace-scope helper. Bind its stable decorated destructor name to the pack's corresponding cleanup reference, accounting for the function-relative positions of funclet references. The seventh comparison passed, and the eighth passed after final community provenance and licence-notice corrections. No copied body or compiler-setting change was used.
