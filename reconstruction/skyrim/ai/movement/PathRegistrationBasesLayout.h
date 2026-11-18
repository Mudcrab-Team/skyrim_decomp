// Source exposure: mixed (community and permitted sibling declarations; target RTTI and construction analysis).
// Code origin: original declarations and defaulted owner construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IBSTCreator.h and include/RE/A/AutoRegisterFactory.h; MIT.
// Declaration source: fo4-private@1b765c70 src/BSSystem/BSTCreateFactory.h and src/BSPathfinding/BSTPathingFactory.h; game-code only, author-permission.
// IBSTCreator, AutoRegisterFactory: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AutoRegisterCreator, AutoRegisterSmartPtrDerivedPathingType: SIBLING(fo4-private@1b765c70, author-permission)
// IPathBuilderFactoryBase, CombatPathingRequestBuilder, AutoRegisterCombatPathingRequestGeneric: EXE_RTTI
// PathRegistrationCreatorLayout, PathBuilderRegistrationLayout, PathRegistrationBasesLayout: GUESS(medium) STANDIN
// Product, Identity, Create, Destroy: GUESS(low) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
namespace ResearchLayouts {
template<class Product, class Identity>
class PathRegistrationCreatorLayout {
public:
    PathRegistrationCreatorLayout();
    virtual ~PathRegistrationCreatorLayout();
    virtual Product* Create() const;
    virtual void Destroy(const Product*) const;
};
template<class Identity>
class PathBuilderRegistrationLayout {
public:
    PathBuilderRegistrationLayout();
    virtual ~PathBuilderRegistrationLayout();
    virtual void Create();
};
// Physical vptr storage mirror, independently observed at the twelve owner construction sites.
// This mirror supplies compile-time offsets; the compiler-emitted adjustors test the real base conversions.
struct PathRegistrationBasesLayout {
    const void* const* requestCreator;
    const void* const* builderFactory;
    const void* const* combatCreator;
};
static_assert(sizeof(PathRegistrationBasesLayout) == 24, "three observed vptr slots");
static_assert(offsetof(PathRegistrationBasesLayout, requestCreator) == 0, "primary subobject slot");
static_assert(offsetof(PathRegistrationBasesLayout, builderFactory) == 8, "builder subobject slot");
static_assert(offsetof(PathRegistrationBasesLayout, combatCreator) == 16, "combat subobject slot");
static_assert(sizeof(PathRegistrationCreatorLayout<void, void>) == 8, "represented creator contract size");
static_assert(sizeof(PathBuilderRegistrationLayout<void>) == 8, "represented builder interface size");
}
