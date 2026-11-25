# 0x5d1760 MagicTarget::HasMagicEffectWithKeyword

<!-- tags: construct/loop, construct/destructor, abi/virtual, abi/exception, method/binding -->

- Function: 0x5d1760 MagicTarget::HasMagicEffectWithKeyword
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 112/181 aligned matching bytes
- Attempts: 3 counted comparisons

## What differed
The target uses a multiple-inheritance callback object with an active-effect visitor and a magic-item keyword search base. The callback tables bound successfully, but the candidate's construction, cleanup and list traversal retained different control flow and a smaller function body. A normal callback destructor remained unresolved; its deleting-destructor slot does not establish the normal destructor's identity.

## Spellings tried that did not help
An empty-list check using both the first item and next node reached 110/181 matching bytes. A first-item check and an explicit empty callback destructor reached 112/181, with the normal destructor reference still unresolved. A class-defined default-destructor alternative removed that unresolved reference but lost the target exception-frame structure and fell to 32/181. The best draft was restored and stopped at the binding-evidence gap rather than assigning an unsupported address.

## Spelling that fixed it
none
