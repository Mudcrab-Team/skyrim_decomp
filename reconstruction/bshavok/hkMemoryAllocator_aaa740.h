// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkMemoryAllocator: CRASHLOGGER_PDB(59818@2026.10.24)
// hkMemoryAllocator::bufRealloc_1409CE7B0: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

struct SFun00cbf280Args;


/*
 * worker/candidate.cpp — DRAFT ONLY.
 * Not compiled, not compared, no MATCH claimed. Parent owns verification.
 *
 * Unit: pack/pack.json symbol bufRealloc_1409CE7B0, 67 bytes, member of a
 * five-slot class, three stack parameters, returns a pointer, cleans 0xC.
 *
 * Every identifier below is a placeholder chosen for readability. The binary
 * carries no type, field or method names. The prose describes what the unit
 * provably does (which values reach which callee) and what that most likely
 * means; the two are kept separate and the guesses are marked as guesses.
 */

/*
 * Free helper reached by the unit's only non-virtual call.
 * Canonical mangled symbol: ?Func00d2caa0@@YAXPAX0I@Z
 *   @@YAX      -> , returns void
 *   PAX, 0     -> void *, void *   (0 back-references the first void *)
 *   I          -> unsigned int
 * so the declaration must be exactly this: a plain C++ free function, not an
 * extern "C" block and not a CRT intrinsic. Its own body is out of scope here;
 * the call site hands it a destination, a source and a byte count, which is
 * consistent with a bounded copy (inference, not verified).
 */
void Func00d2caa0(void* dest, void* src, unsigned int count);

/*
 * Block passed as the unit's third parameter.
 * The unit forwards the pointer unchanged to the slot +0x0C method and, after
 * that call returns, reads the dword at +0x00 of the same block as a signed
 * bound. Whether the block is a plain struct or has its own vptr at +0x00 is
 * not decidable from this unit; a named field is the narrower assumption, so
 * it is used here.
 */
struct SFun00cbf280Args
{
    int limit; /* +0x00: caller-supplied byte bound, read signed */
};

/*
 * Owner class of the unit. The five declarations place the two methods the
 * unit actually calls at byte offsets +0x0C and +0x10; slots +0x00, +0x04 and
 * +0x08 are declared only to hold that layout and are never invoked here.
 * Slot +0x00 is modelled as the destructor, which is the usual MSVC arrangement
 * (inference: this unit gives no evidence about it).
 */
class hkMemoryAllocator
{
  public:
    virtual ~hkMemoryAllocator();

    /* +0x04, +0x08: unknown, unreferenced by this unit. */
    virtual void* VtblSlot04();
    virtual void VtblSlot08();

    /* +0x0C: takes the argument block, returns a writable destination. */
    virtual void* Reserve(SFun00cbf280Args* args);

    /* +0x10: takes the source and the originally requested size; the unit
     * discards whatever it returns. */
    virtual void Commit(void* src, int size);

    /* The unit itself. Non-virtual: it is entered directly, not through a slot. */
    void* bufRealloc_1409CE7B0(void* src, int size, SFun00cbf280Args* args);
};

/*
 * Body, in the order the effects are observable:
 *
 *   1. Reserve(args) is called first and its pointer result is kept alive for
 *      the whole function; it is what gets returned.
 *   2. args->limit is re-read *after* that call, so the unit deliberately
 *      honours a limit the callee may have adjusted. It is then clamped
 *      against the caller's `size` with a signed comparison, i.e. the smaller
 *      of the two wins.
 *   3. Func00d2caa0 receives (destination from step 1, src, clamped count) in
 *      that positional order.
 *   4. Commit(src, size) is called with the *unclamped* size, and its result is
 *      dropped.
 *   5. The destination from step 1 is returned.
 *
 * Read as a whole this looks like: ask the owner for somewhere to put data,
 * copy at most min(size, args->limit) bytes of `src` into it, tell the owner
 * how much was asked for, and hand the buffer back. The "looks like" is
 * deliberate — the semantics of Reserve, Commit and the helper are not
 * established by this unit.
 */
