# std::function implementation slots over small callables

On the pinned Steam build, two virtual slots of `std::_Func_impl_no_alloc<Callable, void>` account for 283 functions outside the matched inventory. One stand-in template and one explicit instantiation per callable reproduce 280 of them. Each compiled function passed the local comparator, including unwind information, its table reference and its sized-delete call target.

| Slot shape | Function observed | Local passes | Bytes | Owner tables or object sizes | Callee |
| --- | --- | ---: | ---: | --- | --- |
| `_Copy`, `_Move`, callable of one pointer | stores the owner table in the destination, copies one pointer-wide callable from `this + 8`, returns the destination | 122 | 2,684 | 61 tables, two slots each | none |
| `_Copy`, `_Move`, callable of sixteen bytes | the same, with the callable copied by one 16-byte vector move pair | 36 | 792 | 18 tables, two slots each | none |
| `_Delete_this(bool)` | when the flag is set, calls sized `operator delete(this, n)`; the callable is trivially destructible | 122 | 1,830 | n = 16 (74), 24 (37), 32 (11) | one shared `operator delete` |

Three further members (two one-pointer copy/move slots and one delete slot, all of the same callable signature) take a Scaleform `GFxValue&` and are held out as a middleware-type instance.

## Method

`tools/std_callable_generate.py` decodes every candidate independently from the image and checks the exact instruction shape. For a copy or move candidate it reads the first two entries of the read-only owner table named by the function and keeps the member only when one entry points at it, which also tells the slot apart (the two slots compile to the same bytes). For a delete candidate it checks that the size is a whole number of words and that the jump target is an indexed function. Each emitted unit holds one small template, `StdCallableState<Bytes>`, and for every callable one derived struct and one `template class std::_Func_impl_no_alloc<Callable, void>;`. The table symbol and the callee are bound by name in the symbol map.

## Reproduce

With Python, `iced-x86==1.21.0`, and the configured contributor toolchain:

```sh
python3 tools/std_callable_generate.py --exe "$SKYRIM_EXE"
python3 tools/std_callable_generate.py --exe "$SKYRIM_EXE" --out .local/std-callable --compare
```

`--only <file>` takes whitespace-separated hexadecimal RVAs and keeps only those members; it is how the held-out tests below were run.

## Evidence and limits

- Target `sse-steam-1-7-104`, image SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`. Boundary source `CRASHLOGGER_PDB(59818@2026.10.24)`.
- Held-out test before bulk emission: for each shape, the lowest RVA as the seed plus ten further members chosen with a fixed random seed (the delete shape stratified over the three object sizes) were generated from the same template and compared on the pinned native Windows compiler. 11 of 11 passed for each shape (one-pointer copy/move, sized delete, and, tested separately before it was emitted, the sixteen-byte copy/move). The first run failed on a symbol spelling that was wrong for every member (the standard template with an empty parameter pack mangles with `$$V`); one change to the generator fixed all members and no member was edited.
- Full run: 280 of 280 comparator passes on that host (158 copy/move, 122 delete).
- Scope: the owner is the standard library template over the game's own callback types (`BSPlatform` platform results, `MarketplaceEvent` interface binders, texture creation and similar); the `bnet::` client namespace and Scaleform argument types were excluded. Every owner name comes from the image's RTTI, so these are standard-library instances the game's own code instantiated (`docs/resource-guidelines.md`, standard-library row).
- Not covered: the callable's signature, its captured state and its original type are unknown; every emitted callable is `GUESS(low) STANDIN`. A byte match shows the compared code, nothing about the original lambda or binder.
- Related shapes not attempted: a copy/move whose callable is copied with two scalar moves (39 members; a plain state array of any size compiles to the vector form, so the stand-in needs a member-wise copy shape that is not yet known) and the call slot (about 40 members; the stored target differs per member).
- These runs supply one-host evidence only; second-host comparison and admitted review are pending.

Neighbouring cluster, not shipped: 185 slot-3 members of `CopyableCallable<...bnet_std::detail::FunctionImpl<...>>` (82 bytes, one exception state) are the Bethesda.net client's own runtime. `docs/resource-guidelines.md` lists that client as out of scope, so it was recorded and left alone.
