# 0xcd6fb0 BSXAudio2Audio::ReleaseGameSound

<!-- tags: construct/destructor, wall/register-schedule, method/diagnostic -->

- Function: 0xcd6fb0 BSXAudio2Audio::ReleaseGameSound
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: register-allocation
- Best score: comparator PASS; 80/80 bytes covered, including 8 reference bytes; unwind covered
- Attempts: 3 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The explicit save, set, delete, restore body had the right instruction shape but exchanged two
callee-saved register roles. Its alignment distance was 1.0, with 51/80 matching bytes.
This is local evidence for sse-steam-1-7-104 only; it does not establish acceptance.

## Spellings tried that did not help
The plain saved integer and explicit restore remained unchanged through two comparisons.
A bounded PC permuter search from that body exhausted its pool after 16 candidates and
10 unique objects, keeping distance 1.0. Provenance comments did not change the compiled result.

## Spelling that fixed it
Represent the allocation category lifetime with a local inline scope guard, following cookbook
rule 21. Its constructor saves the thread-local category and sets the temporary category; its
destructor restores the saved category. Keep the virtual delete inside that scope. The third
comparison passed with the final provenance comments present. The body is original reconstruction;
name evidence is the community-generated CrashLogger source labelled above, not identity evidence.
