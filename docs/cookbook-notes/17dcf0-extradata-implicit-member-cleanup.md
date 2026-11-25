# 0x17dcf0 ExtraTextDisplayData scalar deleting destructor

<!-- tags: abi/virtual, construct/destructor, method/binding, method/diagnostic, wall/inlining -->

- Function: 0x17dcf0 ExtraTextDisplayData scalar deleting destructor
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 66/66
- Attempts: 1

## What differed

The wrapper destroys a member at 0x10 first and only then stores the BSExtraData vftable. The
derived class's own vftable is never stored.

## Spellings tried that did not help

none

## Spelling that fixed it

Leave the owner's destructor implicit, so it stores nothing and only destroys its members. Give
BSExtraData an inline empty root destructor, which supplies the trailing vftable store, and give the
member type an out-of-line destructor. This matched ExtraTextDisplayData, ExtraAttachRefChildren
and ExtraCellWaterEnvMap. A template member (`BSSimpleList<T>`) with a declared destructor binds by
position like a plain one.

```cpp
class BSExtraData { public: BSExtraData(); virtual ~BSExtraData() {} BSExtraData* next; };
class ExtraTextDisplayData : public BSExtraData {
public:
    ExtraTextDisplayData();
    BSFixedString displayName;
    char unk18[0x20];
};
```
