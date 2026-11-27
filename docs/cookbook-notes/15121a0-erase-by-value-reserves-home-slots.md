# 0x15121a0 ShadowSceneNode::UpdateLightList

<!-- tags: wall/register-schedule, construct/loop -->

- Function: 0x15121a0 ShadowSceneNode::UpdateLightList
- Label: GUESS(low)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 301/301 aligned matching bytes
- Attempts: 13 comparisons

## What differed
The earlier round left two gaps: the light position copy went through an integer register for one component, and the
prologue used a different set of incoming home slots for the callee-saved registers.

## Spellings tried that did not help
- Three float locals for the position: one component still moved through an integer register.
- A by-value `operator!=` on the array iterator: it fixed the home slots here but moved them by one in 0x150f930, which
  shares the header.

## Spelling that fixed it
- The position as a constructed temporary, `light->position = NiPoint3(c.x, c.y, c.z);`, with a three-float constructor on
  the point and the member-wise `operator=`. This gives three float loads followed by three float stores.
- The removal as `it = a_lights->erase(it);`, where `erase` takes and returns the iterator by value and returns the null
  iterator when the array is empty. The by-value iterator argument is what reserves the home slots the target skips.
- Keep `operator!=` by const reference, so 0x150f930 still matches.
