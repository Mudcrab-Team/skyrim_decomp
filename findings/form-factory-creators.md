# Form factories with an out-of-line product constructor

Sixteen slot-one implementations of `ConcreteFormFactory<T, FormType>::CreateImpl` reduce to `return new T;`. The scalar allocation operator initializes the shared heap on demand. MSVC calls the product constructor on success and emits a separate cleanup that invokes the global sized delete if construction throws.

| Opportunity on the pinned image | Candidates | Selection |
| --- | ---: | --- |
| Out-of-line product construction | 19 | 17 use a 95-byte primary body and two use a 94-byte body. Three intersect another indexed extent. The remaining 16 contribute 1,519 primary bytes. |
| Other slot-one creators | 96 | The 115 distinct factory slot-one targets include creators that inline product initialization. Recovering each constructor's fields and base calls requires a different template. |
| Ordinary factory teardown | 118 | 115 refer to a base factory table and three to a different owner. The survey found no direct calls or jumps to these addresses. A base vtable store alone cannot distinguish an ordinary base destructor from inherited cleanup. |

## Evidence and results

The extractor starts from primary RTTI vtables, allows a derived factory to inherit its base's slot, and checks the complete indexed extent against the exception directory. It decodes the heap guard, allocator arguments, null path and constructor call. The constructor must reference the product's own primary vtable, and product RTTI must place a nonvirtual TESForm at offset zero. The generator forward-declares the real product type for each factory specialization. A single scoped storage template represents the product constructor, primary base and allocation size. They make no claim about intermediate bases or individual product fields.

On repository revision `b0ba3115cb`, all 16 generated functions compiled with pinned MSVC 19.16.27054 under Wine and passed the ordinary local comparator. Each comparison covered the static heap references, three primary calls, unwind state and the sized deallocation in the constructor-failure funclet. The 1,519-byte total excludes funclets.

| Validation partition | Passed / tested | Primary bytes |
| --- | ---: | ---: |
| Development | 9 / 9 | 854 |
| Held out | 7 / 7 | 665 |

The existing form-name hash split kept each product in one partition throughout. The initial EffectSetting prototype matched the primary hash with a class-specific unsized delete but failed on the cleanup extent. Global sized delete passed. Adding `noexcept` to the allocator in the first generated development build changed the exception state map and all nine failed. Removing it restored nine passes. The frozen template passed all seven held-out functions on the first evaluation. Tightening the prologue and epilogue checks left all selections unchanged. After the held-out run, a cross-tree declaration audit found 15 product types already defined elsewhere. The submitted layout uses one scoped product template in place of those duplicate definitions. A repeat on the same partitions passed 9/9 and 7/7. This repeat is revised validation, and the first held-out result above belongs to the original layout. These counts are local verification.

## Reproduction

Use a configured contributor checkout with the pinned executable, compiler and current claims. Supply a fresh directory below `.local/`. Existing claims, markers and accepted work are excluded.

```sh
python3 tools/form_factory_create_generate.py --exe "$SKYRIM_EXE" --out .local/form-create --compare
python3 -m unittest discover -s tests -p 'test_form_factory*'
```

The pinned image supplied the RTTI, references and allocation sizes. Community extents came from `CRASHLOGGER_PDB(59818@2026.10.24)`. The previously merged interface and product-base declarations use `COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)`. Exposure is mixed. The heap helper names and product storage type are stand-ins.
