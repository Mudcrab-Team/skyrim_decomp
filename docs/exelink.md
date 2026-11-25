# exelink: matched functions relinked in place

`tools/exelink/` places every matched function, compiled from this repository's source, at its
original RVA inside a copy of the owner's own executable, and compares the copy with the original.
The rest of the image is the owner's bytes, so when every placed function is right the copy is
identical to the retail file. The idea comes from the `exelink` tool of gibbo101/ra2-decomp.

It checks something the per-function comparator does not: the functions together, in one image,
with every relocation resolved to a real address and every referent (callee, global, funclet,
exception table) at the place the image says it is. It is also the base for later builds that
move or replace parts of the image: a shiftable build or a hook build starts from a tree that is
known to relink identical.

It is a local diagnostic over private inputs. It accepts nothing, writes no match record and never
counts as the second host of `docs/verification.md`. Only the comparator, on two hosts, shows a
byte match.

## What it does

For each matched function (`data/progress.json` status `matched`, record under `reports/`):

1. Find the function in its compiled object the way the comparator does: by symbol for ordinary
   functions, by the pinned selector for the admitted internal functions (`docs/comparator-internal-prototype.md`).
2. If the compiled size is not the size of the retail slot, place nothing and count it
   (`size-mismatch`).
3. Bind the function's funclets, exception data and `.pdata` entries to the RVAs the image's own
   exception data gives them, with the comparator's binding code (`Function.compare_unwind`) but
   without its byte comparison.
4. Write every bound section into the image copy at its RVA with each relocation resolved:
   `REL32` and its variants, `ADDR32NB` and `ADDR64` from the unit's symbol map, `__ImageBase`,
   `_tls_index` from the TLS directory, and `SECREL` for declared thread-local entries. Sections
   of the same object that the exception data binds resolve to their placed RVA. A relocation whose
   target has no address stays as the object has it and is counted (`unresolved-relocation`).
5. After every function is placed, compare each placed range with the original image.

Placed range kinds: `code` (the function), `funclet`, `eh-data` (unwind info, FuncInfo and handler
tables) and `pdata` (the function's entries in the exception directory, at the slots the image has
them in). Two functions that share bytes, such as folded copies, must agree; if they do not the
function is noted `placement-conflict`.

## Classes

Each function ends in exactly one class. They are separate counts and are never merged.

| class | meaning |
|---|---|
| `identical` | every placed byte equals the original |
| `size-mismatch` | the compiled size differs from the retail slot; nothing was placed |
| `unresolved-relocation` | at least one relocation target has no address (not in the unit's symbol map, or an unsupported relocation kind), and the bytes differ |
| `post-link-patch` | size fits, all relocations resolved, bytes differ, and every differing byte lies inside a range declared with `--post-link` |
| `residual-difference` | size fits, all relocations resolved, bytes differ, and no declared patch explains them |
| `not-linked` | nothing was placed: no object for the unit, the object has no usable function symbol, or the unit's symbol map cannot be read. Each reason is its own count. |

A post-link patch is a change made to the executable after the linker ran (the case the ra2 tool
handles): a loader or protection stage, a hot patch, an edit by the publisher. Nothing in this
repository claims one exists in the pinned build. The tool therefore reports a difference it
cannot explain as `residual-difference`, the candidate list for new patch ranges, and lists a
difference as `post-link-patch` only for ranges the owner has declared in a file:

```json
[{"rva": 1048576, "length": 16, "label": "free text, no bytes"}]
```

Notes on a function, counted separately and not classes: `object-differs-from-record` (the object's
code-section hash differs from the one in the match record, so the source or compile changed since
acceptance), `exception-data-unbound` (the image's exception data could not be bound, so only the
code range was placed), `placement-conflict`, `identical-with-unresolved` (all bytes equal although
a relocation was unresolved).

The report also gives, per image section, the functions and bytes placed and either `identical` or
the first differing RVA with the function it belongs to. `output identical to retail` is true only
when no placed byte differs. It is a statement about the placed functions: everything not placed is
the retail bytes by construction.

## Running it

Everything runs from the repository root. The image is the owner's own executable, from `--image`
or the `image` setting in `.local/verifier/config.json`; it must hash to `builds/target.json`.

```sh
python3 tools/exelink/exelink.py plan --out .local/exelink/plan.json            # all matched functions
python3 tools/exelink/exelink.py plan --out .local/exelink/plan.json --sample 500 --seed 1
python3 tools/exelink/exelink.py plan --out .local/exelink/plan.json --unit reconstruction/<area>/<File>.cpp
```

The plan groups the matched functions by translation unit. Objects can come from any build of
those units, named `<unit id>.obj` (the id is in the plan): the verifier's `candidate.obj`, or the
objects of a CI-hash build.

```sh
python3 tools/exelink/exelink.py link --plan .local/exelink/plan.json --objects DIR --report .local/exelink/report
```

On a Windows host that has the pinned toolchain unpacked (`docs/windows-verifier-host.md`),
`run` compiles the planned units with each unit's recipe, batching several sources per compiler run,
places the objects as each batch finishes and deletes them:

```sh
python tools/exelink/exelink.py run --plan .local/exelink/plan.json --objects .local/exelink/objs \
    --msvc <toolchain> --image <SkyrimSE.exe> --report .local/exelink/report --jobs 1
```

`--jobs` is the number of compiler runs in parallel; linking runs in the calling process besides
them. A unit with no object after its batch is retried alone once. Wine hosts are not driven by
`run`: build with the verifier and pass the objects to `link`.

For a long run, split the plan with `plan --shard K/N` (every Nth unit starting at K), run each
shard with `--summary shard-K.json`, and add them with `merge shard-*.json`.

## Output and privacy

Standard output and `summary.json` hold counts, RVAs and function names. `--report DIR` also
writes `functions.jsonl`, one row per function (id, RVA, size, name, class, first differing RVA and
the kind of range it is in, unresolved target names). No byte value from the image or from an
object is written anywhere. The rows and the relinked image (`--out-image`) derive from the owner's
executable, so both are refused unless the path has a `.local` directory in it; they must never be
committed, uploaded or attached to a PR. Objects are compiled output of the repository's own
source and go under `.local/` too. A PR or handoff may carry the counts of `summary.json`.

## Limits

- Only matched functions are placed. Data, imports, unmatched code and every unplaced byte come from
  the owner's file, so the check says nothing about them.
- An object's `.pdata` entries are placed only for code the exception data bound; a function whose
  exception data cannot be bound is placed as code only and noted.
- Addresses are the pinned image's at its preferred base. There are no base relocations, no
  rebasing and no moving of code yet.
- `ADDR64` is supported, other relocation kinds (`ADDR32`, `SECTION`, `TOKEN`, and so on) are counted
  as unresolved. The comparator accepts none of them for a match either.
- Linking relies on the unit's symbol map for every referent outside the function's own bound
  sections, so a wrong map entry that the comparator accepted would be reproduced here.
- Batch compiles share a compiler process between sources. The code-section hash check of each
  object against its match record (`object-differs-from-record`) is what shows a batch build, or a
  source edited since acceptance, produced different code.

Tests: `tests/test_exelink.py`, on the synthetic images of `tests/synthetic_pecoff.py`.
