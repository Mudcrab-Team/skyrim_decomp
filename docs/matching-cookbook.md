# Matching cookbook

Rules from closing near-misses with `reconstruction/recipes/msvc-19.16.27054-o2.json` on build
`sse-steam-1-7-104`, learned from comparator passes and lab compiles. They describe how this
compiler reacts to source shapes, not what the original said, and are starting hypotheses, never
evidence. Spellings must still meet `docs/drafter-card.md`. Confidence: **high** = closed a
function and the counter-variants failed; **medium** = closed one function; **low** = unsettled.

**Before the first draft, read the sibling.** Open the FNV method and the class's small accessors
that the pack's "Sibling source" section lists; their helper boundaries, argument order and
accessor forms are a cheap first hypothesis. Adapt, do not assume: FNV is a 32-bit VC++ 2008 build
of an older engine and most of its game units are `/Od`, so layouts, offsets, slots and
unoptimised shapes do not carry over. Label what you take (`SIBLING`, `docs/drafter-card.md`).

## Control flow and redundancy

**1. A null test the candidate lacks: re-read the pointer.** (high)
Symptom: the target tests a pointer for null after it was already dereferenced; the candidate
drops the test, so it is shorter with an early mismatch. Cause: the original re-reads the member
or accessor (`GetBaseObject()`, `entry->object`) after a call or in a case body. A value MSVC has
already dereferenced is proven non-null, but a reload counts as a new value. Fix: read the member
again where the target tests it instead of keeping a local. Closed CanBeMoved 0x2e73a0 and the
worn-item test in VisitWornItems 0x237300.

**2. A shared conditional jump merged in the wrong place: reorder a two-way check.** (high)
Symptom: in an "already open?" check over two fields, the candidate merges the two tests' jumps
or puts the arguments of the following call in a different order. Fix: test the non-thread-safe
branch first, with early returns
(`if (!g || !flag) { if (file) return; } else if (handle) return; Open();`), and keep a single
call site. Two call sites, a ternary, or a bool helper that yields `setne` do not match. Closed
TESFile::Seek 0x1cd860 and Duplicate 0x1ce7e0, which share the helper.

**3. A dead loop or a redundant test in a loop: an inlined helper was called twice.** (medium)
Symptom: the target has a loop that is not rotated, a computed value that is never used, and a
null test that repeats. Cause: a null-checking helper is called in both the loop condition and the
body: `while (Root(p->parent)) p = Root(p->parent);`. Fix: write it that way rather than with one
cached call. Closed Duplicate 0x1ce7e0. A helper that includes the null test
(`return object && object->GetRTTI() == rtti;`) in the loop body also removed a loop-head alignment
pad that four loop spellings (for, while, `continue`, a helper) kept:
BSMasterParticleSystem::IsMasterParticleSystem 0xffbcf0.

**4. A computation hoisted above a check: the source computed it first, or the predicate is a
helper called twice.** (medium)
Symptom: in the target a load or an address computation comes before a flag test, and the same
test appears twice. Fix: put the test in a small predicate (`IsCompressed()`) and call it at both
places. Load the limit and compute the position in source order before the second test. Closed
SeekNextSubrecord 0x1cdc60.

**5. A live argument register at a call means the callee takes that argument.** (high)
Symptom: argument registers are shuffled at one call (for example `this` in r8, an offset in
ecx), and a register the candidate does not set (here edx) still holds an earlier value. Fix:
capture that value before the intervening test and pass it as an extra parameter of the matching
width (here the 1-byte form type). Closed HasQuestObject 0x2e5a60. Check every call whose
argument setup differs for a value the target leaves in rdx, r8 or r9.

**6. Register differences in a switch: change the width of the switch operand.** (medium)
`switch (static_cast<std::uint32_t>(byteField))` and switching on a byte enum give different
register allocation and different zero-extension placement. Try both. Closed VisitWornItems.

**7. A missing shared constant: put the value-producing branch in its own helper.** (medium)
Symptom: the target materialises `-1` once and reuses it for both the compare and the result.
Fix: `int32 mask = -1; if (slot != -1 && slot < 10) mask = table[slot]; return mask;` in a helper.
An explicit `case kLight: mask = 0;` keeps a separate case where the default would otherwise
absorb it. Closed VisitWornItems.

**8. A jump that skips the caller's fallback: an early `return false` inside a bool helper.**
(medium)
Symptom: one target path jumps straight past a fallback test (`|| object->type == kLight`) that
the candidate evaluates. Fix: wrap the whole decision in a bool helper, so the null-object path
returns false before the fallback. Closed VisitWornItems.

## Data and calls

**9. Uninitialised locals are part of the source.** (medium)
Symptom: the candidate has an extra zero store to a stack slot that is later passed by address.
Fix: drop the initialiser (`char* message;`) when a callee fills it and the value is only
released. Closed Seek 0x1cd860.

**10. `delete p` called through the scalar deleting destructor with flag 1: the class has its
own operator new/delete.** (high)
Symptom: the target calls one function with edx = 1 where the candidate calls the destructor and
then `operator delete(p, size)`. Fix: declare class-scope `operator new`/`operator delete` (Bethesda
heap classes have them) and bind the deleting destructor to the target's callee. Inside a `try`
region MSVC splits the call again. Seen in RemoveFavorite 0x237a20.

**11. Missing virtual slots shift every virtual call.** (high)
A call through slot N needs N - 1 earlier virtuals in the stand-in, including the inherited
TESForm slots; add placeholders labelled GUESS. Used for CanBeMoved (slot 0x42).

**14. A vtable slot 0 destructor is the deleting destructor, `??_G` (or `??_E`), not `??1`.**
(high)
Symptom: `function-size-mismatch` on `X::~X`, the target larger than the candidate, its listing
testing bit 0 of the second argument and calling operator delete under it. The compiler always
emits the plain `??1` separately; the slot body is `??_G` with the destructor inlined, emitted
only beside the vftable, so the unit must define a constructor (or otherwise reference the
vftable). `attempt` reads the kind from the pack (`task.json` `functions[].destructor`) and binds
it; a bind hint it cannot use is printed as a WARNING. Closed TESGrass 0x270890.

**15. An inlined map lookup matches through a bool helper that writes its out-parameter only on
a hit.** (medium)
Symptom: the target's inlined lookup leaves the caller's local untouched on a miss, where a
candidate returning the value (or a default) stores on both paths. Fix: write the lookup as
`bool Find(key, T& out)` that assigns `out` only when found and returns whether it did.

**16. A flag bit tested as load, `shr`, `test al,1`: a by-value bit-index helper.** (high)
Symptom: the target reads a flag word into a register, shifts it right by the bit number and
tests the low byte (`mov eax,[rcx+0x10]; shr eax,3; test al,1`); the candidate has
`test byte ptr [mem],imm`, `test dword ptr [mem],imm` or `bt`. Cause: MSVC folds every mask, bit-field
or direct `(flags >> n) & 1` spelling of the member into a memory test; the shift survives only
when the word and the bit number reach the test through an inlined call. Fix, first thing to try:

```cpp
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}
... if (TestBit(formFlags, 3)) ...
```

For a bit-field struct, pass the whole word (`*reinterpret_cast<const std::uint32_t*>(&flags)` in
a small accessor). A bit-0 test the target does as `movzx eax, byte ptr [mem]; and al,1` is the
same helper on the low byte. The label is `GUESS(low)`: the helper's name and the engine's real
accessor are unknown. Its probable origin is a flag accessor that takes a bit index (the shape
says index and shift, not mask), not the community wrappers: `stl::enumeration::any()` and
`REX::EnumSet::any()` test `(_impl & mask) != 0`, the expression that folds (not tried as a
by-value copy). Closed Character::SetCrimeFaction 0x67eab0, TESObjectCELL::GetLocation 0x2bb180
and NiNode::OnVisible 0xee2cc0; 0x3299f0 closed with the whole 32-bit member as the word (a byte view did not), and 0x3bfc00 with
a by-value clear-bit helper that keeps the complement inside the helper. It also fixed the flag tests
of NiNode::UpdateDownwardPass
0xee24d0 and TESNPC::ClearData 0x3bbf50, which still differ elsewhere (rules 19, 20).

**17. `static_assert` needs a message.** (high)
The recipe compiles as C++14 (no `/std:c++17`), so `static_assert(sizeof(X) == 0x10);` is a
compile error. Write `static_assert(sizeof(X) == 0x10, "size");`.

**18. A deleting destructor that calls the plain one: declare `~X();` and do not define it.**
(medium)
Symptom: the target's `??_G` calls the plain destructor; the candidate's `??_G` inlines a vptr
store and the base destructor calls instead. Cause: defining `~X()` in the unit lets the compiler
inline it into `??_G`. Fix: declare the destructor out of line without a definition and bind
`??1X@@...` to the target's callee with a bind hint; the `??_G` is still emitted beside the vftable
(rule 14). Closed Character's destructor 0x73abc0.

**21. A read through `gs:[0x58]` indexed by `_tls_index` is a `__declspec(thread)` variable.**
(medium)
Symptom: the target loads `_tls_index`, reads the TLS array at `gs:[0x58]`, indexes it and adds a
small constant, the variable's offset in the TLS template; an ordinary global gives a `REL32`
where the target has that constant, and an intrinsic `__readgsqword` read changes the frame and
registers. Fix: declare `extern __declspec(thread) T name;` (a thread-safe function-local static
reads the CRT's `_Init_thread_epoch` the same way) and bind it with the hint
`{"<decorated name>": "tls:0x<offset>"}`; `_tls_index` needs no hint. Give each variable one name
and offset for every function that uses it. Compared from comparator 0.5.0 on (earlier:
`unsupported-relocation` SECREL).

When the value is saved, set for the body, and restored afterward, represent its lifetime with
an inline scope guard, rather than restoring it only on the normal return path. Its destructor
must also restore it while unwinding. Match the loaded width, the written value, the scope entry
and the order of the other destructor-bearing locals. For example, with all helper names labelled
`GUESS(low)` in a reconstruction:

```cpp
extern __declspec(thread) std::uint32_t activeTag;
class TagScope {
public:
    explicit TagScope(std::uint32_t value) : saved(activeTag) { activeTag = value; }
    ~TagScope() { activeTag = saved; }
private:
    std::uint32_t saved;
};
```

Instantiate at the observed entry with the observed value; use another instance for a nested
save/restore. A separately read TLS flag needs its own variable and binding, not another guessed
use of this slot. This shape passed BGSKeyword::Load 0x391fe0 (299/299, unwind covered) and its
accepted regression in a fresh one-host attempt; that is a source-shape observation, not acceptance.
The same guard closed Actor 0x6d9f20 (120/120), where the candidate's only differences were a
permutation of the three callee-saved roles and the TLS offset form; the plain save, loop, restore
version did not. TESForm 0x1e6930 and 0x1e5b30 remain separate, unclosed functions.

**22. A callee's out-parameter below an 8-byte temporary in the home slots is a small type.**
(medium)
Symptom: the target passes the addresses of two locals to a call and the one the callee writes
sits in a lower home slot than an 8-byte key temporary; the candidate swaps them. Cause: locals
passed by address are packed by size, 1 to 4 byte locals in lower slots before 8-byte ones,
whatever the declaration order. Fix: make the out-parameter `bool` or `std::uint32_t` (here an
`inserted` flag), not a pointer or an 8-byte value; declaration order, wrappers and by-reference
or by-value spellings do not move the slots. Fixed NiObject::ProcessClone 0xedca00 in a one-host
attempt (not yet confirmed on two hosts).

**23. A member the target loads after a null test is read after the test.** (medium)
Symptom: the candidate loads a field into a register before a null test of another value; the
target loads it only on the path after the test. Fix: read the member inside the `&&` or the
block that follows the test instead of caching it in a local first (`if (!result &&
encounterZone) { auto* zone = encounterZone; ... }`). The same family as rule 1, seen from the
other side. Fixed TESWorldSpace::GetLocationFromPosition 0x310ff0 in a one-host attempt (not yet
confirmed on two hosts).

**24. An inlined 3-byte copy: two `memcpy` calls, 2 bytes then 1, from one source pointer.**
(medium, one observation)
Symptom: the target copies three bytes out of a buffer as a 16-bit move and a byte move, both
addressed from one computed source pointer. Three single-byte assignments fold into indexed
addressing off the buffer base instead. Fix: compute the source pointer once
(`const std::uint8_t* src = base + position;`) and write `std::memcpy(&out, src, 2);
std::memcpy(&out.third, src + 2, 1);`. Closed BGSLoadGameBuffer::ReadFormID 0x637ab0 in a one-host
attempt (not yet confirmed on two hosts).

**25. A `??_E<Class>@@W<n>@...` destructor is an adjustor thunk: give the unit the whole base set.**
(medium, one observation)
Symptom: the compared destructor is a few bytes that adjust `this` by a secondary base's offset and
jump to the deleting destructor; `attempt` reports it `UNBOUND` or binds nothing at that RVA.
Cause: MSVC emits the thunk only beside the vftable of that secondary base, so the class must have
every base of the image's multiple inheritance at its offset (stand-ins are enough). Fix: declare
all bases in the image's vftable order, define a constructor (rule 14) and the destructor (an empty
body), and bind the thunk's decorated name (`??_E...W...`, from the compiled object) with a hint;
binding the deleting destructor it jumps to as well helps. Closed BGSMovableStatic 0x264444 in a
one-host attempt (not yet confirmed on two hosts).

**26. `eh-funclet-extent`, `eh-funclet-entry-inside` and `FuncInfo.n_ip_map`.** (medium)
From comparator 0.6.0 a funclet packed against another function's funclet passes when its bytes
match: the image's own `.pdata` or the other FuncInfo proves where it ends. So
`eh-funclet-extent` now means the candidate's funclet is shorter than the target's, and
`eh-funclet-entry-inside` that it is longer; `unwind-entry-crosses-boundary` on a funclet means
the target's funclet has a frame and a call (its own `.pdata`) where the candidate's is a leaf,
for example a `new` whose constructor can throw and whose cleanup calls a sized
`operator delete`. All three are fixed from source by changing what the cleanup does. An
`n_ip_map` count lower than the target's, with identical instructions, means the target treats a
call as able to throw where the candidate does not. Likely cause (untested): the callee is
defined in the same unit, so the compiler sees it cannot throw and drops its IP-to-state entry.
Seen in TESObjectREFR::PopulateGraphNodesToTarget 0x2fd4f0, whose missing entry is at its call to
Get3D2, which the unit also defines (not yet closed).

**27. `__declspec(noinline)` stands in for a translation-unit boundary, nothing else.** (policy)
The one-unit-per-class layout puts functions in one file that the image built in separate units,
so the compiler may inline a callee the image calls. `__declspec(noinline)` is acceptable only
when the callee has its own out-of-line body at its own RVA in the image and the compared
caller reaches it there by a call or a jump. Its comment says it stands in for that boundary
(`// noinline: own body at its own RVA; the image calls it from GetScale`). When the callee is
not itself compared in the unit, prefer declaring it without defining it: the call stays a
call and no attribute is needed. An attribute whose callee no longer has a caller in the unit
is removed. Using it to change the caller's code in any other way is "to match" and is rejected.

**28. Destructor vptr stores need typed component subobjects.** (medium)
Several stores to different offsets of `this` identify separate polymorphic subobjects. Use RTTI
and declarations to distinguish bases from polymorphic members. Preserve the bases, their order,
their observed sizes and the primary base's virtual slots. A padding array of the same total size cannot produce their destructor cleanup or secondary vftables.
Give the derived class a constructor so the compiler emits its deleting destructor (rule 14).

Distinguish each base cleanup from the listing: an out-of-line destructor call needs a declaration
and binding; inlined cleanup needs an inline body in this unit, with its members represented by
actual types whose destructors perform the observed cleanup. An empty component destructor can
still store its own vftable before member destruction and its base's vftable afterward. Do not
replace these transitions with explicit vtable writes. Keep a called base destructor out of line,
and keep an inlined empty base cleanup inline; a small inline out-of-class definition can supply
that body locally without editing the shared declaration. This is justified only by the cleanup
the listing shows. C++ destroys members and bases in reverse construction order.

Restoring TESFullName and TESTexture at TESEyes' observed subobject offsets closed the deleting
destructor 0x3b32b0 (126/126, unwind covered), while Load 0x3b2fc0 (429/429) and the accepted
InitializeData regression still passed in the same fresh one-host attempt. Its texture destructor
stays an external call; full-name string cleanup and the empty BaseFormComponent cleanup inline.
This is one proving unit, not a promise that every multiple-inheritance destructor shares that
cleanup. BSPathing is a composition case: the pinned powerof3/CommonLibSSE `BSPathing.h` declares
a polymorphic FindTriangleForLocationFilterCheckDeltaZ member after its own vptr. Making that
filter a base would share the primary vptr and lose the observed member offset. A new
inventory-named base definition still needs a passing comparison; declare an existing external
constructor instead of emitting a partial local version.

**29. Callee-saved stores that skip the first home slot: name the decremented reference count.** (high)
Symptom: the prologue saves callee-saved registers from the second home slot on and never uses
the first, while the rest of the body matches; the function inlines an intrusive reference-count
release. Cause: when the inlined release keeps the decremented count in a named local before
testing it (`std::uint32_t count = _InterlockedDecrement(&_refCount); if (count == 0) DeleteThis();`),
the compiler reserves the first home slot for that local and then needs no memory for it. The
same release written as one expression (`if (_InterlockedExchangeAdd(&_refCount, -1) == 1)`,
`if (_InterlockedDecrement(...) == 0)` or a helper returning the call) saves into the first slot.
Generated code is otherwise identical, so the change belongs in the shared release helper. Closed
CopyMembers, ClearTextures and ComputeCRC32 members of five lighting material classes; companion
functions compiled from the same header kept identical code. Rule 12's lock functions and rule 13
are not explained by it (they inline no release). When three or more inlined releases store null
and `this` and the -1 constant swap registers, see rule 30.

**30. Releases that store null with `this` and the -1 constant swapped: assign a raw null pointer
through the generic assignment.** (medium)
Symptom: a run of smart-pointer clears (`ClearTextures`) matches except that `this` and the -1
release constant sit in each other's callee-saved registers, and the candidate builds the -1 as
`lea r, [zero - 1]` where the target writes `mov r, 0xFFFFFFFF`. Cause: a `nullptr_t` overload
(`if (_ptr) { old = _ptr; _ptr = nullptr; release }`) lets the compiler derive the -1 from the zero
register. Fix: clear each pointer through the generic raw-pointer assignment, with a null argument:
`if (_ptr != p) { if (p) p->IncRefCount(); T* old = _ptr; _ptr = p; if (old) old->DecRefCount(); }`.
Keep rule 29's named count in the release. If the shared header must stay unchanged, define the
assignment as a small template helper in the unit. Closed BSLightingShaderMaterialBase::ClearTextures
0x1523e50 in a one-host attempt. The other variants tried here, a `nullptr_t` overload, `reset()` with
release then store, and store then release, all kept the swap.

**31. Immediate versus xor-zero stores, or a constant store scheduled above the vptr store: default-construct
smart-pointer members.** (medium)
Symptom: a constructor that zeroes pointer members and stores float constants differs only in
scheduling: one 1.0f store moves above the vtable store. Or a `Create` that inlines the constructor
stores immediate zeros where the out-of-line constructor stores a zeroed register, and no single
spelling gives both. Cause: value-initialising a smart-pointer aggregate (`member{}`, `member()`)
or assigning its field in the body is lowered differently from a pointer whose own default
constructor sets it. Fix: give the smart pointer a non-trivial default constructor, for example NG's
`T* _ptr{ nullptr };` default member initializer, leave those members out of the init list, and
initialise the scalars in the init list. Closed BSLightingShaderMaterialEnvmap::Create 0x1524b80, with
its accepted constructor 0x1524a60 reproduced by the same source in a lab compile, and the
BSLightingShaderMaterialMultiLayerParallax constructor 0x15281a0, both in one-host attempts. When the
shared header's pointer is an aggregate, put the class in a standalone unit rather than change
the header under other accepted units.

The same fix applies to any sub-object whose stores the target schedules as a unit: give it its own
inline constructor or member function and let the owner call it. A list member whose constructor
clears its count before the two pointers (NiParticleSystem 0xf99cb0), a spline basis template with its
own constructor (NiBSplineBasisData 0xf769a0), and a pair of floats built by a two-argument
constructor and assigned from a temporary, with the flag OR in a `set` member (0x80a250), each moved
the displaced store into place; assigning the members from the owner's body did not. A base class
declared `__declspec(novtable)` with a pure `GetType` and an inline constructor closed
ExtraInteraction 0x18c280, where the target stores the base's zero field before the vtable (changed
together with reading `a_rhs.ptr` in the pointer copy).

**32. One 16-bit immediate store over two members: two adjacent bytes.** (medium)
Symptom: the target clears a 16-bit field with `mov word ptr [m], 0`, and the candidate writes it from
a zeroed register (`xor eax, eax; mov word ptr [m], ax`), so it is shorter. Cause: a 16-bit member
(`std::uint16_t`, `std::int16_t`, a wrapping struct) shares the zero register with the
neighbouring stores. Two adjacent `bool` (or byte) members merge into one immediate word store.
Fix: declare two byte members. Closed BGSSceneActionTimer::Unk_0D 0x3ad170 in a one-host attempt.

**33. The argument of the next call comes from `rax` after a constructor-like call: a by-value return.**
(medium)
Symptom: the target builds a temporary in a stack slot (`lea rcx, [rsp+n]; call X`), then passes
`rax`, the callee's return, to the next call (`mov rdx, rax`). The candidate passes the temporary's
address again (`lea rdx, [rsp+n]`). Cause: a constructor call does not tell the compiler that `rax`
holds the object, but a by-value return through a hidden return pointer does. Fix: produce the
temporary with a function returning the type by value (`member = Make(a_str);`). Label it GUESS,
because the image function may be the type's constructor. Closed BGSKeyword::SetFormEditorID
0x29e720 in a one-host attempt.

**19. A struct copy whose last store moves one slot earlier: read the scalar first, copy the
sub-object through references.** (medium, one observation)
Symptom: copying a bound (three floats then a float radius), the target loads the radius early
and stores it last; the candidate stores it one store earlier than the source order, whether the
radius is cached in a local or stored before the last centre component. A direct
`radius = other.radius` and a `center = other.center` struct copy change more (a wider move). Fix:
`const float radius = src.radius; NiPoint3& destCenter = dest->bound.center; const NiPoint3&
center = src.bound.center; destCenter.x = center.x; ...; dest->bound.radius = radius;`, with the
base copy called as the real member (`NiNode::CopyMembers(dest, cloning)`) rather than a
free stand-in bound by address. Both changes were made together, so which one matters is unknown.
Closed BSOrderedNode::CopyMembers 0x1570240. Not closed: NiNode::UpdateDownwardPass 0xee24d0
(code-byte-mismatch, two stores swapped), which has not been tried with this spelling.

**34. Exits that differ only in register choice, select form or epilogue sharing: one result local,
one return.** (high)
Symptom: the instruction set is the same or one off, and the target ends in a conditional move or a
shared zero/true block where the candidate has a set-on-condition, a duplicated epilogue, an
inverted last branch, or keeps a pointer or null in another register. Cause: early returns,
`return a ? b : c` and value-returning helpers hand the optimiser separate exits. Fix: declare the
result first and assign it on every path, with one return at the end:

```cpp
bool result = false;
if (state == kA) {
    result = true;
} else if (other && other->Test()) {
    result = true;
}
return result;
```

A switch assigns the result in each case and `break`s, with no `default` (or a `default: break;`,
or the result preset before the switch); a switch that returns directly closed with an explicit
`default: return -1;` inside the switch and typed enum labels, where the same return after the
switch did not. Keep an early return only on a path that leaves through a different epilogue, such
as a tail call (0xa00860). Tried first and not enough in every case: early returns, ternaries, a
helper returning the value, a bool helper. Closed 0x86aa30, 0x8f1bd0, 0xa00860, 0x152340,
0x8f26a0, 0x868df0 (`result = true` instead of `return true` was the whole change), 0x6cb940,
0x6767e0, 0x6af050, 0x301a20, 0x6744d0 and 0x6c6380 (the last under the `o2-fpfast` recipe); the
switch-returning form is 0x184ab0.

**35. A loop that stops on a found result: put the result in the loop condition; clear flags with
`if`.** (medium, two observations)
Symptom: the candidate rotates the loop with a pre-test where the target tests the index at the
top, or a counter increment lands after a conditional move instead of before the element loads.
Fix: `for (i = 0; !sound && i < count; ++i) { if (entries[i].id == id) sound = entries[i].sound; }`
(0x14b570), and `if (a[i] != b[i]) equal = false;` rather than `equal = same ? equal : false;`
(0x183b40, where that was the only change). Not enough for 0x1d89e0 (see Unsolved).

**36. Walking a linked list: take a reference to the element, advance, then use it.** (medium)
Symptom: the loop matches except for one missing instruction and the order of an argument move.
Cause: the target keeps the element address computed before the position advances. A helper
that returns the element and advances through an out-parameter (`GetNext(pos, &pos->data)`)
scored the same 93 of 104 bytes in four attempts. Fix: read the context value into a local before
the loop, then `const Ref& item = pos->element; pos = pos->next; item->Visit(ctx, a, b);`. Closed
NiParticleSystem 0xf999c0 (promoted from idea A below).

**37. A flag word loaded, edited in a register and stored once.** (low, two observations)
Symptom: the target does one load and one store of the word; the candidate emits two read-modify-write
operations with another load between, or hoists the load above a branch. Two spellings each closed
one function: the word declared `volatile` with one assignment expression
(`flags = (flags & ~kClear) | kSet;`, 0xfddba0), and, for a word tested under a branch, member helpers
on the pointed-to struct, a clear that returns whether anything was set and a set by slot, with the
null test of the struct inside each branch (0x14e77b0). `volatile` alone did not close 0x14e77b0, and
setter, by-value helper and temporary spellings did not close 0xfddba0.

**38. A compare whose width or sign decides the branch form.** (medium)
Symptom: size off by a few bytes with the same control flow, a mask kept in a wider register, or a
condition inverted. Fixes that each closed one function, each after other spellings failed:
cast the masked value to the field's width, `static_cast<std::uint16_t>(x & mask) == value`, in place
of a helper taking the mask and value (0x674250); write the mask as a signed 64-bit constant in
`(flags & kMask) <= 0` (0x1519980); widen a byte field to `int` before a range test (0x868df0,
0x41efc0); test two values that differ in one bit as `((x - a) & ~bit) == 0` on an `int` (0x41efc0).
In rule 16's helper, pass the whole 32-bit member, not a byte view of it (0x3299f0).

**39. `delete` after an inlined release adds a null test: delete a local copy.** (medium)
Symptom: the candidate has an extra null test before the operator delete that the target lacks.
Cause: `if (ptr && ptr->DecRef() == 1) delete ptr;` re-reads the member, and a reload is a new
value (rule 1, from the other side). Fix: `T* object = ptr; if (object && object->DecRef() == 1)
delete object;`. Closed ExtraAnimGraphManager 0x18ed10 (with an inline defaulted destructor) and
the release at 0x7aa7e0.

**40. A null path threaded straight to the exit, where the target keeps a zero and tests it again:
pass the value through an inline accessor with its own null test.** (low, one observation)
Symptom: the candidate sends the null-process and null-entry paths directly to the zero return.
Fix: `InventoryEntryData* entry = GetCurrentAmmoEntry(); TESForm* form = entry ? entry->GetObject() :
nullptr; if (form && form->IsAmmo()) return ...;`. Closed Actor::GetCurrentAmmo 0x6cc700. Not tried
on the same symptom in 0x64d290 and 0x14e70b0.

## Shaping ideas from one contributor's cheap-model runs

These are observations from one contributor's drafting runs with a cheap model, not rules.
Items A to D each helped close at least one near-miss there; E is a way of working. The project
has not checked them. Treat each as a hypothesis and try it when a candidate is close. A
comparator pass is the only evidence. The names below (`Node`, `list`, `value`) are invented
examples. (low)

**A. Walking a linked list.** Confirmed by a pass; see rule 36.

**B. Give each value its own local, declared just before its write.**
Symptom: stack offsets differ because the candidate shares one slot between values. Fix: copy
each value into its own local, declared right before the statement that writes it
(`std::uint32_t count = list.count; Write(count);`). Do not reuse one local for several values.

**C. Write an inner search as a small helper that returns.**
Symptom: the jumps of a nested search loop merge in a different place from the target's. Fix: move
the inner loop into a small helper with `return true` on a hit and `return false` after the loop
(`bool Contains(const List& list, const Key& key)`). The caller then tests its result. Label the
helper name `GUESS(low)`: the original may have inlined it.

**D. A callee argument that fills a full 32-bit register may be a 32-bit integer, not `bool`.**
Symptom: the target sets the whole 32-bit argument register, where the candidate sets a byte.
Fix: try `std::uint32_t` (or an enum), and label the type `GUESS(low)` unless other evidence pins it.
A changed signature has a new decorated name, so bind the new name to the target's callee with a hint.

**E. Check the size difference first.**
A difference of a few bytes (4, for example) is often one missing or extra instruction. Look for that instruction (an unused address computation, a store, a
register move) before you rewrite the logic.

## Unsolved patterns

**12. A pure callee-saved register swap with the same instructions.** (low)
Symptom: every instruction matches except which callee-saved registers hold `this` and a loop
counter. The comparator reports unwind-info-mismatch at +0x0 with equal sizes. In this recipe,
about 45 source spellings never move `this` out of rbx. Only spellings that add counter
references flip it, and those add instructions. Whole-program optimization is refuted as the
cause, and so are the swept flags: `/GL` linked `/LTCG` gives byte-identical code for these
sources, and no profile data exists ([finding](../findings/whole-program-optimization.md)).
For the variant whose saves skip the first home slot, see rule 29. Otherwise cause unknown. Untested hypotheses from that finding: EH state removed after frame layout (a
`noexcept` or `throw()` helper whose throwing path folds away), or frame layout kept from dead
code (a parameter or `this` whose address is taken and then optimised out). Seen in
BSReadWriteLock::LockForRead 0xce3250 and LockForWrite 0xce32d0, and in the same form in 0x2bccc0,
0x6d6820, 0x6ff0e0, 0x727bf0, 0x32c260 and 0x3c62f0 (eight functions; a plain save and restore, an
RAII guard struct and a reference with an explicit null check were tried on 0x2bccc0). When the
function saves, changes and restores a thread-local, the guard of rule 21 closed the same
symptom in 0x6d9f20, and rule 34 closed a swap of the null and pointer registers in 0x6767e0,
0x301a20 and 0x6af050.

**13. A -2 store to the UnwindHelp stack slot, eager saves of callee-saved registers, and no EH handler.** (low)
Symptom: the prologue stores the C++ EH UnwindHelp slot and saves rbx/rbp/rsi/rdi before any
early return, yet the unwind info has flags 0. Because shrink wrapping is off, every register
differs from a candidate that does not use EH. In lab compiles, a destructor-bearing local around
a throwing call keeps a handler. Locals whose scope has no throwing call, noexcept or throw()
helpers, and try/catch all either drop the -2 store or keep a handler; so do the same guards
under `/GL` and `/LTCG`. Whole-program optimization is not confirmed for RemoveFavorite and
refuted for the other near-misses measured ([finding](../findings/whole-program-optimization.md));
cause unknown. The 151 image functions with this shape cluster by address. Untested hypotheses
from the finding: EH state removed after frame layout (a `noexcept` or `throw()` helper whose
throwing path folds away), or frame layout kept from dead code (an address taken and then
optimised out), tried first on one dense run. Seen in RemoveFavorite 0x237a20 and, as a recursive list-node
destructor (a scalar-deleted node, an exception-state slot, no handler), in 0x346700, 0x346780,
0x346800, 0x3244a0 and 0x14c550, where `noexcept(false)`, a non-destructor form and a scalar-deleting
variant did not add the state; four more of the same shape (0x346880, 0x395320, 0x1f0840, 0x7e99a0)
were not attempted. Triage these instead of drafting them.

**20. A pointer loop that the compiler turns into a counted loop.** (low)
Symptom: the target walks an array with `it != end` (two callee-saved registers, no trip count);
the candidate computes a trip count with `lea`/`shr`/`cmova` and needs two more callee-saved
registers, so the prologue differs. A raw pointer loop and a range-for over `begin()`/`end()` both
give the counted form; `if (count)` before the loop and a `do`-`while` did not help either. Not
closed: TESNPC::ClearData 0x3bbf50 and the entry-array visitor 0x397810.

**41. Repeated tests of one value folded into a single test.** (low, four functions)
Symptom: the target tests the same loaded word or pointer more than once (three separate masks of a
state word, three form-type compares, a parent null test plus a use-flag test repeated through an
inlined helper) and the candidate always folds them into one subtract-and-test or one test. About 40
spellings did not help on Character 0x6a1120 (bit-field, raw masks, shifts, signed fields, struct
copies, helpers, switch, loops, base-class views); switch, `||` and early returns did not help on
0x1e9fc0; calling the helper twice did not help on TESWorldSpace 0x30dad0 and 0x30e140. The local
copy with plain comparisons that closed SetAlpha 0x14e7f40 (`const float old = alpha;` tested with
`old >= 1.0f` and `a < 1.0f`) has not been tried on them.

**42. Two operands loaded or stored in the other order.** (low, five functions)
Symptom: every instruction matches except that two loads or two stores come in the opposite order,
or a compare's operands flip. Local-variable orderings, direct stores, a `const` and a non-const
local, a reference parameter, a hoisted declaration, signed and unsigned types, local copies, and
initialiser-list versus body assignment all failed on 0x1812d0, 0x1892e0, 0x449390, 0x639a20 and
0xf857d0 (the last loads a 16-byte value right after the base constructor call, before the vtable
store). Try rule 31's sub-object constructor first.

**43. A set-on-condition where the target uses a conditional move, and the bare-return idiom.**
(low, five functions)
Symptom: the target returns from a both-null path with an unshared return and shares one true block
at the end, or keeps a preset zero and selects with a conditional move; every spelling tried emits a
set-on-condition, a duplicated true block or an extra jump. Tried: an explicit result flag, references,
pointers, a struct array, two arrays, loop counter signedness. Seen in 0x186670, 0x186370, 0x18b1c0,
0x41f410 and 0x2f3da0 (which keeps a constant true in a callee-saved register). Rule 34 closed the
same symptom in twelve other functions; it is not recorded as tried on these.

**44. A find loop whose index increment and found register differ.** (low, five functions)
Symptom: the target copies the index before incrementing, tests a found flag at the loop top and
re-compares the last element after the loop; the candidate strength-reduces to a pointer, hoists the
increment or swaps the index and result registers. A flag loop gave a register swap and a last-element
loop gave a widened copy of the counter. Seen in 0x1d89e0, 0x3cc660, 0x727bf0, 0x6ff0e0 and the nested
search 0x3e8380. Rule 35 closed a found-in-condition loop with a different exit.

**45. Float code: loads of the operands before the first compare.** (low, five functions)
Symptom: the target loads all the source floats (or computes both centres) before the first compare,
the candidate loads them one at a time and the operand order follows the source order; the
short-to-float conversion differs between the default and `o2-fpfast` recipes. Source reordering did
not converge on 0x518a30, 0x191710, 0x18a8c0, 0xbafa60 and 0x3c7460.

**46. A tail call where the target calls, or the reverse.** (low, three functions)
Symptom: the final call of the candidate becomes a jump where the target keeps a normal call
(BSWaterShaderProperty::ForEachTexture 0x152ce50), or the target jumps to the sink's slot although a
stack local's address went to the previous call and MSVC emits a call and a return for every variant:
void and bool returns, a hidden-return temporary (0x7a3ec0). Also 0x3c62f0 (the template pointer
sits in another register for the tail call).

## Method and permuter recommendations

The permuter that mechanises rules 1, 2 (inversions only), 6 and 9 is
`tools/verifier/permute.py`; see [permuter.md](permuter.md) for its rules and measured yield.

- Compile many variants per attempt: temporary `LabNN` members with candidate bodies in the same
  unit, one `attempt`, then score each variant locally against the normalised pack listing
  (relocations masked, branch targets as `T`). Strip lab code before the final attempt; only a
  real `attempt` pass counts. A permuter should use this as its inner loop (10 to 20 per compile).
- Generate variants as AST rewrites from the rules above, not random token edits: reload or cache
  a member (1), flip a two-way check (2), duplicate or merge a helper call (3, 4), add the live
  argument (5), change the switch width (6), extract a value or a bool decision into a helper
  (7, 8), drop an initialiser (9), add class operator new/delete (10), route a flag test through
  a by-value bit-index helper (16).
- Score the prologue and unwind info apart from the body. A register-only diff with identical
  mnemonics (12) or a -2 UnwindHelp store with no handler (13) should stop the search and go to
  triage: no source permutation tried here changes them.
- Reject variants that add code only to steer register allocation (rule 12's counter tricks),
  even when they score higher.
- Watch inlining: extra lab copies can stop a helper being inlined, so a variant that shrinks
  sharply must be rescored alone (`__forceinline` is acceptable in lab code only).
