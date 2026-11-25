Transfer status: UNREVIEWED

# Finding: compiled INI setting defaults, source conflicts, shadow split overlap and bias scales

| Item | Evidence record |
|---|---|
| Status | OBSERVED for verified claims. INFERRED and UNVERIFIED items are marked. Static only. |
| Author | A research run of `claude-sonnet-5-5` (Claude Sonnet 5.5), department task for Mudcrab issue #949, item 16. Not the reviewer below. |
| Human operator | Taylor. |
| Reviewer | A separate fresh-context run of `claude-sonnet-5-5`. A Sol run was not available because of usage limits. See "Independent review". |
| Date | 2026-11-24 CST. The author ran from 00:52 to 01:14 CST. The independent review ran from 01:15 to 01:36 CST. A third Sonnet run applied the review corrections and regenerated the table on the same day. |
| Build | `sse-steam-1-7-104`, retail `1.7.104.0`, Steam build 24914197. Executable SHA-256 `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`, equal to the pin in [builds/target.json](../builds/target.json). All runs asserted the equality. |
| Principal function addresses | VAs at image base `0x140000000`: `0x140652ab0` (start-up that loads the INI files), `0x14065db50` (INI path build and template copy), `0x140fd0e10` (per-setting INI read), `0x14157f080` (directional cascade update), `0x141568300` (shadow-light constant writer), `0x14155c4b0` (base shadow-light constructor), `0x14157e490` (directional light constructor), `0x14150c810` (local light creation), `0x14000c560` and twelve more static initialisers (G06). Descriptive function labels are GUESS. |
| Source exposure | Mixed. The operator's pinned executable. The five shipped INI files from the operator's install (`Skyrim_Default.ini` and the four presets). The requester's list of requested keys and audit table rows (names and chosen values only). Earlier drafts and findings (`sun-shadows`, `exterior-fog`, `grass-*`, `terrain-*`, `large-references`). Decoded shader text for one shadow-mask pixel shader from the earlier shadow work (generated locally). The author also compared compiled values with a third-party community list of defaults that the requester supplied privately. This file reproduces no value from that list. The reviewer did not read it. No PDB was read. The launcher executable got a string scan only. No sibling implementation source was used. |
| Immutable sources | Image hash above. `Skyrim_Default.ini` `61c151bc60d5d737dad3d65a99a48d9bb8b50812b6b9f1f993323f0337813fa8`. `Low.ini` `f045a0165b9d09d167ea11a228401e21c517497d0a333939db0a2e9ab7a25c9b`. `Medium.ini` `e5cb56c29c28a0e57055b75bf3153c6e7d8510100f656b490fadd3b9bdffc5fe`. `High.ini` `2413dc2f7cbf4551d9c6686780dfd20664c68604cab764604e30daa648606f95`. `Ultra.ini` `10dc00f0dae7783e2f904eabf68be09e4c2460ec1edd30a6231f22b47b847000`. The launcher executable in the install has SHA-256 `9204f00ba4e0093f00fd461883f171f1b98f7d7de27969ff5e41ba3608ae271b`. It is not the pinned image. |
| Name provenance | Setting names are the image's own `key:Section` strings. The class names `INISetting` and `INIPrefSetting`, the light field label "bias" (`+0x540`) and every function role are GUESS. No public generated name table is used. |
| Intended recipient | The Mudcrab department, for the INI work in issue #949, after boundary review under [docs/clean-room.md](../docs/clean-room.md). |

Evidence addresses are VAs at image base `0x140000000`. **Verified** means re-read at the cited source. **Inferred** marks an interpretation. **Unverified** marks a missing read or runtime observation. This file contains counts, names, default values, formulas and addresses. It contains no game text, no disassembly and no value from the community list.

## Answer

### Conflicts between the shipped template and the compiled default (question C)

In every row below, the shipped `Skyrim_Default.ini` or a preset supplies a value that differs from the compiled default. By the load rule in G02, the template value is the one in force when the key stays in the player's `Skyrim.ini`. For the two mesh-LOD keys the presets decide, and they sit in `SkyrimPrefs.ini`. The reading is static. No run confirmed it.

| Setting (section, file domain) | Compiled default, value field | `Skyrim_Default.ini` | Presets Low / Medium / High / Ultra | In force by G02 (static reading, no run) |
|---|---|---|---|---|
| `fFirstSliceDistance` (Display, Skyrim.ini) | 1250, `0x1420d9470` | 2000.0000 | none | 2000 from the template. 1250 only if the key is absent. |
| `fMusicDuckingSeconds` (Audio, Skyrim.ini) | 1, `0x14207e318` | 6.0 | none | 6 |
| `fMusicUnDuckingSeconds` (Audio, Skyrim.ini) | 4, `0x14207e330` | 8.0 | none | 8 |
| `fMenuModeFadeOutTime` (Audio, Skyrim.ini) | 0.5, `0x1420b4b08` | 3.0 | none | 3 |
| `fMenuModeFadeInTime` (Audio, Skyrim.ini) | 0.5, `0x1420b4b20` | 1.0 | none | 1 |
| `fMeshLODLevel1FadeDist` (Display, **SkyrimPrefs.ini**) | 9999999, `0x1420d66d0` | none | 4000 / 6000 / 999999 / 999999 | The preset value once the launcher has written it to `SkyrimPrefs.ini` (Ultra: 999999). 9999999 only if no file has the key. |
| `fMeshLODLevel2FadeDist` (Display, **SkyrimPrefs.ini**) | 9999999, `0x1420d66e8` | none | 1600 / 3000 / 999999 / 999999 | Same rule (Ultra: 999999). |
| `fGrassMinStartFadeDistance` (Grass, **SkyrimPrefs.ini**) | 400, `0x1420793b8` | 0.0000 | none | 0 from the template (`Skyrim.ini` is read first for this setting, G02). |
| `fTreesMidLODSwitchDist` (Display, **SkyrimPrefs.ini**) | 3600, `0x1420d6798` | 9999999.0000 | none | 9999999 from the template. |
| `iRadialBlurLevel` (Imagespace, Skyrim.ini) | 0, `0x1420d9130` | 2 | none | 2 |
| `fDecalLODFadeStart` (LightingShader, Skyrim.ini) | 0.05, `0x1420d6c40` | 0.45 | none | 0.45 |
| `fDecalLODFadeEnd` (LightingShader, Skyrim.ini) | 0.06, `0x1420d6c58` | 0.5 | none | 0.5 |

A key in the `Skyrim.ini` domain can also be changed by `SkyrimCustom.ini`. A key in the `SkyrimPrefs.ini` domain can also be changed by `SkyrimPrefs.ini`. The last column ignores both files. The compiled value matters only when no file has the key.

**What the table supports for Mudcrab.** The static reading supports the requester's chosen values in all seven rows of its conflict table: 2000, 6 / 8 / 3 / 1, Ultra 999999, 0.0, 9999999.0, 2 and 0.45 / 0.5. The reading is static. No run confirmed it.

**Load order (G02, static reading).** The compiled default is the start value. Then `Skyrim.INI` is applied if it has the key. Then `SkyrimCustom.ini` is applied for a `Skyrim.ini`-domain setting, or `SkyrimPrefs.ini` for a `SkyrimPrefs.ini`-domain setting. The last file that has the key wins. `Skyrim_Default.ini` is only a first-run copy source for `Skyrim.INI`. The image never reads settings from it.

### Shadow cascade overlap `fSplitOverlap` (question C, second part)

`fSplitOverlap` is one global float in world units. Its compiled default is 100, value field `0x1420d94e8`. The code reads it at two places only. Both are in the directional cascade update `0x14157f080`. For cascade `i` with fractions `t_i`, camera near `n`, clamped far `F` and `N` cascades:

```text
far_i  = 0.5 * (n * pow(F/n, t_i) + n + (F - n) * t_i) + O
near_0 = n
near_(i+1) = far_i - 2 * O
```

The overlap band between two neighbouring cascades is `2 * O` wide, centred on `far_i - O`. The last far endpoint is `F + O` for `N >= 2`. It is one value for every cascade. See G03.

### Shadow bias scales (question C, third part)

Defaults: `fShadowBiasScale` 1.0 (`0x1420d9080`) and `fShadowDirectionalBiasScale` 0.3 (`0x1420d9518`). Each setting has exactly one read in the image.

* `fShadowBiasScale` is read once, in the base shadow-light constructor. It sets the light's bias field. The two paths that create lights overwrite that field afterwards. The directional (sun) constructor writes 60.0. The local-light path writes a value from a descriptor. In the paths traced, `fShadowBiasScale` has no lasting effect. See G04.
* `fShadowDirectionalBiasScale` is read once, in the per-light constant writer. It multiplies the first of two bias constants for lights of the directional kind. For other lights the multiplier is 1.0.
* The writer sends two floats per light, not per cascade: `y = B * 0.00025 * k` and `z = B * (1/12000) * 1.0`. `B` is the light's bias field. `k` is `fShadowDirectionalBiasScale` (directional) or 1.0 (local). With defaults the sun gets `y = 0.0045` and `z = 0.005`. A shadow-mask pixel shader uses `y` for the first cascade and `z` for later cascades, as a subtraction from the receiver depth before the compare. Both values assume that the store at `0x1414eaea7` ran before the writer (G04, unverified).

## Review verdicts

| Group | Verdict | Note |
|---|---|---|
| G01. Compiled defaults, counts, coverage | Corrected | Values were right. The first table omitted 35 registered settings. |
| G02. Load order | Corrected (minor) | Wording and one second walker address. |
| G03. `fSplitOverlap` | Confirmed | |
| G04. Shadow bias scales | Corrected (minor) | One missing caveat and two missing callers. |
| G05. Compiled facts for the requested keys | Confirmed (compiled side) | |
| G06. Initialiser exceptions | Corrected | 13 settings, not 8. |
| G07. Template and Ultra values | Confirmed | |
| G08. Template keys without a setting | Corrected (wording) | Five keys, not six. |

## Question and method

Mudcrab issue #949 asks for the compiled default of every INI setting. This item answers three parts. (A) The table of compiled defaults for the pinned image. (B) Compiled facts for the requested keys and for four settings whose compiled value differs from a community list. (C) Seven source conflicts, and how retail applies `fSplitOverlap`, `fShadowBiasScale` and `fShadowDirectionalBiasScale`.

Method. The author scanned the image for `name:Section` strings and found the static setting objects, both by the name strings and by walking the static initialisers that register each object. Each object is 24 bytes: vtable pointer, 8-byte value, name pointer. The author read the value field with the type given by the name prefix. The author checked the three vtables, the collection singletons and the INI loader code. The author compared the values with the five shipped INI files. The author traced the three shadow settings from their value fields to the shader constant writer. Short ranges were disassembled locally with `llvm-objdump`. The reviewer then wrote an independent extractor before reading the draft. A third run rebuilt the table with a structural scan and compared it with the reviewer's extraction (G01).

## Observations

### G01. Compiled defaults of every INI setting in the image (verified, high for the objects found)

**Verified.** The image holds 1857 static setting objects that are registered with a setting collection. It holds one more setting built in code (`iNumThreads:HAVOK`, default 1, built in the constructor at `0x1410a1a60`). Of the 1857, 1832 have a `key:Section` name and 25 have a name without a section. Types by name prefix over all 1858 settings: 1016 float, 447 bool, 145 int, 126 unsigned, 115 string, 9 colour. Over the 1833 sectioned settings: 1010 float, 438 bool, 142 int, 126 unsigned, 108 string, 9 colour. Colours store four bytes in one dword. The reader fills them from `%u,%u,%u` (alpha 255) or `%u,%u,%u,%u`, red in the top byte (`0x140fd0ffa–0x140fd1088` and `0x140fd108d–0x140fd1126`). The table prints `R,G,B,A`.

**Verified.** The vtable decides the file domain. `0x1417ee3f8` (1700 sectioned and 17 sectionless static objects) belongs to a class whose destructor uses the collection singleton from `0x14019d780`. `0x1417efb70` (126 sectioned and 8 sectionless objects) uses the singleton from `0x1401b5310`. A third vtable, `0x1417e0360`, has 6 `Interface` objects with section names. They are registered through `0x1401499e0`, the same getter as the 3516 game settings (GMST). These six are not INI settings in the sense of G02. The first two classes are `INISetting` and `INIPrefSetting`. These names are GUESS.

**Verified (static reading).** 25 objects in the two INI classes have a name without `:Section`. Examples are `fHUDOpacity`, `bSaveOnRest`, `bCrosshairEnabled`, `fSkyCellRefFadeDistance` and `bUseWaterHDR`. The per-setting read `0x140fd0e10` splits the name at the first colon. When there is no colon, it uses the string at `0x141a69e40`, which is `MAIN`, as the section. So these keys are read from `[MAIN]`. The full table lists them with the section `(none; read under MAIN)`. Two sectionless objects share the name `sControlsDefinitionFile` and have different values.

**Verified.** Coverage of the priority sections. The count ignores case and the trailing space that three `Display` names carry in the image.

| Section | Settings | Section | Settings |
|---|---|---|---|
| Display | 303 | Controls | 107 (plus 2 whose section text is `:Controls`) |
| LOD | 33 | Imagespace (two spellings) | 7 |
| TerrainManager | 11 | Weather | 10 |
| Grass | 18 | Actor | 3 |
| Trees | 7 | Audio (two spellings) | 57 |
| Water | 35 | Camera | 83 |

That is 674 settings in the 12 priority sections (676 with the two `:Controls` keys). The other 1182 settings are in 58 further sections. The largest are Interface 228, General 159, Pathfinding 110, Combat 63, BudgetCaps 50 and Animation 50. The appendix lists the 676 priority settings. The full table of 1858 rows (name, section, type, compiled default, shipped value, class, read order, object RVA) is held privately and goes to the requester outside this repository.

**Verified.** Completeness. The author found the objects by name strings. The first table missed ten sectioned objects and the 25 sectionless objects. The reviewer found them by walking the static initialisers that call the collection getters. The third run then scanned the image data for the object layout, without a name search. That scan found 1857 objects, which equals the reviewer's count (1851 INI and Pref objects plus 6 game-setting-class objects). The two scans use different methods. Both find 5367 registered objects in total, with the 3516 game settings. The ten sectioned settings that the first table missed are `bDisableCombatDialogue:Combat`, `fAimUpDegrees:Combat`, `bUseKinect:Controls`, `iNumHotkeys:Controls`, `fLODFadeOutObjectMultComplex:LOD`, `fLODLandDropAmount:LOD`, `fMapLocalHeight:MapMenu`, `uCreationsResolvedEnvironment:Bethesda.net`, and `fKeyboardRepeatDelay` and `fKeyboardRepeatRate` with section text `:Controls`. All 40 requested keys resolve. Eight names with spaces exist (`uInterior Cell Buffer`, `uExterior Cell Buffer`, `bCreate Maps Enable`, `iSize W`, `iSize H`, `iLocation X`, `iLocation Y`, `bFull Screen`).

**Verified.** Comparison of the regenerated table with the reviewer's extractor. The reviewer's scripts were run again. They return the same 1851 INI and Pref objects as the saved review. The regenerated table has 1858 rows. The comparison key is (setting, section, type, value). Result: **0 differences**. The 1857 object addresses are identical. For all 1857 static objects, the static value field equals the reviewer's value (0 differences, strings compared in full). For the 13 initialiser settings (G06), the table prints the initialiser value, and the comparison uses the initialiser values from the review. `iNumThreads:HAVOK` has no static object and is compared by its constructor value.

**Limitations.** A setting created in code at run time with no registration in a static initialiser would be missed. `fMaxDistanceMoved:Pathfinding`, `fSteamPollInterval:Bethesda.net`, `fSteamPollDuration:Bethesda.net` and the sectionless `sControlsDefinitionFile` each have two objects. See G06.

**Confidence: high** for the values and addresses. **Medium-high** for "complete", because it rests on initialiser and structure scans.

### G02. How the INI files are loaded, and which value wins (verified code reading, medium-high; launcher and presets unverified)

**Verified.** The image has four file-name strings in a pointer table at `0x1420b57a8–0x1420b57c0`: `Skyrim.INI`, `SkyrimCustom.ini`, `SkyrimPrefs.ini` and `Skyrim_default.ini`. It has no string for `Low.ini`, `Medium.ini`, `High.ini` or `Ultra.ini`.

**Verified.** Start-up `0x140652ab0` calls `0x14065db50` at `0x140652b87`. That function builds the My Games folder path. It then forms the full path of `Skyrim.INI` and tests it with `_access`. If the file is missing, it calls `CopyFileA` from `Skyrim_default.ini` to `Skyrim.INI` with fail-if-exists set (`0x14065dd0a–0x14065dd3d`). So `Skyrim_Default.ini` is a first-run template. The image never reads settings from it.

**Verified.** Start-up then loads four files. Each load sets the collection's path, then makes the virtual calls at `+0x28`, `+0x48` and `+0x30`.

| Step | Site | Collection | File |
|---|---|---|---|
| 1 | `0x140653195` | `INISetting` singleton | `Skyrim.INI` |
| 2 | `0x14065321d` | `INISetting` singleton | `SkyrimCustom.ini` |
| 3 | `0x1406532a2` | `INIPrefSetting` singleton | `Skyrim.INI` |
| 4 | `0x140653327` | `INIPrefSetting` singleton | `SkyrimPrefs.ini` |

**Verified.** The `+0x48` call walks the collection's settings and calls the per-setting read `0x140fd0e10` through the collection's vtable slot `+0x20`. The `INISetting` walker is `0x1401924c0`. The `INIPrefSetting` walker is `0x140cede70`. It then calls slot `+0x38`, which only returns true. The per-setting read uses `GetPrivateProfileStringA` or `GetPrivateProfileIntA` with the section and key split from the name string. The part after the first colon is the section. With no colon the section is `MAIN`. For bool, int and unsigned, the default argument is the current value, so an absent key leaves the value as it was. A present key replaces it (`0x140fd1128–0x140fd1167`). For floats, the code prints the current value with `%f` as the default text, reads the key, and parses the result with `%f` (`0x140fd0f82–0x140fd0ff1`). Strings use the current string as the default (`0x140fd0f24`). Colours use an empty default (`0x141b58020`). So an absent key changes nothing for strings and colours.

**Inferred.** The rule for one setting: start at the compiled default. Apply `Skyrim.INI` if the key is in it. Then apply `SkyrimCustom.ini` for an `INISetting`, or `SkyrimPrefs.ini` for an `INIPrefSetting`. The last file with the key wins. This is why a `Skyrim_Default.ini` value (copied into the player's `Skyrim.ini`) beats the compiled default. It is also why the four `INIPrefSetting` keys in the template (`fGrassMinStartFadeDistance`, `fGrassMaxStartFadeDistance`, `fTreesMidLODSwitchDist`, `fLightLODStartFade`) take effect, although they sit in a file other than `SkyrimPrefs.ini`. Medium-high confidence. No run confirmed the order.

**Inferred.** Float rounding. The float default text is `%f`. So an absent float key still goes through a six-decimal round trip. A compiled value with more than six decimals changes slightly after load. Examples are `fMaxTime:HAVOK` (compiled 0.01666667 would become 0.016667) and `fMaxTimeComplex`. Values with six decimals or fewer are unchanged. **Unverified:** this has no run check. Low-medium confidence.

**Verified.** All four preset files contain the same 35 keys. 33 of them resolve to an `INIPrefSetting` and none to an `INISetting`. The other 2 (`iMaxDecalsPerFrame`, `iMaxSkinDecalsPerFrame` under `[Decals]`) match objects in section `Display`, also `INIPrefSetting` (G08). No key appears in both the template and a preset. So the presets address `SkyrimPrefs.ini`.

**Inferred.** The launcher writes the chosen preset into `SkyrimPrefs.ini`. The image has no preset name. The launcher executable has the wide strings `Ultra` and `Skyrim_Default`. The launcher was not analysed. So the write order, the trigger and any partial write are **unverified**. If the launcher applies no preset, the compiled value or the template value stays.

**Alternatives.** (a) The player's `Skyrim.ini` is stale or edited and lacks a key. Then the compiled default is in force. (b) The game writes every setting back to `SkyrimPrefs.ini` on exit. Then a template value for an `INIPrefSetting` enters `SkyrimPrefs.ini` and wins on later runs.

**Confidence: high** for the file names, the copy behaviour, the four load steps and the per-setting read. **Medium** for the combined rule and its use for Mudcrab defaults. Runtime logging of file opens would settle it.

### G03. `fSplitOverlap` (verified, high; units inferred)

**Verified.** The value field `0x1420d94e8` has two code reads: `0x141580086` (adds `O` to each far endpoint) and `0x141581657` (multiplies `O` by 2.0 and subtracts the product from the far endpoint to get the next near endpoint). The constants at `0x141b5be14` and `0x141b5be44` are 0.5 and 2.0. Per-cascade fractions come from `0x14157ff1c–0x14157ffb5`. The first fraction is `t0 = min(D/N, max(fFirstSliceDistance, 500)) / D`, where `D` is `fShadowDistance`. For `N >= 2`, `t_i = t0 + (1 - t0) * i / (N - 1)`. Each far endpoint is stored at light `+0x5a4 + 4i`. Each near endpoint is stored at `+0x598 + 4i` (`0x141580070`, `0x14158008e`). This agrees with the earlier sun-shadows draft. The reviewer decoded it again. The merged sun-shadows finding states the same formula and treats the units as verified (shader reading).

**Inferred.** Units. The formula mixes `O` with the camera near and far distances. So `O` is in the same view-distance units as those (game units). A default of 100 gives a 200-unit overlap band.

**Unverified.** Which render path consumes the near and far arrays for blending (the earlier draft covers the shader fade). Behaviour for `iNumSplits` above 3. The reviewer did not re-derive the sources of `n` and `F`.

**Confidence: high** for the formula and the single global use. **Medium** for the unit statement.

### G04. Shadow bias scales (producers verified high; shader link inferred medium; units low)

**Verified.** `fShadowBiasScale` has one read, at `0x14155c56a` in the base shadow-light constructor `0x14155c4b0`. It stores the float at light `+0x540`. Four construction sites call this base constructor: `0x14157e4ba` (directional), and `0x141587317`, `0x141587659`, `0x141587fbe` (local classes).

**Verified.** The directional constructor `0x14157e490` runs the base constructor, then stores `0x42700000` (60.0) at `+0x540` (`0x14157e8a3`). So a directional light does not keep `fShadowBiasScale`. The constructor has one caller, `0x14150bdb4`.

**Verified.** The local-light creation function `0x14150c810` calls `0x1415872e0` (`0x14150c906`) or `0x141587f90` (`0x14150c939`, `0x14150c95e`). Those are the only callers of both. The creation function `0x14150c810` has two more callers, at `0x14150c7f4` and `0x14150ce40`. They were not traced. After creation, it stores a descriptor float at `+0x540` (`0x14150c970`). The descriptor float comes from one of two producers. A placed-light call site at `0x1402748a6–0x1402748c0` takes it from `0x140300250`. That function returns a float from `0x14016c9c0` for the object at `+0x70` when a type byte is `0x1f`, else 0. The loading-menu site at `0x14098c189–0x14098c1d6` takes it from the setting `fLoadingMenuShadowBias:Display` (compiled 30.64, value field `0x1420bbde8`). So in these paths `fShadowBiasScale` has no lasting effect. A second overload at `0x141587620` has no direct caller that was found. **Unverified:** whether it is used, and whether other creators exist.

**Verified.** `fShadowDirectionalBiasScale` has one read, at `0x1415688f4`, in the per-light constant writer (function chunks `0x141568300–0x141568964`). Let `r` be true when two virtual predicates on the light (`+0x28`, `+0x38`) both return false. The base class and the directional class return false from both (`0x14155dbb0`, `0x14155dbc0`). The two local classes each return true from one (`0x141587f80` for the class built at `0x1415872e0`, `0x141588e30` for the class built at `0x141587f90`). So `r` is true for directional lights and false for local ones. The writer computes, with `B` = light `+0x540`:

```text
k = r ? fShadowDirectionalBiasScale : 1.0                 (1.0 at 0x141b5be28)
y = B * 0.00025 * k * G
z = B * 8.3333e-05 * S * G
```

The constants `0x141b4aca8` (0.00025 = 1/4000) and `0x141b4aca4` (8.3333e-05 = 1/12000) are literal floats. `S` is the float at `0x1420d8ffc`. `G` is the float at `0x1434869b0`. Their only writes are the stores of 1.0 at `0x1414eaeb1` and `0x1414eaea7`. `G` (`0x1434869b0`) is 0.0 in the file image (zero-initialised data). It becomes 1.0 only through the store at `0x1414eaea7`. `S` (`0x1420d8ffc`) is 1.0 in the image. If the writer ran before that store, `y` and `z` would be 0. **Unverified:** the run order of the store at `0x1414eaea7` and the writer. The default values 0.0045 and 0.005 assume the store ran first. No other write through a pointer was found. The writer stores `y` and `z` once per light, in the light's own constant block, at float offsets +1 and +2 of a slot index read from a byte in the active shader descriptor (`+0x40`). The writer is not per cascade.

**Verified, derived.** With the default settings the directional light gets `y = 60 * 0.00025 * 0.3 = 0.0045` and `z = 60 / 12000 = 0.005`. A local light with descriptor bias `b` gets `y = b / 4000` and `z = b / 12000`. Both results assume the store at `0x1414eaea7` ran first.

**Verified.** The decoded shadow-mask pixel shader for key `0x202002` reads `cb2[2].y` and `cb2[2].z`. It picks `cb2[2].y` as the bias for the first cascade and `cb2[2].z` for later cascades. It subtracts the bias from the receiver's light-space depth, then lights the pixel when the sampled depth is at least that result.

**Inferred.** The writer's slot index equals 2, so that `y` and `z` are the `cb2[2].y` and `.z` the shader reads. The index byte comes from the active shader's descriptor, set at run time. It was not read. Medium confidence. Likewise, "normalised depth units" for the bias is inferred from the shader compare. Low confidence.

**Unverified.** Whether the group 7 variants other than `0x202002` read the same slots. Whether the local-light shaders read these floats. Whether the `0x1433d3e90` branch or the flag at light `+0x558` changes the bias block (the bias block runs after both, `0x1415688a9`).

**Confidence: high** for who reads each setting, the construction order and the formulas. **Medium** for the shader link. **Low** for units. The vtable-to-constructor binding for the two virtual predicates is by slot contents (`0x14155dbb0`, `0x14155dbc0`, `0x141587f80`, `0x141588e30`). The reviewer did not re-derive it. A second reading of the construction sites would settle it.

### G05. Compiled facts for the requested keys (verified, high for the compiled side)

**Verified.** Four requested keys have compiled facts that earlier lists may not carry. For `bOutputSaveGameScreenshot`, `fMaxDistanceMoved`, `sResourceArchiveList` and `sEnvironment`, the compiled value differs from a community list of defaults. The table gives the compiled side only.

| Setting | Compiled (1.7.104) | Note |
|---|---|---|
| `bOutputSaveGameScreenshot:SaveGame` | 1, `0x1420b5518` | One read in the image (`0x14061ec96`). No write found. |
| `fMaxDistanceMoved:Pathfinding` | two objects: 5 (`0x1420d44f0`) and 50 (`0x1420d4508`) | The consumers are not directly referenced, so which object the game reads is **unverified**. |
| `sResourceArchiveList:Archive` | 11 archives, ending with `MarketplaceTextures.bsa` and `Skyrim - Patch.bsa` | The shipped `Skyrim_Default.ini` lists 7 other archives (G07). |
| `sEnvironment:Bethesda.net` | `AUTO` | Upper case. |

Static field differs, effective value follows the initialiser (G06): `uExterior Cell Buffer`, `fAutosaveEveryXMins`, `iDifficulty`, `bGamePadRumble`, `fGamepadHeadingSensitivity`, `bShowFloatingQuestMarkers`, `fLightLODStartFade`, the five sectionless keys listed in G06, and `bFootIK`, `bGrabIK` and `bPoseMatching` in `RagdollAnim`.

Float compiled values with more than four decimals: `fMapMenuOverlayScale` 3.5e-05, `fMapMenuOverlaySnowScale` 4.5e-05, `fMaxTime:HAVOK` 0.01666667 and `fMaxTimeComplex` 0.03333333. Colours have a fourth byte: `rConsoleTextColor` alpha 255, `rConsoleHistoryTextColor` 153 (colour 153,153,153), `rDebugTextColor` 255 and the six `rUIMistMenu_*` colours 0. `strPluginsFileHeader` has two lines. The four `uPersistentUuidData` values are 0.

**The 43 listed keys.** All are compiled in the image. The table gives the type and the compiled default. The first block contains the 40 requested keys. The three marked `+` were not in the requested list. The six `Interface` rows belong to the game-setting class (G01).

| Section | Setting | Type | Compiled default |
|---|---|---|---|
| Bethesda.net | `bEnableBNetDebugOutput` | bool | 1 |
| Bethesda.net | `fMarketplaceIntroWarningDisplayTime` | float | 5 |
| Bethesda.net | `uDownloadBufferSize` | unsigned | 0 |
| Bethesda.net | `uUploadBufferSize` | unsigned | 0 |
| Controls | `bEnableGestureDualSwing` | bool | 1 |
| Controls | `bEnableGesturePowerAttackByAccel` | bool | 1 |
| Controls | `bEnableGesturePowerAttackByInput` | bool | 1 |
| Controls | `bEnableSixaxisBowAiming` | bool | 0 |
| Controls | `bEnableSixaxisLockpicking` | bool | 0 |
| Controls | `bEnableSixaxisMagicAiming` | bool | 0 |
| Controls | `bGestureEngageButtonsRequired` | bool | 1 |
| Controls | `bRequireSixaxisLockpickingEngageLeft` | bool | 1 |
| Controls | `bSixaxisAimingRespectsFOV` | bool | 1 |
| Controls | `bSixaxisAimingRespectsTimeMultiplier` | bool | 1 |
| Controls | `fGesturePowerAttackAccelThreshhold` | float | 4 |
| Controls | `fLockResetSixaxisWiggleRoom` | float | 0.08 |
| Controls | `fLockTurnSixaxisMinThreshhold` | float | 0.06 |
| Controls | `fSixaxisAlphaMaxThreshold` | float | 0.05 |
| Controls | `fSixaxisAlphaMin` | float | 0.15 |
| Controls | `iGestureShieldTickBuffer` | int | 200 |
| Controls | `iMountedGestureAttackBuffer` | int | 600 |
| CreationsMenu | `bMusicOn` | bool | 1 (code also writes it, `0x140580493`, `0x140581be5`) |
| Display | `bSynchronizeDynamicWidthAndHeight` | bool | 0 |
| Display | `uShadowFilterType` | unsigned | 3 |
| Gameplay | `bCheckForMissingContentOnStartup` | bool | 1 (code also writes it, `0x140623d90`) |
| General | `bFreebiesSeen` | bool | 0 (code also writes it, `0x14095d05c`) |
| General | `bUpsellOwned` | bool | 0 (code also writes it) |
| General | `fJoyConStrapInstructionDelay` | float | 5 |
| General | `sStartingConsoleCommand` | string | empty |
| Interface | `fDoorMarkerDisplayHeight` | float | 64 |
| Interface | `fShoutMeterFinishTime` | float | 3 |
| Interface | `iCreditsFileMaxLinesLength` | int | 1000 |
| Interface | `iEnemyHealthDisplayAngle` | int | 90 |
| Interface | `iEnemyHealthDisplayTime` | int | 2000 |
| Interface | `iFavoritesDisplayTime` | int | 3000 |
| Interface | `iObjectivesWaitTime` | int | 250 |
| Menu | `bUseConsoleHotkeys` | bool | 0 |
| Menu | `sConsoleDefaultINI` | string | `SkyrimConsoleDefault.ini` |
| Menu | `sConsoleINI` | string | `SkyrimConsole.ini` |
| OAuth | `sGameCode` | string | empty |
| + Camera | `f1stPitchOffsetSixaxisMaxLag` | float | 10 |
| + Camera | `f1stPitchOffsetSixaxisMaxSnapDelta` | float | 0.15 |
| + General | `uiMarketplaceUpdatedHash` | unsigned | 4294967295 (code also writes it, `0x14060044c`) |

None of the 40 requested keys is in `Skyrim_Default.ini` or a preset. `uShadowFilterType` has a compiled default of 3.

**Confidence: high** for the compiled values. The community list is a third-party source for an unstated version. The reviewer did not read it. Any statement that a compiled value "differs from the list" is **unverified** by the reviewer.

### G06. Settings whose static field is not the final default (verified, high)

**Verified.** Thirteen settings have a static initialiser that stores a computed default after the static object is built. For each, the static field is 0, and the initialiser's value is the compiled default. The full table prints the initialiser value. The appendix marks it with †.

| Setting | Static field | Default after the initialiser | Initialiser |
|---|---|---|---|
| `uExterior Cell Buffer:General` | 0 | 36 = (`uGridsToLoad` + 2) * `uGridsToLoad` + 1, with `uGridsToLoad` = 5 | `0x14000c560` (store `0x14000c582`) |
| `fAutosaveEveryXMins:SaveGame` | 0 | 15 | `0x14009a4e0` (constant `0x1418a6e48`) |
| `iDifficulty:GamePlay` | 0 | 2 | `0x1400a6110` (constant `0x1418a6e30`) |
| `bGamePadRumble:Controls` | 0 | 1 | `0x1400a9ce0` (constant `0x1418a6e20`) |
| `bInvertYValues:Controls` | 0 | 0 | `0x1400a9fb0` (constant `0x1418a6e14`) |
| `fGamepadHeadingSensitivity:Controls` | 0 | 0.66672 (copy of `fGamepadHeadingSensitivityDefault`) | `0x1400aa4a0` |
| `bShowFloatingQuestMarkers:GamePlay` | 0 | 1 | `0x1400c3570` (constant `0x1418a6e34`) |
| `fLightLODStartFade:Display` | 0 | 1000 (copy of `fLightLODDefaultStartFade`) | `0x1401001b0` |
| `bSaveOnRest` (no section, read under `MAIN`) | 0 | 1 | `0x1400c3390` (constant `0x1418a6e38`) |
| `bSaveOnWait` (no section) | 0 | 1 | `0x1400c34d0` (constant `0x1418a6e3c`) |
| `bSaveOnTravel` (no section) | 0 | 1 | `0x1400c3430` (constant `0x1418a6e40`) |
| `bSaveOnPause` (no section) | 0 | 0 (constant `0x1418a6e44` is 2.0, not 1.0) | `0x1400c32f0` |
| `fHUDOpacity` (no section) | 0 | 1 | `0x1400c3a80` (constant `0x1418a6e54`) |

The last five are `INIPrefSetting` objects. The first table listed only the first eight because it skipped sectionless names (G01).

**Verified.** Three settings are forced to 0 after the INI files load. Start-up code `0x1403fd7f0`, called at `0x1406535f4` after the four loads, stores 0 to `bFootIK`, `bGrabIK` and `bPoseMatching` in `RagdollAnim` (`0x1403fd7ff`, `0x1403fd806`, `0x1403fd80d`). Their static fields are 1. So the `RagdollAnim` INI keys have no lasting effect (static reading).

**Verified.** 71 other settings (not counting the thirteen initialiser settings and the three above) have direct code writes outside the INI reader. The scan finds 87 distinct objects with a direct rip-relative store: 13 + 3 + 71. Examples: the display and reflection tuning group written from `0x14037e4e0`, the slider mapping function `0x14065ca50` and the terrain block distances at `0x14036ef40`. What each write means was not traced. Their static field remains the "compiled default" in the table. A write may replace the value after load. `iScreenShotIndex` is incremented, not set. The full table notes up to three write sites for each.

**Verified.** Two objects share a name with different defaults for `fMaxDistanceMoved:Pathfinding` (5 and 50). Two sectionless objects named `sControlsDefinitionFile` also have different values. `fSteamPollInterval` and `fSteamPollDuration` (Bethesda.net) have two objects with equal defaults.

**Confidence: high.** An initialiser that was not found (for example one that writes through a pointer) would change a row. The scan finds direct writes only.

### G07. Template and preset values against the compiled defaults (verified, high)

**Verified.** 27 keys in `Skyrim_Default.ini` differ from the compiled default. Besides the conflicts above: `uMaxSkinDecalPerActor` 60 (compiled 25), `bUseNavMeshForMovement` 0 (1), `fDDOFFocusCenterweightExt` 2 (1.6), `fMagnetismStrafeHeadingMult` 0.0 (0.5), `fMagnetismLookingMult` 0.0 (10), `fPostLoadUpdateTimeMS` 500 (2000), `bLoadArchiveInMemory` 1 (0), `fLightLODStartFade` 3500 (1000), `fDOFMaxDepthParticipation` 10000 (50000), `fDynamicDOFFarBlur` 0.4 (0.7), `sTestFile1` and the other archive and test lists. The full table shows the template value in the `shipped INI value` column. Long text and file-name lists appear as `<text, N chars, omitted>` or `<list, N chars, M items>`.

**Verified.** Ultra differs from the compiled default in 12 keys: `fLODFadeOutMultActors` 15 (compiled 6), `fLODFadeOutMultItems` 10 (3), `fLODFadeOutMultObjects` 30 (5), `uLargeRefLODGridSize` 11 (9), `fBlockLevel0Distance` 60000 (35000), `fBlockLevel1Distance` 90000 (70000), `fMeshLODLevel1FadeDist` and `fMeshLODLevel2FadeDist` 999999 (9999999), `iVolumetricLightingQuality` 2 (1), `bUse64bitsHDRRenderTarget` 1 (0), `iShadowMapResolution` 4096 (2048) and `fShadowDistance` 10000 (8000). The other 21 resolved Ultra keys, and the two `[Decals]` lines (G08), equal the compiled default. Mudcrab's "Ultra where presets differ" rule needs only these 12 overrides.

**Confidence: high.**

### G08. Shipped INI keys the image does not use (verified absence, medium-high)

**Verified.** Five keys in `Skyrim_Default.ini` have no matching setting: `fShadowLODMaxStartFade`, `fSpecularLODMaxStartFade`, `fLightLODMaxStartFade`, `iShadowMapResolutionPrimary` and `bAllowScreenshot` have no name string anywhere in the image (case-insensitive, ASCII and UTF-16LE). `uExterior Cell Buffer` matches an object (G06). The merged sun-shadows finding already reports zero hits for the first two names. So the earlier "unverified" notes on `iShadowMapResolutionPrimary` and `fShadowLODMaxStartFade` in the draft of that finding are settled. This reading is by name string. A name built at run time would escape the search (unlikely).

**Verified, inferred use.** The four presets list `iMaxDecalsPerFrame` and `iMaxSkinDecalsPerFrame` under `[Decals]`. The image's settings carry those names in section `Display` (compiled 100 and 25). **Inferred:** the reader asks for section `Display`, so the preset lines under `[Decals]` do not apply. Medium confidence. Both are `INIPrefSetting`.

**Confidence: high** for absence by string. **Medium** for the `[Decals]` effect.

## Interpretation and alternatives

The compiled default is a fallback. For most keys in `Skyrim_Default.ini` it is not what a player sees. The template value comes first, then the player's other file. A retail default for Mudcrab is "the value in force" under the static reading in G02. No run confirmed it. Use the last column of the Answer table, not the compiled column, for those rows.

Alternatives and limits. (a) A player with an old `Skyrim.ini` that lacks a key keeps the compiled value. (b) The launcher may write the preset in a way that was not traced. (c) A runtime write may replace a static field (G06). (d) A community list of defaults can come from another build. So a compiled difference from it (G05) says nothing about the 1.7.104 behaviour.

## Relation to earlier findings

- **#806** (sun shadows and interior shadow-light admission): G03, G04 and G08 build on its cascade, bias and key facts and settle two of its "unverified" key notes. No correction to #806.
- **#812** (exterior fog retail facts): the reviewer compared its default claims with the table and found no conflict. No correction to #812.
- **#816** (object LOD segment order and large-reference suppression): the reviewer found no conflict between its default claims and the table. No correction to #816.
- **#821** (large-reference selection, loading and object LOD suppression): the reviewer found no conflict between its default claims and the table. No correction to #821.
- **#822** (terrain LOD shading retail facts): the terrain drafts cite `fLODLandDropAmount:LOD` = 230 (value field `0x1420b5e78`). It equals the compiled default and now has a table row. No correction to #822.

The reviewer checked 70 default or value claims across five merged findings and 14 drafts. 50 agree with the table. The other 20 flagged lines carry no default claim. No value in the earlier findings is wrong. Published corrections stay in force.

## Independent review (2026-11-24 CST)

Reviewer: a separate fresh-context run of `claude-sonnet-5-5`. The reviewer is not the author. A Sol run was not available because of usage limits. The reviewer saved an independent extraction (Part 1) before reading the draft, the table or the author's files. Verdict: **corrected**. Outcome per group: 3 confirmed (G03, G05 compiled side, G07), 5 corrected (G01, G02, G04, G06, G08). 0 rejected. All corrections are applied in this file.

What the reviewer corrected:

- G01. The first table omitted 35 registered settings: 10 sectioned and 25 sectionless. The totals and four section counts were wrong. The statement that sectionless names are game settings was wrong. They are INI-class settings read under `MAIN`.
- G02. One second walker address, and wording.
- G04. `G` is 0.0 in the file image until a store. Two more callers of the creation function exist. The vtable binding was not re-derived.
- G06. The static-initialiser exceptions are 13, not 8. Five are sectionless.
- G08. Five keys, not six.
- Hygiene. The draft contained a column of third-party values and a remark about a private player file. Both are removed.

Error rates. The reviewer checked a random sample of 150 settings (seed 20261124) from the 659 settings of the 12 priority sections. **1 of 150** was wrong. It was a coverage error (a missing row). There was no value error. The reviewer then checked all 1823 table rows against its own extraction by object address. **0 of 1823** had a wrong value, name, type or class. 35 registered objects were missing from the table (1.9 percent of 1857 objects). The 12 priority conflict keys were checked for value, type, section, domain and address. 0 were wrong.

The reviewer matched the load order, the four load steps, the first-run copy, the read semantics and the shadow formulas by an independent code reading. After the corrections, a third run regenerated the table and compared it with the reviewer's extractor (G01). That comparison found 0 differences.

Source exposure of the review: the pinned executable, the five shipped INI files and the author's draft after Part 1. The reviewer did not read the community list and did not open any player file. This review is a static review. It is not match evidence for any function, and it does not decide transfer eligibility.

Reviewer and outcome: reviewed independently by a separate `claude-sonnet-5-5` run. Outcome: 3 confirmed, 5 corrected, 0 rejected. Static evidence only. Transfer status: UNREVIEWED.

## Negative results and limitations

* Static only. No game process and no trace was run. Every "in force" statement rests on reading code and files.
* The launcher is a separate binary and is not pinned. Its preset logic was not decoded. A string scan found `Ultra` and `Skyrim_Default` as wide strings. Which preset file reaches `SkyrimPrefs.ini` is **unverified**.
* Runtime behaviour is **unverified**: the file open order, the final value of any setting, the run order of the store at `0x1414eaea7` and the bias writer, and which object of a duplicated name the game reads.
* The six `Interface` objects with vtable `0x1417e0360` belong to the game-setting class (getter `0x1401499e0`). No file read was traced for them.
* The descriptor byte that gives the bias slot index was not traced. The consumers of two of the writer's constants beyond the shader read in G04 were not traced.
* The tables leave out game text. Strings with spaces appear as `<text, N chars, omitted>`. File-name lists (`sResourceArchiveList`, `sResourceArchiveList2`, `sArchiveToLoadInMemoryList`, `sArchiveList`, `sEsmToLoadInMemoryList`) appear as `<list, N chars, M items>`.
* Game settings (GMST, getter `0x1401499e0`) are not covered. Sectionless INI-class names are covered (G01).
* The community list is a third-party source with no stated version. It is not evidence about 1.7.104. This file gives no value from it.
* A direct code-write scan finds writes through RIP-relative operands only.

## Appendix: compiled defaults of the priority sections

Each table lists the settings of one priority section, sorted by name. `File` is `I` for the `Skyrim.ini` domain (`INISetting`) and `P` for the `SkyrimPrefs.ini` domain (`INIPrefSetting`). The value is the compiled default (static field of the object). A † marks a value that a static initialiser computes (G06). A ‡ marks a setting that other code also writes after the load (G06). Colours print `R,G,B,A`. Section names are matched without case. The two `:Controls` keys follow the Controls table. The other 1182 settings are in the private full table.

### Display (303)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bActorSelfShadowing` | bool | I | 0 |
| `bAllowShaderCache` | bool | I | 1 |
| `bAssertOnShaderCompileAtRuntime` | bool | I | 1 |
| `bAutoViewDistance` | bool | I | 0 |
| `bBorderless` | bool | P | 0 |
| `bBreakOnValidationError` | bool | I | 1 |
| `bBreakOnValidationWarning` | bool | I | 0 |
| `bCharacterLighting` | bool | I | 1 |
| `bCompensateUnstableFrameTime` | bool | I | 1 |
| `bCompileOnRender` | bool | I | 1 |
| `bCreateShadowRenderTarget` | bool | I | 0 |
| `bDeactivateAOOnSnow` | bool | I | 1 |
| `bDirShadowMapFullViewPort` | bool | I | 1 |
| `bDisableHighTreeShadow` | bool | I | 1 |
| `bDisableShadowJumps` | bool | I | 1 |
| `bDisableZPrepassOutput` | bool | I | 0 ‡ |
| `bDo30VFog` | bool | I | 1 |
| `bDOFApplyCenterWeight` | bool | I | 1 |
| `bDOFBilateralBlur` | bool | I | 1 |
| `bDoTestHDR` | bool | I | 0 |
| `bDownSampleNormalSSR` | bool | I | 1 ‡ |
| `bDrawLandShadows` | bool | P | 0 |
| `bDynamicDOF` | bool | I | 1 |
| `bEnableAutoDynamicResolution` | bool | I | 0 ‡ |
| `bEnableDownsampleComputeShader` | bool | I | 1 ‡ |
| `bEnableFrontToBackPrepass` | bool | I | 0 |
| `bEnableImprovedSnow` | bool | P | 1 |
| `bEnableLandFade` | bool | I | 1 |
| `bEnableParallaxOcclusion` | bool | I | 0 ‡ |
| `bEnableProjecteUVDiffuseNormals` | bool | P | 1 ‡ |
| `bEnableProjecteUVDiffuseNormalsOnCubemap` | bool | I | 0 |
| `bEnableSnowMask` | bool | I | 1 |
| `bEnableSnowRimLighting` | bool | I | 1 |
| `bEnableStippleFade` | bool | I | 1 |
| `bEnableVolumetricLighting` | bool | I | 0 |
| `bForceCreateTarget` | bool | P | 0 |
| `bFull Screen` | bool | P | 0 |
| `bFXAAEnabled` | bool | P | 0 |
| `bIBLFEnable` | bool | P | 1 |
| `bImageSpaceEffects` | bool | I | 1 |
| `bIndDownscaled` | bool | I | 0 |
| `bIndEnable` | bool | P | 0 |
| `bIndNormalMap` | bool | I | 1 |
| `bLoadMarkers` | bool | I | 1 |
| `bLockFramerate` | bool | I | 1 |
| `bLodZPrepass` | bool | I | 1 |
| `bLowHealthIModEnabled` | bool | I | 1 |
| `bOutputMissingTexture` | bool | I | 1 |
| `bProjectileOnReflection` | bool | I | 0 ‡ |
| `bSAO_CS_Downscaled` | bool | I | 0 |
| `bSAO_CS_Enable` | bool | P | 0 |
| `bSAOApplyFog` | bool | I | 1 |
| `bSAODownscaled` | bool | I | 0 |
| `bSAOEnable` | bool | P | 1 |
| `bSAONormalMap` | bool | I | 1 |
| `bScreenSpaceReflectionEnabled` | bool | P | 1 |
| `bShadowsOnGrass` | bool | I | 1 |
| `bShowMarkers` | bool | I | 0 |
| `bShowMenuTextureUse` | bool | I | 1 |
| `bSimpleLighting` | bool | I | 0 |
| `bSparklesOnly` | bool | I | 0 |
| `bStaticMenuBackground` | bool | I | 1 |
| `bSynchronizeDynamicWidthAndHeight` | bool | I | 0 |
| `bTAAWater` | bool | I | 0 |
| `bToggleSparkles` | bool | P | 1 |
| `bTreesReceiveShadows` | bool | P | 1 |
| `bUse16BitsDepthTarget` | bool | I | 1 |
| `bUse64bitsHDRRenderTarget` | bool | P | 0 |
| `bUseDeviceDebug` | bool | I | 0 |
| `bUseFilmicCurve` | bool | I | 0 |
| `bUseMultipleLuminanceReferences` | bool | I | 1 |
| `bUsePrecipitationOcclusion` | bool | P | 1 |
| `bUsePrecomputedNoise` | bool | I | 0 |
| `bUseSunbeams` | bool | I | 0 |
| `bUseTAA` | bool | P | 1 |
| `bValidateRenderTargets` | bool | I | 1 |
| `bVolumetricLightingDisableInterior` | bool | I | 1 |
| `bVolumetricLightingEnable` | bool | P | 1 |
| `bVolumetricLightingEnableTemporalAccumulation` | bool | I | 1 ‡ |
| `bVolumetricLightingUpdateWeather` | bool | I | 1 |
| `f1stPersonFarDepthRange` | float | I | 0.01 |
| `f1stPersonFarDepthRangeControlDriven` | float | I | 0.1 |
| `fAlphaWeight` | float | I | 1 ‡ |
| `fCharacterLightLumMax` | float | I | 0.75 |
| `fCharacterLightLumScale` | float | I | 2 |
| `fCharacterLightPrimaryLightIntensity` | float | I | 0.75 |
| `fCharacterLightSecondaryLightIntensity` | float | I | 0.3 |
| `fClampScale` | float | I | 0.4 ‡ |
| `fConstHDRAdaptTimerForMenu` | float | I | 0.3 |
| `fDDOFAngleThreshold` | float | I | 2 |
| `fDDOFFocusCenterweightExt` | float | I | 1.6 |
| `fDDOFFocusCenterweightInt` | float | I | 1 |
| `fDDOFFocusDelay` | float | I | 500 |
| `fDDOFFocusDuration` | float | I | 1000 |
| `fDDOFPositionThreshold` | float | I | 5 |
| `fDecalLifetime` | float | I | 30 |
| `fDecalLOD0` | float | I | 800 |
| `fDecreaseDRMilliseconds` | float | I | 32 |
| `fDefault1stPersonFOV` | float | I | 80 ‡ |
| `fDefaultFOV` | float | I | 80 |
| `fDefaultWorldFOV` | float | I | 80 ‡ |
| `fDOFCenterWeight` | float | I | 0.6 |
| `fDOFMaxDepthParticipation` | float | I | 50000 |
| `fDRClampOffset` | float | I | 0.002 |
| `fDRClampOffsetNeo` | float | I | 0.0005 |
| `fDynamicDOFBlurMultiplier` | float | P | 0.8 ‡ |
| `fDynamicDOFBlurMultiplierMax` | float | I | 1 |
| `fDynamicDOFBlurMultiplierMin` | float | I | 0 |
| `fDynamicDOFFarBlur` | float | I | 0.7 |
| `fDynamicDOFFarDist` | float | I | 1000 |
| `fDynamicDOFFarRange` | float | I | 10000 |
| `fDynamicDOFNearBlur` | float | I | 1 |
| `fDynamicDOFNearDist` | float | I | 100 |
| `fDynamicDOFNearRange` | float | I | 100 |
| `fExponentialShadowMapScale` | float | I | 10 |
| `fFilmicWhiteScale` | float | I | 1.4 |
| `fFilteringAlphaThreshold` | float | I | 0.01 |
| `fFilteringWaterDepthThreshold` | float | I | 0.005 |
| `fFirstSliceDistance` | float | I | 1250 |
| `ffocusShadowMapDoubleEveryXUnit` | float | P | 450 |
| `fGamma` | float | P | 1 ‡ |
| `fGammaMax` | float | I | 1.4 |
| `fGammaMin` | float | I | 0.6 |
| `fGlobalBloomThresholdBoost` | float | I | 0 |
| `fGlobalBrightnessBoost` | float | I | 0 |
| `fGlobalContrastBoost` | float | I | 0 |
| `fGlobalEyeAdaptSpeedScale` | float | I | 2 |
| `fGlobalEyeAdaptStrengthScale` | float | I | 0.4 |
| `fGlobalMapBloomThresholdBoost` | float | I | 0.25 |
| `fGlobalMapBrightnessBoost` | float | I | 0.25 |
| `fGlobalMapContrastBoost` | float | I | -0.3 |
| `fGlobalSaturationBoost` | float | I | 0 |
| `fIBLFAnamorphicsIntensity` | float | I | 0.1 |
| `fIBLFAnamorphicsIntensityFar` | float | I | 1 |
| `fIBLFBloomIntensity` | float | I | 0 |
| `fIBLFChannelsDistortionBlue` | float | I | -2 |
| `fIBLFChannelsDistortionGreen` | float | I | 0 |
| `fIBLFChannelsDistortionRed` | float | I | 2 |
| `fIBLFFlaresDispersal` | float | I | 0.3 |
| `fIBLFGlobalIntensity` | float | I | 0.7 |
| `fIBLFHaloFetch` | float | I | 0.5 |
| `fIBLFHaloWidthPow` | float | I | 3 |
| `fIBLFLightsBurn` | float | I | 1 |
| `fIBLFLightsRangeDownshift` | float | I | 1 |
| `fIncreaseDRMilliseconds` | float | I | 30 |
| `fIndBias` | float | I | 2.5 |
| `fIndIntensity` | float | I | 50 |
| `fIndRadius` | float | I | 100 |
| `fInteriorShadowDistance` | float | P | 3000 ‡ |
| `fLeafAnimDampenDistEnd` | float | P | 4600 |
| `fLeafAnimDampenDistStart` | float | P | 3600 |
| `fLightLODDefaultStartFade` | float | I | 1000 |
| `fLightLODRange` | float | I | 500 |
| `fLightLODStartFade` | float | P | 1000 † |
| `fLinePrimitiveWidth` | float | I | 8 |
| `fLoadingMenuShadowBias` | float | I | 30.64 |
| `fLoadingMenuShadowFallOff` | float | I | 0 |
| `fLowestDynamicHeightRatio` | float | I | 1 |
| `fLowestDynamicWidthRatio` | float | I | 0.7 |
| `fLowHealthIModInterval` | float | I | 2 |
| `fLowHealthIModStrengthMax` | float | I | 1.5 |
| `fLowHealthIModStrengthMin` | float | I | 0.8 |
| `fMaxFocusShadowMapDistance` | float | I | 450 |
| `fMaxHeightShadowCastingTrees` | float | I | 5000 |
| `fMeshLODFadeBoundDefault` | float | P | 256 |
| `fMeshLODFadePercentDefault` | float | P | 1.2 |
| `fMeshLODFadeTime` | float | I | 1 |
| `fMeshLODLevel1FadeDist` | float | P | 9999999 |
| `fMeshLODLevel1FadeTreeDistance` | float | P | 2844 |
| `fMeshLODLevel2FadeDist` | float | P | 9999999 |
| `fMeshLODLevel2FadeTreeDistance` | float | P | 2048 |
| `fMipBias` | float | I | 0 |
| `fNear1stPersonDistance` | float | I | 5 |
| `fNearDistance` | float | I | 15 |
| `fNoLODFarDistanceMax` | float | I | 10240 |
| `fNoLODFarDistanceMin` | float | I | 100 |
| `fNoLODFarDistancePct` | float | I | 1 |
| `fNonSpecularSparklesIntensity` | float | I | 0.4 |
| `fPoissonRadiusScale` | float | I | 4 |
| `fProjectedUVDiffuseNormalTilingScale` | float | P | 0.5 |
| `fProjectedUVNormalDetailTilingScale` | float | P | 1.2 |
| `fRatioDecreasePerSeconds` | float | I | 0.07 |
| `fRatioIncreasePerSeconds` | float | I | 0.03 |
| `fReflectionMarchingRadius` | float | I | 0.4 ‡ |
| `fReflectionRayThickness` | float | I | 0.001 ‡ |
| `fReflectionsIntensityScale` | float | I | 0.8 ‡ |
| `fReflectionsMotionVectorScale` | float | I | 1 ‡ |
| `fReinhardWhiteScale` | float | I | 1.1 |
| `fSAO_CS_Bias` | float | I | 2.5 |
| `fSAO_CS_Intensity` | float | I | 10 |
| `fSAO_CS_Radius` | float | I | 250 |
| `fSAOBias` | float | I | 2.5 |
| `fSAOExpFactor` | float | I | 0.11 |
| `fSAOIntensity` | float | I | 15 |
| `fSAORadius` | float | I | 250 |
| `fSAOValueDiffFactor` | float | I | 0.3 |
| `fScopeScissorAmount` | float | I | 0.3 |
| `fShadowBiasScale` | float | I | 1 |
| `fShadowClampValue` | float | I | 0.3 |
| `fShadowDirectionalBiasScale` | float | I | 0.3 |
| `fShadowDistance` | float | P | 8000 ‡ |
| `fShadowSparkleIntensity` | float | I | 0.25 |
| `fSnowGeometrySpecPower` | float | I | 3 |
| `fSnowNormalSpecPower` | float | I | 2 |
| `fSnowRimLightIntensity` | float | I | 0.3 |
| `fSnowSparklesColorB` | float | I | 1 |
| `fSnowSparklesColorG` | float | I | 1 |
| `fSnowSparklesColorR` | float | I | 1 |
| `fSnowSSSColorB` | float | I | 0.08 |
| `fSnowSSSColorG` | float | I | 0 |
| `fSnowSSSColorR` | float | I | 0 |
| `fSnowSSSDepthDiff` | float | I | 0.5 |
| `fSnowSSSStrength` | float | I | 50 |
| `fSparklesDensity` | float | I | 0.85 |
| `fSparklesIntensity` | float | I | 1 |
| `fSparklesMaxDistance` | float | I | 1000 |
| `fSparklesSize` | float | I | 6 |
| `fSparklesSpecularPower` | float | I | 2 |
| `fSpecMaskBegin` | float | I | 0.1 ‡ |
| `fSpecMaskSpan` | float | I | 0 ‡ |
| `fSpecularSparklesIntensity` | float | I | 1 |
| `fSplitOverlap` | float | I | 100 |
| `fSunShadowUpdateTime` | float | I | 1 |
| `fSunStaticTimeUpdateScale` | float | I | 0.1 |
| `fSunUpdateThreshold` | float | I | 0.5 |
| `fTAAEffectThreshold` | float | I | 0.1 |
| `fTAAHighFreq` | float | I | 0.8 |
| `fTAALowFreq` | float | I | 0.5 |
| `fTAAPostOverlay` | float | I | 0.21 |
| `fTAAPostSharpen` | float | I | 0.21 |
| `fTAASharpen` | float | I | 1 |
| `fTreesMidLODSwitchDist` | float | P | 3600 |
| `fVolumetricLightingCustomColorContribution` | float | I | 0 |
| `fVolumetricLightingDensityContribution` | float | I | 0.3 |
| `fVolumetricLightingDensityScale` | float | I | 300 |
| `fVolumetricLightingIntensity` | float | I | 2 |
| `fVolumetricLightingPhaseContribution` | float | I | 0.83 |
| `fVolumetricLightingPhaseScattering` | float | I | 0.85 |
| `fVolumetricLightingRangeFactor` | float | I | 40 |
| `fVolumetricLightingTemporalAccumulationFactor` | float | I | 0.75 ‡ |
| `fVolumetricLightingWindFallingSpeed` | float | I | 0.3 |
| `fVolumetricLightingWindSpeedScale` | float | I | 15 |
| `fWaterSSRBlurAmount` | float | I | 0.3 ‡ |
| `fWaterSSRIntensity` | float | I | 1.3 ‡ |
| `fWaterSSRNormalPerturbationScale` | float | I | 0.05 |
| `fWindGrassMultiplier` | float | I | 1 |
| `iAutoViewHiFrameRate` | int | I | 40 |
| `iAutoViewLowFrameRate` | int | I | 20 |
| `iAutoViewMinDistance` | int | I | 2000 |
| `iDebugTextLeftRightOffset` | int | I | 10 |
| `iDebugTextSubPage` | int | I | 0 |
| `iDebugTextTopBottomOffset` | int | I | 20 |
| `iEnableShadowCastingFlag` | int | I | 2 ‡ |
| `iLandscapeMultiNormalTilingFactor` | int | I | 4 |
| `iLoadingMenuShadowLightFlags` | int | I | 1 |
| `iLocation X` | int | I | 0 |
| `iLocation Y` | int | I | 0 |
| `iMaxDecalsPerFrame` | int | P | 100 |
| `iMaxSkinDecalsPerFrame` | int | P | 25 |
| `iNumFocusShadow` | int | P | 4 |
| `iNumSplits` | int | P | 2 |
| `iReflectionResolutionDivider` | int | P | 2 |
| `iSaveGameScreenShotHeight` | int | P | 192 |
| `iSaveGameScreenShotHeighWSt` | int | P | 192 |
| `iSaveGameScreenShotWidth` | int | P | 256 |
| `iSaveGameScreenShotWidthWS` | int | P | 320 |
| `iScreenShotIndex` | int | P | 0 ‡ |
| `iShaderPackageMemoryCap` | int | I | 409600 |
| `iShadowMapResolution` | int | P | 2048 |
| `iShadowMaskQuarter` | int | P | 4 |
| `iSize H` | int | P | 1080 |
| `iSize W` | int | P | 1920 |
| `iSnowSparklesColor` | int | I | 2 |
| `iSnowSSSCurrentColor` | int | I | 2 |
| `iTrilinearThreshold` | int | I | 3 |
| `iUnstableFrameTimeHistorySize` | int | I | 8 |
| `iVolumetricLightingNoiseTextureDepth` | int | I | 32 |
| `iVolumetricLightingNoiseTextureHeight` | int | I | 32 |
| `iVolumetricLightingNoiseTextureWidth` | int | I | 32 |
| `iVolumetricLightingQuality` | int | P | 1 |
| `iVolumetricLightingTextureDepthHigh` | int | I | 90 |
| `iVolumetricLightingTextureDepthLow` | int | I | 50 |
| `iVolumetricLightingTextureDepthMedium` | int | I | 70 |
| `iVolumetricLightingTextureFormatHigh` | int | I | 1 |
| `iVolumetricLightingTextureFormatLow` | int | I | 0 |
| `iVolumetricLightingTextureFormatMedium` | int | I | 1 |
| `iVolumetricLightingTextureHeightHigh` | int | I | 192 |
| `iVolumetricLightingTextureHeightLow` | int | I | 96 |
| `iVolumetricLightingTextureHeightMedium` | int | I | 128 |
| `iVolumetricLightingTextureWidthHigh` | int | I | 320 |
| `iVolumetricLightingTextureWidthLow` | int | I | 160 |
| `iVolumetricLightingTextureWidthMedium` | int | I | 224 |
| `iVSyncPresentInterval` | int | P | 1 |
| `sDebugText` | string | I | VATS |
| `sScreenShotBaseName` | string | I | ScreenShot |
| `uBookRatio` | uint | P | 2 |
| `uIBLFBloomRadius` | uint | I | 2 |
| `uIBLFBlurRadiusX` | uint | I | 7 |
| `uIBLFBlurRadiusY` | uint | I | 2 |
| `uIBLFLateralRepeat` | uint | I | 0 |
| `uIBLFLensesCount` | uint | I | 3 |
| `uiResolutionChangeInterval` | uint | I | 5 |
| `uShadowFilterType` | uint | I | 3 |

### LOD (33)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bDisplayLODLand` | bool | I | 1 |
| `fActorLODMax` | float | I | 15 |
| `fActorLODMin` | float | I | 5 |
| `fDistanceMultiplier` | float | I | 1 |
| `fFadeInThreshold` | float | I | 0.7 |
| `fFadeInTime` | float | I | 1.2 |
| `fFadeOutThreshold` | float | I | 0.3 |
| `fFadeOutTime` | float | I | 2 |
| `fItemLODMax` | float | I | 10 |
| `fItemLODMin` | float | I | 1.5 |
| `fLODBoundRadiusMult` | float | I | 10 |
| `fLodDistance` | float | I | 500 |
| `fLODFadeOutActorMultCity` | float | I | 1 |
| `fLODFadeOutActorMultComplex` | float | I | 1 |
| `fLODFadeOutActorMultInterior` | float | I | 1 |
| `fLODFadeOutItemMultCity` | float | I | 1 |
| `fLODFadeOutItemMultComplex` | float | I | 1 |
| `fLODFadeOutItemMultInterior` | float | I | 1 |
| `fLODFadeOutMultActors` | float | P | 6 ‡ |
| `fLODFadeOutMultItems` | float | P | 3 ‡ |
| `fLODFadeOutMultObjects` | float | P | 5 ‡ |
| `fLODFadeOutMultSkyCell` | float | P | 1 |
| `fLODFadeOutObjectMultCity` | float | I | 1 |
| `fLODFadeOutObjectMultComplex` | float | I | 1 |
| `fLODFadeOutObjectMultInterior` | float | I | 1 |
| `fLODFadeOutPercent` | float | I | 0.6 |
| `fLODLandDropAmount` | float | I | 230 |
| `fLODLandVerticalBias` | float | I | 0 |
| `fLODMultTrees` | float | I | 0.5 |
| `fObjectLODMax` | float | I | 30 |
| `fObjectLODMin` | float | I | 5 |
| `fTalkingDistance` | float | I | 2000 |
| `iFadeNodeMinNearDistance` | int | I | 500 |

### TerrainManager (11)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bDisplayCloudLOD` | bool | I | 1 |
| `bKeepLowDetailTerrain` | bool | I | 1 |
| `bShowLODInEditor` | bool | P | 1 |
| `bUseNewTerrainSystem` | bool | I | 1 |
| `fBlockLevel0Distance` | float | P | 35000 ‡ |
| `fBlockLevel1Distance` | float | P | 70000 ‡ |
| `fBlockMaximumDistance` | float | P | 250000 ‡ |
| `fCameraAboveMaxHeightThreshold` | float | I | 2048 |
| `fSplitDistanceMult` | float | P | 1.5 |
| `fTreeLoadDistance` | float | P | 75000 |
| `uDistantTreeBlockCacheSizePerCell` | uint | I | 1 |

### Grass (18)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bAllowCreateGrass` | bool | I | 1 |
| `bAllowLoadGrass` | bool | I | 0 |
| `bDrawShaderGrass` | bool | I | 1 |
| `bEnableGrassFade` | bool | I | 1 |
| `bGenerateGrassDataFiles` | bool | I | 0 |
| `bGrassPointLighting` | bool | I | 0 |
| `fGrassFadeInTime` | float | I | 1.8 |
| `fGrassFadeRange` | float | I | 1000 |
| `fGrassMaxStartFadeDistance` | float | P | 7000 |
| `fGrassMinStartFadeDistance` | float | P | 400 |
| `fGrassStartFadeDistance` | float | P | 7000 ‡ |
| `fGrassWindMagnitudeMax` | float | I | 125 |
| `fGrassWindMagnitudeMin` | float | I | 5 |
| `fTexturePctThreshold` | float | I | 0 |
| `fWaveOffsetRange` | float | I | 1.75 |
| `iGrassCellRadius` | int | I | 2 |
| `iMaxGrassTypesPerTexure` | int | I | 2 |
| `iMinGrassSize` | int | I | 20 |

### Trees (7)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bEnableTreeAnimations` | bool | I | 1 |
| `bEnableTrees` | bool | I | 1 |
| `bForceFullDetail` | bool | I | 0 |
| `bPickSkinnedTrees` | bool | I | 1 |
| `bRenderSkinnedTrees` | bool | P | 1 |
| `fUpdateBudget` | float | I | 1.5 |
| `uiMaxSkinnedTreesToRender` | uint | P | 40 |

### Water (35)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bAutoWaterSilhouetteReflections` | bool | I | 0 |
| `bForceHighDetailReflections` | bool | I | 0 |
| `bForceLowDetailReflections` | bool | I | 0 |
| `bForceLowDetailWater` | bool | I | 0 |
| `bReflectExplosions` | bool | I | 0 |
| `bReflectLODLand` | bool | I | 1 |
| `bReflectLODObjects` | bool | I | 1 |
| `bReflectLODTrees` | bool | I | 1 |
| `bReflectSky` | bool | I | 1 |
| `bUseBulletWaterDisplacements` | bool | I | 1 |
| `bUseCubeMapReflections` | bool | I | 1 |
| `bUseWater` | bool | I | 1 |
| `bUseWaterDepth` | bool | P | 1 |
| `bUseWaterDisplacements` | bool | P | 1 |
| `bUseWaterHiRes` | bool | I | 0 |
| `bUseWaterLOD` | bool | I | 1 |
| `bUseWaterReflectionBlur` | bool | I | 0 |
| `bUseWaterReflections` | bool | P | 1 |
| `bUseWaterRefractions` | bool | P | 1 |
| `bUseWaterShader` | bool | I | 1 |
| `fCubeMapRefreshRate` | float | I | 0 |
| `fExteriorWaterReflectionThreshold` | float | I | 300 |
| `fInteriorWaterReflectionThreshold` | float | I | 10 |
| `fRefractionWaterPlaneBias` | float | I | 3 |
| `fSurfaceTileSize` | float | I | 2048 |
| `fTileTextureDivisor` | float | I | 4.75 |
| `fWadingWaterQuadSize` | float | I | 2048 |
| `fWadingWaterTextureRes` | float | I | 512 |
| `fWaterGroupHeightRange` | float | I | 10 |
| `iWaterBlurAmount` | int | I | 1 |
| `iWaterNoiseResolution` | int | I | 256 |
| `sSurfaceTexture` | string | I | water |
| `uMaxExteriorWaterReflections` | uint | I | 2 |
| `uMaxInteriorWaterReflections` | uint | I | 4 |
| `uSurfaceFPS` | uint | I | 12 |

### Controls (109)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bAlwaysRunByDefault` | bool | P | 1 |
| `bBackgroundMouse` | bool | I | 0 |
| `bDampenPlayerControls` | bool | I | 1 |
| `bEnableGestureDualSwing` | bool | I | 1 |
| `bEnableGesturePowerAttackByAccel` | bool | I | 1 |
| `bEnableGesturePowerAttackByInput` | bool | I | 1 |
| `bEnableSixaxisBowAiming` | bool | I | 0 |
| `bEnableSixaxisLockpicking` | bool | I | 0 |
| `bEnableSixaxisMagicAiming` | bool | I | 0 |
| `bFreezeDirectionOnLargeDelta` | bool | I | 1 |
| `bGamepadLookApplyMaxedOutAcceleration` | bool | I | 1 |
| `bGamepadLookApplySensitivityThreshold` | bool | I | 0 |
| `bGamepadLookApplySnapToAxis` | bool | I | 1 |
| `bGamepadLookTimeNormalizeInputs` | bool | I | 1 |
| `bGamePadRumble` | bool | P | 1 † |
| `bGestureEngageButtonsRequired` | bool | I | 1 |
| `bInvertMovementThumbstick` | bool | I | 0 |
| `bInvertYValues` | bool | P | 0 † |
| `bPlayerGraphFeedback` | bool | I | 0 |
| `bRequireSixaxisLockpickingEngageLeft` | bool | I | 1 |
| `bShowKinectDebugInfo` | bool | I | 0 |
| `bSixaxisAimingRespectsFOV` | bool | I | 1 |
| `bSixaxisAimingRespectsTimeMultiplier` | bool | I | 1 |
| `bUseKinect` | bool | P | 0 |
| `fControllerBufferDepth` | float | I | 0.14 |
| `fControllerDampenTime` | float | I | 0.18 |
| `fControllerSampleThreshold` | float | I | 0.1 |
| `fDialogueHardStopAngle1P` | float | I | 45 |
| `fDialogueHardStopAngle3P` | float | I | 55 |
| `fDialogueSoftStopAngle1P` | float | I | 20 |
| `fDialogueSoftStopAngle3P` | float | I | 25 |
| `fDirectionalDeadzone` | float | I | 0.5 |
| `fDualCastChordTime` | float | I | 0.05 |
| `fFreezeDirectionDefaultAngleThreshold` | float | I | 60 |
| `fFreezeDirectionDefaultSpeedThreshold` | float | I | 100 |
| `fGamepadHeadingSensitivity` | float | P | 0.66672 † |
| `fGamepadHeadingSensitivityDefault` | float | I | 0.66672 |
| `fGamepadHeadingSensitivityMax` | float | I | 1.5556 |
| `fGamepadHeadingSensitivityMin` | float | I | 0.4445 |
| `fGamepadHeadingXScale` | float | I | 1 |
| `fGamepadHeadingYScale` | float | I | 0.5625 |
| `fGamepadLookAccelPitchMult` | float | I | 2.5 |
| `fGamepadLookAccelSec` | float | I | 0.92 |
| `fGamepadLookAccelYawMult` | float | I | 2.5 |
| `fGamepadLookMultExponent` | float | I | 0 |
| `fGesturePowerAttackAccelThreshhold` | float | I | 4 |
| `fHeadingAxisDeadzone` | float | I | 0.15 |
| `fHorseClampAngle` | float | I | 10 |
| `fHorseControlsDampenTime` | float | I | 1 |
| `fHorseHeadingMovementMult` | float | I | 1 |
| `fHotKeyDelay` | float | I | 0.25 |
| `fInitialPowerAttackDelay` | float | I | 0.3 |
| `fInitialPowerBashDelay` | float | I | 0.3 |
| `fKeyboardRepeatDelay` (section `:Controls`) | float | I | 0.3 |
| `fKeyboardRepeatRate` (section `:Controls`) | float | I | 0.05 |
| `fLockResetSixaxisWiggleRoom` | float | I | 0.08 |
| `fLockTurnSixaxisMinThreshhold` | float | I | 0.06 |
| `fLookCurveSensitivityThreshold` | float | I | 0.1 |
| `fLookGraphCoefficient1` | float | I | 0.115141 |
| `fLookGraphCoefficient2` | float | I | -0.382666 |
| `fLookGraphCoefficient3` | float | I | 2.02865 |
| `fLookGraphCoefficient4` | float | I | -0.754499 |
| `fLookGraphX1` | float | I | 0.4 |
| `fLookGraphX2` | float | I | 0.6 |
| `fLookGraphX3` | float | I | 0.8 |
| `fLookGraphX4` | float | I | 0.9 |
| `fLookGraphY1` | float | I | 0.1 |
| `fLookGraphY2` | float | I | 0.2 |
| `fLookGraphY3` | float | I | 0.3 |
| `fLookGraphY4` | float | I | 0.6 |
| `fLookSnapToAxisStrength` | float | I | 0.15 |
| `fLookTimeNormalizingFloorFramerate` | float | I | 20 |
| `fLookTimeNormalizingTargetFramerate` | float | I | 30 |
| `fLThumbDeadzone` | float | I | 0.25 |
| `fLThumbDeadzoneMax` | float | I | 0.97 |
| `fMaxLookRampUpDelta` | float | I | 0.13 |
| `fMaxMoveRampDownDelta` | float | I | 500 |
| `fMouseHeadingSensitivity` | float | P | 0.0125 ‡ |
| `fMouseHeadingSensitivityMax` | float | I | 0.05 |
| `fMouseHeadingSensitivityMin` | float | I | 0.01 |
| `fMouseHeadingXScale` | float | I | 0.02 |
| `fMouseHeadingYScale` | float | I | 0.85 |
| `fMoveGraphX1` | float | I | 0.2 |
| `fMoveGraphX2` | float | I | 0.7 |
| `fMoveGraphX3` | float | I | 0.9 |
| `fMoveGraphY1` | float | I | 0.1 |
| `fMoveGraphY2` | float | I | 0.5 |
| `fMoveGraphY3` | float | I | 0.9 |
| `fMovementAxisDeadzone` | float | I | 0.15 ‡ |
| `fOutsideDialogueAngleRotationDampen` | float | I | 0.33 |
| `fPCDialogueLookSpeed` | float | I | 10 |
| `fPCDialogueLookStart` | float | I | 25 |
| `fPlayerThirdPersonDampenTime` | float | I | 0.25 |
| `fReverseDirThreshold` | float | I | 0.3 |
| `fRThumbDeadzone` | float | I | 0.25 |
| `fRThumbDeadzoneMax` | float | I | 0.97 |
| `fSixaxisAlphaMaxThreshold` | float | I | 0.05 |
| `fSixaxisAlphaMin` | float | I | 0.15 |
| `fSprintStopThreshold` | float | I | 0.5 |
| `fSubsequentPowerAttackDelay` | float | I | 2 |
| `fSubsequentPowerBashDelay` | float | I | 2 |
| `fTogglePOVDelay` | float | I | 0 |
| `fTriggerDeadzone` | float | I | 0.05 ‡ |
| `fZKeyDelay` | float | I | 0.2 |
| `iGestureShieldTickBuffer` | int | I | 200 |
| `iMountedGestureAttackBuffer` | int | I | 600 |
| `iNumHotkeys` | int | I | 37 |
| `iNumLookGraphSettings` | int | I | 4 |
| `iNumMoveGraphSettings` | int | I | 3 |

### Imagespace (7)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bDoDepthOfField` | bool | P | 1 |
| `bDoRadialBlur` | bool | I | 1 |
| `bLensFlare` | bool | P | 1 ‡ |
| `fLensFlareFalloffRange` | float | I | 256 |
| `fLensFlareGlobalIntensity` | float | I | 1 ‡ |
| `fRenderDepthMaxDepth` | float | I | 10000 |
| `iRadialBlurLevel` | int | I | 0 |

### Weather (10)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bFogEnabled` | bool | I | 1 |
| `bPrecipitation` | bool | I | 1 |
| `fAlphaReduce` | float | I | 1 |
| `fSunBaseSize` | float | I | 425 |
| `fSunBoost` | float | I | 1 |
| `fSunGlareMultiplier` | float | I | 2 |
| `fSunGlareSize` | float | I | 600 |
| `sBumpFadeColor` | string | I | 255,255,255,255 |
| `sEnvReduceColor` | string | I | 255,255,255,255 |
| `sLerpCloseColor` | string | I | 255,255,255,255 |

### Actor (3)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bUseNavMeshForMovement` | bool | I | 1 |
| `fNotVisibleNavmeshMoveDist` | float | I | 2048 |
| `fVisibleNavmeshMoveDist` | float | I | 4096 |

### Audio (57)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bEnableAudio` | bool | I | 1 |
| `bEnableAudioCache` | bool | I | 1 |
| `fASFadeInTime` | float | I | 3 |
| `fASFadeOutTime` | float | I | 8 |
| `fAudioRumbleBigDeadZone` | float | I | 0 |
| `fAudioRumbleBigExponent` | float | I | 0.5 |
| `fAudioRumbleBigLerpMax` | float | I | 1 |
| `fAudioRumbleBigLerpMin` | float | I | 0 |
| `fAudioRumblePowerAttackAdj` | float | I | 0.15 |
| `fAudioRumbleSmallDeadZone` | float | I | 0 |
| `fAudioRumbleSmallExponent` | float | I | 0.4 |
| `fAudioRumbleSmallLerpMax` | float | I | 1 |
| `fAudioRumbleSmallLerpMin` | float | I | 0 |
| `fCollisionSoundHeavyThreshold` | float | I | 160 |
| `fDefaultMasterVolume` | float | I | 1 |
| `fDialogueHeadPitchExaggeration` | float | I | 2 |
| `fDialogueHeadRollExaggeration` | float | I | 2 |
| `fDialogueHeadYawExaggeration` | float | I | 2 |
| `fHardLandingDamageThreshold` | float | I | 500 |
| `fHighlightSpeechOverlap` | float | I | 0.5 |
| `fMaxHighlightRadius` | float | I | 250 |
| `fMenuModeFadeInTime` | float | I | 0.5 |
| `fMenuModeFadeOutTime` | float | I | 0.5 |
| `fMinSoundVel` | float | I | 60 |
| `fMusicDuckingSeconds` | float | I | 1 |
| `fMusicFinaleCrossFadeTimeIn` | float | I | 3 |
| `fMusicFinaleCrossFadeTimeOut` | float | I | 6 |
| `fMusicUnDuckingSeconds` | float | I | 4 |
| `fNonDialogVoiceDucking` | float | I | 9 |
| `fNonDialogVoiceDuckingFadeIn` | float | I | 1 |
| `fNonDialogVoiceDuckingFadeOut` | float | I | 1.5 |
| `fNonHighlightSpeechAtten` | float | I | 12 |
| `fRegionLoopFadeInTime` | float | I | 6 |
| `fRegionLoopFadeOutTime` | float | I | 8 |
| `fRegionRandomSoundPlacementBase` | float | I | 100 |
| `fRegionSoundPlacementRandomOffset` | float | I | 650 |
| `fRegionSoundPlacementZOffset` | float | I | 256 |
| `fReverbTransitionTime` | float | I | 0.5 |
| `fWaterAudioFadeInSeconds` | float | I | 3 |
| `fWaterAudioFadeOutSeconds` | float | I | 5 |
| `iCollisionSoundTimeDelta` | int | I | 150 |
| `iHighlightSpeechOverlap` | int | I | 500 |
| `sAudioAPI` | string | I | XAudio2 |
| `sDeathCameraEffect` | string | I | MAGShoutSlowTimeActiveLP |
| `sMissingAssetSoundFile` | string | I | (empty) |
| `uAsyncReadPriorityThreshold` | uint | I | 64 |
| `uAudioThreadSleepTimeGameMode` | uint | I | 33 |
| `uAudioThreadSleepTimeMenuMode` | uint | I | 1 |
| `uiAudioHWThread` | uint | I | 6 |
| `uiInitialCacheSize` | uint | I | 1048576 |
| `uiMaxAudioCacheSize` | uint | I | 2097152 |
| `uMaxSizeForCachedSound` | uint | I | 262144 |
| `uRegionSoundsAllowedPerUpdate` | uint | I | 1 |
| `uStreamingThreshold` | uint | I | 4194304 |
| `uWaterAudioAmbientAttenuation` | uint | I | 2200 |
| `uWaterAudioAxisSamplePoints` | uint | I | 8 |
| `uWaterAudioSamplePointsToUse` | uint | I | 8 |

### Camera (83)

| Setting | Type | File | Compiled default |
|---|---|---|---|
| `bDisableAutoVanityMode` | bool | I | 0 |
| `bDragonCameraTargetPlayer` | bool | I | 1 |
| `bForceAutoVanityMode` | bool | I | 0 |
| `bReturnTo1stPersonFromVanity` | bool | I | 0 |
| `f1st3rdSwitchDelay` | float | I | 0.25 |
| `f1stHorzDampeningSpringConstant` | float | I | 0.0001 |
| `f1stHorzDampeningVelocityDampening` | float | I | 0.4 |
| `f1stPitchOffsetMouseFollowSpeed` | float | I | 15 |
| `f1stPitchOffsetMouseMaxLag` | float | I | 4 |
| `f1stPitchOffsetMultOffAccel` | float | I | 1 |
| `f1stPitchOffsetMultOffMaxSpeed` | float | I | 1 |
| `f1stPitchOffsetMultOnAccel` | float | I | 0.5 |
| `f1stPitchOffsetMultOnMaxSpeed` | float | I | 0.6 |
| `f1stPitchOffsetSixaxisMaxLag` | float | I | 10 |
| `f1stPitchOffsetSixaxisMaxSnapDelta` | float | I | 0.15 |
| `f1stPitchOffsetTarget` | float | I | 0.75 |
| `f1stVertDampeningSpringConstant` | float | I | 0.001 |
| `f1stVertDampeningVelocityDampening` | float | I | 0.6 |
| `fActorFadeOutLimit` | float | I | 30 |
| `fAutoVanityIncrement` | float | I | 0.01 |
| `fAutoVanityModeDelay` | float | I | 120 |
| `fCameraCasterBleedOutSize` | float | I | 5 |
| `fCameraCasterSize` | float | I | 15 |
| `fCameraCasterTargetSize` | float | I | 20 |
| `fCharControllerCheckHeightOffset` | float | I | 124 |
| `fChaseCameraMaxAngle` | float | I | 30 |
| `fChaseCameraSpeed` | float | I | 10 |
| `fCollisionRecoveryMinDist` | float | I | 4000 |
| `fCollisionRecoverySpeed` | float | I | 3 |
| `fDefaultAutoVanityZoom` | float | I | 300 |
| `fDragonCameraDollyTime` | float | I | 0.75 |
| `fDragonMaxAngleBeforeTurn` | float | I | 90 |
| `fFirstPersonDisablePOVLerpDPS` | float | I | 2 |
| `fFirstPersonSittingAngleLimit` | float | I | 1.5707964 |
| `fFirstPersonSittingRotationSpeed` | float | I | 0.1 |
| `fFreeCameraRotationSpeed` | float | I | 3 |
| `fFreeCameraRunSpeed` | float | I | 2 |
| `fFreeCameraTranslationSpeed` | float | I | 20 ‡ |
| `fFreeCameraTriggerDeadzone` | float | I | 0.1 |
| `fFreeRotationSpeed` | float | I | 3 |
| `fFurnitureCameraAngle` | float | I | 0.3926991 |
| `fFurnitureCameraZoom` | float | I | 250 |
| `fHorseDismountYawCorrection` | float | I | 0.32 |
| `fHorseMaxAngleBeforeTurn` | float | I | 90 |
| `fLookingSpeed` | float | I | 0.1 |
| `fMinCurrentZoom` | float | I | -0.2 |
| `fMouseWheelZoomIncrement` | float | I | 0.075 |
| `fMouseWheelZoomMinDelta` | float | I | 0.005 |
| `fMouseWheelZoomSpeed` | float | I | 0.8 |
| `fOverShoulderCombatAddY` | float | I | -100 |
| `fOverShoulderCombatPosX` | float | I | 0 |
| `fOverShoulderCombatPosZ` | float | I | 20 |
| `fOverShoulderDragonAddY` | float | I | -600 |
| `fOverShoulderDragonPosX` | float | I | 0 |
| `fOverShoulderDragonPosZ` | float | I | 0 |
| `fOverShoulderHorseAddY` | float | I | -300 |
| `fOverShoulderHorsePosX` | float | I | 0 |
| `fOverShoulderHorsePosZ` | float | I | 0 |
| `fOverShoulderPosX` | float | I | 30 |
| `fOverShoulderPosZ` | float | I | -10 |
| `fPitchZeroBlendTime` | float | I | 0.75 |
| `fPitchZoomOutMaxDist` | float | I | 100 |
| `fShoulderDollySpeed` | float | I | 3 |
| `fSlowVanityIncrement` | float | I | 0.02 |
| `fThumbstickZoomSpeed` | float | I | 0.05 |
| `fTweenCamRotAngle` | float | I | 0.05 |
| `fTweenCamRotClosingSpeed` | float | I | 10 |
| `fTweenCamRotSpeed` | float | I | 4 |
| `fTweenCamZoomFOVMod` | float | I | 10 |
| `fTweenCamZoomSpeed` | float | I | 25 |
| `fVanityModeMaxDist` | float | I | 600 |
| `fVanityModeMaxDistFlyMult` | float | I | 4 |
| `fVanityModeMinDist` | float | I | 155 |
| `fVanityModeMinDistFly` | float | I | 1200 |
| `fWorkbenchCameraPitch` | float | I | 0.5 |
| `fWorkbenchCameraTranslateX` | float | I | 0 |
| `fWorkbenchCameraTranslateY` | float | I | 50 |
| `fWorkbenchCameraTranslateZ` | float | I | -50 |
| `fWorkbenchCameraYaw` | float | I | -1 |
| `fWorkbenchCameraZoom` | float | I | 100 |
| `iAnimatedTransitionMillis` | int | I | 1000 |
| `iBleedoutTransitionMillis` | int | I | 500 |
| `iHorseTransitionMillis` | int | I | 500 |

