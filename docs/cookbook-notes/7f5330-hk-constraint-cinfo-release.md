# 0x7f5330 hkHingeConstraintCinfo scalar deleting destructor

- Function: 0x7f5330 hkHingeConstraintCinfo scalar deleting destructor
- Label: EXE_RTTI
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 76/76
- Attempts: 1

## What differed

Every Havok constraint-info deleting destructor stores the hkConstraintCinfo vftable, calls one
member function with a null argument, and calls no base destructor. RTTI puts the
hkSerializableCinfo base at displacement 8, so that base has no vftable of its own.

## Spellings tried that did not help

none

## Spelling that fixed it

Make the base non-polymorphic with eight bytes of padding and no destructor. Give hkConstraintCinfo
the root virtual destructor with an inline body that passes null to a member setter. Derived owners
keep implicit destructors and pad to the delete size. The same spelling matched all 15.

```cpp
class hkSerializableCinfo { public: char unk00[8]; };
class hkConstraintCinfo : public hkSerializableCinfo {
public:
    virtual ~hkConstraintCinfo() { SetConstraintData(nullptr); }
    void SetConstraintData(hkpConstraintData* a_data);
};
```
