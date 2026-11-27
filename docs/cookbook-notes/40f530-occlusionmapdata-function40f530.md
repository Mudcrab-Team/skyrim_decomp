# 0x40f530 OcclusionMapData::Function40f530

<!-- tags: wall/inlining, wall/register-schedule, construct/destructor -->

- Function: 0x40f530 OcclusionMapData::Function40f530
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: inlining
- Best score: 425/435 (aligned_matching_bytes)
- Attempts: 10

## What differed

Using a named local with `_InterlockedDecrement` in `DecRefCount` (Cookbook rule 29) and reading `T* old = _ptr;` inside `if (_ptr != a_object)` before incrementing the new object closes both the prologue home-slot alignment and the smart-pointer assignment order. However, for the by-value smart-pointer argument to `PositionOcclusionCamera`, the target binary stores the camera pointer to the parameter stack slot twice (once before the atomic increment and once after it). An earlier draft reached the full size only by writing a repeated store in `NiPointer`'s copy constructor (`_ptr(a_rhs._ptr)` followed by `_ptr = Acquire(a_rhs._ptr)`), which violates source rules; every single-store copy constructor stops at 434/435 bytes (425/435 aligned bytes, omitting the second store and shifting the later loop-head alignment padding).

## Spellings tried that did not help

- Single-store copy constructor `NiPointer(const NiPointer& a_rhs) : _ptr(a_rhs._ptr) { if (_ptr) _ptr->IncRefCount(); }` (434 B, 425/435 aligned; emits only the store before the atomic increment).
- Single-store copy constructor assigning `_ptr = a_rhs._ptr` in the body instead of the initializer list (434 B, 425/435 aligned; identical output).
- Single-store copy constructor copying into a local `T* object = a_rhs._ptr; if (object) object->IncRefCount(); _ptr = object;` (434 B, 421/435 aligned; emits only the store after the atomic increment and drops the prologue frame pointer).
- Incrementing `a_rhs._ptr` before assigning `_ptr = a_rhs._ptr` without a local pointer (450 B, 419/435 aligned; reloads `a_rhs._ptr` after the atomic increment).
- Initializing `_ptr(nullptr)` and delegating to `*this = a_rhs` (442 B, 347/435 aligned; zeros the slot first and allocates an extra callee-saved register).

## Spelling that fixed it

none
