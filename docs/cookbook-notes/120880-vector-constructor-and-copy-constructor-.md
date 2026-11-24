# 0x120880 vector constructor and copy constructor iterator helpers

<!-- tags: construct/vector, wall/inlining, sibling/fo4 -->

- Function: 0x120880 vector constructor iterator; 0x812bd0 vector copy constructor iterator
- Label: GUESS
- Outcome: fixed
- Cause: inlining
- Best score: 100%
- Attempts: 1

## What differed

These two targets are compiler-generated helper functions, not source functions: a loop that calls a constructor (or copy constructor) through a function pointer once per array element. They cannot be written directly.

## Spellings tried that did not help

None needed; a user-written copy constructor that initialises the array member did not compile (array initialisation needs a brace list).

## Spelling that fixed it

Make the compiler emit the helper by constructing a class with an array member whose element type has an out-of-line constructor, then bind the target address to the helper's decorated name with a `// CI hash:` line (the `attempt` output lists the name under "defined in object"):

```cpp
struct ArrayElement { ArrayElement(); char data[24]; };
struct ArrayHolder { ArrayHolder(); ArrayElement elements[8]; };
ArrayHolder::ArrayHolder() {}
```

For the copy variant give the element an out-of-line copy constructor, leave the holder's copy constructor implicit and copy it by value from a free function:

```cpp
ArrayHolder CopyHolder(const ArrayHolder& other) { return other; }
```
