// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BGSMenuDisplayObject: EXE_RTTI
// GetMenuDisplayObject: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>

// BaseFormComponent: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the class name, slot order and 8-byte size are claimed
class BaseFormComponent
{
public:
    // BaseFormComponent::~BaseFormComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 0
    virtual ~BaseFormComponent() {}
    // BaseFormComponent::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 1
    virtual void InitializeDataComponent();
    // BaseFormComponent::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 2
    virtual void ClearDataComponent();
    // BaseFormComponent::CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 3
    virtual void CopyComponent();
};
static_assert(sizeof(BaseFormComponent) == 0x8, "layout");

class BGSMenuDisplayObject : public BaseFormComponent
{
public:
    // BGSMenuDisplayObject::BGSMenuDisplayObject: GUESS(low); defined so the vftable and the deleting destructor are emitted
    BGSMenuDisplayObject();
    // BGSMenuDisplayObject::~BGSMenuDisplayObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the listing inlines the complete destructor, so the body is empty
    ~BGSMenuDisplayObject() override {}
    // BGSMenuDisplayObject::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    void InitializeDataComponent() override;
    // BGSMenuDisplayObject::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    void ClearDataComponent() override;
    // GetMenuDisplayObject: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
    virtual void* GetMenuDisplayObject() const;

    void* member;  // 08
};
static_assert(sizeof(BGSMenuDisplayObject) == 0x10, "layout");
