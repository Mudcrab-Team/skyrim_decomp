# 0x346700 BSSimpleList<T>::~BSSimpleList

<!-- tags: abi/exception, construct/destructor, wall/inlining -->

- Function: 0x346700 BSSimpleList<SCRIPT_REFERENCED_OBJECT*>::~BSSimpleList
- Label: list template and RemoveAll: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 128/128 (earlier rounds: 75/128 and a size mismatch)
- Attempts: 5 counted; 0x346780, 0x346800 and 0x346880 passed the first time with other element types

## What differed
The prologue stores the exception-state slot and saves registers eagerly, yet the function has no
handler in its unwind data. Earlier sources either kept a handler or dropped the slot.

## Spellings tried that did not help
A plain loop that deletes each node with `delete`, with and without a guard local, `noexcept` and
`throw()` forms, and a try/catch around the loop.

## Spelling that fixed it
The destructor calls an inline `RemoveAll(0, 0)` whose body tests a callback parameter and calls it,
otherwise deleting the node. With the null callback the indirect call folds away only after the
exception state is committed, which leaves the slot and eager saves but no handler. Instantiate the
template destructor explicitly and bind it by its decorated name.

```cpp
void RemoveAll(void (*del)(Node*, void*), void* data) { while (next) { Node* n = next->next; next->next = 0; if (del) del(next, data); else delete next; next = n; } item = T(); }
~BSSimpleList() { RemoveAll(0, 0); }
```
