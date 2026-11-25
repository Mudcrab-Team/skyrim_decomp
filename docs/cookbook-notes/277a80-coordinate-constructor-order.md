# 0x277a80 TESBoundObject::Function277a80

<!-- tags: construct/float, wall/register-schedule, wall/layout -->

- Function: 0x277a80 TESBoundObject::Function277a80
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: instruction-order
- Best score: 69/69 bytes; local comparator PASS
- Attempts: 3

## What differed

Separate signed-short coordinate-difference locals produced the correct extent and operations but loaded the first and third coordinates in the opposite order. Both initial arithmetic spellings measured alignment distance 2.0 and 53/69 matching bytes. Community bound-data layout corroborated routing the new unit to TESBoundObject; the method retains its neutral RVA name.

## Spellings tried that did not help

Reversing the order of the three squared terms left the same four displacement differences. The existing fast-floating-point recipe was selected from the observed inline square root and cookbook rule 48.

## Spelling that fixed it

Construct an ordinary three-coordinate signed-short value from the coordinate differences, then compute its length and multiply by the locally observed scale. The coordinate constructor's argument evaluation produced the observed load order. The unchanged comparator passed on attempt 3. This is a local candidate only.
