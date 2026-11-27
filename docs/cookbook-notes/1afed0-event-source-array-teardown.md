# 0x1afed0 Event-source array teardown

<!-- tags: construct/destructor -->

- Function: 0x1afed0 Event-source array teardown
- Label: GUESS(low)
- Outcome: fixed
- Cause: struct-layout
- Best score: 178/178 primary bytes with relocations and unwind covered
- Attempts: 1 development comparison of the enclosing destructor

## What differed

The previously reconstructed single-array destructor explains one release. Each enclosing destructor releases three arrays, at offsets 0x30, 0x18 and 0x00, and calls both base destructors for each array. All 65 candidates have the same helper targets.

## Spellings tried that did not help

The first bulk probe explicitly instantiated a class with an in-class defaulted destructor. MSVC omitted the unused destructor symbols, so the comparator had no functions to check.

## Spelling that fixed it

Declare the array base and allocator destructors out of line. In the array destructor, release a non-null buffer and reset the size. Declare three array members in the owner and let its defaulted destructor visit them in reverse order. Defining that destructor out of class makes explicit class instantiation sufficient to emit it. This produces all nine call references and the C++ termination metadata.

The three-array layout is consistent with the sinks and two pending lists in CommonLibSSE-NG at b93280e (MIT). The project inventory and community caller labels, CRASHLOGGER_PDB(59818@2026.10.24), support that reading for the script error logger, virtual machine and save-data utility. The event types remain stand-ins.

The initial survey at ed8a45ce grouped 24,721 eligible functions by instruction form and checked function boundaries, internal branches and external callees. The source developed on 0x1afed0 passed on the other 64 candidates as well. Together they cover 11,570 primary bytes on the pinned Steam 1.7.104 build.
