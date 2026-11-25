# 0x3f2590 TESTopicInfo::CreateGroupData

<!-- tags: wall/register-schedule, construct/serialization -->

- Function: 0x3f2590 TESTopicInfo::CreateGroupData
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: register-allocation
- Best score: comparator PASS, 73-byte function; initial aligned matching bytes 50/73, distance 3
- Attempts: 2

## What differed

The group-record builder used the same observed references and record fields, with no aligned behavioral-value mismatch. The first candidate retained the parent topic in a different scratch register and scheduled a signature load differently. This changed the compiled extent.

## Spellings tried that did not help

The combined parent-pointer test and repeated member expression left distance 3. A one-worker PC permutation search scored 81 candidates and retained distance 3; its unchanged best source was not applied.

## Spelling that fixed it

Inside the validated parent-group branch, read `parentTopic` into a named local, return if that local is null, and use the same local for its form ID. This gives the parent pointer an explicit lifetime through construction of the output record. The second ordinary comparison passed. This is one measured compiler spelling, not proof of the original source or semantic equivalence beyond the comparator's claim.
