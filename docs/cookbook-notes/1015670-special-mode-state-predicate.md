# 0x1015670 RenderTargetManager::SetDepthStencilRenderTarget

<!-- tags: construct/bitfield, method/diagnostic, wall/control-flow -->

- Function: 0x1015670 RenderTargetManager::SetDepthStencilRenderTarget
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: other
- Best score: 60/60 aligned matching bytes; native local comparator PASS
- Attempts: 2

## What differed

The first draft had the same measured size and 58/60 aligned matching bytes, but its special-mode predicate was reversed. It only considered the slice when the mode had one distinguished value, whereas the observed update condition also dirties state whenever the mode differs from that value. A high similarity score did not establish equivalent behavior.

## Spellings tried that did not help

The initial combined condition used `mode == 3 && depthSlice != slice` as its final disjunct. This was a semantic error, rather than a register allocation problem. The diagnostic suggested cookbook rule 2; that suggestion classified a branch difference but did not establish the correct predicate.

## Spelling that fixed it

Use `mode != 3 || depthSlice != slice` as the final part of the update condition. The second compare passed without changing the state stores or global bindings. This is evidence for this function's predicate, not a general rule for other render-state setters. The source was handwritten from the pinned local pack; the method name came from the generated CrashLogger facts. The result is one-host evidence only, not acceptance.
