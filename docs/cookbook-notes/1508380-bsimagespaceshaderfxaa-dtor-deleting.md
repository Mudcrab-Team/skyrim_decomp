# 0x1508380 BSImagespaceShaderFXAA::dtor_deleting

<!-- tags: method/diagnostic -->

- Function: 0x1508380 BSImagespaceShaderFXAA::dtor_deleting
- Label: GUESS(low)
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 67/67
- Attempts: 5

## What differed

The target's deleting destructor destroys a member through an out-of-line call and then calls the base destructor out of line, with no store of the derived class vtable pointer. The candidate stores the derived vtable pointer first (10 bytes longer).

## Spellings tried that did not help

`__declspec(novtable)` on the class (the deleting destructor is no longer emitted). A `final` class.

## Spelling that fixed it

Do not declare the derived destructor at all. Write only the constructor (so the compiler emits the vtable and the deleting destructor) and let the destructor be implicit:

```cpp
class BSImagespaceShaderFXAA : public BSImagespaceShader {
public:
    BSImagespaceShaderFXAA();   // no ~BSImagespaceShaderFXAA() declaration
    ParamSet param;             // member with an out-of-line destructor
};
```

The implicit destructor stores no vtable pointer, so the deleting destructor calls the member destructor, then the out-of-line base destructor, then sized delete, as the target does. This closed 0x1508380, 0x1530820 and 0x15307b0. When the target does store its vtable pointer first (an array-release loop in the destructor body), declare and define the destructor instead (0x1550420, 0x153dc30, 0x1584bd0, 0x1584af0, 0x1586580; the array's inline `SetAt` with the element delete inside `if (element)`).
