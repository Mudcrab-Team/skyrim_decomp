// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and layout as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent, TESContainer, TESContainer::~TESContainer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESContainer.cpp:78
// FreeObjectList: SIBLING(fo4-private@1b765c70, author-permission)
// pContainerObjectsA, uiNumContainerObjects: GUESS(medium); names as the sibling uses them in its own TESContainer
#pragma once

#include <cstdint>

struct ContainerObject;

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() {}  // 00
    virtual void InitializeDataComponent() = 0;  // 01
    virtual void ClearDataComponent() = 0;  // 02
    virtual void CopyComponent(BaseFormComponent* a_rhs);  // 03
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class TESContainer : public BaseFormComponent
{
public:
    ~TESContainer() override;  // 00, compared: 0x1e0000
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02

    void FreeObjectList();

    ContainerObject** pContainerObjectsA;  // 08
    std::uint32_t uiNumContainerObjects;  // 10
    std::uint32_t pad14;  // 14
};
static_assert(sizeof(TESContainer) == 0x18, "TESContainer size");
