# 0x145690 ConcreteFormFactory<AlchemyItem, 46> scalar deleting destructor

<!-- tags: abi/exception, abi/virtual, construct/destructor, construct/switch, family/form-factory, method/diagnostic -->

- Function: 0x145690 ConcreteFormFactory<AlchemyItem, 46> scalar deleting destructor
- Label: EXE_RTTI
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 86/86 bytes, including checked relocation targets
- Attempts: 2

## What differed

The first family-wide development build produced a 76-byte deleting destructor. The target switches to the factory interface vtable after it unregisters the form and before it conditionally releases the object. The shorter candidate omitted that transition.

## Spellings tried that did not help

Defaulting the virtual destructor in the interface declaration omitted the final vtable store with the pinned compiler.

## Spelling that fixed it

Give the interface destructor an explicit empty body and keep form unregistration in the concrete factory destructor. Let MSVC generate the deleting wrapper for each factory instantiation. The ordinary comparator also checks the unwind action against the runtime termination import.

```cpp
virtual ~IFormFactory() {}
```
