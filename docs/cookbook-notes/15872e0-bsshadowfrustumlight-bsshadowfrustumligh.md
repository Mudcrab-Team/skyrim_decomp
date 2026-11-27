# 0x15872e0 BSShadowFrustumLight::BSShadowFrustumLight

<!-- tags: construct/constructor, construct/float, wall/register-schedule -->

- Function: 0x15872e0 BSShadowFrustumLight::BSShadowFrustumLight
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: register-allocation
- Best score: 824/824
- Attempts: 3

## What differed

The four-argument frustum light constructor matched except the temporary that carries the stack-passed far plane: the target uses the first scratch float register where the candidate used the second. Size was equal, and the clamp already used one local per step as in the sibling constructor that matched.

## Spellings tried that did not help

A named local for the far plane before its store changed nothing. Reordering the member stores changes the byte order and was not tried.

## Spelling that fixed it

Pass the last clamp result straight into the tangent call instead of naming it: `unk560 = tanf(capped > low ? capped : low);`. The first two clamp steps keep their own locals. Dropping the named local probably released the first scratch register at that point and the far plane load took it. A permuter run (one, 13 s) found it as a temporary inline; the source form above is the plain spelling of that result.
