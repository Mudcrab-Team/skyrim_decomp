// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// TESObjectLAND: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// TESObjectLAND, TESForm, TESChildCell, BaseFormComponent, TESFileContainer, LoadedLandData, OBJ_LAND, data, parentCell, queuedTextures, loadedData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function2ab510, UpdateData, FinishUpdate, ptr: GUESS(low)
class TESFileArray; class TESObjectCELL; class QueuedFile;
enum class FormType : std::uint8_t;
namespace stl { template<class E, class T> struct enumeration { T value; }; }
struct TESFileContainer { TESFileArray* array; };
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent {
public:
 enum class InGameFormFlag : std::uint16_t;
 TESFileContainer sourceFiles;
 std::uint32_t formFlags, formID;
 stl::enumeration<InGameFormFlag, std::uint16_t> inGameFormFlags;
 stl::enumeration<FormType, std::uint8_t> formType;
 std::uint8_t pad1B;
 std::uint32_t pad1C;
};
class TESChildCell { public: virtual ~TESChildCell(); virtual TESObjectCELL* GetSaveParentCell() = 0; };
template<class T> struct NiPointer { T* ptr; };
struct OBJ_LAND { enum class Flag : std::uint32_t; stl::enumeration<Flag, std::uint32_t> flags; };
class TESObjectLAND : public TESForm, public TESChildCell {
public:
 struct LoadedLandData;
 void Function2ab510(std::uint8_t first, std::uint16_t second);
 void FinishUpdate();
 OBJ_LAND data;
 std::uint32_t pad2C;
 TESObjectCELL* parentCell;
 NiPointer<QueuedFile> queuedTextures;
 LoadedLandData* loadedData;
};
void UpdateData(std::uint8_t first, std::uint16_t second, TESObjectLAND::LoadedLandData* data);
