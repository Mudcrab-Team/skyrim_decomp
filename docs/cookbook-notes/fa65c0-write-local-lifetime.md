# 0xfa65c0 NiPSysAgeDeathModifier::SaveBinary

<!-- tags: abi/virtual, construct/serialization, method/diagnostic, wall/inlining -->

- Function: 0xfa65c0 NiPSysAgeDeathModifier::SaveBinary
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 107/111 aligned matching bytes before the fix; 111/111 on the local comparator pass
- Attempts: 3 counted; second passed, third confirmed the final provenance labels

## What differed

The original target-derived draft called the base serializer, wrote the spawn flag through the binary stream, then saved the linked spawn modifier. Its final virtual call remained an ordinary call where the target ends with a tail call. The address-taken flag and component-size locals belonged to the serializer's scope.

## Spellings tried that did not help

Keeping both write locals directly in the serializer reached 107/111 and retained the call/return difference. The observed fields and reference binding already agreed; no alternate sibling implementation was inspected.

## Spelling that fixed it

Move the one-value write into an ordinary inline binary-stream helper, then call that helper before saving the link. The helper owns the address-taken locals and updates the stream position. This spelling emitted the target tail call and passed locally. The helper is adapted from CommonLibSSE-NG at b93280e, MIT, and labelled in the unit header; the serializer body is reconstructed from target observations. The narrower local lifetime is a source-level explanation of the successful spelling, not proof of the original source.
