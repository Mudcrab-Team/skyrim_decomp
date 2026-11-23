# 0x152ce50 BSWaterShaderProperty::ForEachTexture

- Function: 0x152ce50 BSWaterShaderProperty::ForEachTexture
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) SYMBOLS(tesv-2013-map)
- Outcome: fixed
- Cause: register-allocation
- Best score: 98/98
- Attempts: 5

## What differed

Direct member access produced a different scratch register choice for the last two visitor calls. The compiler also produced a tail call in a nested conditional spelling.

## Spellings tried that did not help

Nested positive-result conditionals gave a tail call. Early returns produced the desired common return but retained the scratch register difference with direct member access.

## Spelling that fixed it

Early returns after unsuccessful visitor calls, followed by small inline accessors for the second and third texture fields, produced the matching comparison. This is a source-shape observation, not evidence that the original used those accessors.
