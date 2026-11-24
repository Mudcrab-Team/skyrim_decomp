# 0x27c210 TESObjectARMA::Load

<!-- tags: construct/allocation, construct/bitfield, construct/constructor, construct/destructor, construct/switch, method/diagnostic, wall/callee, wall/control-flow, wall/flag-fold, wall/inlining, wall/layout -->

- Function: 0x27c210 TESObjectARMA::Load
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: sim 85.6 (Opus; not a byte match)
- Attempts: 8

## What differed
Near-pilot function, Sonnet draft 73.2, Sol 74.1 and Opus 85.6 (not a byte match). The draft wrote the four-term
shift-and-mask the decompiler printed for a 32-bit byte swap; the target uses the hardware swap (a 15-instruction run per
site against one; +14.7 on the first fix). Swaps were `x = Swap(x)` on copies; the target swaps in place through a
reference. Every form-id subrecord had its own local; the target reuses one function-scope 32-bit local and stores it
into the pointer field as an integer. The four model-path subrecords were spelled out four times. The DATA case read straight
into the live structure; the target reads an older on-disk layout into a stack struct and converts it by value (the single
legacy priority fills both current priority slots). The editor-id read saved and restored the thread-local load context by
hand with a raw allocation; both are scoped objects in the target whose constructors and destructors are real callees. The
switch selector was unsigned; the target's range branches are signed.

## Spellings tried that did not help
- A field-by-field DATA conversion alone: -1.1 (closer layout, lower shape score).
- `= default` on the base functor destructor, `__forceinline` on the conversion and a one-member struct around the form id:
  no change. A forced inline on a small read helper before the byte swap was fixed grew the function to 1.16 and cost 3.5;
  the cause was the shift expansion, not the inlining.
- A standard library bit-cast header: not in the pinned toolset; use a byte copy.

## Spelling that fixed it
`_byteswap_ulong` (with a justification comment) from the first draft; in-place swaps through a reference
(`SwapInPlace(T&)`), one shared form-id local, one inline helper per model path, the legacy DATA struct converted by value, the
load-context guard and scratch buffer as scoped objects, and `BSTArray` clear and `push_back` as inline members with the heap
allocator functor built on the stack and passed to the grow routine (together +9.5 over the Sonnet byte swap). Then the editor-id
pointer cached in a local with the derived functor's destructor left implicit (+2.5) and the flag test written on a bit-field as
`~flags.nonPlayable & 1` (+0.4). Signed selector: +2.0 on the Sol version.

The snippet is a generic shape with invented names, not the unit's code.

```cpp
template <typename T> void SwapInPlace(T& value);   // store back through the reference, not x = Swap(x)
std::uint32_t formId = 0;                            // one function-scope local for every form-id subrecord
switch (static_cast<int>(type)) { /* signed range branches */ }
```
