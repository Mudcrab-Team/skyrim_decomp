# 0x17dfb0 NonActorMagicTarget::~NonActorMagicTarget

<!-- tags: abi/virtual, construct/constructor, construct/destructor, method/diagnostic, method/sibling, wall/register-schedule -->

- Function: 0x17dfb0 NonActorMagicTarget::~NonActorMagicTarget
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 75/75
- Attempts: 3

## What differed

The defaulted derived destructor installed two derived virtual tables before member cleanup. The target destroys the list and secondary base, then installs the primary base’s virtual table. The extra stores also changed the saved registers.

## Spellings tried that did not help

An out-of-line defaulted derived destructor with the constructor defined in the same unit.

## Spelling that fixed it

Use the sibling’s declaration order. Define the constructor first to emit the virtual tables and deleting destructor, then redeclare the class with `novtable` before the empty destructor. The compiler kept the constructor’s table references and emitted the observed base cleanup in the deleting wrapper.

```cpp
NonActorMagicTarget::NonActorMagicTarget() = default;

class __declspec(novtable) NonActorMagicTarget;

NonActorMagicTarget::~NonActorMagicTarget()
{
}
```
