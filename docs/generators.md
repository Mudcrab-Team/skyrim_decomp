# Family generators

Many functions share one compiler shape (a deleting destructor, a wrapper that forwards its first argument, a
lazy static initializer). A **family generator** finds every member of one shape in your own local copy of the
image, writes the units, and, with `--compare`, checks each member with the same comparator you use by hand. Before
drafting a function by hand, look its shape up here: if a generator covers it, run the generator, and drafting
the leftovers is all that is left to do.

A generator proves nothing by itself. Only the comparator's byte match on two hosts plus one review makes a
function `matched` ([verification.md](verification.md)); a generated unit lands through the normal PR route
and carries the same labels as any other unit. Inputs, selection files and output stay under `.local/`: no game
bytes, listings or private selections are ever committed.

**Write the family down.** A generator PR that adds or changes `tools/*_generate.py`, or a PR that lands 50 or
more functions from one area, should carry a short family note: the shape, why it matches, the pitfalls. Either a
`findings/<family>.md` note (a whole family) or a lesson note in `docs/cookbook-notes/` (`./sr lesson`; format in
[cookbook-notes/README.md](cookbook-notes/README.md)). The bot's one comment asks for it when it is missing; it never
blocks. `python3 tools/lesson_credits.py` credits family notes and generator authors alongside lesson notes.

## How to read the tables

- **Command**: run from the repository root with `python3` on your own machine. `<exe>` is your legally obtained
  `SkyrimSE.exe` under `.local/`. The self-contained generators need `iced-x86==1.21.0` and the pinned contributor
  compiler (`./sr setup`).
- **Verification**: `--compare` compiles every generated member with the pinned contributor toolchain and compares
  it locally. It is a pre-check; the PR's two-host comparator and review decide.
- **Credit**: the GitHub login of the author in the git history of the file.
- **Findings**: the family note, when there is one.
- A row with a version suffix (`_v2`, `_v3`) is another revision of the same extractor; prefer the highest
  revision unless a family note says otherwise.

## Self-contained generators (`--exe`, `--compare`)

These read the image directly and verify on their own. Each has a unit test in `tests/test_<name>.py`.

| Generator | Family it emits | Verification | Command | Credit | Findings |
| --- | --- | --- | --- | --- | --- |
| `tools/bst_array_generate.py` | non-EH `BSTArray` / `BSTSmallArray` / `BSTScrapArray` container helper methods | code, unwind, static references and call targets per member | `python3 tools/bst_array_generate.py --exe <exe> --out .local/bst-array --compare` | @aivv73 | [bst-array-helpers](../findings/bst-array-helpers.md) |
| `tools/conditional_dealloc_generate.py` | conditional sized deallocators and cleanup-then-deallocate wrappers | code, unwind and call targets per member | `python3 tools/conditional_dealloc_generate.py --exe <exe> --out .local/conditional-dealloc --compare` | @aivv73 | [conditional-deallocators](../findings/conditional-deallocators.md) |
| `tools/custom_dealloc_generate.py` | custom-allocator scalar deleting destructors (TLS-router and global-heap forms) | code, unwind, static references and call targets per member | `python3 tools/custom_dealloc_generate.py --exe <exe> --out .local/custom-dealloc --compare` | @aivv73 | [custom-allocator-deallocators](../findings/custom-allocator-deallocators.md) |
| `tools/descriptor_init_generate.py` | static reflection descriptor initializers (class descriptor calls and 6-field type-info records) | code, unwind, static references and call targets per member | `python3 tools/descriptor_init_generate.py --exe <exe> --out .local/descriptor-inits --compare` | @aivv73 | [static-descriptor-initializers](../findings/static-descriptor-initializers.md) |
| `tools/fixed_argument_generate.py` | wrappers that forward the first argument and fix the second unsigned integer | full code including the direct jump target | `python3 tools/fixed_argument_generate.py --exe <exe> --out .local/fixed-argument --compare` | @aivv73 | [fixed-argument-wrappers](../findings/fixed-argument-wrappers.md) |
| `tools/form_factory_create_generate.py` | form-factory creators with an out-of-line product constructor | full code, heap and constructor bindings, unwind and sized-delete funclet | `python3 tools/form_factory_create_generate.py --exe <exe> --out .local/form-create --compare` | @aivv73 | [form-factory-creators](../findings/form-factory-creators.md) |
| `tools/form_factory_generate.py` | RTTI-owned scalar deleting destructors of the Bethesda form-factory templates | comparator pass per member; needs a contributor claims lookup | `python3 tools/form_factory_generate.py --exe <exe> --out .local/form-factories --compare` | @aivv73 | [form-factory-destructors](../findings/form-factory-destructors.md) |
| `tools/guarded_callback_generate.py` | guarded static-callback dispatch and destroy-then-callback wrappers | code, unwind, guard and callback addresses, call targets | `python3 tools/guarded_callback_generate.py --exe <exe> --out .local/guarded-callback --compare` | @aivv73 | [guarded-callbacks](../findings/guarded-callbacks.md) |
| `tools/lazy_static_generate.py` | lazy static-slot initializers and singleton-registration wrappers | code, unwind, static references and call targets per member | `python3 tools/lazy_static_generate.py --exe <exe> --out .local/lazy-static --compare` | @aivv73 | [lazy-static-initializers](../findings/lazy-static-initializers.md) |
| `tools/memory_factory_generate.py` | non-EH `MemoryManager::Allocate` factory and creator methods | code, unwind, static references and call targets per member | `python3 tools/memory_factory_generate.py --exe <exe> --out .local/memory-factory --compare` | @aivv73 | [memory-factory-creators](../findings/memory-factory-creators.md) |
| `tools/range_copy_generate.py` | range-copy wrappers that copy `[first, last)` to a destination and return destination plus count | code, unwind and the direct call target | `python3 tools/range_copy_generate.py --exe <exe> --out .local/range-copy --compare` | @aivv73 | [range-copy-wrappers](../findings/range-copy-wrappers.md) |
| `tools/return_argument_generate.py` | wrappers that call another entry and return a preserved pointer argument | code, unwind and the direct call target | `python3 tools/return_argument_generate.py --exe <exe> --out .local/return-argument --compare` | @aivv73 | [return-argument-wrappers](../findings/return-argument-wrappers.md) |
| `tools/sbo_alloc_log_generate.py` | BNet-runtime SBO binders, custom-allocator factories, buffer-clear and guarded-log wrappers | code, unwind, static references and call targets per member | `python3 tools/sbo_alloc_log_generate.py --exe <exe> --out .local/sbo-alloc-log --compare` | @aivv73 | [sbo-alloc-log-wrappers](../findings/sbo-alloc-log-wrappers.md) |
| `tools/static_data_generate.py` | two static-data leaf families: readers and object wrappers | every member compared locally with `--compare`; counts only without `--out` | `python3 tools/static_data_generate.py --exe <exe> --out .local/static-data --compare` | @aivv73 | [static-data-families](../findings/static-data-families.md) |
| `tools/vftable_reset_generate.py` | polymorphic table-reset wrappers: initializers, tail cleanups and deallocators | code, unwind, read-only table address and call targets | `python3 tools/vftable_reset_generate.py --exe <exe> --out .local/vftable-reset --compare` | @aivv73 | [vftable-reset-wrappers](../findings/vftable-reset-wrappers.md) |

## Selection-driven generators

These take a private selection file (RVAs and sizes chosen from the census; never committed) and emit bounded
units. They embed no target bytes: each member is decoded in full, bound independently, and then compiled and
compared by the ordinary comparator. A generated unit is a candidate, never a pass. See also
[generator-leaves-selection](../findings/generator-leaves-selection.md) and
[static-context-resource-lineage](../findings/static-context-resource-lineage.md).

| Generator | Family it emits | Verification | Command | Credit | Findings |
| --- | --- | --- | --- | --- | --- |
| `tools/adjustor_thunk_generate_v3.py` | member-local tail-call adjustor thunks with image-relative RTTI binding | decode plus RTTI bind, then the comparator | `python3 tools/adjustor_thunk_generate_v3.py --selection <selection.json>` | @awarebayes | - |
| `tools/census_checked_copy_generate.py` | checked-copy members with complete per-member reference validation | template match on every non-reference field, then the comparator | `python3 tools/census_checked_copy_generate.py --out <dir> [--population <file>]` | @awarebayes | - |
| `tools/census_leaf_generate.py` | bounded census leaf pilot (rva, size, owner, kind, virtual, RTTI-owned) | per-member extent check, then the comparator | `python3 tools/census_leaf_generate.py --selection <selection.json>` | @awarebayes | [generator-leaves-selection](../findings/generator-leaves-selection.md) |
| `tools/deleting_eight_generate_v3.py` | deleting destructor leaves from the `deleting_eight_template_v3` template | independent leaf-shape extraction, then the comparator | `python3 tools/deleting_eight_generate_v3.py --selection <selection.json>` | @awarebayes | - |
| `tools/deleting_leaf_generate.py` | deleting destructor leaves | independent leaf-shape extraction, then the comparator | `python3 tools/deleting_leaf_generate.py --selection <selection.json>` | @awarebayes | - |
| `tools/deleting_wrapper_generate.py` | deleting destructor wrappers | independent wrapper-shape extraction, then the comparator | `python3 tools/deleting_wrapper_generate.py --selection <selection.json>` | @awarebayes | - |
| `tools/large_form_prefix_generate_v1.py` | typed large-form prefix units (partial declarations for secondary destructor adjustors) | adjustors compared only; prefixes make no layout claim | `python3 tools/large_form_prefix_generate_v1.py --root <checkout> --plan <plan.json>` | @awarebayes | - |
| `tools/parked_initializer_generate_v2.py` | static initializer candidates for one census cluster | candidates; verifier confirmation and review required | `python3 tools/parked_initializer_generate_v2.py --census <census.json> --out <dir> --cluster 0x8640` | @awarebayes | [static-context-resource-lineage](../findings/static-context-resource-lineage.md) |
| `tools/primitive_leaf_generate.py` | one selected primitive-leaf population | image hash and complete decoded shape checked before any write | `python3 tools/primitive_leaf_generate.py --selection <selection.json>` | @awarebayes | [generator-leaves-selection](../findings/generator-leaves-selection.md) |
| `tools/represented_field_generate.py` | field leaves over a pinned catalogue of represented layouts | extents and represented header hashes checked before source writes | `python3 tools/represented_field_generate.py --selection <selection.json>` | @awarebayes | - |
| `tools/represented_field_generate_v2.py` | same family, second revision | same checks | `python3 tools/represented_field_generate_v2.py --selection <selection.json>` | @awarebayes | - |
| `tools/represented_field_generate_v3.py` | same family, third revision | same checks | `python3 tools/represented_field_generate_v3.py --selection <selection.json>` | @awarebayes | - |
| `tools/rootless_represented_wrapper_generate_v3.py` | deleting wrappers from complete represented declarations with relative includes | include spellings and the wrapper class identifier only change | `python3 tools/rootless_represented_wrapper_generate_v3.py` (internal: reads and updates private plan state) | @awarebayes | - |
| `tools/rootless_wrapper_generate_v1.py` | rootless deleting wrapper revision | comparator | `python3 tools/rootless_wrapper_generate_v1.py` (internal: reads and updates private plan state) | @awarebayes | - |
| `tools/rootless_wrapper_generate_v2.py` | rootless deleting wrapper revision | comparator | `python3 tools/rootless_wrapper_generate_v2.py` (internal: reads and updates private plan state) | @awarebayes | - |
| `tools/shader_adjustor_generate.py` | member-local shader destructor adjustors | LLVM decode plus image-relative RTTI binds owner, base, offset and both slots | `python3 tools/shader_adjustor_generate.py --selection <selection.json> --out <dir>` | @awarebayes | - |
| `tools/shared_teardown_generate.py` | complete shared-owner static teardown shapes | a freshly compiled probe supplies the shape, never proof; comparator decides | `python3 tools/shared_teardown_generate.py --selection <selection.json> --out <dir>` | @awarebayes | - |
| `tools/static_context_resource_generate_v2.py` | static context/resource initializer candidates | candidates; verifier confirmation and review required | `python3 tools/static_context_resource_generate_v2.py --census <census.json> --out <dir> --cluster 0x7c40` | @awarebayes | [static-context-resource-lineage](../findings/static-context-resource-lineage.md) |
| `tools/static_generate.py` | static initializer candidates from a private census | candidates; verifier confirmation and review required | `python3 tools/static_generate.py --census <census.json> --out <dir>` | @awarebayes | - |
| `tools/static_resource_generate.py` | static resource initializer candidates for two clusters | candidates; verifier confirmation and review required | `python3 tools/static_resource_generate.py --census <census.json> --out <dir> --cluster 0x7c40` | @awarebayes | [static-context-resource-lineage](../findings/static-context-resource-lineage.md) |
| `tools/storage_free_return_generate.py` | storage-free return leaves | complete decode is an enrollment check; the comparator compiles each member | `python3 tools/storage_free_return_generate.py --selection <selection.json> --out <dir>` | @awarebayes | - |
| `tools/storage_init_generate.py` | storage-initializing candidates from a private extraction contract | instruction contract and source template kept separate; a shape is not a pass | `python3 tools/storage_init_generate.py --selection <selection.json>` | @awarebayes | - |
| `tools/storage_init_generate_v2.py` | same family, second revision | same checks | `python3 tools/storage_init_generate_v2.py --selection <selection.json>` | @awarebayes | - |
| `tools/string_static_generate_v2.py` | static string acquisition candidates | private full-instruction contract; every unit is compiled by the two-host confirmation | `python3 tools/string_static_generate_v2.py --selection <selection.json>` | @awarebayes | - |
| `tools/table_store_generate.py` | complete table stores with an independently bound RTTI locator | no template address is transferred between members; comparator decides | `python3 tools/table_store_generate.py --selection <selection.json>` | @awarebayes | - |
| `tools/virtual_tail_generate.py` | nullable first-slot virtual call shapes | extractor checks argument source, slot offset, flag and local branch per member | `python3 tools/virtual_tail_generate.py --selection <selection.json> --out <dir>` | @awarebayes | - |

## Shared helpers and harvesters

Not family generators themselves; they feed or back the ones above. Everything they write is game-derived and stays
under `.local/` ([tools/ghidra/README.md](../tools/ghidra/README.md)).

| Tool | What it does | Command | Credit |
| --- | --- | --- | --- |
| `tools/leaf_family_batch.py` | private snapshot and comparator workflow shared by the indexed leaf-family generators | imported by the generators above | @aivv73 |
| `tools/ghidra/export_pack.py` | private per-function context packs and Drafter task directories | `python3 tools/ghidra/export_pack.py packs <list file>` | @awarebayes |
| `tools/ghidra/build_function_table.py` | whole-image function and class tables for planning and class skeletons | `python3 tools/ghidra/build_function_table.py` | @awarebayes |
| `tools/ghidra/class_skeleton.py` | header skeleton for one class from the private class table | `python3 tools/ghidra/class_skeleton.py <Class>` | @awarebayes |
| `tools/ghidra/harvest_handlers.py` | clean-room harvesters for executable-owned handler names (OBSERVED): command tables, string-and-handler registrations, and script-engine native registrations joined to declarations | see the module docstring | @awarebayes |
| `tools/papyrus_psc.py` | parses the native declarations of the owner-installed script archive (names, flags, returns, parameters) into a private table | `python3 tools/papyrus_psc.py scan <Scripts.zip> --out .local/papyrus/natives.json` | @awarebayes |
| `tools/papyrus_natives.py` | joins script registrations in the image to those declarations and to the class types of `NativeFunctionN`; counts and typed prototypes for native handlers, and the census of the 310 `NativeFunctionN` instances (their run functions are not generated yet: [findings](../findings/papyrus-native-registrations.md)) | `python3 tools/papyrus_natives.py sites\|join --config <cfg> --natives .local/papyrus/natives.json` | @awarebayes |
| `tools/ghidra/plan_cheap.py` | many small functions per Drafter, grouped into shared-header families | `python3 tools/ghidra/export_pack.py plan --order cheap ...` | @awarebayes |
| `tools/ghidra/community_ids.py` | Address Library id to community name associations from a CommonLibSSE checkout | see the module docstring | @awarebayes |

## Adding a generator

1. Put the file at `tools/<family>_generate.py` with a docstring that says what it emits, how `--compare`
   verifies, and the command.
2. Add a row to the right table above, with your GitHub login in **Credit**. `tests/test_generator_index.py` fails
   when a `tools/*_generate*.py` has no row, or a row names a file that is gone.
3. Write the family note (`findings/<family>.md`, or a lesson note) and link it in **Findings**.
4. Open the PR; the bot's comment tells you if the note is missing.
