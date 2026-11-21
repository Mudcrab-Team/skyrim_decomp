# Code rules for reconstructed source

A byte match proves the compiled code. It does not prove the source. A unit can reach the bytes
through an offset cast, a private copy of a type or a member that only pushes others into place,
and then the binary is reproduced without what was written being recovered. The acceptance rule
already rejects that as "byte steering" (`docs/verification.md`, Tier 1, item 3), and it names
the leftover risk itself: a missed plausibility finding by the one review.

These rules make the mechanical part of that judgement a computed number.
`tools/check_code_rules.py` reads every unit and reports, beside the byte count, how many
`matched` functions also pass every [match] rule below. It is advisory. It changes no gate,
revokes nothing, and is never evidence of a match; `matched` stays two hosts plus one review.
Making any of it blocking is a change to the acceptance rule and the maintainer's decision.

The test every rule serves: would a programmer on the original team have typed this, and can a
reader see what it does without opening a listing?

## Two laws

1. **The bytes win.** A change made for these rules must not change the compiled code. In this
   repository that is checked for you: any edit changes the unit digest, and the unit is compiled
   and compared again before its record moves. Where a rule and the bytes disagree, keep the bytes
   and write `// RULE-EXCEPTION: <rule>, <the reason the bytes give>` at the code. An exception
   bends a style rule. It never licenses fake code.
2. **Identical bytes alone are not the finished job.** A function is *matched under the rules*
   when it is `matched` and its unit has no [match] finding. Placeholder names do not count
   against it: they are open naming work, like Tier 2.

## Tiers

| tag | meaning here |
|---|---|
| [match] | counted by the checker; a function with a finding is `MATCH-PENDING` under the rules |
| [free] | cannot change code (comments, layout); still changes the digest, so the bot recompiles |
| [checked] | can change code or binding; goes through `compare` and the two-host confirmation |
| [evidence] | changes a name or signature; needs a labelled origin (`PROVENANCE.md`) |

## Rules

Numbers are stable identifiers; new rules take the next free number.

| rule | tier | what it asks |
|---|---|---|
| R1 | match | Each type is declared once, in a header every user includes. No per-unit copy, no partial "layout view", no `class`/`struct` keyword that differs between declarations (MSVC mangles it). |
| R2 | match | Each global is declared once, `extern` in a header, and defined once. Never model an address inside an object as separate storage. |
| R3 | free / checked | Headers have one shape: guard, includes, constants, enums, types, `extern` globals, prototypes grouped by defining unit. |
| R4 | match | Typed members, never fixed offsets: no `*(T*)((char*)p + 0x58)`, no offset macro, no arithmetic on `this`. Byte arithmetic stays legitimate where data has no fixed struct (parsers, allocator headers). |
| R5 | evidence | An enum for a proven finite set; a field keeps its stored width. |
| R6 | evidence | The original's own types. `bool` only where the evidence shows `bool`. |
| R7 | checked / evidence | Names say what things mean. Placeholders (`Unk_07`, `Function1581e30`, `unk58`, `DeletingLeaf9d4fa0`) are honest open work; a confident invented name is not. |
| R8 | free | One naming style per unit; never normalize one unit's style into another's. |
| R9 | free / checked | Decimal for counts and sizes, hex for masks and flags, floats never as raw bits. |
| R10 | checked | Name bit operations (flag constants, helpers); do not replace them. |
| R11 | free / checked | Name meaningful constants. A named `const float` can change the referenced symbol: check. |
| R12 | evidence | Functions live where the original put them: a method stays a method of its real class. |
| R13 | match | Every declared virtual is a slot of the image's vtable and every slot is declared. No virtual named as padding. |
| R14 | checked | `goto` only where the control flow needs it. |
| R15 | checked | Original function order and unit boundaries. Here: one pair per class until translation units are evidenced (`reconstruction/README.md`). |
| R16 | checked | Restore the accessor or inline helper instead of open-coding it at each site. |
| R17 | match | No fake code: no `volatile` carrier, dummy local, empty block, bare `;`, `do { } while (0)` outside a macro, self-assignment, `+ 0`, `* 1`, padding member. |
| R18 | match | Assembly is not source (`tools/lint_reconstruction.py` already refuses it). |
| R19 | free / checked | Casts only where the meaning needs one; a cast chain is a wrong declared type. |
| R20 | evidence | `const` and references as the evidence shows; both are in the decorated name. |
| R21 | free | Comments say what the code means and why the bytes need it. No history, dates or scores. |
| R22 | free | Only what the pinned compiler accepts (profile below). |
| R23 | free | Formatting gets its own change, never mixed with code changes. |
| R24 | free | Generated files (`INDEX.md`, the progress pictures, reports) are regenerated, never edited. |
| R25 | checked | Every called function has its prototype in a header, not declared in the caller's `.cpp`. |
| R26 | checked | Pointers keep their type; `void*` only at a real boundary. |
| R27 | free / checked | Structs read as documentation: one member per line, offsets in comments, unknown ranges named by offset. Member and virtual order never move. |
| R28 | checked | Free functions carry their subsystem's prefix. |
| R29 | free / evidence | Each kind of thing follows one naming pattern (profile table). |
| R30 | checked | One local, one meaning, one name. |
| R31 | free / checked | Macros are hygienic and named for what they do. |
| R32 | free / checked | Units open the same way: header lines, includes, unit data, functions. |
| R33 | free | A comment above each function definition says what it does, or `guess:` when unknown. |
| R34 | checked | Never split or merge functions for readability. |
| R35 | free / checked | One statement per line, braces on every block, no state change hidden in an expression. |
| R36 | free | Label the original's quirks (`// BUG:`, `// NOTE: original ...`); never fix them silently. |
| R37 | checked | `#if` only for builds the original had. No parked alternatives. |
| R38 | match | No codegen steering: no `#pragma optimize`, `intrinsic` or `function`, no `_ReadWriteBarrier`, no `__declspec(noinline)` without a `// noinline: <evidence>` comment. |
| R39 | match | No decompiler leftovers: no `undefined`, `undefined1/2/4/8`, `CONCAT`, `SUB`, `ZEXT`, `SEXT`, `CARRY`, `SBORROW`. The name shapes `param_N`, `iVar`, `local_N`, `in_`, `extraout_`, `unaff_` are advisory. |
| R40 | match | Clean comments: no model, tool or pipeline name, checkpoint id, host path or e-mail address in a comment. Label lines stay legitimate. |

Human idioms of the code's era are not fakes: `*dst++ = *src++`, `while (--n)`, one `goto fail`
cleanup label, a long `switch`, `x = y = 0` for related state, a bug the original shipped (R36).

## What the checker tests

A [match] rule counts against a function exactly where one of these rows fires. They are narrow
by intent: genuine code passes, and so can a determined fake, which stays the Reviewer's.

| rule | row |
|---|---|
| R1 | a type name defined in two files with different bodies (anonymous-namespace types excluded); a type declared both `class` and `struct` |
| R2 | an `extern` variable declared in a `.cpp`; one global declared with different types |
| R4 | a constant (a literal, or a constant named `...Offset`) added to a byte-pointer cast, the sum cast to another pointer; an offset macro outside `offsetof` |
| R13 | a virtual named `pad...` or `dummy...` |
| R17 | `volatile` on a local, or elsewhere without a `// volatile: <evidence>` comment; an empty `if` or `else` body; a bare `;` statement (empty loop bodies and `case X: ;` pass); `do { } while (0)` outside a macro; self-assignment; `+ 0`; `* 1`; a member named `pad...` |
| R18 | the inline-assembly tokens |
| R38 | `#pragma optimize`, `#pragma intrinsic`, `#pragma function`; `_ReadWriteBarrier`; `noinline` with no `// noinline: <evidence>` comment on the same or previous line |
| R39 | an identifier that is exactly `undefined`, `undefined1/2/4/8`, `CONCAT<nn>`, `SUB<nn>`, `ZEXT<nn>`, `SEXT<nn>`, `CARRY<n>` or `SBORROW<n>` (comments and literals skipped); advisory: `param_<n>`, `<u/i/p/l/c/b>Var<n>`, `local_<hex>`, `in_*`, `extraout_*`, `unaff_*` |
| R40 | in a comment: `Claude`, `GPT`, `Codex`, `Sonnet`, `Opus`, `Haiku`, `Gemini`, `ChatGPT`, `Copilot`, `generated by`, `chk_*`, `/Users/`, `C:\Users\`, `.local/`, an e-mail address. Removed before the test: `COMMUNITY(...)`, `SIBLING(...)`, `SYMBOLS(...)`, `CRASHLOGGER_PDB(...)`, the SPDX line, `Sibling source:`, `CI hash:` |

The checker skips `reconstruction/generated/`. Those files are machine-generated declarations, not
reconstructed units, and are not scored.

R38-R40 differ from the other [match] rows in one way: contributor intake also refuses them
(`tools/contrib_validation.py`, through `check_code_rules.refusals`) in every file the change
touches, with a message that names the rule, file, line, offending text and the fix. Headers that
a changed unit only includes are not checked, so existing debt blocks no unrelated PR. A PR that
touches a file with debt fixes that debt in the same change; a comment-only fix keeps the code
digest. `tools/lint_reconstruction.py` already refuses `#pragma` words other than `once`, `pack`
and `warning` for the whole tree, so R38's pragma row has no debt; its `noinline` row is stricter
than that lint (a named `noinline:` note instead of any three-word comment), and
`_ReadWriteBarrier` is refused outright instead of justified. `tools/lint_review_readiness.py`
already refuses `undefined1/2/4/8`, `param_N`, `local_N` and `FUN_`/`DAT_` names at intake.

Advisory rows never make a function pending: R7 placeholder and address-derived names, R25
prototypes in a `.cpp`, R33 definitions with no comment above, R35 bodies without braces, R37
`#if 0`, and `!!x`.

Not implemented, and why: unused locals (R17) and layout views read through a cast (R1) need a
parser; slot-for-slot vtable comparison (R13) needs the private function table. A body finding
belongs to its function when the unit's `// 0x<rva> <Name>` line names it. Every other finding
(file scope, headers of the include closure) counts against all compared functions of the unit,
which over-reports for functions that never touch the flagged declaration.

## Project profile

- **Compiler and dialect.** MSVC 19.16.27054 for x64, `/O2 /MD /GS- /EHsc /GR /fp:precise /Gy`
  and the other recipes under `reconstruction/recipes/`. No `/std` flag, so the compiler's
  default (C++14 with its extensions): `nullptr`, `auto`, `override`, `<cstdint>` are accepted;
  `static_assert` needs a message (`docs/contributor-card.md`). Which standard the original
  source was written to is not established.
- **Annotation format.** Unit header lines: `Source exposure:`, the SPDX line, `Code origin:`,
  one `// 0x<rva> <Class::Method>` line per compared function, label lines
  `// <names>: <LABEL>` (`reconstruction/README.md`). There is no parking mechanism: a function
  that does not match is not published, so R37 has no exemption. `STANDIN` marks a declaration
  that is not recovered; it is this project's label for open R1 work.
- **Placeholder patterns (R7).** `FUN_`, `DAT_`, `sub_`, `Unk_<slot>`, `Function<rva>`,
  `Slot<n>`, `unk<offset>`, `unknown<offset>`, and any identifier ending in six to eight hex
  characters (`DeletingLeaf9d4fa0`, `SharedTeardown17b85f0`). `PLACEHOLDERS` in the checker.
- **Evidence sources.** In order of reliability: the pinned image's RTTI (`EXE_RTTI`); what the
  compared code shows (`OBSERVED`); the pinned community headers (`COMMUNITY`, hypotheses); the
  permitted sibling decompilations (`SIBLING`, never evidence about this image). Symbol files of
  sibling builds corroborate names and show original object files; what they give is in
  `data/name-corroboration.json` and `data/symbol-names.json`, and their status and limits are in
  `findings/sibling-symbol-files.md`. A unit cannot carry a name from them until the maintainer
  records the decision and its label.
- **Line information.** Not established: no finding records whether the image embeds source
  line numbers. It does not matter for the process, because every edit is recompiled and
  compared; treat a layout change in a unit as [checked] all the same.
- **Commands.** Per-function check: `./sr compare`. Byte gate: the two-host confirmation and the
  CI hash job. Rule checker: `python3 tools/check_code_rules.py --list <files>` for findings,
  `--strict <files>` to fail on a [match] finding, no argument for the totals.
  Symbol evidence: `python3 tools/symbol_corroboration.py --source LABEL=PATH`, with files you
  hold, kept outside the repository.
- **Rule changes.** None. No rule is tightened into the acceptance rule and none is relaxed.
  Stand-ins and `extern` declarations in a `.cpp` are how units compile today
  (`reconstruction/README.md`, "Stand-ins"); they stay reported as R1 and R2 so the count says
  how much shared-header work is left, which that section already schedules ("it moves to one
  shared header").

### Naming style

Evidence for the original style: class names recorded by the image's RTTI, and the FNV sibling
(`momusdigital/fnv_decomp@91e1b6e8`), which is the same studio's code and tags its own name
origins. The sibling is a hypothesis about style, not about this binary. Community names are
what the units use; follow the unit you are in (R8) and do not restyle a unit to another's.

| entity | style | examples | origin |
|---|---|---|---|
| class | recorded name, verbatim; the prefix names the library layer | `NiNode` (Gamebryo), `BSShaderProperty` (engine), `TESForm`, `BGSVoiceType` (game data), `bhkWorld` (Havok wrapper) | `EXE_RTTI` |
| unit | `<area>/<Class>.h` and `.cpp` | `skyrim_shared/forms/TESActorBaseData.cpp` | `reconstruction/README.md` |
| method | `PascalCase`, verb first; `Get`/`Set`, `Is`/`Has` | `GetVoiceType`, `InitializeDataComponent` | `COMMUNITY` |
| unknown virtual | placeholder by slot | `Unk_07` | open naming |
| member | community `lowerCamel` | `actorBaseFlags`, `voiceType` | `COMMUNITY` |
| member, sibling style | `m_` and a type prefix: `p` pointer, `k` object, `f` float, `ui` unsigned, `b` bool, `sp` smart pointer | `m_pDeathItem`, `m_uiActorFlags`, `m_kFactionList` | `SIBLING`, hypothesis |
| unknown member | placeholder by offset | `unk10`, `unknown290` | open naming |
| parameter | community `a_` prefix, or plain in units that have none | `a_array`, `stream` | `COMMUNITY`, `GUESS` |
| global | guessed, labelled | `gDefaultBaseDisposition` | `GUESS` |
| constant | `k` and `PascalCase` | `kEmptyString` | `COMMUNITY`, `GUESS` |

In the sibling's `include/` at that revision the member prefixes count `m_p` 1176, `m_k` 1126,
`m_f` 918, `m_ui` 627, `m_b` 551, `m_i` 426. That is the best available evidence of how the
studio named members. No mass rename is proposed: a rename changes every affected digest, and a
method rename changes the decorated name the comparator binds.

### Layout

Follow the unit you are in. New units: the skeleton's layout, four-space indent, braces on
their own line for functions and types, a short `//` sentence above each function (R33). Unit
headers stay within the compact budget (`docs/contributor-card.md`); function comments are not
header lines and do not count against it.

## Baseline

Measured with `python3 tools/check_code_rules.py` at base `a3514b259`, 58,232 files.

| count | functions | bytes |
|---|---:|---:|
| `matched` (two hosts and review) | 32,696 | 1,611,619 |
| matched under the rules | 14,444 | 393,694 |
| of which with no placeholder name (R7) | 478 | 13,808 |
| `MATCH-PENDING` under the rules | 16,973 | |
| not classified (unit has no `// 0x<rva>` line) | 1,279 | |

Pending by rule, a function counted once per rule: R1 14,043, R2 1,691, R4 783, R17 3,244.

| rule | finding | count | files |
|---|---|---:|---:|
| R1 | type defined with different bodies | 15,298 | 12,331 |
| R1 | `class`/`struct` keyword mismatch | 11,924 | 11,254 |
| R2 | `extern` in a `.cpp` | 1,314 | 1,098 |
| R2 | one global, different types | 60 | 57 |
| R4 | offset cast | 1,606 | 805 |
| R17 | padding member | 1,426 | 443 |
| R17 | `volatile` without evidence comment | 121 | 91 |
| R17 | `volatile` local | 3 | 3 |
| R38 | `noinline` without a `// noinline:` note | 187 | 187 |
| R39 | decompiler type or helper | 0 | 0 |
| R39 | decompiler-style name (advisory) | 0 | 0 |
| R40 | model, tool, pipeline name, id, path or address in a comment | 71 | 30 |
| R7 | placeholder name (advisory) | 62,854 | 53,842 |
| R33 | no comment above a definition (advisory) | 13,998 | 11,805 |
| R35 | body without braces (advisory) | 3,027 | 1,787 |
| R25 | prototype in a `.cpp` (advisory) | 1,820 | 1,720 |

R38-R40 were measured later, at base `0be03da78` (58,616 files), which is why the rows above
differ from a fresh run; with them the tree has 17,110 `MATCH-PENDING` functions (R38 38, R40 147
of them). `#pragma optimize`, `intrinsic`, `function`, `_ReadWriteBarrier` and every R39 word
occur nowhere. The R40 findings are `Drafted by <model>` header lines (the model-name row, 30 units)
and a few `Generated by` lines.

What the numbers say, and their limits. Most R1 findings are one cause: 10,723 generated static
initialiser units each declare their own `struct Manager` stand-in, every one different because
it names its own unit's type, and three unrelated units declare a `class Manager`. Both R1 rows
key on the type's name, so unrelated stand-ins that share a name are reported together; whether
one shared declaration can serve the static units and keep their matches is untested. The three `volatile` locals and the
1,606 offset casts are the findings closest to the Reviewer's byte-steering ground. The rows
found no empty block, self-assignment, `+ 0`, `* 1` or `do { } while (0)` anywhere. A function
that passes is not thereby original source: a stand-in class with an address-derived name
passes every [match] row and is still open R7 and R12 work, which is why the third line of the
first table is the honest headline.

## Bringing a unit under the rules

Fix in tiers, one kind of change per pull request.

1. **Comment-only fixes first** (R21, R33, R36, `// volatile:` evidence): the code section is
   unchanged, so the unit takes the label-only path of `docs/verification.md`.
2. **Declaration fixes** (R1, R2, R17 padding members, R25): move a type that several units
   declare to one shared header in its own area, replace a padding member with nothing where
   the compiler pads anyway or with `unk<offset>` where it is unknown storage, keep every
   `static_assert` on size and offset. Each affected unit is re-confirmed, as
   `reconstruction/README.md` already requires for a shared-header move.
3. **Code fixes** (R4, R17 in bodies, R16, R30): find what the trick hides. An offset cast hides
   a member or a base class; a `volatile` local hides a wrong type or a missing call; a
   padding member hides unknown members or a wrong base. A fix that loses the match is reverted
   or reshaped, never kept.
4. A rule the bytes defeat gets a `RULE-EXCEPTION` comment with the reason the bytes give.

Use a generic linter or a modern style guide read-only. Their fixes change code (renames,
reordering, extracted helpers, added `const`), and many of their findings are required by the
binary.
