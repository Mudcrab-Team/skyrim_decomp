# 0xef82c0 NiTimeController::dtor

<!-- tags: abi/exception, abi/virtual, construct/destructor, method/binding -->

- Function: 0xef82c0 NiTimeController::dtor
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: other
- Best score: 82/82 matching code bytes before the exception-metadata fix; final comparator pass
- Attempts: 5 counted compares, plus 1 exempt binding-only invocation

## What differed

The direct cleanup body reached identical code while exception metadata still differed: the target had one cleanup state and the candidate had none. The retained controller link is an ownership member, so its destruction participates in the containing destructor's cleanup structure.

## Spellings tried that did not help

- Reading the retained link again after the atomic release produced a larger function.
- A cached link pointer corrected that difference, but ordinary volatile decrement of the live-object counter still produced separate accesses.
- Atomic counter decrement closed the code difference. Keeping the retained-link release directly in the outer destructor still left the cleanup-state mismatch.

## Spelling that fixed it

Represent the retained link as a minimal pointer holder with its own releasing destructor, and leave the outer destructor body empty. Keep the shared counters atomic. The final ordinary comparison passed both code and exception metadata.

The explicitly tagged destructor/exception retrieval supplied related ownership and cleanup lessons; rule 26 describes the exception-extent family. Initial automatic retrieval supplied no tags. This is one local candidate result, not acceptance evidence.

The fifth counted compare confirms the final declarations after provenance and padding cleanup; it also passed. The source-origin checker reports nontrivial similarity of the minimal holder to sibling middleware. Those bodies were not inspected or adapted; the holder was written from target observations and community declarations.
