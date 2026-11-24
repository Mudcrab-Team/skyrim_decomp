# 0x4b51a0 BSTempEffectSPG::LoadGame

<!-- tags: construct/serialization, wall/inlining, sibling/fo4 -->

- Function: 0x4b51a0 BSTempEffectSPG::LoadGame
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: inlining
- Best score: 160/160
- Attempts: 2

## What differed

Everything matched except the end: the target jumps to the last read call, the candidate calls it and
returns (160 bytes against 161). The function passes the address of a stack local (a form identifier)
to an earlier call, which the cookbook's rule 46 lists as a reason a tail call turns into a call.

## Spellings tried that did not help

- A plain local identifier read through an out-of-line member, then the lookup and the cast written
  inline in the function: the last call stayed a call and a return.

## Spelling that fixed it

Put the identifier local inside an inline member template of the buffer class that reads the identifier,
looks the form up and casts it to the wanted type, and call that with the destination member. The
address-taken temporary then belongs to an inlined helper and the final call became a jump.

```cpp
template <class T>
void LoadFormID(T*& a_out)
{
    std::uint32_t formID = 0;
    ReadFormID(formID);
    a_out = dynamic_cast<T*>(TESForm::LookupByID(formID));
}
// caller: apLoadGameBuffer->LoadFormID(this->pSPGData);
```
