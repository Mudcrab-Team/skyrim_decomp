# 0x149bc0 ConcreteFormFactory<EffectSetting, 18>::CreateImpl

<!-- tags: abi/exception, construct/allocation, family/form-factory -->

- Function: 0x149bc0 ConcreteFormFactory<EffectSetting, 18>::CreateImpl
- Label: EXE_RTTI
- Outcome: fixed
- Cause: other
- Best score: full local comparator pass, including the constructor-failure funclet
- Attempts: 4

## What differed

The primary function hash matched while the full comparator rejected the exception cleanup. The allocator declaration and the delete selected on constructor failure both mattered.

## Spellings tried that did not help

A class-specific unsized delete produced a shorter cleanup. Adding `noexcept` to the modeled allocator changed the exception state map.

## Spelling that fixed it

Use `return new T;` with the class allocator declared without an exception specification. Let lookup select the global sized delete. The compiler then emits the cleanup that frees the allocation if the product constructor throws.
