# 0x98b0d0 UI3DSceneManager::SetCameraPosition

<!-- tags: construct/float, wall/register-schedule, method/sibling -->

- Function: 0x98b0d0 UI3DSceneManager::SetCameraPosition
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: instruction-order
- Best score: 62/62
- Attempts: 1

## What differed

The nested form `if (camera) { ... }` stores the update-data time before the third translation
component. The target stores the third component first. The function sizes, calls and operations
agreed, so the only difference was the order of two stores.

## Spellings tried that did not help

Whole-point assignment (`translate = position`) made the function smaller. Reordering the constructor
arguments and assigning the update-data fields directly kept the store order. A bounded permutation
search did not move the stores, because its early-return rule only rewrites if/else pairs and never a
guarded block at the end of a function.

## Spelling that fixed it

Turn the guarded block into a guard clause. The block statements stay in the same order.

```cpp
NiCamera* object = camera;
if (!object)
    return;
object->local.translate.x = position.x;
object->local.translate.y = position.y;
object->local.translate.z = position.z;
NiUpdateData data{0.0f, 0};
object->NiAVObject::Update(data);
```
