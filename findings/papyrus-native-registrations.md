# Script-engine native registrations joined to typed prototypes

Static analysis of the pinned executable and of the owner-installed script archive found handler addresses for 663 of the 686 native script declarations, 592 of them with a typed prototype read from the run-time type information of the registered function object. No function was reconstructed or matched by this work; it supplies names and parameter types for 648 unmatched handlers.

## Method

- **Declarations.** `tools/papyrus_psc.py` parses every `.psc` member of `Data/Scripts.zip` (SHA-256 `200053b5d747adbc1ff04a43dd2d18639ddc94fd6aa78b10fa45f39aaccf02f7`): script name, parent, flags, and for each function or event its return type, parameters and the `native`, `global` and `latent` flags, including declarations that continue over several lines. Bodies, comments, doc strings and default values are discarded while parsing.
- **Registrations.** `tools/ghidra/harvest_handlers.py` gains `RegistrationSiteScanner`, which reads the image's disassembly once and, at each direct call, records the argument registers that hold RIP-relative addresses and the stores into the new object that follow. A site counts only when two argument strings are a declared (script, function) pair and one executable address is passed or stored as the handler. A handler claimed by two different pairs is dropped.
- **Types.** The virtual table the site stores (or its constructor stores) names a `NativeFunctionN<Self, R, A1..An>` class; `tools/papyrus_natives.py` decodes the class's template arguments and compares them with the declaration (arity, return kind and the kind of each argument).
- **Dedup.** Handlers are checked against the matched inventory and against the CrashLogger names (`CRASHLOGGER_PDB(59818@2026.10.24)`).

## Observations

| Measure | Count |
|---|---:|
| `.psc` members parsed (no parse errors) | 14,301 |
| Scripts with native declarations | 44 |
| Native declarations (functions, none are events) | 686 |
| Global declarations | 156 |
| Declarations with a return value | 316 |
| Declarations with an array parameter or return | 0 |
| Registration call sites scanned | 17,208 |
| Declarations resolved to a handler (one to one) | 663 |
| Registered classes decoded as `NativeFunctionN` | 592 of 663 |
| Typed prototypes whose arity and argument kinds agree with the declaration | 571 |
| Typed prototypes whose return kind differs from the declaration | 21 |
| Handlers already matched | 15 |
| Unmatched handlers | 648 |
| Unmatched handlers with no CrashLogger name | 375 |
| CrashLogger `papyrus` names that match a declared pair | 272 |
| Of those, handler confirmed by a registration | 268 |
| Of those, contradicted by a registration | 0 |

Of the 71 registrations without a decoded class, 8 construct a `NativeLatentFunctionN` instance (a family this version does not decode) and 63 have no single virtual table stored by the site or its constructor; they carry the declaration's types only. Of the 21 return mismatches, 14 are declared with no return value against a class whose result type is not void (the rest an integer, a float, a string or an object against another kind); the prototype keeps the class's types. No declaration carries a `latent` flag in the script text.

The executable holds 310 `NativeFunctionN` classes. Each owns three virtual-table functions: the destructor and one small adjustor (all 310 of each matched) and the run function that unpacks the argument values, calls the handler and packs the result (0 matched). The run functions form 169 relocation-masked shapes, 180 of them in groups of two or more, the largest group holding 30; their sizes run from 86 to 1,377 bytes (`docs/generators.md`).

## Interpretation and alternatives

The strings alone would pair a name with any function that happens to be loaded next to them; the join to a declared (script, function) pair, the handler address and the class's own argument types agreeing on 571 of 592 is what makes the pairing credible. A declaration names the script API, not the C++ method: several scripts can share a handler, and none did here. The names are `OBSERVED` leads for a namer; only a byte match is acceptance.

## Reproduction and sanitized evidence

On a machine holding the owner's installation and the private analysis config: `python3 tools/papyrus_psc.py scan <Scripts.zip> --out .local/papyrus/natives.json`, then `python3 tools/papyrus_natives.py sites` and `join` with the config and analysis directories named in the tool's header. The per-handler table stays in `.local/papyrus/`; this file carries counts only.

## Negative results and limitations

- Source exposure: mixed (the pinned executable's disassembly and run-time type information, and the shipped script archive). No sibling, leaked or downstream source. No script text, disassembly or table is reproduced here.
- The hidden engine arguments of a handler (registry and stack identifier) are not part of the prototypes: the join does not establish their types.
- 23 declarations did not resolve (no call site loads both strings, or the handler is built some other way); they are not counted as absent.
- Handler resolution covers direct calls only. A registration reached through a table or an indirect call is missed by construction.
- A first hand-written unit for the largest run-function group reproduced the instruction sequence and the register assignment but not the exception-region layout around the result temporary (151 to 154 bytes against 152), so no generator is enrolled.
- Confidence: high for the 571 agreeing pairs and the 268 confirmed CrashLogger leads; medium for the 21 return mismatches; the prototypes are guesses until a function compiles to its target bytes.
