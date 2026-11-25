# 0x798b40 MovementControllerNPC::Function798b40

<!-- tags: abi/calling-convention, abi/virtual -->

- Function: 0x798b40 MovementControllerNPC::Function798b40
- Label: GUESS(low)
- Outcome: fixed
- Cause: calling-convention
- Best score: 91/91 matching bytes; local comparator PASS
- Attempts: 4

## What differed
The initial boolean-returning dispatcher introduced an extra result initialization on its final exit. Its candidate size was 93 bytes against a 91-byte target, although alignment reported 91 matching bytes. The queried interface is the motion-control subobject at the observed community-declared position.

## Spellings tried that did not help
Retaining the last boolean query in a named local and returning that local left the candidate size unchanged. A fourth compare was required after the final provenance and license notice edits changed the source digest.

## Spelling that fixed it
Declare the dispatcher and action slots as returning void; only the three query slots return bool. This treats the calls as actions and permits the no-action exit to return without producing a value. The third compare passed, and the fourth confirmed the final source. No sibling body was read or adapted.
