# 0x18f3e0 ExtraInteraction::~ExtraInteraction

<!-- tags: construct/destructor, abi/virtual, wall/inlining -->

- Function: 0x18f3e0 ExtraInteraction::~ExtraInteraction
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: PC comparator pass, 92/92 bytes; initial alignment distance 2
- Attempts: 2 counted comparisons; 2 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The first draft put intrusive reference release directly in the derived destructor body. The candidate was 102 bytes against the target's 92, with two extra instructions and alignment distance 2. It retained a derived vtable assignment before releasing the pointee.

## Spellings tried that did not help
A direct destructor body with a local pointer, atomic reference decrement, and virtual deletion produced the extra derived vtable assignment. Its source and failed report remain in the private task's first attempt.

## Spelling that fixed it
Keep the release in an inline smart pointer member destructor and default the containing destructor. This represents the community-declared smart pointer ownership. The PC comparator then passed code, references and unwind checks. This is a local candidate pass; second-host comparison and independent review remain required.
