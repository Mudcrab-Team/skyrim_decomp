# References and attribution

Reviewed 2026-11-11, updated 2026-11-12. These references informed project organization and
research direction. No upstream source, text passages, logos, screenshots or site assets were
copied into this repo, except the attributed excerpts listed under CommonLibSSE-NG below and the
names labelled by origin in `reconstruction/` (`PROVENANCE.md`). Reported upstream achievements
have not been independently reproduced here. `tools/check_origin.py` lists, for local use, every
reconstruction body close to a same-named body in the pinned community or FNV checkouts.

- [momusdigital/fnv_decomp](https://github.com/momusdigital/fnv_decomp), reviewed at
  `91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6`: reconstruction and comparison workflow.
  Its LICENSE grants no license. By maintainer decision (`docs/authorizations.md`, Notes) its
  names, declarations and code at that revision may be reused in reconstructions, labelled
  `SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)`, with each reused body cited by a
  `Sibling source:` line in the unit header; its tools are not copied and its tree is not
  vendored. Units with such lines: `netimmerse/NiPSysModifier` (LinkObject, RegisterStreamables,
  ProcessClone) and `bsengine/BSLightingShaderMaterialBase` (NiRefObject reference counting); both
  declare close parallels found after drafting, not recorded copies.
- [lemiur/Game-Decompilation-Skill-For-Claude](https://github.com/lemiur/Game-Decompilation-Skill-For-Claude),
  pinned at `f49d2153f8ad9279262a720c88b5d337e7c63534`, licensed CC-BY-4.0
  (`licenses/CC-BY-4.0.txt`). Author lemiur gave permission to copy, adapt and credit on PR #572.
  Adapted, with modifications, into `.claude/skills/matcher` (with `levers.md`), `.claude/skills/permute` and
  `.claude/skills/wall-identifier`; each directory has a `NOTICE.md`. Generic prose only: the source contains no game
  bytes, disassembly or symbols. Not an evidence source about the Skyrim binary. Other skills in that repo were not imported.
- [momusdigital/f3_decomp](https://github.com/momusdigital/f3_decomp), at
  `f5bac1b54fc8fde16294c1d6779f27407d0a117b`: Fallout 3 reconstruction. LICENSE is CC0 1.0. By
  maintainer decision (`docs/authorizations.md`, Notes) used like the FNV one, labelled
  `SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)`, a reused body cited by a `Sibling source:`
  line; not vendored.
- [momusdigital/fnv_decomp_exe](https://github.com/momusdigital/fnv_decomp_exe), reviewed at
  `d11951cb936c38252cefbc99eb69d777bf5decd2`: separate local executable-building project.
  Its LICENSE grants no license. Linked as a reference only; Skyrim building is not implemented.
- [FNV report](https://www.fnvdecomp.com/) and [method](https://www.fnvdecomp.com/how):
  public progress, verification and scope communication. Reference only; no reuse permission assumed.
- [Fallout 3 report](https://f3decomp.com/) and [method](https://f3decomp.com/how):
  active-project reporting and work organization. Reference only; no reuse permission assumed.
- [ByteBard97/skyrim-re-toolkit](https://github.com/ByteBard97/skyrim-re-toolkit), reviewed at
  `b5039b37de51c78a04d0319fbdb4c436a339853a`: type archives and runtime research tooling.
  README reports MIT for toolkit/community headers and Apache-2.0 for the parser extension;
  verify actual license files and dependency revisions before importing. Not vendored here.
- [CharmedBaryon/CommonLibSSE-NG](https://github.com/CharmedBaryon/CommonLibSSE-NG), pinned at
  `b93280e832f263dbef44e44cbe2936622a02f91a`: reverse-engineered community declarations, the main
  naming source (labels `COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)`). Licence: MIT,
  verified from `LICENSE` at that revision (Copyright (c) 2018 Ryan-rsm-McKenzie). No tree is
  vendored and it is not a build dependency, but small excerpts are adapted into reconstruction
  units:
  - upstream files: `include/RE/N/NiBinaryStream.h` and `src/RE/N/NiBinaryStream.cpp` (the
    ReadFn and WriteFn aliases and the read, write, put, binary_read and binary_write bodies),
    `include/RE/N/NiObject.h` (the inline AsNode to AsBhkLimitedHingeConstraint bodies),
    `src/RE/N/NiObject.cpp` (the IsEqual body), `include/RE/A/ActorState.h` (the IsUnconscious
    body), `include/RE/B/BSTArray.h` (the operator[] body), `include/RE/B/BSLightingShaderMaterialBase.h`
    (the class's virtual and member list), and the logic of `src/RE/N/NiRefObject.cpp` (reference
    counting, rewritten with compiler intrinsics);
  - units carrying excerpts: `bsengine/BSLightingShaderMaterialBase.h`, `netimmerse/NiNode.h`,
    `netimmerse/NiObject.h` and `.cpp`, `netimmerse/NiPSysModifier.h`, `actors/Actor.h` and
    `magic/MagicCaster.h`; each header names the bodies it adapts;
  - changes made: asserts dropped, binary_read and binary_write defined inline, read and write
    folding in binary_read and binary_write and returning true in NiPSysModifier, NiRTTI's name
    read through its member, BSTArray's data member indexed directly;
  - notice: each of those headers keeps NG's MIT notice verbatim, as the licence requires.
- [powerof3/CommonLibSSE](https://github.com/powerof3/CommonLibSSE), pinned at
  `654e55f7979c1733033d5dbef176e43827bac944`: a fork of CommonLibSSE, used as a naming source only
  (labels `COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)`). Licence: GPL-3.0-or-later per its
  `COPYING` at that revision (its `licenses/LICENSE-MIT.txt` keeps the original MIT notice for
  historical attribution). By maintainer decision (`docs/authorizations.md`, Notes) its names may
  appear in published reconstruction sources, and a file using them states GPL-3.0 in its
  header. No body is adapted from it: where it carries the same body as NG, the body is cited to NG.
- [meh321/AddressLibraryDatabase](https://github.com/meh321/AddressLibraryDatabase), pinned at
  `0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91`: its `skyrimae.rename` name list is a naming source
  (labels `COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)`). No licence file; used
  with the author's permission as reported by the maintainer (`docs/authorizations.md`). Nothing
  is vendored; only names are used.
- [Mudcrab](https://github.com/Mudcrab-Team/mudcrab): independent Rust engine implementation;
  contextual link only. No source or research material has been transferred between repos.

Original code in this bootstrap uses the Python standard library. GitHub Actions referenced in
workflows execute as hosted dependencies, pinned by commit. No third-party runtime code is bundled.
Future imports need a separate attribution entry with exact revision, license, paths and changes.

## Additive contributor declaration kit

`reconstruction/declarations/*.h` adapts declarations only from CharmedBaryon/CommonLibSSE-NG
`b93280e832f263dbef44e44cbe2936622a02f91a` (MIT): `include/RE/N/NiRefObject.h`, `NiObject.h`,
`NiObjectNET.h`, `NiAVObject.h`, `NiNode.h`, `include/RE/B/BaseFormComponent.h`, `BSTEvent.h`
and `include/RE/T/TESForm.h`, with reference types from `include/RE/F/FormTypes.h` and
`include/RE/B/BSCoreTypes.h`. `tools/declaration_kit.py` removes bodies, version macros and
implementation comments; preserves virtual signatures/slot order; replaces member regions with
explicitly unknown storage; retains full MIT notices. Sizes/slots remain community hypotheses,
not target evidence. No upstream tree or game-derived class table is included.

The contributor renderer may prepare other classes from these pinned NG headers, falling back
to the permitted powerof3/CommonLibSSE revision above. Adapted declarations retain their origin
labels, MIT attribution and GPL-3.0-or-later notices when applicable.
`licenses/CommonLibSSE-GPL-3.0.txt` retains the full, unmodified `COPYING.txt` from
powerof3 at the pinned revision; it applies to GPL-derived declarations, not the MIT-only kit.
No community implementation body is adapted by the declaration-kit generator.

The full MIT licence text of CommonLibSSE-NG (Copyright (c) 2018 Ryan-rsm-McKenzie) is kept once in
`licenses/CommonLibSSE-NG.txt`; unit headers carry the one-line `SPDX-License-Identifier: MIT
(CommonLibSSE-NG declarations, ...)` notice that points at it.
