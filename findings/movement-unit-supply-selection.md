# Finding: movement, camera, script and render-setup unit supply selection

Status: selection metadata only; no new match or behavior claim. Image-derived facts (function starts, extents, vftable slots) are OBSERVED; every name is a HYPOTHESIS.
Author / human operator: Taylor Turner
AI assistance / model: Claude Sonnet 5.5 (`claude-sonnet-5-5`), worker MAP-1
Date (UTC): 2026-11-18
Target build id / image SHA-256: `sse-steam-1-7-104` / `846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`
Source exposure: mixed (local binary-analysis metadata and community headers).
Sources and immutable revisions / licenses: Address Library 1.7.104.0 database (ids to RVAs; `findings/address-mapping.md`); CharmedBaryon/CommonLibSSE-NG `b93280e832f263dbef44e44cbe2936622a02f91a` (MIT); powerof3/CommonLibSSE `654e55f7979c1733033d5dbef176e43827bac944` (GPL-3.0); meh321/AddressLibraryDatabase `0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91`, used with the author's permission as reported by the maintainer (`docs/authorizations.md`); image RTTI vftable slots; comparator extents from the image's `.pdata` and the Ghidra analysis body.
Name provenance: COMMUNITY (unverified) for 266 entries; GUESS (placeholder) for 121 entries.
Confidence: high for RVA, extent and non-overlap; medium for class attribution of RTTI-joined names; low for id-joined names and every GUESS class; names remain unverified.

## Question and method

The contributor inventory (`data/progress.json`) lists no function of the player controller, the character physics wrapper, the movement controllers, the camera states, the actor movement members, the script natives for the player, or the lighting and shadow setup. `./sr claim` and `./sr start` accept only listed functions. This note records the selection that adds 387 such functions as `mapped` entries (`docs/anti-eu-bureaucracy.md`, rules 2 and 3: the cheapest option that keeps the floor, recorded in one line).

Selection is by class and subsystem: player controller and input, character physics (Havok wrappers), movement controllers and actor state, camera states, actor and process movement members, player scripts, and render setup (lighting shader setup, fog and shadow constant writers). An entry is added only when all of these hold:

1. The RVA is a function start in the image's `.pdata`, or a function start of the Ghidra analysis of the pinned image for a leaf without `.pdata`.
2. The recorded size equals one extent: the single `.pdata` entry, or the chain of contiguous `.pdata` entries equal to the analysis body, or the analysis body of a leaf. A function whose analysis body and `.pdata` chain differ is held back (table below).
3. No existing entry has the same RVA or an overlapping range. 94 selected RVAs were already listed and are not repeated.
4. The name follows this order, per RVA: a name of the pinned MIT NG tree; else a name of the pinned powerof3 tree; else a real meh321 name; else a GUESS placeholder. A name joins either through the image RTTI vftable slot (the virtual slot comment of the class header) or through the Address Library id that the header declares. A name from a newer or different snapshot of any tree is not used and not cited.
5. A community name that does not fit the function body is not used. Two ids were found wrong this way (`0x1064690` and `0x1541f40`); both are GUESS placeholders.

GUESS placeholders use `Class::Func<slot>` where the image RTTI vftable gives the class, `Class::Function<rva>` where only a class-only placeholder of the meh321 list gives it, and `Function<rva>` where nothing gives a class. A `BSTEventSink` base slot is recorded as `<RTTI class>::ProcessEvent` GUESS because the template argument is not recorded.

Where one RVA carries two names (shared slot or identical code folding), the entry keeps one name: the MIT NG name first, then the one whose class matches an RTTI vftable class. The pinned MIT NG and powerof3 trees give different names for 10 selected RVAs; the MIT NG name is used.

Entries are added in two commits so that the first ten can be started first: the small movement-helper group (below), then the other 377.

## Observations

The `0x6aded0` extent was rechecked against the pinned image after the neighboring entry was matched. This leaf has no `.pdata` entry. Its terminal instruction ends at `0x6adee1`, followed by 15 bytes of alignment padding up to the `.pdata` start at `0x6adef0`. The original 33-byte body included the padding and the first byte of the neighbor. The corrected extent is 17 bytes.

| subsystem (by class prefix, approximate) | entries |
|---|---|
| player controls and input | 10 |
| movement controllers and actor state | 24 |
| actor, process and animation members | 73 |
| camera | 82 |
| havok character physics | 72 |
| player-controller helpers | 19 |
| scripts | 2 |
| render setup, fog and shadow | 90 |
| other | 15 |
| total | 387 |

Name sources: 154 MIT NG, 86 powerof3, 26 meh321, 121 GUESS. Extent basis: 280 single `.pdata` entries, 58 chains of 3 to 10 entries, 49 leaves without `.pdata`. Sizes: 112 entries up to 128 B, 163 entries of 129 to 512 B, 112 entries above 512 B.

The first group (first commit) is small movement helpers of the player controller:

| RVA | size | name | name source |
|---|---|---|---|
| `0x4208a0` | 81 | `Actor::GetMovementWeightEffect` | meh321 |
| `0x675110` | 505 | `Actor::Jump` | meh321 |
| `0x685c30` | 141 | `TESObjectREFR::Function685c30` | GUESS |
| `0x692800` | 282 | `TESObjectREFR::Function692800` | GUESS |
| `0x6b21b0` | 356 | `Actor::ProcessEvent` | GUESS |
| `0x6bd530` | 199 | `TESObjectREFR::Function6bd530` | GUESS |
| `0x7cf1e0` | 160 | `JumpAnimEventHandler::Handle` | meh321 |
| `0x10645e0` | 27 | `bhkCharacterController::Function10645e0` | GUESS |
| `0x10c7cc0` | 686 | `bhkCharacterStateInAir::Unk_08` | MIT NG |
| `0x10c8030` | 470 | `bhkCharacterStateJumping::Unk_08` | MIT NG |

Held back because the analysis body and the `.pdata` chain differ (15 RVAs; sizes in bytes):

| RVA | analysis body | `.pdata` extent |
|---|---|---|
| `0x2bd4b0` | 3741 | 3742 |
| `0x412df0` | 3121 | 3129 |
| `0x55cc60` | 378 | 379 |
| `0x6f0e30` | 852 | 853 |
| `0x7972f0` | 957 | 1196 |
| `0x8f71e0` | 376 | 377 |
| `0x8fc6b0` | 128 | 320 |
| `0x8fc920` | 96 | 138 |
| `0x99c180` | 2970 | 3028 |
| `0x1064d20` | 3893 | 3894 |
| `0x10ddf30` | 336 | 399 |
| `0x116ac80` | 1011 | 1013 |
| `0x1522520` | 599 | 744 |
| `0x1547d20` | 2718 | 2796 |
| `0x1589240` | 1032 | 1108 |

## Interpretation and alternatives

An entry is an inventory fact, not a claim about behavior. A COMMUNITY name was written for a different build (1.6.x layouts); the Address Library id may point at another function on 1.7.104, as two ids did. An RTTI-joined name is stronger than an id-joined name, because the slot ownership is read from this image. Unverified names do not change acceptance: a function is `matched` only under `docs/verification.md`.

The contributor tools accept only a name of the form `Class::Method` whose class starts with a capital letter and has an area in `tools/unit_paths.py` (`PLAIN_NAME`, `unit_files`). Entries whose class starts with `bhk` or `hk`, free functions, `papyrus::` natives and `Function<rva>` placeholders are listed but are not startable until a tool or naming change. Ten classes have no area rule; a separate commit proposes `data/unit-areas.json` overrides.

## Reproduction and sanitized evidence

Inputs stay in `.local/`: the pinned image (RTTI vftables, `.pdata`), the Address Library database, the three pinned name trees, and the Ghidra function bounds. Join: id to RVA through the database; RVA to name through the pinned header virtual order (vftable slot) and the header id declarations; extents from `.pdata` and the analysis bounds. No listing, bytes or decompiler output is published. Entries cite this file as `evidence`.

## Negative results and limitations

- 15 candidates are not added because two extent measures disagree.
- Script natives other than the two registered under `papyrus::Game` and one `PlayerCharacter` member are not in the selection: no name or registration was established for them.
- Names are not verified. Class attribution of the `Class::Function<rva>` placeholders comes from a class-only placeholder and may be wrong.
- Counts describe this selection only. They are not a completion denominator.

## Reviewer and outcome

Not reviewed. No claim, pull request or acceptance is made by this note.

## Entries

| RVA | size | name | name source |
|---|---|---|---|
| `0x19ef60` | 2408 | `Function19ef60` | GUESS |
| `0x1a28a0` | 2036 | `TES::Function1a28a0` | GUESS |
| `0x1a30a0` | 1949 | `TES::Function1a30a0` | GUESS |
| `0x24a090` | 42 | `TESCameraState::Update` | MIT NG |
| `0x274390` | 1851 | `TESObjectLIGH::GenDynamic` | po3 |
| `0x285a30` | 115 | `Actor::IsOnMount` | meh321 |
| `0x2b3380` | 950 | `TESObjectLAND::Function2b3380` | GUESS |
| `0x2bc790` | 986 | `TESObjectCELL::Function2bc790` | GUESS |
| `0x2ffd70` | 282 | `TESObjectREFR::Function2ffd70` | GUESS |
| `0x2fff70` | 61 | `Function2fff70` | GUESS |
| `0x300020` | 84 | `TESObjectREFR::Function300020` | GUESS |
| `0x301a50` | 158 | `TESObjectREFR::Function301a50` | GUESS |
| `0x307460` | 865 | `TESWaterForm::Function307460` | GUESS |
| `0x37ac30` | 108 | `ConsoleFunc::handler::SetFramebufferRange` | meh321 |
| `0x37b3a0` | 385 | `ConsoleFunc::handler::ToggleControlsDriven` | meh321 |
| `0x37bff0` | 97 | `ConsoleFunc::handler::FunctionToggleVolumetricLighting` | meh321 |
| `0x3fd820` | 340 | `Function3fd820` | GUESS |
| `0x412810` | 1484 | `Sky::UpdateWeather` | meh321 |
| `0x413a30` | 1231 | `Sky::Function413a30` | GUESS |
| `0x416050` | 475 | `Sky::Function416050` | GUESS |
| `0x419b30` | 113 | `Sky::Function419b30` | GUESS |
| `0x419c80` | 113 | `Function419c80` | GUESS |
| `0x41bd90` | 3018 | `Sun::Update` | MIT NG |
| `0x4208a0` | 81 | `Actor::GetMovementWeightEffect` | meh321 |
| `0x43e4f0` | 310 | `Function43e4f0` | GUESS |
| `0x5220c0` | 1092 | `BGSAutoWater::GeneratePlaceableWater` | po3 |
| `0x5299b0` | 3788 | `Function5299b0` | GUESS |
| `0x553430` | 292 | `IAnimationGraphManagerHolder::GetGraphVariableNiPoint3` | MIT NG |
| `0x553fc0` | 140 | `IAnimationGraphManagerHolder::UpdateAnimationGraphManager` | MIT NG |
| `0x5584a0` | 331 | `ShakeCamera` | MIT NG |
| `0x558dd0` | 53 | `TESCamera::SetCameraRoot` | MIT NG |
| `0x558e70` | 281 | `TESCamera::Update` | MIT NG |
| `0x559060` | 140 | `TESCamera::~TESCamera` | MIT NG |
| `0x55c740` | 30 | `DragonCameraState::Begin` | po3 |
| `0x55c770` | 27 | `DragonCameraState::End` | po3 |
| `0x55c7a0` | 44 | `DragonCameraState::GetFreeRotationMode` | po3 |
| `0x55c8a0` | 206 | `DragonCameraState::SaveGame` | po3 |
| `0x55c980` | 295 | `DragonCameraState::LoadGame` | po3 |
| `0x55cab0` | 142 | `DragonCameraState::Revert` | po3 |
| `0x55cb50` | 84 | `DragonCameraState::ProcessWeaponDrawnChange` | po3 |
| `0x55cbb0` | 9 | `DragonCameraState::SetCameraHandle` | po3 |
| `0x55cbc0` | 150 | `DragonCameraState::Unk_0A` | po3 |
| `0x55cdf0` | 1443 | `DragonCameraState::UpdateRotation` | po3 |
| `0x55d460` | 73 | `DragonCameraState::~DragonCameraState` | po3 |
| `0x55d590` | 37 | `ThirdPersonState::GetFreeRotationMode` | MIT NG |
| `0x643490` | 510 | `Function643490` | GUESS |
| `0x657c90` | 1492 | `Main::Function657c90` | GUESS |
| `0x65a400` | 450 | `Function65a400` | GUESS |
| `0x65c0f0` | 525 | `Function65c0f0` | GUESS |
| `0x65fcb0` | 236 | `Function65fcb0` | GUESS |
| `0x65fda0` | 502 | `Function65fda0` | GUESS |
| `0x6623e0` | 178 | `Function6623e0` | GUESS |
| `0x665740` | 245 | `SceneGraph::GetFarDistance` | MIT NG |
| `0x66ff80` | 2293 | `Character::Function66ff80` | GUESS |
| `0x6713e0` | 489 | `Actor::Load3D` | MIT NG |
| `0x6740b0` | 250 | `Actor::SetRotationZ` | MIT NG |
| `0x6742a0` | 219 | `Actor::IsRunning` | po3 |
| `0x674390` | 252 | `Actor::CanRun` | meh321 |
| `0x6747f0` | 140 | `Actor::IsInMidair` | MIT NG |
| `0x674890` | 138 | `PlayerCharacter::Function674890` | GUESS |
| `0x675110` | 505 | `Actor::Jump` | meh321 |
| `0x685900` | 41 | `Actor::GetBoundRadius` | po3 |
| `0x685c30` | 141 | `TESObjectREFR::Function685c30` | GUESS |
| `0x687ac0` | 61 | `Actor::IsMovementAnimationDriven` | po3 |
| `0x689370` | 4309 | `Actor::Move` | po3 |
| `0x690be0` | 76 | `Actor::GetCollisionFilterInfo` | MIT NG |
| `0x692800` | 282 | `TESObjectREFR::Function692800` | GUESS |
| `0x692b40` | 211 | `Character::Function692b40` | GUESS |
| `0x692eb0` | 405 | `Actor::SetRotationX` | MIT NG |
| `0x693050` | 412 | `Function693050` | GUESS |
| `0x6a6050` | 398 | `Actor::StopMoving` | MIT NG |
| `0x6aded0` | 17 | `Character::Function6aded0` | GUESS |
| `0x6ae3e0` | 472 | `Actor::SetMaximumMovementSpeed` | meh321 |
| `0x6aefa0` | 65 | `Actor::IsMoving` | MIT NG |
| `0x6b21b0` | 356 | `Actor::ProcessEvent` | GUESS |
| `0x6bd530` | 199 | `TESObjectREFR::Function6bd530` | GUESS |
| `0x6c2cc0` | 19 | `ActorState::Unk_14` | MIT NG |
| `0x6d39c0` | 252 | `Character::Function6d39c0` | GUESS |
| `0x6e13c0` | 60 | `ActorState::Unk_15` | MIT NG |
| `0x6e1ad0` | 62 | `ActorState::~ActorState` | MIT NG |
| `0x6e1b90` | 4 | `ActorState::DoGetMovementSpeed` | MIT NG |
| `0x6e1bc0` | 4 | `ActorState::DoGetRotationSpeed` | MIT NG |
| `0x6e9b70` | 337 | `AIProcess::AddToProcedureIndexRunning` | po3 |
| `0x6f0a20` | 1024 | `AIProcess::SetupSpecialIdle` | MIT NG |
| `0x6f22f0` | 514 | `AIProcess::RandomlyPlaySpecialIdles` | po3 |
| `0x6f2560` | 310 | `AIProcess::SetActorsDetectionEvent` | MIT NG |
| `0x6f6720` | 1057 | `AIProcess::Update3DModel_Impl` | po3 |
| `0x6ff050` | 66 | `AIProcess::GetHeadtrackTarget` | MIT NG |
| `0x6ff380` | 82 | `AIProcess::ClearMuzzleFlashes` | MIT NG |
| `0x71dcf0` | 174 | `HighProcessData::ClearHeadtrackTarget` | MIT NG |
| `0x71fa50` | 113 | `HighProcessData::SetHeadtrackTarget` | MIT NG |
| `0x720660` | 51 | `AIProcess::GetCurrentWeapon` | po3 |
| `0x721f70` | 131 | `AIProcess::SetRunOncePackage` | po3 |
| `0x723510` | 67 | `AIProcess::SetHeadtrackTarget` | MIT NG |
| `0x723620` | 402 | `AIProcess::KnockParalyze` | po3 |
| `0x7237c0` | 913 | `AIProcess::KnockExplosion` | MIT NG |
| `0x739610` | 310 | `PlayerCharacter::GetArmorValue` | po3 |
| `0x7397e0` | 401 | `PlayerCharacter::GetEquippedWeaponsDamage` | po3 |
| `0x739980` | 125 | `PlayerCharacter::GetDamage` | po3 |
| `0x739a40` | 452 | `Actor::DoReset3D` | po3 |
| `0x73c160` | 116 | `Function73c160` | GUESS |
| `0x73c720` | 66 | `HighActorCuller::Function73c720` | GUESS |
| `0x7414c0` | 177 | `Function7414c0` | GUESS |
| `0x742df0` | 654 | `PlayerCharacter::CenterOnCell_Impl` | MIT NG |
| `0x747350` | 309 | `PlayerCharacter::AddPlayerAddItemEvent` | MIT NG |
| `0x749190` | 361 | `PlayerCharacter::CheckPoisonWeapon` | po3 |
| `0x749510` | 74 | `PlayerCharacter::CheckCast` | MIT NG |
| `0x74a4c0` | 7 | `SetGodMode` | meh321 |
| `0x74cd90` | 124 | `PlayerCharacter::Function74cd90` | GUESS |
| `0x751580` | 525 | `PlayerCharacter::ActivatePickRef` | po3 |
| `0x751870` | 439 | `PlayerCharacter::StartGrabObject` | po3 |
| `0x751a30` | 14 | `Function751a30` | GUESS |
| `0x752630` | 3900 | `PlayerCharacter::Function752630` | GUESS |
| `0x753580` | 2939 | `PlayerCharacter::Function753580` | GUESS |
| `0x754110` | 665 | `PlayerCharacter::DestroyMouseSprings` | MIT NG |
| `0x754790` | 206 | `PlayerCharacter::PlayMagicFailureSound` | MIT NG |
| `0x7559f0` | 104 | `PlayerCharacter::SetAIDriven` | MIT NG |
| `0x757a70` | 809 | `PlayerCharacter::UpdateCrosshairs` | MIT NG |
| `0x759b90` | 683 | `PlayerCharacter::AttemptPickpocket` | MIT NG |
| `0x75a890` | 427 | `PlayerCharacter::SetEscaping` | MIT NG |
| `0x75ceb0` | 102 | `PlayerCharacter::GetTintMask` | po3 |
| `0x75d060` | 58 | `PlayerCharacter::GetNumTints` | po3 |
| `0x77a130` | 660 | `Function77a130` | GUESS |
| `0x795120` | 546 | `MovementControllerAI::Unk_06` | MIT NG |
| `0x7963c0` | 73 | `MovementControllerNPC::Unk_0A` | MIT NG |
| `0x796410` | 66 | `MovementControllerNPC::Unk_0B` | MIT NG |
| `0x796940` | 170 | `MovementControllerNPC::Unk_0C` | MIT NG |
| `0x7969f0` | 170 | `MovementControllerNPC::Unk_0D` | MIT NG |
| `0x796aa0` | 11 | `MovementControllerNPC::Unk_0E` | MIT NG |
| `0x796ac0` | 8 | `MovementControllerNPC::Unk_0F` | MIT NG |
| `0x796ad0` | 114 | `MovementControllerNPC::Unk_10` | MIT NG |
| `0x796b50` | 128 | `MovementControllerNPC::Unk_11` | MIT NG |
| `0x796be0` | 1787 | `MovementControllerNPC::Unk_12` | MIT NG |
| `0x798fa0` | 153 | `MovementControllerNPC::Unk_14` | MIT NG |
| `0x79a7b0` | 52 | `MovementControllerNPC::~MovementControllerNPC` | MIT NG |
| `0x7a3fd0` | 2324 | `MovementHandlerAgentPlayerControls::Func2` | GUESS |
| `0x7ad450` | 642 | `PlayerControls::Ctor` | po3 |
| `0x7ad900` | 1405 | `PlayerControls::ProcessEvent` | GUESS |
| `0x7aeba0` | 1279 | `Function7aeba0` | GUESS |
| `0x7af240` | 405 | `Function7af240` | GUESS |
| `0x7af3e0` | 403 | `Function7af3e0` | GUESS |
| `0x7b1c40` | 52 | `PlayerControls::~PlayerControls` | MIT NG |
| `0x7b2660` | 614 | `HeldStateHandler::SetHeldStateActive` | MIT NG |
| `0x7cf1e0` | 160 | `JumpAnimEventHandler::Handle` | meh321 |
| `0x869540` | 1234 | `Character::Function869540` | GUESS |
| `0x8f3770` | 139 | `AutoVanityState::Begin` | po3 |
| `0x8f3810` | 352 | `AutoVanityState::Update` | po3 |
| `0x8f39c0` | 69 | `AutoVanityState::GetTranslation` | po3 |
| `0x8f3a10` | 376 | `Function8f3a10` | GUESS |
| `0x8f3b90` | 313 | `BleedoutCameraState::Begin` | MIT NG |
| `0x8f3cd0` | 105 | `BleedoutCameraState::End` | MIT NG |
| `0x8f3d40` | 1517 | `BleedoutCameraState::Update` | MIT NG |
| `0x8f46d0` | 148 | `FirstPersonState::Begin` | MIT NG |
| `0x8f4770` | 32 | `FirstPersonState::End` | MIT NG |
| `0x8f47a0` | 2557 | `FirstPersonState::Update` | MIT NG |
| `0x8f51b0` | 341 | `FirstPersonState::GetRotation` | MIT NG |
| `0x8f5310` | 78 | `FirstPersonState::GetTranslation` | MIT NG |
| `0x8f54b0` | 236 | `PlayerInputHandler::ProcessButton` | meh321 |
| `0x8f55f0` | 170 | `FirstPersonState::SaveGame` | MIT NG |
| `0x8f56a0` | 151 | `FirstPersonState::LoadGame` | MIT NG |
| `0x8f5740` | 109 | `FirstPersonState::Revert` | MIT NG |
| `0x8f5b60` | 215 | `Function8f5b60` | GUESS |
| `0x8f5e30` | 144 | `FreeCameraState::Begin` | MIT NG |
| `0x8f5ed0` | 109 | `FreeCameraState::End` | MIT NG |
| `0x8f5f50` | 265 | `FreeCameraState::Update` | MIT NG |
| `0x8f6630` | 171 | `FurnitureCameraState::Begin` | po3 |
| `0x8f66f0` | 273 | `FurnitureCameraState::Update` | po3 |
| `0x8f6810` | 118 | `FurnitureCameraState::End` | po3 |
| `0x8f6890` | 192 | `FurnitureCameraState::GetRotation` | po3 |
| `0x8f6960` | 69 | `FurnitureCameraState::GetTranslation` | po3 |
| `0x8f6c50` | 137 | `HorseCameraState::Begin` | MIT NG |
| `0x8f6dd0` | 206 | `HorseCameraState::SaveGame` | MIT NG |
| `0x8f6eb0` | 282 | `HorseCameraState::LoadGame` | MIT NG |
| `0x8f7010` | 225 | `HorseCameraState::ProcessWeaponDrawnChange` | MIT NG |
| `0x8f7100` | 9 | `HorseCameraState::SetCameraHandle` | MIT NG |
| `0x8f7110` | 194 | `HorseCameraState::Unk_0A` | MIT NG |
| `0x8f7360` | 692 | `ThirdPersonState::UpdateRotation` | MIT NG |
| `0x8f7650` | 73 | `HorseCameraState::~HorseCameraState` | MIT NG |
| `0x8f7700` | 605 | `IronSightsState::Update` | meh321 |
| `0x8f79a0` | 78 | `IronSightsState::GetCurrentPosition` | meh321 |
| `0x8f79f0` | 288 | `PlayerCamera::ctor` | meh321 |
| `0x8f7cf0` | 2438 | `PlayerCamera::SetCameraRoot` | MIT NG |
| `0x8f8680` | 810 | `PlayerCamera::Update` | po3 |
| `0x8f8de0` | 64 | `PlayerCamera::ForceFirstPerson` | MIT NG |
| `0x8f8f40` | 78 | `PlayerCamera::ForceThirdPerson` | MIT NG |
| `0x8f9330` | 275 | `PlayerCamera::ToggleFreeCameraMode` | MIT NG |
| `0x8fa5d0` | 1825 | `PlayerCamera::ApplyCameraCaster` | po3 |
| `0x8fb1e0` | 31 | `PlayerCamera::GetCurrentNormalFOV` | meh321 |
| `0x8fb2e0` | 697 | `PlayerCamera::Function8fb2e0` | GUESS |
| `0x8fb5a0` | 215 | `PlayerCamera::UpdateThirdPerson` | po3 |
| `0x8fc4f0` | 123 | `BleedoutCameraState::~BleedoutCameraState` | MIT NG |
| `0x8fc670` | 52 | `PlayerCamera::~PlayerCamera` | MIT NG |
| `0x8fcc30` | 112 | `PlayerCameraTransitionState::GetRotation` | MIT NG |
| `0x8fccb0` | 149 | `PlayerCameraTransitionState::GetTranslation` | MIT NG |
| `0x8fcd50` | 1187 | `PlayerCameraTransitionState::Update` | MIT NG |
| `0x8fd390` | 315 | `ThirdPersonState::Begin` | MIT NG |
| `0x8fd4e0` | 164 | `ThirdPersonState::End` | MIT NG |
| `0x8fd590` | 727 | `ThirdPersonState::Update` | MIT NG |
| `0x8fd970` | 79 | `ThirdPersonState::ProcessWeaponDrawnChange` | MIT NG |
| `0x8fdb50` | 330 | `ThirdPersonState::SetFreeRotationMode` | MIT NG |
| `0x8fdd20` | 691 | `PlayerInputHandler::ProcessButton` | meh321 |
| `0x8fe0c0` | 188 | `ThirdPersonState::SaveGame` | MIT NG |
| `0x8fe190` | 191 | `ThirdPersonState::LoadGame` | MIT NG |
| `0x8fe260` | 345 | `ThirdPersonState::Revert` | MIT NG |
| `0x8fe3c0` | 844 | `ThirdPersonState::Function8fe3c0` | GUESS |
| `0x8fe720` | 254 | `ThirdPersonState::UpdateRotation` | MIT NG |
| `0x8fe830` | 699 | `ThirdPersonState::UpdateDelayedParameters` | meh321 |
| `0x8feb00` | 327 | `ThirdPersonState::HandleLookInput` | MIT NG |
| `0x8ff310` | 105 | `TweenMenuCameraState::Begin` | po3 |
| `0x8ff3a0` | 507 | `TweenMenuCameraState::Update` | po3 |
| `0x8ff5b0` | 396 | `TweenMenuCameraState::GetRotation` | po3 |
| `0x8ffac0` | 622 | `VATSCameraState::Update` | po3 |
| `0x8ffd40` | 1300 | `VATSCameraState::GetRotation` | po3 |
| `0x900260` | 18 | `VATSCameraState::GetTranslation` | po3 |
| `0x98c020` | 536 | `Function98c020` | GUESS |
| `0x99bd30` | 1083 | `MapMenu::AdvanceMovie` | MIT NG |
| `0xa23ee0` | 214 | `papyrus::Game::DisablePlayerControls` | meh321 |
| `0xa23fc0` | 165 | `papyrus::Game::EnablePlayerControls` | meh321 |
| `0xaa2c40` | 89 | `hkReferencedObject::CalcContentStatistics` | MIT NG |
| `0xaa7180` | 43 | `Functionaa7180` | GUESS |
| `0xb3b6e0` | 66 | `Functionb3b6e0` | GUESS |
| `0xb98560` | 125 | `hkpCharacterStateManager::~hkpCharacterStateManager` | MIT NG |
| `0xb98920` | 452 | `hkpCharacterRigidBody::CheckSupport` | po3 |
| `0xb98af0` | 2538 | `hkpCharacterRigidBody::GetSupportInfo` | po3 |
| `0xb994e0` | 530 | `hkpCharacterRigidBody::GetGround` | po3 |
| `0xb99940` | 125 | `hkpCharacterRigidBody::~hkpCharacterRigidBody` | po3 |
| `0xb99e20` | 733 | `hkpMouseSpringAction::ApplyAction` | po3 |
| `0xb9f720` | 2159 | `hkpCharacterProxy::UpdateManifold` | MIT NG |
| `0xba04d0` | 443 | `hkpCharacterProxy::ExtractSurfaceConstraintInfo` | MIT NG |
| `0xba0e90` | 335 | `hkpCharacterProxy::CalcContentStatistics` | MIT NG |
| `0xba15c0` | 125 | `hkpCharacterProxy::~hkpCharacterProxy` | MIT NG |
| `0xbd3040` | 185 | `BShkbAnimationGraph::SetGraphVariableBool` | po3 |
| `0xbd3100` | 190 | `BShkbAnimationGraph::SetGraphVariableFloat` | po3 |
| `0xbd31d0` | 180 | `BShkbAnimationGraph::SetGraphVariableInt` | po3 |
| `0xbd3350` | 189 | `BShkbAnimationGraph::GetGraphVariableBool` | MIT NG |
| `0xbd3420` | 185 | `BShkbAnimationGraph::GetGraphVariableFloat` | MIT NG |
| `0xbd34e0` | 185 | `BShkbAnimationGraph::GetGraphVariableInt` | MIT NG |
| `0xce36b0` | 696 | `Functionce36b0` | GUESS |
| `0xceed20` | 267 | `Functionceed20` | GUESS |
| `0xcef8a0` | 210 | `ControlMap::PushInputContext` | MIT NG |
| `0xcef980` | 274 | `ControlMap::PopInputContext` | MIT NG |
| `0xcefaa0` | 136 | `Functioncefaa0` | GUESS |
| `0xcefb30` | 25 | `Functioncefb30` | GUESS |
| `0xcefb50` | 30 | `Functioncefb50` | GUESS |
| `0xcefb80` | 18 | `Functioncefb80` | GUESS |
| `0xcefba0` | 14 | `Functioncefba0` | GUESS |
| `0xcefbc0` | 21 | `Functioncefbc0` | GUESS |
| `0xcefd60` | 33 | `Functioncefd60` | GUESS |
| `0xcefd90` | 307 | `Functioncefd90` | GUESS |
| `0xedcb70` | 7 | `NiObject::GetStreamableRTTI` | MIT NG |
| `0xeebf20` | 17 | `CombatGroupDetectionListener::Unk_02` | MIT NG |
| `0xfd97a0` | 250 | `BSPortalGraphEntry::Functionfd97a0` | GUESS |
| `0xff19f0` | 113 | `BSFadeNode::Functionff19f0` | GUESS |
| `0x100ae80` | 1697 | `Function100ae80` | GUESS |
| `0x1048aa0` | 109 | `Function1048aa0` | GUESS |
| `0x104ab70` | 175 | `Function104ab70` | GUESS |
| `0x104ac30` | 2095 | `bhkWorld::Unk_32` | MIT NG |
| `0x1058d70` | 200 | `bhkRigidBody::SetLinearVelocity` | MIT NG |
| `0x1058e40` | 200 | `bhkRigidBody::SetAngularVelocity` | MIT NG |
| `0x1058f10` | 152 | `bhkRigidBody::SetLinearImpulse` | MIT NG |
| `0x1058fb0` | 152 | `bhkRigidBody::SetAngularImpulse` | MIT NG |
| `0x10629a0` | 3568 | `bhkCharacterControllerCinfo::Function10629a0` | GUESS |
| `0x1063880` | 903 | `Function1063880` | GUESS |
| `0x1063e80` | 1770 | `bhkCharacterController::Function1063e80` | GUESS |
| `0x10645e0` | 27 | `bhkCharacterController::Function10645e0` | GUESS |
| `0x1064690` | 55 | `bhkCharacterController::Function1064690` | GUESS |
| `0x1066020` | 72 | `bhkCharacterController::Function1066020` | GUESS |
| `0x1066970` | 86 | `bhkCharacterController::IsHurtfulBody` | po3 |
| `0x1066c60` | 745 | `bhkCharacterController::ProcessHurtfulBody` | po3 |
| `0x1069680` | 133 | `bhkCharacterController::~bhkCharacterController` | MIT NG |
| `0x1069b50` | 136 | `hkpCharacterState::~hkpCharacterState` | MIT NG |
| `0x10829c0` | 88 | `bhkSerializable::SetReferencedObject` | MIT NG |
| `0x1082b10` | 114 | `bhkSerializable::Unk_2D` | MIT NG |
| `0x1082b90` | 47 | `bhkSerializable::Unk_30` | MIT NG |
| `0x1082bd0` | 12 | `bhkSerializable::Unk_31` | MIT NG |
| `0x10970a0` | 290 | `Function10970a0` | GUESS |
| `0x10976a0` | 2540 | `bhkCharProxyController::ProcessConstraintsCallback` | MIT NG |
| `0x10980a0` | 144 | `bhkCharProxyController::ContactPointAddedCallback` | MIT NG |
| `0x1098140` | 57 | `bhkCharProxyController::ContactPointRemovedCallback` | MIT NG |
| `0x1098180` | 15 | `bhkCharProxyController::ObjectInteractionCallback` | MIT NG |
| `0x10981a0` | 102 | `bhkCharProxyController::CharacterInteractionCallback` | MIT NG |
| `0x1098c90` | 391 | `bhkCharacterController::Unk_0B` | MIT NG |
| `0x1098e90` | 260 | `bhkCharacterController::CheckSupportImpl` | MIT NG |
| `0x1099420` | 133 | `bhkCharProxyController::~bhkCharProxyController` | MIT NG |
| `0x1099550` | 52 | `bhkCharacterProxy::~bhkCharacterProxy` | MIT NG |
| `0x109aa20` | 157 | `bhkCharacterController::Unk_0E` | po3 |
| `0x109aad0` | 42 | `bhkCharacterController::GetWorldImpl` | po3 |
| `0x109ab10` | 816 | `bhkCharacterController::SetPositionImpl` | po3 |
| `0x109ae50` | 465 | `bhkCharacterController::GetPositionImpl` | po3 |
| `0x109b030` | 124 | `bhkCharacterController::GetTransformImpl` | po3 |
| `0x109b0c0` | 186 | `bhkCharacterController::SetTransformImpl` | po3 |
| `0x109b180` | 54 | `bhkCharacterController::GetLinearVelocityImpl` | po3 |
| `0x109b1c0` | 160 | `bhkCharacterController::SetLinearVelocityImpl` | po3 |
| `0x109b270` | 168 | `bhkCharacterController::GetCollisionFilterInfo` | po3 |
| `0x109b320` | 166 | `bhkCharacterController::Unk_09` | po3 |
| `0x109b3d0` | 382 | `bhkCharacterController::Unk_0B` | po3 |
| `0x109b570` | 199 | `bhkCharacterController::CheckSupportImpl` | po3 |
| `0x109b640` | 1039 | `bhkCharacterController::Unk_12` | po3 |
| `0x109ba60` | 232 | `bhkCharacterController::Unk_0A` | po3 |
| `0x109bb50` | 863 | `bhkCharacterController::RotateImpl` | po3 |
| `0x109c100` | 376 | `bhkCharRigidBodyController::~bhkCharRigidBodyController` | po3 |
| `0x10a09c0` | 394 | `bhkBipedOrientationController::Func8` | GUESS |
| `0x10c7cc0` | 686 | `bhkCharacterStateInAir::Unk_08` | MIT NG |
| `0x10c8030` | 470 | `bhkCharacterStateJumping::Unk_08` | MIT NG |
| `0x10c82d0` | 1303 | `bhkCharacterStateOnGround::Unk_08` | MIT NG |
| `0x10c88b0` | 665 | `bhkCharacterStateSwimming::Unk_08` | MIT NG |
| `0x10ca620` | 314 | `bhkQuadOrientationController::Function10ca620` | GUESS |
| `0x10dd570` | 765 | `bhkCharacterPointCollector::AddCdPoint` | MIT NG |
| `0x10dd880` | 15 | `bhkCharacterPointCollector::Reset` | MIT NG |
| `0x10de370` | 99 | `bhkCharacterProxy::LoadBinary` | MIT NG |
| `0x10de3e0` | 103 | `bhkCharacterProxy::LinkObject` | MIT NG |
| `0x10de450` | 77 | `bhkCharacterProxy::RegisterStreamables` | MIT NG |
| `0x10de4b0` | 73 | `bhkCharacterProxy::SaveBinary` | MIT NG |
| `0x10de660` | 234 | `bhkCharacterProxy::CreateClone` | MIT NG |
| `0x10de750` | 362 | `bhkCharacterProxy::Unk_2F` | MIT NG |
| `0x10de8c0` | 187 | `bhkCharacterProxy::Unk_2B` | MIT NG |
| `0x10de990` | 400 | `bhkCharacterProxy::Unk_2E` | MIT NG |
| `0x10deb30` | 39 | `bhkCharacterProxy::GetWorld1` | MIT NG |
| `0x10deca0` | 218 | `bhkCharacterProxy::AdjustRefCount` | MIT NG |
| `0x11033f0` | 728 | `Function11033f0` | GUESS |
| `0x12130d0` | 140 | `MovementControllerAI::Unk_05` | MIT NG |
| `0x1213180` | 534 | `MovementControllerAI::Unk_07` | MIT NG |
| `0x12133a0` | 243 | `MovementControllerAI::Unk_08` | MIT NG |
| `0x12134a0` | 204 | `IMovementControllerRegisterInterface::Unk_01` | MIT NG |
| `0x1213580` | 196 | `IMovementControllerRegisterInterface::Unk_03` | MIT NG |
| `0x1213650` | 196 | `IMovementControllerRegisterInterface::Unk_02` | MIT NG |
| `0x1213720` | 335 | `IMovementControllerRegisterInterface::Unk_04` | MIT NG |
| `0x14e81f0` | 320 | `NiAVObject::Function14e81f0` | GUESS |
| `0x14e89d0` | 181 | `BSLeafAnimNode::OnVisible` | meh321 |
| `0x14e93d0` | 108 | `BSTreeNode::OnVisible` | meh321 |
| `0x14ea2d0` | 3641 | `Function14ea2d0` | GUESS |
| `0x14ec3b0` | 889 | `Function14ec3b0` | GUESS |
| `0x150ba50` | 1436 | `ShadowSceneNode::ctor` | meh321 |
| `0x150c810` | 758 | `ShadowSceneNode::AddLight` | po3 |
| `0x150cbf0` | 303 | `Function150cbf0` | GUESS |
| `0x150d240` | 333 | `Function150d240` | GUESS |
| `0x150e090` | 343 | `ShadowSceneNode::RemoveAllLights` | po3 |
| `0x150e400` | 238 | `ShadowSceneNode::Function150e400` | GUESS |
| `0x150f3d0` | 420 | `ShadowSceneNode::Function150f3d0` | GUESS |
| `0x150f8b0` | 121 | `Function150f8b0` | GUESS |
| `0x1514c80` | 80 | `Function1514c80` | GUESS |
| `0x1518110` | 259 | `Function1518110` | GUESS |
| `0x151a160` | 4211 | `BSLightingShaderProperty::GetRenderPasses` | MIT NG |
| `0x151b1e0` | 2757 | `BSLightingShaderProperty::Unk_2B` | MIT NG |
| `0x151cbc0` | 1030 | `Function151cbc0` | GUESS |
| `0x151f540` | 1581 | `BSShaderAccumulator::Function151f540` | GUESS |
| `0x1522870` | 2048 | `BSGrassShader::Func6` | GUESS |
| `0x15233c0` | 120 | `Function15233c0` | GUESS |
| `0x152be10` | 479 | `Function152be10` | GUESS |
| `0x152c700` | 1524 | `BSWaterShaderProperty::GetRenderPasses` | MIT NG |
| `0x1531b30` | 1788 | `Function1531b30` | GUESS |
| `0x1537fd0` | 1111 | `NiCamera::CalculateAndDrawShadowCasterLights` | meh321 |
| `0x1538860` | 328 | `ResetCalculatedShadowCasterLights` | meh321 |
| `0x15389b0` | 1354 | `CalculateActiveShadowCasterLights` | meh321 |
| `0x1538fa0` | 2755 | `Function1538fa0` | GUESS |
| `0x1539f10` | 1684 | `Main::RenderWorld` | po3 |
| `0x1541230` | 938 | `Function1541230` | GUESS |
| `0x1541f40` | 5188 | `Function1541f40` | GUESS |
| `0x1547210` | 648 | `Function1547210` | GUESS |
| `0x154b770` | 252 | `Function154b770` | GUESS |
| `0x154b880` | 773 | `Function154b880` | GUESS |
| `0x154bb90` | 627 | `Function154bb90` | GUESS |
| `0x154c010` | 438 | `Function154c010` | GUESS |
| `0x154d700` | 1715 | `BSWaterShader::Func4` | GUESS |
| `0x1555fd0` | 195 | `BSFadeNodeCuller::Process1` | po3 |
| `0x1556840` | 1006 | `BSEffectShader::Func2` | GUESS |
| `0x1557090` | 3765 | `BSEffectShader::Func6` | GUESS |
| `0x1558fd0` | 1163 | `BSDistantTreeShader::Func2` | GUESS |
| `0x155c4b0` | 216 | `Function155c4b0` | GUESS |
| `0x155ca00` | 1165 | `BSShadowDirectionalLight::Function155ca00` | GUESS |
| `0x155d110` | 340 | `BSShadowDirectionalLight::Function155d110` | GUESS |
| `0x155d270` | 1348 | `BSShadowParabolicLight::Function155d270` | GUESS |
| `0x1566710` | 2295 | `BSUtilityShader::SetupTechnique` | po3 |
| `0x15673f0` | 3208 | `BSUtilityShader::SetupGeometry` | po3 |
| `0x1569550` | 539 | `Function1569550` | GUESS |
| `0x1575930` | 434 | `Function1575930` | GUESS |
| `0x1575d20` | 452 | `BSLight::Function1575d20` | GUESS |
| `0x157e490` | 1114 | `Function157e490` | GUESS |
| `0x157ebb0` | 335 | `BSShadowDirectionalLight::Render` | po3 |
| `0x157f080` | 9883 | `BSShadowDirectionalLight::UpdateCamera` | po3 |
| `0x1581730` | 639 | `Function1581730` | GUESS |
| `0x15872e0` | 824 | `BSShadowLight::Function15872e0` | GUESS |
| `0x1587bc0` | 805 | `BSShadowFrustumLight::UpdateCamera` | po3 |
| `0x1587f90` | 1473 | `Function1587f90` | GUESS |
| `0x1588590` | 822 | `BSShadowParabolicLight::UpdateCamera` | po3 |
| `0x158e440` | 1342 | `Function158e440` | GUESS |
| `0x17b1040` | 93 | `Function17b1040` | GUESS |
