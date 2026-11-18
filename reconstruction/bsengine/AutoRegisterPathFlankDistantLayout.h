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
// AutoRegisterPathFlankDistantLayout, AutoRegisterPathFlankDistantLayoutIdentity: GUESS(medium) STANDIN
#pragma once
#include "PathRegistrationBasesLayout.h"
namespace ResearchLayouts {
class AutoRegisterPathFlankDistantLayoutIdentity;
class AutoRegisterPathFlankDistantLayoutIdentityRequest;
class AutoRegisterPathFlankDistantLayoutIdentityCombatPath;
class AutoRegisterPathFlankDistantLayout : public PathRegistrationCreatorLayout<AutoRegisterPathFlankDistantLayoutIdentityRequest, AutoRegisterPathFlankDistantLayoutIdentity>,
    public PathBuilderRegistrationLayout<AutoRegisterPathFlankDistantLayoutIdentity>,
    public PathRegistrationCreatorLayout<AutoRegisterPathFlankDistantLayoutIdentityCombatPath, AutoRegisterPathFlankDistantLayoutIdentity> {
public:
    AutoRegisterPathFlankDistantLayout();
    ~AutoRegisterPathFlankDistantLayout() override;
};
static_assert(sizeof(AutoRegisterPathFlankDistantLayout) == 24, "three represented registration base contracts");
}
