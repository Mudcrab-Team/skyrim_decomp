// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0x1d8f80 (skyrim/interface/BGSMenuDisplayObject): source copied, names replaced by placeholders.
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Owner121290: GUESS(low) STANDIN
// GetMenuDisplayObject, member, Owner121290::Owner121290, Owner121290::~Owner121290, Owner121290::InitializeDataComponent, Owner121290::ClearDataComponent: GUESS(low) STANDIN
#pragma once
#include "BGSMenuDisplayObject.h"

class Owner121290 : public BaseFormComponent
{
public:
    Owner121290();
    ~Owner121290() override {}
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    virtual void* GetMenuDisplayObject() const;

    void* member;  // 08
};
static_assert(sizeof(Owner121290) == 0x10, "layout");
