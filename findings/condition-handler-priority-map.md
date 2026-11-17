# Retail condition-handler priority map

Status: MAPPED; this finding does not establish a source match or a gameplay contract.
Author / human operator: awarebayes.
AI assistance / model: gpt-6.1-sol (Engineer), gpt-6.1-terra (Drafter).
Date (UTC): 2026-11-16.
Target build: sse-steam-1-7-104.
Image SHA-256: 846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f.
Source exposure: mixed (binary-analysis and community-headers).
Name provenance: GUESS(high) for the association between the public condition name and
the retail handler; original C++ signatures and ownership remain guesses.

The priority order is the 42-function slice requested in
[Mudcrab issue 648](https://github.com/Mudcrab-Team/mudcrab/issues/648), read on 2026-11-16.
That issue's usage and coverage figures have not been independently reproduced here.
Public names and condition indices are cross-checked against
[CommonLibSSE-NG TESCondition.h](https://github.com/CharmedBaryon/CommonLibSSE-NG/blob/b93280e832f263dbef44e44cbe2936622a02f91a/include/RE/T/TESCondition.h)
and the declaration of SCRIPT_FUNCTION in
[CommandTable.h](https://github.com/CharmedBaryon/CommonLibSSE-NG/blob/b93280e832f263dbef44e44cbe2936622a02f91a/include/RE/C/CommandTable.h)
(MIT). No code or declaration from these headers is copied into this finding.

## Method and limitations

On the maintainer's Windows machine, inspect the pinned owned image and follow the
condition evaluator's indexed indirect call. The command table begins at RVA 0x207ea90,
has stride 0x50, and carries the condition-handler pointer at entry offset 0x40. Read
each requested entry's name and opcode from that same entry, then resolve its handler
pointer to an RVA. Function sizes use the stock exporter’s comparator-v2 extent walk,
including consecutive chained unwind ranges, pending complete comparator checks.
Five of the requested handlers have such chained ranges; using only their first
exception-directory entry would truncate their scope.

The private extraction and all raw observations stay in ignored local research storage.
Reproduce with a locally supplied pinned image and the above public declarations; never
upload the image or raw exports. Independent checking caught and corrected an initial
one-entry name-field offset error before publication or acceptance. No prior incorrect
mapping is match evidence.

The pool entries in data/progress.json carry each handler's RVA, size and current status.
Every association is build-specific. An RVA or unwind extent alone proves neither the
original function name nor behavior. A future matched status requires the unchanged
comparator, independent confirmation, admitted Reviewer approval and integration.

## Transfer boundary

Transfer status: UNREVIEWED.
This is exposure-bearing research for this repository. No finding, reconstruction or
behavior summary is approved for transfer to Mudcrab by this mapping. No issue comment
has been posted there.
