# 0xee24d0 NiNode::UpdateDownwardPass

<!-- tags: construct/float, method/diagnostic, method/sibling, sibling/f3, sibling/fnv, wall/inlining, wall/register-schedule -->

- Function: 0xee24d0 NiNode::UpdateDownwardPass
- Label: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
- Outcome: fixed
- Cause: instruction-order
- Best score: 411/419 aligned bytes before the fix, 419/419 after
- Attempts: 5 counted

## What differed
The first child's bound is copied into the node's own bound (three centre floats, then the radius).
In the target the radius is loaded early and stored last, after the third centre float. Every
inline spelling put the radius store one slot earlier, before the third centre float. Cookbook rule 19
records this as not closed.

## Spellings tried that did not help
- Three component assignments and a radius assignment written inline in the function.
- A local caching the radius before the stores.
- A whole-struct copy of the centre, which compiles to one 8-byte move plus a 4-byte move.
- A member setter that assigns the three components by hand, called with accessor results.

## Spelling that fixed it
Take the shape from the Fallout 3 and New Vegas decompilations: a `NiBound::SetCenterAndRadius(const
NiPoint3& center, float radius)` member that does `center = a_center; radius = a_radius;`, where
`NiPoint3::operator=` is the component-wise copy (x, y, z one by one, returning `*this`). The call is
`worldBound.SetCenterAndRadius(child->worldBound.center, child->worldBound.radius)`. The point
type's own `operator=` is what changed the scheduling; copying the three components by hand in the
setter body did not.

```cpp
NiPoint3& operator=(const NiPoint3& o) { x = o.x; y = o.y; z = o.z; return *this; }
void SetCenterAndRadius(const NiPoint3& c, float r) { center = c; radius = r; }
```
