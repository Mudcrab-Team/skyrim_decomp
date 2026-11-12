# Finding: census of the image for cheap reconstruction lanes, and what matching has cost

Status: OBSERVED (counts on the pinned image; usage and prices of the runs so far); HYPOTHESIS (every projection, tier cost and subscription pace below; nothing was compiled or compared for this finding)
Author / human operator: awarebayes
AI assistance / model: Claude Code Engineer worker (claude-opus-5-5), task p22-token-census; local only, no Boat, no agents
Date (UTC): 2026-11-12
Target build id / image SHA-256: `sse-steam-1-7-104` / `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f` (the function table's recorded input hash)
Function RVA / size (if applicable): none listed; per-function rows are private
Source exposure: binary-analysis (the image's code, `.pdata`, unwind and EH data, RTTI vftables; Ghidra export for entry points); community-headers for name presence only
Sources and immutable revisions / licenses: CommonLibSSE-NG `b93280e8` (MIT), powerof3/CommonLibSSE `654e55f7` (GPL-3.0, presence of a name only), meh321 names `8becdeae9fd2`, Address Library 1.7.104.0, FNV sibling index of `momusdigital/fnv_decomp@91e1b6e8` (presence of a counterpart only); repository at `17702a2`; vendor price and plan pages listed under Sources, read 2026-11-12
Name provenance: none published
Confidence: high for counts and measured spend; medium for families, the funclet estimate and the subscription capacity; low for projections (assumptions stated beside each)

## Question and method

How much of the image can be matched with no or almost no model work, where does the rest fall,
what has a matched function cost so far in money per role, and what would the whole image cost
under three ways of working? Two original scripts, stdlib only, tested on synthetic input
(`tests/test_census.py`, `tests/test_usage_census.py`):

- `tools/census.py build` joins the whole-image function table (`build_function_table.py`, 176,001
  entries), the Ghidra export, the image, the FNV index, the parked census and `data/progress.json`;
  decodes every non-funclet function with `tools/analysis/x64.py`; computes three cluster keys,
  a family, a funclet-extent class and a tier; writes a private per-function TSV and a counts-only
  summary. Whole run: 24 s. `tools/census.py project` turns the summary and the measured stage
  costs into the plan costs of section 6, with every assumption in `ASSUMPTIONS`.
- `tools/usage_census.py` reads only metadata of agent transcripts (message ids, model, usage
  counters, timestamps, tool names, result lengths, and whether a Bash call ran `attempt`), never
  their text, and prices them at the list prices under Sources. `roles` gives spend per role and
  stage for the orchestrator session and its 164 subagents; `windows` sums all transcripts on this
  machine inside a time window (used for the subscription limit stops).

Definitions:

- Population: every function-table entry. Funclets (67,911 entries, 990,476 B in `.text$x`) are
  compiled and compared with their parent, so they are counted apart. Targets: 108,090 functions,
  21,975,738 B (ordinary 89,973, static initializers 9,762, static teardown 6,508, thunks 1,622,
  import thunks 225). Size is the comparator v2 extent from the table (chained entries and switch
  tables in, funclets out).
- `exact`: identical bytes. `masked` (L1, "exact duplicate" below): identical after zeroing every
  field the comparator treats as a reference — rel32 call/branch displacements that leave the
  function, every RIP-relative displacement, image-base-relative switch-table entries and DIR64
  slots — with the same field offsets and kinds, the same self-relative targets, the same unwind
  codes, the same chained-entry layout and the same handler presence (`imagemodel.py`, unchanged).
  Members differ only in which symbols they reference. `shape` (L3): per instruction the opcode
  bytes (register-in-opcode bits cleared), the group extension, the memory form (none, register
  base, base+index, RIP, stack) and the widths of displacement and immediate fields; registers,
  immediates, displacements and targets dropped; plus handler presence.
- Families: ordered rules on the decoded instructions of functions up to 96 B (larger ones are
  `large`), static initializers and teardowns by group and size (`FAMILIES` in the script).
- Tiers: T4 blocked whatever the model (parked classes, comparator v2 refusals other than thunks);
  T0 a member of an L1 cluster other than its representative (lowest RVA, or the matched member);
  T1 a family whose source a generator can write from metadata alone, T1p one it can write with
  compiler-order caveats; T2 up to 128 B without C++ EH; T3 the rest.

## Observations

### 1. Size distribution (functions per bucket; the last row gives bytes)

| size | functions | bytes | unwind | C++ EH | funclets | public name | NG/po3 | meh321 | RTTI owner | FNV sibling |
|---|---|---|---|---|---|---|---|---|---|---|
| <=8 | 8,680 | 43,606 | 1 | 0 | 0 | 6,645 | 4,571 | 2,997 | 6,461 | 194 |
| 9-16 | 5,872 | 67,233 | 16 | 0 | 0 | 2,969 | 1,087 | 1,688 | 2,896 | 68 |
| 17-32 | 4,957 | 119,467 | 1,652 | 118 | 39 | 2,184 | 692 | 539 | 1,987 | 63 |
| 33-64 | 19,048 | 904,074 | 17,058 | 3,363 | 2,479 | 6,979 | 3,045 | 2,388 | 6,543 | 217 |
| 65-128 | 29,550 | 2,743,207 | 28,578 | 16,249 | 15,448 | 5,735 | 2,952 | 2,904 | 4,635 | 267 |
| 129-256 | 18,292 | 3,330,516 | 17,921 | 7,800 | 7,235 | 5,036 | 3,014 | 2,281 | 3,967 | 227 |
| 257-512 | 12,425 | 4,488,604 | 12,326 | 6,298 | 6,224 | 2,635 | 1,488 | 1,123 | 2,025 | 133 |
| 513-1k | 6,459 | 4,480,695 | 6,427 | 3,265 | 3,260 | 1,047 | 632 | 437 | 810 | 59 |
| 1k-4k | 2,613 | 4,477,328 | 2,604 | 1,398 | 1,398 | 552 | 350 | 223 | 423 | 52 |
| >4k | 194 | 1,321,008 | 193 | 107 | 107 | 40 | 28 | 17 | 26 | 2 |
| total | 108,090 | 21,975,738 | 86,776 | 38,598 | 36,190 | 33,822 | 17,859 | 14,597 | 29,773 | 1,282 |
| bytes | | | 21,464,950 | 10,790,180 | 10,546,118 | 4,753,426 | 2,758,235 | 2,048,188 | 3,724,210 | 272,228 |

"Public name" is any non-placeholder NG/po3 or meh321 name, or an RTTI owner class from a vftable
slot (class known, method name possibly not). 19,509 functions (18.0%) are at most 32 B, but they
hold 230,306 B (1.0% of the bytes); half the bytes are in the 7.3% of functions over 512 B.

### 2. Exact duplicates

| level | clusters (>=2) | functions in them | bytes | beyond one per cluster |
|---|---|---|---|---|
| exact bytes | 1,277 | 10,184 | 233,609 | 8,907 fns, 189,037 B |
| masked (L1) | 5,368 | 56,694 | 4,877,782 | 51,326 fns, 4,138,405 B |
| shape (L3) | 5,657 | 65,396 | 5,889,647 | 59,739 fns, 5,006,005 B |

L1 clusters by member count: 2: 3,077; 3-4: 1,161; 5-9: 600; 10-19: 275; 20-99: 198; 100+: 57.
L1 members by size: <=8 8,131; 9-16 4,690; 17-32 2,724; 33-64 13,524; 65-128 19,400; 129-256
5,274; 257-512 1,957; 513-1k 939; 1k-4k 55. The p7 census (`.text$mn` only) found 34,515 repeats;
the larger figure here comes from static initializers and teardowns (15,199 of the T0 members),
which are internal-linkage copies per translation unit.

Largest L1 clusters (members, size in bytes): 5,368 x 67; 3,264 x 116; 2,091 x 106; 2,063 x 39;
2,062 x 43; 1,763 x 3; 1,609 x 5; 1,060 x 11; 939 x 8; 596 x 53; 515 x 49; 454 x 3; 432 x 23;
408 x 78; 372 x 63; 365 x 52; 335 x 82; 321 x 3; 312 x 33; 311 x 9.

Already matched functions sit in 71 L1 clusters of two or more; those clusters hold 8,733 other
functions (95,592 B) that one solved source covers today, given a stamping lane: empty 1,732,
tail-call thunks 1,608, deleting destructors 1,066, vftable-store-only 1,041, global-address
returns 938, constant returns 937, adjustor thunks 465, member returns 262, other 684.

### 3. Families

| family | functions | bytes | in L1 clusters | generator | matched | attempts/fn | draft $/fn | review $/fn |
|---|---|---|---|---|---|---|---|---|
| large (>96 B) | 47,342 | 18,861,222 | 10,916 | no | 49 | 2.62 | 0.259 | 0.283 |
| small-calls | 20,341 | 1,221,495 | 11,153 | no | 74 | 2.10 | 0.148 | 0.165 |
| small-leaf | 6,971 | 205,985 | 3,446 | no | 27 | 2.31 | 0.116 | 0.208 |
| static-init-other | 6,703 | 787,138 | 6,225 | no | 0 | - | - | - |
| teardown-other | 6,276 | 433,372 | 6,081 | no | 0 | - | - | - |
| scalar-deleting-dtor | 4,856 | 218,962 | 4,753 | yes | 17 | 1.19 | 0.082 | 0.134 |
| static-init-atexit | 3,059 | 129,093 | 2,878 | partial | 0 | - | - | - |
| return-constant | 1,747 | 8,024 | 1,664 | yes | 7 | 1.16 | 0.080 | 0.193 |
| empty | 1,733 | 5,199 | 1,733 | yes | 1 | 2.86 | 0.150 | 0.240 |
| tail-call-thunk | 1,609 | 8,045 | 1,609 | yes | 1 | 0.33 | 0.050 | 0.210 |
| adjustor-thunk | 1,452 | 14,160 | 1,405 | yes | 7 | 1.65 | 0.123 | 0.156 |
| flag-test | 1,175 | 15,404 | 703 | partial | 14 | 1.20 | 0.075 | 0.142 |
| vftable-store-only | 1,061 | 11,990 | 1,057 | partial | 1 | 6.50 | 0.250 | 0.280 |
| return-global-address | 939 | 7,512 | 939 | yes | 1 | 0.33 | 0.050 | 0.090 |
| return-member | 732 | 4,060 | 601 | yes | 13 | 1.50 | 0.088 | 0.123 |
| refcount-release | 286 | 15,634 | 227 | partial | 0 | - | - | - |
| set-member | 266 | 1,765 | 115 | yes | 12 | 1.75 | 0.072 | 0.138 |
| return-member-address | 257 | 1,372 | 236 | yes | 3 | 1.31 | 0.073 | 0.220 |
| member-reset | 232 | 5,388 | 47 | partial | 11 | 1.00 | 0.065 | 0.111 |
| teardown-stub | 232 | 3,258 | 229 | partial | 0 | - | - | - |
| import-thunk | 228 | 1,394 | 228 | yes | 0 | - | - | - |
| trivial-ctor-vftable | 217 | 6,273 | 115 | partial | 1 | 1.50 | 0.050 | 0.190 |
| member-forwarder | 196 | 2,023 | 178 | partial | 2 | 4.96 | 0.205 | 0.185 |
| return-global | 104 | 854 | 103 | yes | 2 | 2.05 | 0.120 | 0.285 |
| vcall-thunk | 73 | 613 | 53 | yes | 0 | - | - | - |
| undecoded | 3 | 5,503 | 0 | no | 0 | - | - | - |

Shapes (one line each; what a generator needs): empty: returns at once (symbol, signature).
return-constant: constant into the return register (value, width). return-member(-address): one
load (or address) of a member of `this` (offset, width: class layout). return-global(-address):
a global or its address, which covers `GetRTTI`-style accessors (symbol). set-member: stores an
argument or constant into a member (offset, width, source). member-reset: two or more constant
stores into members without calls, the `InitializeDataComponent`-style resets (offsets, values;
store order and zero-register reuse follow the compiler, hence partial). flag-test: reads a
member and tests or shifts bits, at most six instructions (offset and mask; bitfield or mask
spelling decides the instruction, partial). tail-call-thunk: one jump (callee). adjustor-thunk:
adjusts `this`, tail-calls (hierarchy offset; normally emitted by the compiler from the class).
member-forwarder: loads a member or global into an argument register, tail-calls (partial).
vcall-thunk: jumps through a vftable slot (slot). trivial-ctor-vftable: stores vftable pointers
and constants, returns `this`, no calls (class, bases, defaults; partial). vftable-store-only:
the out-of-line base destructor body (partial). scalar-deleting-dtor: destroy, then free when
bit 0 of the flags is set (class, object size, destructor). static-init-atexit: initializer of
at most 64 B that registers a destructor (partial: TU order decides layout). teardown-stub:
static teardown of at most 32 B (partial). "yes" families: 13,996 functions, 271,960 B;
"partial": 6,458, 189,063 B. Most of them are L1 duplicates already (T0); outside T0 the
generators would write 1,020 (T1) and 1,171 (T1p) functions.

Cross-check with the 243 matched functions: attempts per function are the task unit's counted
attempts divided by its functions (all 243 have them); money is the ledger's allocation
(`data/costs.json`, draft and review stages, at the prices below). Matched examples of "yes"
families averaged 0.3 to 2.9 attempts; drafting cost 5 to 15 cents and review 9 to 29 cents per
function, and review cost more than drafting in every family but one. Attempts per function over all 243:
<=1: 90; 1-2: 78; 2-4: 53; 4-8: 21; >8: 1.

### 4. Parked and blocked classes

| class | functions | bytes |
|---|---|---|
| prologue skips the first home slot | 768 | 283,667 |
| EH state store (-2) without a handler | 151 | 57,591 |
| v2 refusal: handler not identified | 1,131 | 863,091 |
| v2 refusal: jump table without the layout v2 compares | 643 | 867,994 |
| v2 refusal: multiple .pdata, unresolvable reference, split body | 38 | 6,144 |
| total blocked under any model (T4) | 2,731 | 2,078,487 |
| funclet parents provable under 0.5.0 rules (estimate) | 15,024 | 3,866,069 |
| funclet parents that need 0.6.0 (own .pdata end 1,308; FuncInfo entry 8,122) | 9,430 | 5,234,227 |
| funclet parents unprovable under 0.6.0 (estimate) | 0 | 0 |

The funclet classes are a target-side estimate: each funclet is assumed to end where its own
`.pdata` ends, or a leaf funclet after its first jump or return, as a matching candidate's section
would; the end is then checked against the rules of each version (0.5.0: a `.pdata` start, the
function or one of its own funclets, `int3` padding; 0.6.0 adds the funclet's own `.pdata` end
and any FuncInfo entry, read from every C++ FuncInfo plus Ghidra's `.text$x` entries). 37 leaf
targets outside `.text$x`, named by 18,183 parents (one shared termination stub among them), are
shared code a candidate references, not funclets, and are excluded. While `main` stays at 0.5.0,
9,430 functions (5.2 MB, 24% of the bytes) are out of reach in addition to T4.

### 5. What matching has cost (measured)

All spend of the orchestrator session that produced the 243 matched functions: the top-level
transcript (orchestrator, `claude-fable-5-2`) and its 164 subagents, priced at list price.
Three earlier short sessions add $0.75 and are left out. Roles come from each subagent's
recorded type and description (`ROLE_RULES`).

| stage | runs | model | cache write | cache read | output | USD | USD per matched fn |
|---|---|---|---|---|---|---|---|
| drafting | 50 + 1 | Sonnet 5.5 (+ one Haiku 5.5 run) | 5.58M | 156.6M | 1.65M | 42.91 | 0.177 |
| function review | 32 | Opus 5.5 | 4.71M | 117.6M | 0.97M | 66.57 | 0.274 |
| integration and acceptance | 9 | Opus 5.5 | 1.74M | 74.7M | 0.42M | 31.78 | 0.131 |
| triage and near-misses | 9 | Opus 5.5 | 2.00M | 99.9M | 0.64M | 42.72 | 0.176 |
| batch preparation | 5 | Opus 5.5 | 0.94M | 51.2M | 0.36M | 22.04 | 0.091 |
| orchestration | 1 | Fable 5.2 | 1.97M (1 h) | 93.5M | 0.49M | 69.86 | 0.287 |
| per-function subtotal | | | | | | 275.88 | 1.135 |
| machinery review | 10 | Opus 5.5 | 1.47M | 18.9M | 0.31M | 17.27 | 0.071 |
| tooling, comparator, analysis | 48 | Opus, Fable, Sonnet | 13.80M | 580.4M | 3.90M | 273.23 | 1.124 |
| total | 165 | | | | | 566.38 | 2.331 |

Fresh (uncached) input is under 20,000 tokens in total. In the per-function stages cache reads
are 96% of the tokens but 37% of the money; cache writes are 33% and output 30%. Money per matched
function by kind: cache writes $0.38, cache reads $0.42, output $0.34.

- Drafting by batch (Sonnet unless noted): second batch 5 runs $1.15, 17 attempts; batch 3 8 runs
  $5.55, 81 attempts; batch 4 30 runs $26.37, 239 attempts; batch 5 6 runs $7.20, 98 attempts;
  Sonnet control (cheaper-drafter experiment, s07 group) 1 run $1.06, 12 attempts, 14 of 15
  functions passing per its handoff ($0.076 per passing function); Haiku 5.5 run (s01 group)
  $1.58 and 35 attempts so far, outcome not yet recorded. Attempts per Drafter run: median 6,
  range 0 to 35.
- Before the first `attempt` call a Sonnet Drafter spent 35.5% of its money (18.5% of its tokens;
  45 runs with at least one attempt): reading the card, cookbook, brief and packs, then writing
  the first draft. The rest is the compile-compare loop.
- Orchestrator: 25% of the per-function cost, 12% of everything. Its money: 1-hour cache writes
  $31.57 (45%), output $19.58 (28%, mostly briefs and plans), cache reads $18.69. It received
  1,266,585 characters of worker reports and Reviewer texts (116 task notifications, Agent
  results) — about 317k tokens at 4 characters per token — which were written once to its cache
  ($5.07) and re-read on every later turn until one of the two compactions (about 18.0M cache-read
  tokens, $3.61): $8.67, 12% of its spend, $0.036 per matched function. Two-line summaries
  (about 7k tokens in all) would remove almost all of it and push compactions back.

### 6. Projection for the whole image (money at API list prices)

Reachable functions (all but T4): 105,359. Tiers:

| tier | functions | bytes | how | model work per function |
|---|---|---|---|---|
| T0 stamp | 50,877 | 3,979,378 | L1 duplicate of a solved representative | none; cluster-level review plus a sample |
| T1 generator | 1,020 (+1,171 partial) | 15,487 (+33,029) | family generator from metadata | none after a one-time generator |
| T2 harness | 17,647 | 1,177,389 | <=128 B, no C++ EH | weak model single shots in a scripted loop |
| T3 agent | 34,644 | 14,691,968 | everything else reachable | Sonnet agent as today (harness first up to 512 B) |
| T4 parked | 2,731 | 2,078,487 | section 4 | none until tooling changes |

T0 by kind: 18,103 code with a class or name identity (776,979 B), 17,575 code without one
(1,984,874 B, names would be placeholders), 15,199 static initializers and teardowns (1,217,525 B,
internal-linkage copies: comparing them needs the contract change p7 named). The maintainer's
decision (family-level review plus a random sample for stamped and generated functions, every
function still compared on two hosts) is assumed for T0 and T1.

Measured inputs: the per-stage costs of section 5 for a matched function of mean size 61 B.
Assumptions (all in `ASSUMPTIONS`, low/high): cost grows with size by a factor of 1 up to 64 B,
1-1.8 for 65-128 B, 2-3, 3-5, 5-9, 8-16 and 15-40 for the larger buckets (only "large" matched
examples, 1.6-1.9x the small ones, back the start of this curve); harness 2-5 calls per function
at $0.0009-0.0021 a call (8-20k input tokens, half or more a cached prefix, 1-2k output, Haiku 5.5
or GPT-6 Luna list prices), 20-50% escalated to a Sonnet agent at today's drafting cost; cluster
review $0.30-1.00 per L1 cluster; random sample 5-10% at $0.05-0.15; 25 generators at $20-80 to
build and $2-5 to review; batch review with a file report and a verdict table $0.05-0.15 per
function (T3: $0.10-0.274); scripted integration $0; orchestration $0.01-0.05 per function;
triage 50-100% of today's.

| plan | API cost, low | API cost, high |
|---|---|---|
| A. today's process for every reachable function | $218,614 | $341,695 |
| B. A, with a weak-model harness replacing drafting up to 512 B | $198,366 | $324,248 |
| C. tiers: stamping + generators + harness + family-level review + scripted integration | $35,060 | $125,969 |
| C, of which T0 / T1 / T2 / T3 | $1,738 / $555 / $2,178 / $30,589 | $6,131 / $2,158 / $8,918 / $108,762 |

Average per reachable function: A $2.07-3.24, B $1.88-3.08, C $0.33-1.20. Plan B saves little
because drafting is 15% of today's per-function cost; review, triage, integration and the
orchestrator are the rest. In plan C, T3 is 87% of the money: the size curve for large functions
is the main uncertainty, and the first T3 wave under plan C is the measurement that narrows it.

### Subscriptions, API and the mixed setup

Official facts (Sources): Claude Pro $20/month, Max $100 ("5x Pro usage" per five hours and per
week), Ultra $200 ("10x Pro usage" weekly; verified accounts have no five-hour limit); Max and
Ultra have a separate weekly Fable limit; Claude and Claude Code share one pool; no plan publishes
token numbers; extra usage ("usage credits") is billed at standard API rates; an `ANTHROPIC_API_KEY`
makes Claude Code bill the API instead of the plan; the Agent SDK docs ask third-party products to
use API keys, not claude.ai login. List prices per million tokens (input / 5-min cache write /
1-h cache write / cache read / output): Fable 5.2 $8 / $10 / $16 / $0.20 / $40; Opus 5.5 $4 / $5 /
$8 / $0.20 / $20; Sonnet 5.5 $2 / $2.50 / $4 / $0.10 / $10; Haiku 5.5 $0.10 / $0.125 / $0.20 /
$0.01 / $0.50 (prompts up to 100k tokens; five times that above). OpenAI: `gpt-6-luna` $0.10 input
/ $0.01 cached / $0.50 output, `gpt-5.6-luna` $0.20 / $0.02 / $1.20 (no cache-write charge; Batch
and Flex half). ChatGPT Plus $20, Pro from $100 ($100/$200/$500), Business $20-25 per seat;
Codex local messages per five hours on Plus or standard Business: GPT-6 Luna 350-3,000, GPT-6.1
Sol 15-160 ("estimates, not fixed limits"); Pro has no five-hour limit now; weekly limits "may
apply", unquantified; credits are charged per token (GPT-6 Luna 2.5 / 0.25 / 12.5 credits per
million input / cached / output), buyable on Plus and Pro; Codex CLI and `codex exec` are plan
features; API-key use is billed at API rates.

Measured on this machine (inference marked):

- Claude: two five-hour limit stops in this session. Their windows (reset time minus five hours,
  to the stop) held $167.25 and $177.62 of API-priced usage across all transcripts here (Opus
  71-74%, Fable 16-21%, Sonnet 8-10%). Nine earlier stops (September-October, other projects)
  held $44-79, so the limit or the plan changed in between. Inference: a five-hour window is
  worth about $170 at API prices now. It is a lower bound (use on other devices or claude.ai is
  invisible here), and how the meter weighs models is not published; assuming it tracks API price
  is an inference. No weekly stop has been seen: 2026-11-05 to 11-12 used $1,081 and October $2,125
  of API-priced usage on this machine, so the weekly cap is at least that. The plan is not stated
  in any local configuration read.
- Codex: the session logs' own rate-limit field gives the plan type (`self_serve_business_prolite`,
  price not on the pricing page) and a weekly window only (no five-hour window). Weeks with $7.79,
  $26.24 and $38.14 of API-priced GPT-6 Astra use reached 2%, 8% and 11%; a week with $157.99 of
  Astra and GPT-6.1 Terra reached 25%. Inference: a week is worth $330-630 at API prices
  (integer percentages, so ±25% on the smallest week). GPT-6 Luna runs of the cheaper-drafter
  experiment (4 runs, 50-280k input tokens each, mostly cached) cost about one cent each at API
  prices and moved the meter by less than 1%.
- Subsidy ratio supported: October's $2,125 of Claude usage on this machine against a plan of at
  most $200/month gives at least 10.6x ($100 plan: at least 21x); the true ceiling is unknown
  because no weekly cap was reached. Codex: $1.4-2.7k per month of API value; the ratio depends on
  this seat's price, which was not found.

Pace on one Claude subscription for the Claude-side work (everything but the harness), at $170
per five-hour window:

| plan | windows | days at 4.8 windows/day | weeks at the observed $1,081/week | matched functions per window |
|---|---|---|---|---|
| A | 1,286-2,010 | 268-419 | 202-316 | 52-82 |
| C | 206-741 | 43-154 | 32-117 | 142-511 |

Per month, plan C on one subscription: 20,000-74,000 functions if only the five-hour limit binds
(4.8 windows a day, every day); 3,900-14,000 at the weekly usage actually observed. Which of the
two holds depends on a weekly cap nobody has published or hit; it cannot be inferred from two
five-hour stops. The same work on the API costs the plan figures above.

The weak-model harness is cheap enough that billing hardly matters: T2 plus the T3 functions up to
512 B (44,952) cost $81-472 in GPT-6 Luna or Haiku 5.5 calls at API prices, under one week of the
Codex seat's measured allowance. Cheapest mix that stays inside the terms (below), for plan C in
about six to twelve months: (1) the harness on GPT-6 Luna or Haiku 5.5 through the API (a few
hundred dollars; no subscription automation question); (2) stamping, generators, sampling,
integration and dispatch as scripts (no model); (3) Sonnet T3 agents and the Reviewers run in
Claude Code on one Claude subscription, Opus kept for family reviews and triage; (4) overflow on
usage credits at API rates when a window runs out, which at plan C's low end is about $0-15k over
the run and at its high end most of the $126k. Several personal subscriptions to multiply limits
are not recommended (terms below); Team or Business seats belong to the people who use them.

Terms that limit plans (read 2026-11-12): Anthropic Consumer Terms (effective 2025-10-08) forbid
access "through automated or non-human means, whether through a bot, script, or otherwise" except
with an API key or where Anthropic explicitly permits it, forbid making an account available to
anyone else, and forbid "bypassing any of our systems or protective measures". Claude Code is the
product and its usage counts against the plan, but a custom harness calling Claude models should
use an API key. OpenAI's consumer terms forbid sharing credentials and automatically or
programmatically extracting data or output; its business terms forbid circumventing rate or usage
limits; `codex exec` and the Codex SDK are listed plan features. Separately, `AGENTS.md` requires
owner authorization and a terms assessment before game-derived material goes to any cloud AI
service: the GPT Luna lane is authorized for one task group only, with no terms assessment
recorded.

### Savings ranked (relative to plan A, whole image, API prices)

1. Scripted integration, acceptance and dispatch, with the orchestrator only planning waves:
   integration + batch preparation + orchestration are $0.51 of today's $1.14 per function;
   scripted, about $0.03. Saves about $92-144k. Part of it: workers and Reviewers write their
   full output to a file and return a verdict table (orchestrator report load $0.036 per function,
   $7-11k, plus later compactions).
2. Stamping T0 with cluster-level review and sampling (decision recorded): 50,877 functions leave
   the model loop. Saves about $71-94k net of the $1.7-6.1k of cluster reviews.
3. Cheaper review: file output plus a verdict table, batches by family, Sonnet instead of Opus
   for generated and trivial families once calibrated. Review is $0.27 of today's $1.14; at
   $0.05-0.15 it saves about $24-67k.
4. Weak-model harness for drafting up to 512 B: $17-20k (plan A minus plan B).
5. Prompt caching of the fixed card, cookbook and rules prefix: Drafter cache writes are $0.054
   per function; sharing one cached prefix across runs saves perhaps half, $5-8k. Cache reads
   already carry 96% of the tokens.

Roles that could drop a tier without weakening a gate, and the evidence each needs first: Reviewer
for T0/T1 families to Sonnet — a calibration set (all seeded blocking defects of
`tests/test_review_mutations.py` style plus 50 real functions) where Sonnet finds every blocking
issue Opus finds; integration and acceptance to a script — the existing `accept_function.py`,
`check.py` and CI status checks already decide, so the evidence is one wave integrated by script
with the same records as a manual run; orchestrator dispatch to a script — one wave dispatched
from a queue file without missed or duplicated tasks; Drafter to Haiku 5.5 or GPT-6 Luna for T2 —
the Sonnet-control comparison now running, on at least 100 functions, with pass rate and money
per passing function; triage stays on Opus (near-misses are where the knowledge is).

### 7. Compiling locally

Facts: the contributor branch ran the pinned compiler (cl 19.16.27054 under msvc-wine and Wine
11.0) on this Mac, reproducing the two-host record's code-section hash for a matched function;
setup took 3 min 46 s and about 4.2 GB of disk; one compare took about 7 s (handoff
`p18-contributor-flow`). This Mac is an Apple M4 Pro with 12 cores (8 performance, 4 efficiency)
and 24 GB of memory. The draft loop's attempts today run on Boat (`tools/verifier/attempt`, about
6 s per attempt in the recorded attempt logs).

What it would take (not built): a local backend for `attempt` that uses the contributor setup
instead of a Boat session; one Wine prefix per worker so compiles do not share a wineserver; a
per-compile timeout (the handoff notes `unit_build.py` has none) and the compile sandbox it lists
as missing; Boat kept for the second-host confirmation, run in bulk per translation unit.
Throughput estimate (not measured): 6-8 parallel compiles, about 50-70 compares a minute, so
3,000-4,000 an hour. Plan C needs about 3-6 compiles per function in the loops (2.1 measured
attempts per matched function, 2-5 harness calls) for the 52,291 T1-T3 functions, plus one per
stamped or generated function: about 210,000-370,000 compiles, 50-125 hours of this Mac; the
second-host confirmations add one compare per function on Boat.

## Interpretation and alternatives

Most of the image is either repeated code or larger than anything matched so far: 47% of functions
are L1 duplicates and 87% of plan C's money is in T3, mostly functions of 129 B to several KB, while
the 243 matched functions average 61 B and only 49 exceed 96 B. The cheap lanes cover many
functions and few bytes (T0 to T2: 67% of reachable functions, 26% of reachable bytes). Spending is dominated by review, triage,
integration and orchestration, not drafting, so the largest savings come from taking models out
of the bookkeeping (scripts) and out of per-function review (families), before making drafting
cheaper. An alternative to the size curve assumed here is that large functions are mostly blocked
by compiler-behaviour puzzles rather than tokens; then T3 cost is bounded by triage time, not by
size, and the first T3 wave should be measured before any budget is set.

## Reproduction and sanitized evidence

```sh
python3 tools/census.py build --config <export_pack.json> --export <Ghidra F/V export> \
  --functions <function table> --fnv <fnv_index.jsonl> --parked <parked-census.json> \
  --progress data/progress.json --costs data/costs.json --tasks <task dirs> --out .local/analysis/census
python3 tools/usage_census.py roles --session <orchestrator transcript> --out .local/analysis/usage-roles.json
python3 tools/usage_census.py windows --root <transcript root> --window START,END ...
python3 tools/census.py project --summary .local/analysis/census/summary.json \
  --roles .local/analysis/usage-roles.json --matched 243
```

Private outputs: per-function TSV and summary under `.local/analysis/census/`, usage summaries
under `.local/analysis/`.

## Negative results and limitations

- Families are rules over instructions, not compiled evidence: a family marked "yes" is a claim
  about what a generator would need, untested. Rules see one function at a time; ICF and inlining
  across functions are not modelled.
- The funclet classes assume a candidate funclet ends where the image's code for it ends; a
  shorter or longer candidate changes the verdict. Leaf funclets reached only through
  non-C++ handlers are not scanned.
- `return-member` and similar families can hide calling-convention or width variants that change
  the source; the matched examples are few (1 to 17 per family).
- Costs come from one session of 243 matched functions averaging 61 B, chosen to be easy. Ledger
  allocations per family are judgement splits (`estimated` records). The before-first-attempt
  share includes writing the first draft.
- Subscription capacity is inferred from limit stops seen on this machine only; the vendors do
  not publish token allowances, and the meter's weighting of models is unknown.
- Prices are list prices read once; they change.

## Sources

- Anthropic model pricing: https://platform.claude.com/docs/en/about-claude/pricing (accessed 2026-11-12)
- Claude plans: https://claude.com/pricing (accessed 2026-11-12)
- Max plan limits: https://support.claude.com/en/articles/11049741 (accessed 2026-11-12)
- Extra usage: https://support.claude.com/en/articles/12429409-extra-usage-for-paid-claude-plans (accessed 2026-11-12)
- Claude Code with Pro or Max: https://support.claude.com/en/articles/11145838-use-claude-code-with-your-pro-or-max-plan.md (accessed 2026-11-12)
- Agent SDK overview: https://code.claude.com/docs/en/agent-sdk/overview (accessed 2026-11-12)
- Anthropic Consumer Terms: https://www.anthropic.com/legal/consumer-terms (accessed 2026-11-12)
- OpenAI API pricing: https://developers.openai.com/api/docs/pricing (accessed 2026-11-12)
- Codex and ChatGPT plan pricing and usage: https://learn.chatgpt.com/docs/pricing (redirect target of developers.openai.com/codex/pricing; accessed 2026-11-12)
- OpenAI terms: https://openai.com/policies/terms-of-use/ returned 403 to the fetch; the clauses quoted
  above come from the search excerpts of that page and of the business terms
  (https://openai.com/policies/may-2025-business-terms/), and should be read in full before relying on them.
- Unofficial, not used for any figure: third-party guides on Claude and Codex limits and on the
  price of a ChatGPT credit (about $0.04, which matches the 25:1 ratio between the credit rates and
  the API prices; inference only).

## Reviewer and outcome

Not reviewed.
