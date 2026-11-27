# 0x156aab0 NiMemStream::Function156aab0

<!-- tags: wall/register-schedule, wall/control-flow, construct/serialization -->

- Function: 0x156aab0 NiMemStream::Function156aab0
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: native comparator PASS, all-checks-passed
- Attempts: 6

## What differed
Independent conditional callback assignments selected the correct functions, but emitted the address choices in a different order. Testing the zero case first removed the reference-order differences and reduced alignment distance from 8.0 to 2.5, leaving register choice and scheduling. The native one-worker permutation search exhausted its available mutations at distance 2.5.

## Spellings tried that did not help
Named callback locals did not improve the initial distance. Reversing the assignment order alone changed matching-byte coverage but left distance 8.0. Named locals with inverted predicates regressed to distance 6.5. The bounded permutation search scored one candidate without an improvement.

## Spelling that fixed it
One ordinary if/else assigns both callbacks for the selected mode. That paired control-flow spelling passed on comparison six. This is evidence for the callback-selection spelling on this function, not a general register-allocation rule. The body is original from local target observations; community callback declarations supply types, and no sibling middleware body was read or adapted. Local PASS remains candidate evidence, pending the independent acceptance gates.
