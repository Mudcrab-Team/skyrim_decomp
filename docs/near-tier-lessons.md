# Near-tier lessons

What a drafter learns on large functions (400 to 6,600 bytes) that are already close, from the near-tier
pilot: 30 functions drafted by Sonnet, the weak ones retried by Sol (Codex) and Opus, 15 written
reflections, every score move recorded. Read it with [the matching cookbook](matching-cookbook.md): the
cookbook's rules were each earned by a comparator pass; these lessons come from a similarity score and no
function in the pilot reached a byte match, so none of them is a rule yet. A lesson that closes a function
later moves into the cookbook with its `Evidence:` line (fold step, [drafter toolkit](drafter-toolkit.md),
"Reflections and lessons"). Per-function recipes ("for 0xX do Y") are lesson notes in
[cookbook-notes/](cookbook-notes/README.md), not lessons.

## How to read a lesson

The score is `sim_shape` from `score.py`: twice the number of aligned, same-shape instruction pairs over
the target's and the candidate's instruction counts, in percent. Registers cost nothing; a different
displacement, constant or operand width does. It is a search signal, never evidence of a match
(`docs/verification.md`). A move is the sim after minus the sim before, in points; **a retry's move is
against the Sonnet draft it started from**. Many moves are a bundle of edits made in one round, and the
lesson says so.

Each lesson has the cookbook's shape, plus bookkeeping the lint reads (`python3 tools/near_lessons.py`):

- **Confidence.** *repeated*: a measured gain on two or more functions; *single*: one function;
  *reported*: stated by a drafter, not measured. The cookbook's high, medium and low need a closed function.
- **Status.** *mapped*: a cookbook rule covers it, and `Rules:` says whether the evidence agrees, extends,
  qualifies or contradicts that rule. *candidate*: no rule covers it. *contradicted*: the evidence
  contradicts a rule as the cookbook states it. *contested*: the pilot has gains and losses from the same
  idea. *open*: a residue nobody closed; the lesson says what was tried.
- **Found by.** Which of Sonnet, Sol and Opus reported or measured it.
- **Evidence.** `0x<rva> <move> (<model>)`: the function and the points it moved (`flat` for no move,
  `callees` for callee agreement, `behaviour` for a defect the score does not see).

## What the pilot measured

Best sim per function; "-" means the model did not retry it. Retries stopped on three flat rounds or about
30 minutes. Sol's mean move over Sonnet was +10.7 points on 23 functions (21 up, 1 down, best +47.9),
Opus's +16.9 on 18 (all up, best +46.6). In the first batch Sonnet stopped at 2 to 9 minutes per function.

| RVA | Bytes | Sonnet | Sol | Opus | RVA | Bytes | Sonnet | Sol | Opus |
| --- | ---: | ---: | ---: | ---: | --- | ---: | ---: | ---: | ---: |
| 0x14a630 | 1716 | 94.7 | - | - | 0x5def30 | 1930 | 62.2 | 75.8 | - |
| 0x1e37d0 | 6367 | 75.7 | 77.0 | 77.2 | 0x6b0650 | 2824 | 80.3 | 81.4 | - |
| 0x232ac0 | 1282 | 93.1 | - | - | 0x6cd850 | 4838 | 55.0 | 57.4 | 64.2 |
| 0x27c210 | 2142 | 73.2 | 74.1 | 85.6 | 0x7e6850 | 5021 | 38.5 | 53.0 | 59.1 |
| 0x29b960 | 483 | 93.3 | - | - | 0x7fd020 | 2562 | 56.4 | 65.6 | 73.1 |
| 0x31b8b0 | 506 | 88.1 | - | - | 0x87a740 | 5960 | 98.0 | - | - |
| 0x3409a0 | 406 | 99.1 | - | - | 0x97a2e0 | 6634 | 76.7 | 76.0 | 87.9 |
| 0x381250 | 3065 | 74.5 | 92.1 | 91.5 | 0xbb8930 | 4451 | 40.9 | 53.1 | 69.1 |
| 0x480750 | 1569 | 70.1 | 83.7 | 86.8 | 0xbbf5c0 | 2063 | 36.5 | 84.4 | 83.1 |
| 0x4ab410 | 5863 | 46.9 | 67.5 | 72.3 | 0xcd9b60 | 1457 | 83.6 | 93.4 | 93.9 |
| 0x4b10e0 | 3543 | 65.9 | 77.7 | 98.5 | 0xcdf660 | 1511 | 73.3 | 76.7 | 85.9 |
| 0x54e9c0 | 1851 | 67.3 | 71.7 | 75.6 | 0xf012f0 | 444 | 77.4 | 86.6 | - |
| 0x5ca670 | 511 | 68.2 | 88.7 | - | 0x1004350 | 1681 | 53.2 | 59.2 | 63.3 |
| 0x5caca0 | 4249 | 46.9 | 66.2 | 66.5 | 0x1007b70 | 2562 | 92.8 | - | - |
| 0x123a7f0 | 3274 | 74.3 | 74.2 | 79.7 | 0x1240a20 | 960 | 57.7 | 64.6 | - |

The behaviour-mismatch count of each of these versions is in the next section.

## Behaviour mismatches of the pilot versions

The sim above cannot see a defect that changes one constant: Sonnet's best draft of 0xcdf660 adds 0x10 to a
block start in the tree realignment where the target adds 0x20, and it still scored 73.3. `score.py` and
`tools/verifier/align.py` now count the **behaviour mismatches** of a candidate: aligned instruction pairs
with the same mnemonic and operand shape but a different member displacement, immediate, call target or
global reference (stack-frame values and stack adjustments do not count, and a reference that does not
resolve on one side is listed apart), and the multiset of displacements and immediates (other than 0, 1 and
-1) that one side holds more often than the other, which also covers regions the alignment did not pair.
The score line prints the counts; the offsets of the pairs and the differing values go to
`<attempt>/<rva>/behaviour.json` in the private attempt directory and never to a log.

Pairs of the 63 retained versions that could be rescored (the attempt that compiled each version was found by
its source; one Sol version had no matching attempt):

| RVA | Sonnet | Sol | Opus | RVA | Sonnet | Sol | Opus |
| --- | ---: | ---: | ---: | --- | ---: | ---: | ---: |
| 0x1e37d0 | 0 | 0 | 0 | 0x7e6850 | 11 | 12 | 12 |
| 0x27c210 | 5 | 5 | 3 | 0x7fd020 | 1 | 10 | 4 |
| 0x381250 | 13 | 10 | 12 | 0x97a2e0 | 12 | 8 | 8 |
| 0x480750 | 1 | 0 | 0 | 0xbb8930 | 17 | 17 | 14 |
| 0x4ab410 | 21 | - | 8 | 0xbbf5c0 | 11 | 5 | 6 |
| 0x4b10e0 | 10 | 8 | 1 | 0xcd9b60 | 1 | 0 | 2 |
| 0x54e9c0 | 14 | 13 | 11 | 0xcdf660 | 4 | 1 | 1 |
| 0x5ca670 | 0 | 0 | - | 0xf012f0 | 1 | 0 | - |
| 0x5caca0 | 10 | 3 | 4 | 0x1004350 | 3 | 7 | 16 |
| 0x5def30 | 14 | 5 | - | 0x123a7f0 | 11 | 11 | 7 |
| 0x6b0650 | 1 | 1 | - | 0x1240a20 | 1 | 4 | - |
| 0x6cd850 | 21 | 26 | 19 |  |  |  |  |

Nine of the 63 have none. 0xcdf660's Sonnet version is flagged with four pairs (three displacements and one
immediate), one of them the start offset (a displacement of 0x1f in the target, 0xf in the draft); the Opus version,
which changed that constant, no longer has it and keeps one other pair. The median is one pair per hundred target instructions (at most 4.7),
and the count falls with sim (correlation -0.53), so most of it is the draft's distance from the target. Read it as a list of places to
check: the alignment can pair unrelated instructions, and a displacement of 0 against 0x40 on one pair is
usually such a pair. A clean count is not a proof of a behaviour match.

## Working method

<a id="lesson-1"></a>
<!-- tags: wall/constant -->
**L1. Run the stop rule literally; a round that gained is not a reason to stop.** (repeated)
Status: candidate. Found by: Sonnet, Opus, Sol. Rules: none.
Symptom: a draft sits at 70 to 75 percent after two to nine minutes, the last round gained, and the note
says "stopped by judgment". Sonnet stopped early on all six functions of the first batch and on more
in every later batch, once right after a gain of ten points and once after one flat round with ten rounds left. Fix: stop on the
brief's rule only (three rounds each under half a point, or the round and time cap); write which condition
fired; read the clock the tool prints, not the sense of effort. Retries that kept going moved the same
drafts by 11 to 33 points.
Evidence: 0x381250 +17.1 (Opus); 0xcdf660 +12.6 (Opus); 0x4b10e0 +32.7 (Opus); 0x97a2e0 +11.2 (Opus); 0x5ca670 +20.5 (Sol).

<a id="lesson-2"></a>
<!-- tags: abi/virtual, construct/vector, method/binding, method/diagnostic, wall/callee, wall/constant -->
**L2. Bind every callee, data symbol, thread-local and literal in one pass, before judging structure.** (repeated)
Status: candidate. Found by: Sonnet, Sol, Opus. Rules: none.
Symptom: the first score is meaningless: unbound callees count as missing and extra calls and hide the real
first mismatch. Fix: run `attempt` once, write every `UNBOUND` name into `bind-hints.json` together, include
vtables, imports (`__imp_` names), vector constants, thread-locals (`tls:`) and string-pool helpers, then
read the score. Binding moves sim by 0 to 1 point and callee agreement from near zero to full: do not count
it as a sim gain, and expect it to cost no more than one round. Do not put a hinted tag type in an anonymous
namespace: its decorated name changes with every edit. Also [toolkit step 5](drafter-toolkit.md).
Evidence: 0x1e37d0 callees (Sonnet); 0x4ab410 +1.1 (Sonnet); 0x6cd850 +0.4 (Sonnet); 0x381250 flat (Sonnet); 0x87a740 +10.0 (Sonnet).

<a id="lesson-3"></a>
<!-- tags: abi/exception, method/binding, method/diagnostic, wall/callee, wall/constant -->
**L3. A binding the tool accepts without an `UNBOUND` line can still point at the wrong symbol.** (repeated)
Status: candidate. Found by: Sonnet, Sol. Rules: none.
Symptom: a callee stays missing with no diagnostic, or a numeric global compares as a different value.
Cause: an invented member name equal to an existing symbol name binds silently to that symbol's address
(four minutes on 0x381250), the automatic binder picks a plausible existing entry for a helper, a literal
or a numeric constant (0x97a2e0, 0x7e6850, 0x6b0650, 0xbbf5c0 had three constants bound to the wrong
places), and the diagnostic can come from an unwind funclet the main-body score does not count. Fix: grep
the symbol map for every name you invent; after binding, compare each reference's kind, width and value
with the pack's reference table; an exact-name hint overrides the automatic one.
Evidence: 0x97a2e0 callees (Sol); 0x381250 callees (Sonnet); 0x7e6850 callees (Sol); 0xbbf5c0 callees (Sol); 0x6b0650 callees (Sol).

<a id="lesson-4"></a>
<!-- tags: abi/calling-convention, construct/float, method/diagnostic, wall/callee, wall/register-schedule -->
**L4. Full callee agreement does not check receivers, argument counts, argument widths or returned storage.** (repeated)
Status: mapped. Found by: Sol, Opus, Sonnet. Rules: 5 agrees, 33 agrees, 70 agrees.
Symptom: the callee set is equal and sim is flat or low. Cause: the decompiler drops trailing register
arguments and variadic ones, a hidden return slot, an embedded-subobject adjustment of the receiver and
the width of each pointee. Fix: for every call read the receiver, each argument register and stack slot,
and what the result is consumed as; a callee that receives no receiver is static; a call whose result sits
in a caller-provided slot has that slot's address at both sites. The signature in the task's symbol map can
itself be wrong (0xbbf5c0 returns a float and takes a fifth argument).
Evidence: 0x480750 +11.2 (Sol); 0x4ab410 +4.4 (Sol); 0x6b0650 +1.1 (Sol); 0x6cd850 +0.8 (Sonnet); 0xcd9b60 +0.3 (Opus); 0xbbf5c0 +46.5 (Opus).

<a id="lesson-5"></a>
<!-- tags: abi/calling-convention, construct/float, construct/switch, wall/callee, wall/register-schedule -->
**L5. A value left in an argument register can be a spill, not an argument: confirm liveness before adding a parameter.** (single)
Status: mapped. Found by: Sol. Rules: 5 qualifies.
Symptom: after a call the listing shows four extra floats in registers and a rewrite adds four parameters.
Cause: stale scratch values and spills read back look like arguments in recovered pseudocode. Fix: check the
callee's slot against the pinned declaration and trace each register to its write; here the slot takes one
request argument and the extra values were spills. Rule 5 is right when the register is live into the call;
the pilot found a case where it is not.
Evidence: 0x1240a20 flat (Sol).

<a id="lesson-6"></a>
<!-- tags: abi/virtual, method/diagnostic, wall/layout -->
**L6. Rewrite a structurally wrong draft instead of patching it.** (repeated)
Status: candidate. Found by: Opus, Sol, Sonnet. Rules: none.
Symptom: padding members, a wrong element stride, "slot ladders" of fake virtual calls, scalar arithmetic
where the target is packed, or a size ratio under 0.85 or over 1.3 after the first score; tuning gains under
a point per round. Fix: from round three, rewrite from the listing on the real layouts (community headers,
engine types) and score the whole rewrite; the first scored round of a rewrite moved the drafts by 20 to 47
points, more than all later tuning together.
Evidence: 0x7e6850 +20.5 (Opus); 0x4ab410 +25.5 (Opus); 0xbbf5c0 +46.6 (Opus); 0xbbf5c0 +47.9 (Sol); 0x5caca0 +19.6 (Opus).

<a id="lesson-7"></a>
<!-- tags: abi/calling-convention, construct/destructor, construct/loop, method/diagnostic, wall/control-flow -->
**L7. Read the size ratio after the first score and fix what it points to first.** (repeated)
Status: candidate. Found by: Sonnet. Rules: none.
Symptom and fix: above about 1.10 the candidate holds an unrolled or duplicated loop or early returns that
duplicate a release (0x31b8b0 at 1.19, 0x5ca670 at 1.17); below about 0.90 an out-of-line helper, merged
branches or a skipped block of argument stores (0x87a740 at 0.73, 0x7e6850 at 0.57, where the whole
spawn-argument block was left out and never added). A long run of plain field stores is the cheapest sim
there is; do not skip it as boilerplate.
Evidence: 0x31b8b0 +10.2 (Sonnet); 0x87a740 +5.4 (Sonnet); 0x5ca670 +2.8 (Sonnet); 0x7e6850 flat (Sonnet).

<a id="lesson-8"></a>
<!-- tags: abi/calling-convention, construct/allocation, construct/bitfield, construct/constructor, construct/destructor, wall/constant, wall/control-flow, wall/flag-fold -->
**L8. Never add state, parameters, flags or bodies the listing does not show.** (repeated)
Status: candidate. Found by: Opus, Sonnet, Sol. Rules: none.
Symptom: a drafted "found" flag, a single `result` variable with one return, an extra constructor parameter
added to nudge an argument move, a field default in a destructor, a placeholder body for an unresolved
allocator operation. Fix: model control flow with early returns, `continue`, `if (!found)` chains and scope
objects; declare an unresolved operation as an external method so a gap stays visible. Dropping the invented
flag, the flat best-fit and the realign constant were one round on 0xcdf660 (+8.5); the invented parameter
cost 1.4 points on 0x3409a0.
Evidence: 0xcdf660 +8.5 (Opus); 0x3409a0 -1.4 (Sonnet); 0x7fd020 flat (Opus); 0x123a7f0 flat (Sol).

<a id="lesson-9"></a>
<!-- tags: construct/allocation, construct/constructor, construct/loop, method/diagnostic, wall/callee, wall/constant -->
**L9. A scored draft is not a reviewed draft: read your own constants, initialisers and header before the last round.** (repeated)
Status: candidate. Found by: Opus, Sonnet, Sol. Rules: none.
Symptom: sim moves by a fraction of a point for a real behaviour bug. Seen: a tree realignment that adds 0x10
where the target adds 0x20 (0xcdf660, found by a careful re-read, not by the score); a member initialiser that
reads members before the constructor sets them (0x1e37d0); a point left uninitialised on a path (0x7fd020);
an unguarded store through a pointer the helper can return null for (0xcdf660); an allocation failure that
falls into the read loop (0x29b960). Fix: re-read every constant against the listing once, and use the
`behaviour_mismatches` count (aligned pairs of the same shape with a different displacement, immediate,
call target or global) and the value multiset `score.py` prints; both are leads, the aligned pairing can
pair unrelated instructions.
Evidence: 0xcdf660 behaviour (Opus); 0x1e37d0 behaviour (Sol); 0x7fd020 behaviour (Sonnet); 0x29b960 behaviour (Sonnet).

<a id="lesson-10"></a>
<!-- tags: method/binding, method/diagnostic, wall/callee -->
**L10. Sim is not faithfulness: keep the faithful version, report both numbers, and do not count callee gains as sim gains.** (repeated)
Status: candidate. Found by: Opus, Sol. Rules: none.
Symptom: a change that makes the frame size or the lifetimes exact lowers sim by a point; another leaves sim
flat while the weighted distance falls from 433 to 370; a binding round raises callee agreement from 0.11
to 1.00 with sim unchanged. Fix: keep the version that is faithful and fully bound, record the higher raw
score next to it, restore the faithful one when the stop rule fires (`score.py --restore` now prefers full
callee agreement and no behaviour mismatches), and do not let a flat-sim round with a falling distance count
as a gain for the stop rule. A fresh reviewer's spot-check of eight best versions found the three that scored 59
to 65 faithful and no unit whose score overstated it: sim understates faithfulness more often than it overstates.
Evidence: 0x5caca0 flat (Opus); 0x7e6850 -1.0 (Opus); 0x6cd850 -0.4 (Sol).

<a id="lesson-11"></a>
<!-- tags: wall/layout -->
**L11. One change per round, or independent structural changes together: the pilot is split.** (single)
Status: contested. Found by: Sonnet, Opus, Sol. Rules: none.
Symptom: a +10 round with three edits in it and no attribution (0x97a2e0, Sonnet); a retry whose first round
combined a decal layout, a sound request and a scope and could not be told apart (0x6cd850, Sol, minus 0.4).
Against that, Opus took +19.6 on 0x5caca0 in one round of independent structural fixes because the gaps were
independent. Fix: until settled, one edit per round when the draft is already above 80 percent or the edit
is a guess; several together only when each has its own evidence in the listing; save a copy of the best
source before each experiment either way.
Evidence: 0x97a2e0 +10.1 (Sonnet); 0x5caca0 +19.6 (Opus); 0x6cd850 -0.4 (Sol).

<a id="lesson-12"></a>
<!-- tags: construct/loop -->
**L12. Read the cookbook, the lesson notes and the function's failure record before the first draft.** (single)
Status: candidate. Found by: Sonnet. Rules: none.
Symptom: rounds spent on a loop-shape rewrite that a note or an earlier failure had already ruled out: 0xf012f0
had 31 earlier failures and a blind do-while rewrite cost 1.4 points. Fix: `grep -n '0x<rva>'` the cookbook
and notes ([toolkit step 2](drafter-toolkit.md)); do one loop-shape experiment at most and revert on a loss.
Evidence: 0xf012f0 -1.4 (Sonnet).

## Compiler recipe and floating point

<a id="lesson-13"></a>
<!-- tags: construct/float, construct/switch, method/binding, wall/callee, wall/control-flow, wall/inlining -->
**L13. Choose the recipe on the first look: a library square-root or floor call in the first compile is the sign.** (repeated)
Status: mapped. Found by: Sonnet, Opus, Sol. Rules: 48 agrees.
Symptom: the first compile shows a `sqrtf` or `floor` call (or a double round-trip) the target does inline,
and one callee is missing. Fix: switch the unit to `o2-fpfast` and write the `Recipe:` line in the unit
header the same minute (`near_start.py` does not write it for an existing unit); the switch removed the
call and restored callee agreement on every function that showed it (the moves above are bundles with
binding or helper changes). Rule 48's symptoms (parity branch,
`fabsf` through double) are not the only ones: an inline square root or floor in the target is the third. A unit
that needs fast code and lacks the `Recipe:` line scores as if the default applied: that line was the only cause
of the missing callees of the Opus version of 0x7e6850, found by a fresh reviewer's spot-check after the drafter had
called it a compiler-mode artefact that no source could close.
Evidence: 0x123a7f0 +17.7 (Sonnet); 0xcd9b60 +5.2 (Sonnet); 0x6cd850 +1.1 (Sonnet); 0x54e9c0 +1.5 (Opus); 0x7e6850 callees (Opus).

<a id="lesson-14"></a>
<!-- tags: construct/float, construct/switch, wall/control-flow, wall/inlining -->
**L14. A recipe is not all-or-nothing: the target mixes precise divides with inline square roots and absolute values.** (repeated)
Status: contradicted. Found by: Opus, Sol, Sonnet. Rules: 48 contradicts.
Symptom: under `o2-fpfast` the target's single-precision divides become reciprocal multiplies (0x7fd020), or
the recipe switch gains 0.3 points and hides the real spelling (0x4b10e0). Rule 48 tells a drafter to switch
the unit before spending attempts on source shapes; here the better result stayed on the default recipe: an
intrinsic square-root helper gives the inline square root, a branch-select float absolute value or `fabsf`
gives the mask, and the divides stay divides. Fix: probe divide, square root and absolute value separately on
a ten-line toy with each recipe, keep the recipe whose shape matches all three, and say so when none does.
The rule holds when every symptom points the same way (L13).
Evidence: 0x4b10e0 +1.1 (Opus); 0x7fd020 +6.6 (Opus); 0x4b10e0 +4.5 (Sol).

<a id="lesson-15"></a>
<!-- tags: construct/float, wall/control-flow -->
**L15. `std::fabs` on a float resolves to the double overload; write `fabsf` or a branch-select absolute value.** (repeated)
Status: mapped. Found by: Opus, Sonnet. Rules: 48 agrees.
Symptom: conversions to double and back and a 64-bit mask around an absolute value, under either recipe.
Fix: `fabsf` and `acosf`/`sqrtf` by name in float code, or a small `NiAbs` that selects by sign and compiles
to a mask under the default recipe. Rule 48 names the symptom for the fast recipe; this is the same fix
without it.
Evidence: 0x4b10e0 +0.8 (Sonnet); 0xbbf5c0 +0.1 (Opus); 0x4b10e0 +1.1 (Opus).

<a id="lesson-16"></a>
<!-- tags: wall/constant, wall/layout -->
**L16. Aligned moves through `__m128` pointers are not reproduced: the target folds loads into memory operands, MSVC 19.16 emits unaligned moves.** (repeated)
Status: open. Found by: Opus, Sonnet. Rules: 51 qualifies.
Symptom: structs read with unaligned loads cannot fold into packed arithmetic; the same candidate with
`__m128` members and 16-byte aligned constants folds (+1.2). Even so, loads and stores through pointers to aligned
types stayed unaligned in 0xbbf5c0 and 0x54e9c0 with `alignas(16)` types and the aligned-load intrinsic.
Fix: use `__m128` members and 16-byte aligned constant types (rule 51); beyond that nothing in source moved
it, so stop after two flat rounds and report it as a recipe or type-layout question, not drafter time.
Evidence: 0x54e9c0 +1.2 (Sonnet); 0xbbf5c0 -2.3 (Opus).
Still failing: 0xbbf5c0, 0x54e9c0.

## Packed arithmetic

<a id="lesson-17"></a>
<!-- tags: construct/vector, method/diagnostic -->
**L17. Havok, quaternion and vector code is packed even when the decompiler prints scalars: look at the instruction mix before writing the maths.** (repeated)
Status: mapped. Found by: Sonnet, Sol, Opus. Rules: 51 extends.
Symptom: size ratio 1.35 to 1.65 or 0.87 with scalar helpers, a transposed matrix or a quaternion store
written lane by lane, and sim between 36 and 55. Fix: before the first draft count packed and scalar
operations in the target by region; if packed dominates, build a four-lane vector type with one-line
helpers (dot with the lane-0 accumulation, shuffle broadcast, cross with the two shuffle selectors, inverse
length from a reciprocal square root plus one Newton step with a zero mask, sign-mask conjugate) and write
the function on it. The packed rewrite was the largest single gain in all three Havok functions of the last
batch and in the animation update.
Evidence: 0xbbf5c0 +46.5 (Opus); 0xbbf5c0 +42.0 (Sol); 0xbb8930 +23.2 (Opus); 0xbb8930 +8.0 (Sol); 0x54e9c0 +16.9 (Sonnet).

<a id="lesson-18"></a>
<!-- tags: construct/vector -->
**L18. Classify the width by region: scalar arithmetic with packed storage stays scalar.** (repeated)
Status: candidate. Found by: Sol. Rules: none.
Symptom: after L17 a function with scalar arithmetic and packed moves gets worse when the arithmetic is
packed, or aggregated into helpers (0x5def30 fell 4.2 points with equal scalar counts on both sides). Fix: count scalar and packed operations in
each region of the target before choosing; use native vector storage for the stores and keep scalar
expressions where the target computes scalars.
Evidence: 0x1240a20 +4.5 (Sol); 0x5def30 -4.2 (Sol); 0x4ab410 +7.8 (Sol).

<a id="lesson-19"></a>
<!-- tags: construct/float, construct/vector -->
**L19. Keep the target's floating-point grouping and lane convention: the accumulation order of a dot product moves several points.** (single)
Status: candidate. Found by: Sol, Opus. Rules: none.
Symptom: packed code of the right shape scores 80 and stops. Cause: the target adds the second and first
products first and the third last; a quaternion's real lane, the sign of the steering cross product and the
conjugate's flipped lane were wrong in the draft. Fix: write the sums in the target's grouping, take the
real-lane convention from a call site, and keep a zero-length behaviour that matches.
Evidence: 0xbbf5c0 +4.3 (Sol); 0xbbf5c0 +1.8 (Sol).

<a id="lesson-20"></a>
<!-- tags: construct/constructor, construct/vector, wall/inlining, wall/register-schedule -->
**L20. A 36-byte matrix stored as two vector stores and a dword is a by-value helper result assigned to the member.** (single)
Status: mapped. Found by: Opus, Sol. Rules: 50 extends, 51 extends.
Symptom: shuffles around stores of 16, 16 and 4 bytes look like hand-written SIMD, and scalar code writing
straight into the destination is 8 percent smaller than the target with a larger frame. Fix: write value-
returning inline helpers in the community library's form (`result.rotate = rotate.Transpose();`,
`bone->local.rotate = eased.ToRotation();`, and `(rotate * -translate) * scale` for the inverse); reading the
live position once into a local keeps it in a register across the call. Hand-written copy constructors for the
point, transform and matrix types lost 0.5 to 9.8 points.
Evidence: 0x1004350 +7.8 (Opus); 0x1004350 +4.7 (Sol); 0x1004350 -9.8 (Opus).

<a id="lesson-21"></a>
<!-- tags: construct/loop, construct/vector -->
**L21. A small matrix product: copy the target's order, which differs between functions.** (repeated)
Status: contested. Found by: Opus. Rules: none.
Symptom: a hand-hoisted 3x3 product against a member `operator*` written as a column loop (target reads the
right-hand matrix one column at a time: three loads, three dot products), or the reverse: MSVC keeps a nested
loop where the target holds all nine products as scalars. Fix: read the target's load pattern first; where it
loads one column at a time write the column loop (+15.7 on 0x4b10e0); where it keeps nine scalars write the
nine statements in the library's column-major order (+1.0 on 0x4ab410).
Evidence: 0x4b10e0 +15.7 (Opus); 0x4ab410 +1.0 (Opus).

<a id="lesson-22"></a>
<!-- tags: construct/destructor, method/binding, wall/constant -->
**L22. Define `NDEBUG` before an assert-bearing header such as DirectXMath: the shipped image is a release build.** (single)
Status: candidate. Found by: Opus. Rules: none.
Symptom: assertion helper calls and file-path string literals among the unbound references of a unit that
includes DirectXMath; the recipe does not define it. Fix: `#define NDEBUG` before the include.
Evidence: 0x4ab410 +3.0 (Opus).

## Structure and control flow

<a id="lesson-23"></a>
<!-- tags: abi/calling-convention, construct/allocation, construct/destructor, wall/inlining -->
**L23. A helper the target expands in place must expand in place; shared scratch buffers are passed in.** (repeated)
Status: candidate. Found by: Sonnet, Opus, Sol. Rules: none.
Symptom: size ratio under 0.9, calls to small helpers the target does not make (argument push, reference
holder, array append, value copy and destructor, scope guard, allocation and list push), and a frame larger
than the target's because every inlined copy has its own text buffer. Fix: write the helper inline (or an
inline function in the header, or `__forceinline` with the [drafter card's](drafter-card.md) justification);
pass the shared scratch buffers in. The same helper called from many sites with different arguments can
instead grow the function (size ratio 1.65 on 0xbbf5c0): check the ratio after each forcing and undo what
grows it. A comparator reads a call to an out-of-line helper as a missing region.
Evidence: 0x232ac0 +16.8 (Sonnet); 0x97a2e0 +19.0 (Sonnet); 0xbb8930 +7.0 (Sonnet); 0x87a740 +5.4 (Sonnet); 0xbbf5c0 -1.4 (Sonnet).

<a id="lesson-24"></a>
<!-- tags: abi/calling-convention, construct/switch, wall/callee, wall/inlining -->
**L24. A helper the target keeps out of line at only some call sites was not reproduced by any spelling.** (single)
Status: open. Found by: Sonnet, Sol, Opus. Rules: 27 qualifies.
Symptom: the target copies a value out of line at two of about 25 sites and inline at the rest; with the
copy forced inline the callee is missing, without it every site is out of line (55 percent). Tried:
modelling the two paths separately with the out-of-line callee declared and bound (Sol, minus 0.7),
removing the force (Opus). Not tried: a different argument type at those two sites. It looks like an inliner budget decision, not a
source shape. Rule 27 is about `noinline`; this is the inverse case.
Evidence: 0x97a2e0 -0.7 (Sol); 0x97a2e0 flat (Opus).
Still failing: 0x97a2e0.

<a id="lesson-25"></a>
<!-- tags: construct/switch, method/diagnostic, wall/callee, wall/inlining -->
**L25. Do not factor the cases of one huge flat function into helpers: MSVC will not inline helpers of that size.** (single)
Status: candidate. Found by: Opus. Rules: none.
Symptom: after splitting a form loader's per-type read sequences into `Load...` functions "for readability",
sim fell from 77 to 20 and callees went out of line. Fix: keep the bodies in the switch; braced scopes per
case cost nothing.
Evidence: 0x1e37d0 -57.0 (Opus).

<a id="lesson-26"></a>
<!-- tags: abi/exception, construct/allocation, wall/control-flow -->
**L26. Exit shape: early returns with a scope guard where the target has unwind state, one result local where it has not.** (repeated)
Status: mapped. Found by: Opus, Sol, Sonnet. Rules: 34 qualifies, 67 extends.
Symptom: the target has one shared exit block for every return, an unwind-state store and a saved value in a
stack slot, and the candidate saves and restores by hand through a `result` variable and one return (rule 34's
fix) or duplicates the epilogue. Fix: when the target shows unwind state, write a small RAII object (an
allocator-tag scope, a lock, a handle owner) and early returns; when it shows none, rule 34's single result
local is the fix (+4.1 on 0x3409a0, where a failing type test first and a single result variable together
gave +7.8).
Evidence: 0x4b10e0 +12.5 (Opus); 0x4b10e0 +7.3 (Sol); 0x3409a0 +4.1 (Sonnet); 0x3409a0 +3.7 (Sonnet).

<a id="lesson-27"></a>
<!-- tags: abi/exception, construct/constructor, construct/destructor, construct/loop, construct/vector, method/diagnostic, wall/register-schedule -->
**L27. Unwind-state stores and constructor or destructor calls at no-op rows mean a local with a destructor; compare `max_state`.** (repeated)
Status: mapped. Found by: Opus, Sol. Rules: 13 extends, 67 extends.
Symptom: an eager save of vector registers, an unwind-state store and a frame built from a copy of the stack
pointer, in a candidate that has none of them, with one raw pointer released by hand at the end of a loop. Fix: replace the raw pointer with a
reference-counted holder (a `NiPointer`-style class) and construct the stack objects in the order of the
target's constructor calls; read `FuncInfo.max_state` in `diagnostics.json` for how many destructible locals
are still missing (the target's was one higher on 0x381250). Rule 13 lists functions with the same prologue
that no spelling closed; here the holder closed most of the gap in sim.
Evidence: 0x381250 +11.3 (Opus); 0x381250 +12.6 (Sol); 0x5caca0 +19.6 (Opus); 0x27c210 +9.5 (Opus).
Still failing: 0x381250.

<a id="lesson-28"></a>
<!-- tags: abi/exception, abi/virtual, construct/destructor, construct/vector, wall/callee, wall/register-schedule -->
**L28. Mark engine and Havok callees `noexcept` and release through a virtual destructor, or MSVC builds a frame the target lacks.** (single)
Status: mapped. Found by: Opus. Rules: 67 extends.
Symptom: a cast handle released by a raw function-pointer virtual call gives a full unwind frame, a state
store and eager vector-register saves the target does not have. Fix: `noexcept` on every callee the target
treats as nonthrowing and `delete p` through a virtual destructor. This is rule 67 in reverse: the same
lever removes a state.
Evidence: 0xbb8930 +3.3 (Opus).

<a id="lesson-29"></a>
<!-- tags: abi/calling-convention, abi/exception, wall/callee, wall/inlining, wall/register-schedule -->
**L29. After a handle lookup the target keeps the pointer in a register with an unwind no-op; every spelling here reloads it from the stack.** (repeated)
Status: open. Found by: Opus. Rules: 13 qualifies.
Symptom: the same residue in two functions that look up a reference by handle and hold it in a smart pointer.
Tried: a by-value lookup wrapper (MSVC 19.16 would not inline it, even forced; one callee went missing), a
holder class, an out-parameter lookup. Not found: the holder or lookup shape.
Evidence: 0x7fd020 flat (Opus); 0x480750 flat (Opus).
Still failing: 0x7fd020, 0x480750.

<a id="lesson-30"></a>
<!-- tags: construct/bitfield, construct/destructor, wall/flag-fold, wall/inlining -->
**L30. Reject paths each set the weight and `continue`; the accept path is one shared tail.** (repeated)
Status: mapped. Found by: Opus. Rules: 2 extends.
Symptom: every reject ends in its own continue and the accept path too, or the candidate nests the checks and
merges the cleanup tails the target duplicates. Fix: a short guard per reject with its own inline release and
`continue`, and one shared accept tail; keep the `continue` where the target duplicates cleanup. Replacing
`continue` with nested ifs cost 3.4 points on 0x7e6850; a flat `if (!found)` chain over the small-list,
last-block and tree stages replaced an invented flag on 0xcdf660.
Evidence: 0x480750 +6.9 (Opus); 0xcdf660 +8.5 (Opus); 0x7e6850 -3.4 (Opus).

<a id="lesson-31"></a>
<!-- tags: construct/switch, wall/control-flow, wall/layout -->
**L31. Write each test in the target's order and polarity: the fall-through case is the `if` body, and one condition stays one condition.** (repeated)
Status: mapped. Found by: Sonnet, Opus. Rules: 2 agrees, 42 extends.
Symptom: branch layout and compare operand order differ with the same instructions: a ternary that falls
through on the other arm, `a > b` against `b < a` (they emit different compare operand orders), a
four-way space test where the target has one condition. Fix: read the target's conditional jump and put its
fall-through case first; try both polarities of each two-way test in one round; spell clip checks as
`disp.c + start.c > max.c` with no running end point (+4.1 on 0x7fd020).
Evidence: 0x3409a0 +3.7 (Sonnet); 0xcd9b60 +3.7 (Opus); 0x7fd020 +4.1 (Opus); 0x480750 +4.9 (Opus); 0x1007b70 +0.8 (Sonnet).

<a id="lesson-32"></a>
<!-- tags: construct/bitfield, construct/loop, wall/callee, wall/control-flow, wall/flag-fold, wall/layout -->
**L32. Loop form pays more than anything else once the callees agree: index or pointer, down-counter with a separate index, guarded do-while, found-flag iterator, post-test walk.** (repeated)
Status: mapped. Found by: Sonnet, Opus. Rules: 35 agrees, 44 agrees.
Symptom: size ratio 1.19 (an unrolled for-with-break), a count the target walks down while it indexes by
offset, a jump into the loop test, an unsigned compare against a bound that is re-read each pass. Fix: write
the loop in the shape the decompiler and listing show, one form at a time: a do-while with the exit test at
the top of the body and a pointer increment (+10.2), a separate 64-bit down-counter plus an index
(+13.8), an `if (0 < n) do { ... } while (j < n)` guard (+10.6), a post-test walk that sets the index to the
count instead of `break` (+4.6), a `for` whose bound is re-read each pass (+0.7).
Evidence: 0x31b8b0 +10.2 (Sonnet); 0x29b960 +13.8 (Sonnet); 0x381250 +10.6 (Sonnet); 0x480750 +4.6 (Opus); 0x5ca670 +0.7 (Sonnet).

<a id="lesson-33"></a>
<!-- tags: abi/exception, construct/bitfield, construct/loop, wall/control-flow, wall/flag-fold -->
**L33. Spellings MSVC canonicalises are not levers: declaration order, commutative operand order, independent store placement, found-flag against branchy loops, reorder-only experiments.** (repeated)
Status: mapped. Found by: Opus, Sonnet. Rules: 42 agrees.
Symptom: rounds with identical code or identical scores. Seen: swapping operands inside a cross product, moving
`done = true`, reordering declarations, a found-flag loop against a branchy one (the target's unwind-state
count was the stronger signal), an `if` chain against min and max. Fix: keep the more readable spelling after
one flat round; every round carries a structural hypothesis from the aligned listing. A blind change of the
loop index to `size_t` cost 3.7 on 0x31b8b0.
Evidence: 0x54e9c0 flat (Opus); 0xcd9b60 flat (Opus); 0x381250 flat (Opus); 0x5ca670 flat (Sonnet); 0x31b8b0 -3.7 (Sonnet).

<a id="lesson-34"></a>
<!-- tags: construct/switch, wall/control-flow -->
**L34. Record-tag dispatch is a switch; the selector's signedness matters; do not flatten a switch into a chain.** (repeated)
Status: mapped. Found by: Sonnet, Sol. Rules: 6 agrees.
Symptom: an if-chain over four-character tags, or over a value the target reduces by successive subtraction,
compiles to a comparison ladder; the target's range branches are signed where the draft's selector is
unsigned. Fix: a `switch` on the tag (+21.9 on 0x3409a0), the selector as a signed integer when the
target's branches are signed (+2.0 on 0x27c210), and the natural switch first: replacing a switch by a chain
because the decompiler printed one cost 17.9 points on 0x1e37d0.
Evidence: 0x3409a0 +21.9 (Sonnet); 0x27c210 +2.0 (Sol); 0x5caca0 +10.4 (Sol); 0x1e37d0 -17.9 (Sol).

<a id="lesson-35"></a>
<!-- tags: construct/loop, wall/constant -->
**L35. Hoist what the target hoists, re-read what it re-reads, and copy an aggregate into a local when the target loads it once.** (repeated)
Status: mapped. Found by: Sonnet, Opus. Rules: 4 agrees, 1 extends.
Symptom: a value computed once before a loop in the listing but inside it in the draft (a squared radius, a
pair count), or a position the target copies into a local object and reads from the copy while the draft
re-reads the live member after a call. Fix: a named local before the loop; a member-wise copy
(`PathingLocation start(startPoint);`) read afterwards. The reverse also holds: hoisting a holder out of a
loop the target re-creates each pass cost 0.7 points, hoisting a constant 0.5.
Evidence: 0x480750 +5.3 (Sonnet); 0x31b8b0 +3.0 (Sonnet); 0x123a7f0 +5.0 (Opus); 0x381250 -0.7 (Opus); 0xcdf660 -0.5 (Opus).

<a id="lesson-36"></a>
<!-- tags: abi/calling-convention, construct/constructor, construct/float, construct/vector, wall/layout -->
**L36. Small value types and temporaries: element-wise or block copy, a stack slot per temporary or one shared local; the pilot is split.** (repeated)
Status: contested. Found by: Sonnet, Opus, Sol. Rules: 50 qualifies.
Symptom: stack offsets differ across a whole function because temporaries share or do not share slots, and a
point or plane type copies as four dwords or one block. Gains: element-wise copies of the point and plane
types, a member-wise copy constructor, scalar floats in place of a point copy, one function-scope value
reused for every argument temporary. Losses: hand-written copy constructors on a transform and a matrix,
named normals and persistent basis vectors, a temporary-per-statement rewrite applied mechanically. Fix:
try the copy shape once, with the target's per-statement slot count in hand, and revert on a loss.
Evidence: 0x4b10e0 +6.0 (Sonnet); 0x123a7f0 +4.4 (Sonnet); 0x97a2e0 +9.1 (Opus); 0x1004350 -9.8 (Opus).

<a id="lesson-37"></a>
<!-- tags: construct/loop, wall/inlining -->
**L37. Singletons: a pointer variable loaded at each use, or a call to an inline `GetSingleton()` in the expression, not an object at a fixed address.** (repeated)
Status: candidate. Found by: Sonnet, Opus. Rules: none.
Symptom: the load of the singleton differs: the target loads a pointer variable every iteration, or loads it as
part of the call expression. Fix: declare it as a pointer variable (+3.7 on 0x5ca670) and call
`Singleton::GetSingleton()->Method(...)` inline (+3.2 on 0x381250); decide by whether the listing loads the
value from the symbol or takes its address.
Evidence: 0x5ca670 +3.7 (Sonnet); 0x381250 +3.2 (Opus).

<a id="lesson-38"></a>
<!-- tags: abi/virtual, construct/allocation, construct/destructor, method/binding, wall/callee -->
**L38. A concrete global object devirtualizes calls on it; reach an allocator through a base pointer to keep the target's vtable call.** (repeated)
Status: candidate. Found by: Sonnet, Opus, Sol. Rules: none.
Symptom: one callee missing: the target calls an allocator's release through the vtable, the candidate
calls the known-type global directly. Fix: call through a local pointer to the base class (or a
reference-returning accessor); for an allocator reached through a thread-local slot, bind the import slot
and the allocator storage separately.
Evidence: 0x7fd020 +1.5 (Opus); 0x7fd020 +0.3 (Sonnet); 0x7e6850 flat (Sol); 0xbb8930 +2.8 (Sol).

<a id="lesson-39"></a>
<!-- tags: abi/virtual, construct/bitfield, construct/destructor, wall/flag-fold, wall/layout -->
**L39. Shared counts are locked increments and decrements: use the interlocked intrinsics, not an atomic template, and release through the embedded handle.** (repeated)
Status: mapped. Found by: Sonnet, Opus, Sol. Rules: 29 agrees, 39 extends.
Symptom: an exchange-and-add where the target has a locked increment; a release that decrements through the
object containing the handle count where the target adds an offset and passes the embedded handle
sub-object to a helper; a separate "finished" flag that routes the result. Fix: `_InterlockedIncrement` and
`_InterlockedDecrement` with a justification comment; the count lives in a sub-object at a fixed offset with a
virtual delete; scoped ownership for the handle and one shared final selection instead of the flag (+19.7 on
0x5ca670 under Sol).
Evidence: 0x6b0650 +7.0 (Sonnet); 0x480750 +1.8 (Sonnet); 0x5ca670 +3.2 (Sonnet); 0x5ca670 +19.7 (Sol); 0x5def30 +7.9 (Sol).

<a id="lesson-40"></a>
<!-- tags: construct/allocation, construct/constructor, construct/destructor -->
**L40. One-expression construction with a class allocation function that returns null reproduces the target's null checks and the temporary's lifetime.** (single)
Status: candidate. Found by: Sonnet. Rules: none.
Symptom: a channel constructed in a block with a named temporary string; the target keeps the temporary alive
to the end of the full expression that adds the channel to the array, with null checks and a conditional
cleanup. Fix: construct, add and destroy in one expression, with a class-specific allocation function that
returns null on failure; a value-initialised `new T()` reproduces "zero five words, then the base
constructor" for stateless classes.
Evidence: 0x6b0650 +1.7 (Sonnet).

<a id="lesson-41"></a>
<!-- tags: construct/loop, wall/constant, wall/inlining -->
**L41. A run of N identical constant-index updates means the original was unrolled; a plain loop is not unrolled at this optimisation level.** (single)
Status: candidate. Found by: Sonnet. Rules: none.
Symptom: sixteen stage updates with an immediate each, a draft loop at size ratio 0.76. Fix: a compile-time
recursive helper with forced inlining and a comment saying it is a deliberate unroll; the drafter called it a
contortion, so say so in the note and label the helper a guess. One observation.
Evidence: 0x1007b70 +29.0 (Sonnet).

## Types, layout and data

<a id="lesson-42"></a>
<!-- tags: abi/virtual, construct/constructor, construct/destructor, method/diagnostic, wall/layout, wall/register-schedule -->
**L42. Check every offset, vptr position and member width against the listing before the first score: a wrong offset looks like register noise.** (repeated)
Status: mapped. Found by: Opus, Sonnet, Sol. Rules: 69 agrees, 68 agrees.
Symptom: a displacement loss across every access through one member (a skill pointer eight bytes high, a data
block 0xC0 high, a lock four bytes early), a dword gap miscounted by hand, a layout taken from another
build's debug data shifted by eight bytes. Fix: compare the first three used offsets against the listing;
confirm an embedded member by the addresses passed to its constructor and destructor; tell a wide field
from two adjacent ones by the store width; compute array lengths with a script and `static_assert` them; a
class with a vptr needs a virtual destructor in the stand-in or the whole layout moves.
Evidence: 0x97a2e0 +1.4 (Opus); 0x4b10e0 +2.0 (Sonnet); 0x4ab410 +0.5 (Sonnet); 0x123a7f0 flat (Sol); 0x7fd020 +1.0 (Opus).

<a id="lesson-43"></a>
<!-- tags: construct/loop -->
**L43. Counters, tables and indices take their width from the compare and store widths.** (repeated)
Status: mapped. Found by: Sonnet. Rules: 68 agrees.
Symptom: a table the draft gave 32-bit entries is 64-bit in the target (the compare and store widths show it);
a loop counter the target widens from 32 to 64 bits while the zero test stays 32-bit. Fix: read the widths
before declaring the struct; widen the counter, keep the zero test on the 32-bit value; no type change
without a listing reason (the reverse cost 3.7).
Evidence: 0x1007b70 +6.2 (Sonnet); 0x232ac0 +2.0 (Sonnet); 0x29b960 +0.4 (Sonnet); 0x31b8b0 -3.7 (Sonnet).

<a id="lesson-44"></a>
<!-- tags: abi/calling-convention, construct/constructor, wall/callee, wall/layout -->
**L44. Take engine and SDK types instead of hand-built stand-ins: their constructors explain long runs of stores and their out-of-line members are real callees.** (repeated)
Status: candidate. Found by: Opus, Sonnet, Sol. Rules: none.
Symptom: a hand-made argument struct whose field order, defaults and size are guesses (a decal-creation block
of 0xC8 bytes whose constructor defaults explain a long run of stores), an opaque pick-data blob the target
initialises field by field, XAudio2 and X3DAudio structures whose offsets match exactly. Fix: search the
community headers and the SDK for the type, include it, and label what you take. Also
[toolkit step 3](drafter-toolkit.md).
Evidence: 0x7e6850 +20.5 (Opus); 0x5caca0 +19.6 (Opus); 0x4ab410 +25.5 (Opus); 0xcd9b60 +2.3 (Sol).

<a id="lesson-45"></a>
<!-- tags: construct/switch, method/diagnostic -->
**L45. A four-term shift-and-mask is a byte swap: use the intrinsic, in place through a reference.** (repeated)
Status: candidate. Found by: Sonnet, Opus. Rules: none.
Symptom: a 15-instruction run at each swap site where the decompiler printed shifts and masks. Fix:
`_byteswap_ulong` (with a justification comment) from the first draft; swap in place through a reference so
the store-back shape matches. Where the target dispatches on size through one swap routine the same change
moved sim by 0.1 only.
Evidence: 0x27c210 +14.7 (Sonnet); 0x27c210 +9.5 (Opus); 0x1e37d0 +0.1 (Sonnet); 0x1e37d0 +0.1 (Opus).

<a id="lesson-46"></a>
<!-- tags: construct/bitfield, construct/float, wall/constant, wall/flag-fold -->
**L46. A float operand the comparison flags as a reference mismatch is usually a literal, not a named global.** (single)
Status: candidate. Found by: Opus, Sol. Rules: none.
Symptom: constants declared `extern const` so the target's operand reads as a different reference; three
inherited numeric globals bound to plausible but wrong entries. Fix: read the value locally and write the
literal; use an extern only when the address is shared or written.
Evidence: 0xcd9b60 +5.3 (Opus); 0xbbf5c0 flat (Sol).

<a id="lesson-47"></a>
<!-- tags: abi/calling-convention, construct/constructor, wall/callee -->
**L47. Zeroing a whole aggregate adds a bulk-clear call: initialise only the members the target writes, and leave callee-filled outputs alone.** (repeated)
Status: mapped. Found by: Sol, Opus. Rules: 9 agrees.
Symptom: one extra callee (a memory-clear call) and extra zero stores, or padding fields the target never
writes. Fix: member-wise initialisation of the observed fields after checking which later reads need them;
drop the initialiser of an out-parameter a callee fills; an empty default constructor for the engine's point
type, which leaves its members uninitialised.
Evidence: 0x7e6850 +3.2 (Sol); 0x54e9c0 +0.4 (Opus); 0x97a2e0 +0.2 (Opus); 0x123a7f0 +0.2 (Opus); 0x5caca0 callees (Sol).

<a id="lesson-48"></a>
<!-- tags: construct/bitfield, wall/flag-fold -->
**L48. Flag tests: a by-value bit helper, a bit-field stand-in, or an if/else assignment of the flag.** (repeated)
Status: mapped. Found by: Opus, Sonnet. Rules: 16 agrees, 52 agrees.
Symptom: a masked compare where the target loads, shifts and tests a bit, or a compound boolean where the target
assigns the flag in two arms. Fix: rule 16's helper, a bit-field for adjacent flags, the if/else form.
Evidence: 0x7e6850 +0.5 (Opus); 0x5def30 +1.9 (Sonnet); 0x27c210 +0.4 (Opus).

<a id="lesson-49"></a>
<!-- tags: abi/virtual, wall/callee -->
**L49. Placeholder virtual slots are an off-by-one risk: one too many shows as one missing and one extra virtual callee.** (single)
Status: mapped. Found by: Sonnet. Rules: 11 agrees.
Symptom: the comparison reports one missing and one extra virtual callee on one call. Fix: number the
placeholders by the slot index in the comment and check each call's displacement divided by eight against it;
the repair is free.
Evidence: 0x6cd850 callees (Sonnet).

## Residues the pilot could not close

<a id="lesson-50"></a>
<!-- tags: construct/loop, wall/constant, wall/control-flow, wall/register-schedule -->
**L50. What was left at 85 to 98 percent was schedule, register and placement: send it to the permuter instead of spending rounds.** (repeated)
Status: mapped. Found by: Opus, Sol, Sonnet. Rules: 12 agrees, 55 agrees, 58 agrees.
Symptom: alignment padding before two loop heads, block placement (an early-return block at the start where
the target has it at the end, a retry block inside the split region), a 64-bit constant the target keeps in a
register for the whole function, spill slots, a best-fit record kept as a branch against a conditional move,
the shrink-wrapping of an early return. Fix: stop after two flat rounds (L33), classify the wall, run the
permuter ([permuter.md](permuter.md)) and explain any winner in authentic source.
Evidence: 0x4b10e0 flat (Opus); 0xcdf660 flat (Opus); 0x29b960 flat (Sonnet); 0x6cd850 flat (Opus).
Still failing: 0x4b10e0, 0xcdf660, 0x29b960, 0x6cd850.

<a id="lesson-51"></a>
<!-- tags: construct/bitfield, construct/switch, method/diagnostic, wall/flag-fold, wall/register-schedule -->
**L51. A target that stores each field, tests a byte-swap flag from memory and reloads before swapping is not reproduced by any reader spelling.** (single)
Status: open. Found by: Sonnet, Sol, Opus. Rules: none.
Symptom: about 180 aligned instructions "missing" in a 6 KB loader: the target keeps its reader temporaries in
memory where the draft keeps them in registers. Tried: typed overload sets, a size-dispatched swap
routine, intrinsic and memory-copy spellings, a bound computed locally, guarded wide reads. Nothing moved sim
by more than 0.2.
Evidence: 0x1e37d0 flat (Opus); 0x1e37d0 +1.2 (Sol).
Still failing: 0x1e37d0.

## Rules the pilot checked

Cookbook rules the lessons above cite, with the verdict of the pilot's evidence. "agrees" means a gain or a
loss of the kind the rule predicts; none of it is a comparator pass.

| Rule | Verdict | Lessons |
| ---: | --- | --- |
| 1, 4 | agrees (re-read, hoist) | 35 |
| 2 | agrees, extends to reject-path guards | 30, 31 |
| 5 | agrees; qualified when the register holds a spill | 4, 5 |
| 6 | agrees (signed selector) | 34 |
| 9 | agrees (more functions) | 47 |
| 11 | agrees | 49 |
| 12, 55, 58 | agrees (residues sent to the permuter) | 50 |
| 13, 67 | agrees; a holder or `noexcept` moves the state | 27, 28, 29 |
| 16, 52 | agrees | 48 |
| 27 | qualified (inverse case, out of line at some sites) | 24 |
| 29, 39 | agrees; extends to the embedded handle | 39 |
| 33 | agrees | 4 |
| 34 | qualified (unwind state decides the exit shape) | 26 |
| 35, 44 | agrees | 32 |
| 42 | agrees (operand order; the non-levers) | 31, 33 |
| 48 | agrees for the sqrt/floor symptom; contradicted as a blanket first move | 13, 14, 15 |
| 50, 51 | agrees; extends to packed math and by-value matrix results; aligned loads not reproduced | 16, 17, 20, 36 |
| 68, 69, 70 | agrees | 4, 42, 43 |

## Tooling gaps the pilot raised

One line each, with what was done. Costs are the drafters' estimates.

- `score.py --restore` took the highest sim even without full callee agreement (about 2 min per use): now
  prefers full agreement and no behaviour mismatches (`--raw` for the old choice).
- Result lines counted every drafter's rounds and appended duplicates (about 10 min of hand patching): now
  counted per model since its own clock, one line per function.
- The attempt logged every retry as Sonnet: the model is passed through (`NEAR_MODEL`) and written on each row.
- The score line gave no distance move and no behaviour count: both are printed now.
- `check_code_rules.py` answered "not a source file under reconstruction/" for an absolute path, a path from a
  subdirectory and a path in another checkout or git worktree: it resolves all of them now.
- `check_code_rules.py --list` reads the whole tree on every call (about 26 s of CPU; eight units in one call hit
  a two-minute tool timeout): it now reads only the files named.
- `near_start.py` does not write the recipe line for an existing unit, and needs `--class` and
  `SR_SKYRIM_EXE` for it (about 2 min a time): open.
- `attempt` does not print C4714 (forced inline refused) from the compile log, and prints "exit 1" for a
  scored non-exact attempt (about 3 min on 0x480750): it prints the C4714 functions and says "scored, not
  exact" (exit status 1 is unchanged).
- `attempt` could print all `UNBOUND` names as one ready-to-paste hints object with the pack's RVAs, collapse
  literal-pool lines and filter funclet names from older attempts (the most repetitive manual step): float,
  vector and string literals now bind by the value their name spells, and the unbound names print once more as
  a paste-ready object (no RVAs yet; funclet filtering is still open).
- The comparator reason `undeclared-alias` appears after a recipe switch with no real alias: open.
- A scratch-register and zero-length-behaviour check for quaternion helpers, and a shared header of Havok
  stand-ins in the declaration kit, were asked for twice: open.
