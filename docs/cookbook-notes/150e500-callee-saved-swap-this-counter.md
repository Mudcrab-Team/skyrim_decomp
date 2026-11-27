# 0x150e500 ShadowSceneNode::AttachSceneObjectsToLight

<!-- tags: wall/register-schedule, construct/loop, method/diagnostic -->

- Function: 0x150e500 ShadowSceneNode::AttachSceneObjectsToLight (also 0x150fe80)
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 203/203 bytes, registers differ (permuter distance 1.0)
- Attempts: 7

## What differed
`this` is kept in rdi and the shared zero counter in rbx; the target has them the other way round. In 0x150fe80 the target
keeps `this` in r10 and the light argument in rdx, while the draft moves the light to r10 and uses rdx for the loaded entry.
Calls, branches and sizes are equal.

## Spellings tried that did not help
- One shared loop counter, two counters, counter declared first, an end local for the bound.
- Permuter runs of about 480 candidates each (best distance unchanged).

## Spelling that fixed it
none. The drafts are parked privately.
