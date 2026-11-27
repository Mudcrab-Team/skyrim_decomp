# 0x766a90 NiAVObject::SetBlendCollisionFieldRecursive

<!-- tags: wall/register-schedule, wall/inlining -->

- Function: 0x766a90 NiAVObject::SetBlendCollisionFieldRecursive
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: register-allocation
- Best score: 231/231 (aligned_matching_bytes)
- Attempts: 5

## What differed

With the collision cast written inline inside a standalone recursive function, the candidate reproduced the exact size and every instruction shape but swapped the two callee-saved registers assigned to the object pointer and the collision pointer, which also caused an unwind-info mismatch at entry. Writing the stop check inline inside a non-template function also made the stop branch unreachable in source.

## Spellings tried that did not help

- Writing the null check and `IsKindOf` cast directly inside `SetBlendCollisionFieldRecursive`.
- Moving only the RTTI cast into a free helper `CastToBlendCollisionObject(object->collisionObject)`.

## Spelling that fixed it

Expressing the function as an explicit instantiation of a generic `TraverseScenegraphObjects<Visitor>` traversal template taking a `SetBlendCollisionFieldVisitor&` functor (returning `BSVisitControl`) made the stop condition reachable in the template and gave the compiler the expected live-range priority and register assignment:

```cpp
BSVisitControl result = visitor(object);
NiNode* node = object->AsNode();
if (node) {
    const std::uint32_t count = node->childrenSize;
    for (std::uint32_t i = 0; i < count && result != BSVisitControl::kStop; ++i) {
        result = TraverseScenegraphObjects(node->GetAt(i), visitor);
    }
}
return result;
```
