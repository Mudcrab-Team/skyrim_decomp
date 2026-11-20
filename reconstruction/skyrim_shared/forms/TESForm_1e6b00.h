// Source exposure: mixed
// Origin: authorized sibling and community declarations
// GPL-3.0: declarations adapted from powerof3/CommonLibSSE at 654e55f7979c1733033d5dbef176e43827bac944, include/RE/F/FORM.h, FORM_ENUM_STRING.h and include/RE/T/TESForm.h.
// TESForm::CreateGroupData: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESForm.cpp:960
// TESForm, FORM, FORM_GROUP: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0); declarations adapted
// names: GUESS(low); signatures and table interpretation remain provisional
#pragma once
#include <cstdint>
class TESFileArray;
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent() = 0; virtual void ClearDataComponent() = 0; virtual void CopyComponent(BaseFormComponent*); };
struct TESFileContainer { TESFileArray* array; };
struct FORM { std::uint32_t form; std::uint32_t length; std::uint32_t flags; std::uint32_t formID; std::uint32_t versionControl; std::uint16_t formVersion; std::uint16_t vcVersion; };
struct FORM_GROUP { FORM groupData; std::uint64_t groupOffset; };
struct FORM_ENUM_STRING { std::uint32_t formCode; const char* name; std::uint32_t type; };
extern FORM_ENUM_STRING formEnumString[];
class TESForm : public BaseFormComponent {
public:
    void CreateGroupData(FORM* out, FORM_GROUP* parent);
    TESFileContainer sourceFiles;
    std::uint32_t formFlags;
    std::uint32_t formID;
    std::uint16_t inGameFormFlags;
    std::uint8_t formType;
};
