# 0x4f5230 Object4f5230::Object4f5230

<!-- tags: method/diagnostic -->

- Function: 0x4f5230 Object4f5230::Object4f5230
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 81/81 (aligned_matching_bytes)
- Attempts: 4

## What differed

After calling the base constructor and storing the vtable pointer, the candidate scheduled the bitwise OR on the inherited flag word (`flagsBA |= 0x50`) before zero-initializing the six derived fields, while the target zero-initialized all six derived fields first and ran the bitwise OR at the end after copying `this` into the return register.

## Spellings tried that did not help

- Zeroing the six derived fields in the member initializer list and setting `flagsBA |= 0x50` in the constructor body kept the OR hoisted ahead of the zero stores.
- Moving all six zero stores into the constructor body before `flagsBA |= 0x50` still hoisted the OR ahead of the zero stores.
- Splitting the flag update into `flagsBA |= 0x10; flagsBA |= 0x40;` produced the exact same hoisted OR instruction.

## Spelling that fixed it

Grouping the six derived fields into a member subobject with its own default constructor kept the subobject zero-initialization ahead of the body's flag update:

```cpp
struct SubData4f5230 {
    SubData4f5230()
        : unk00(0), unk08(nullptr), unk10(0), unk14(0), unk18(nullptr), unk20(0) {}
    // ...
};

Object4f5230::Object4f5230() : Base4f5230(), subData()
{
    flagsBA |= 0x50u;
}
```
