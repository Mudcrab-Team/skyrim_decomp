# 0x449430 BGSAIWorldLocationInteriorCell::LoadGame

<!-- tags: construct/serialization, wall/inlining, sibling/fo4 -->

- Function: 0x449430 BGSAIWorldLocationInteriorCell::LoadGame
- Label: GUESS
- Outcome: fixed
- Cause: calling-convention
- Best score: 114/114
- Attempts: 2

## What differed

The target reads a form id from the buffer, looks the form up, casts it to the cell type, stores it, and then
ends by jumping straight into the buffer's last read call. The first draft had the same instructions
but ended with a normal call, a reload of the saved registers and a return, one instruction longer than the
target. Likely cause (untested beyond the one fix below): the form id variable lived directly in the member function with
its address passed on, and the compiler then kept the final call as a call.

## Spellings tried that did not help

- Reading the form id into a plain unsigned local in the member function, looking it up and casting inline: ends in a call and a return.

## Spelling that fixed it

Put the form id read, the lookup and the cast in a small inline template on the buffer class, which writes its
result through a reference parameter, and call it from the member function with a pointer local:

```cpp
template <class T> void LoadFormID(T*& out)
{
    unsigned int formID = 0;
    LoadFormID(formID);
    out = dynamic_cast<T*>(TESForm::LookupByID(formID));
}
// member function
TESObjectCELL* loaded = nullptr;
a_buffer->LoadFormID(loaded);
cell = loaded;
a_buffer->LoadDataEndian(&point, 12, 4);
```

The inlined helper's id local then no longer blocks the final call from becoming a jump. The same sibling-body
shape (a typed form id reader followed by one more read) probably recurs in other LoadGame functions.
