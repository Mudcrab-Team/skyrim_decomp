// Source exposure: mixed (community headers; the pinned image listing).
// BaseFormComponent, TESTexture, BSFixedString, textureName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// BSFixedString::value: GUESS(low)
#pragma once

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() {}
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(BaseFormComponent* a_rhs);
};

class BSFixedString
{
public:
    ~BSFixedString();

    const char* value;  // 00
};

class TESTexture : public BaseFormComponent
{
public:
    ~TESTexture() override;

    BSFixedString textureName;  // 08
};
static_assert(sizeof(TESTexture) == 0x10, "TESTexture size");
