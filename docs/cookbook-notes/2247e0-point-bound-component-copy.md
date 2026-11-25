# 0x2247e0 NiCamera::PointInFrustum

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0x2247e0 NiCamera::PointInFrustum
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: instruction-order
- Best score: 69/69 aligned matching bytes
- Attempts: 4

## What differed

The null-camera branch and the bound test agreed on the first attempt. Constructing the bound by copying its center as one object let the compiler combine adjacent coordinates, producing a 54-byte function for a 69-byte target.

## Spellings tried that did not help

Aggregate-initializing the bound directly from the point and the radius kept the wider coordinate copy.

## Spelling that fixed it

Initialize the center from the three individual coordinates and pass the resulting bound by reference. The pinned compiler emits scalar coordinate loads and stores for this expression.
