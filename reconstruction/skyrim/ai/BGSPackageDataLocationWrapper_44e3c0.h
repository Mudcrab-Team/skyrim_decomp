// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// BGSPackageDataLocationWrapper::AllocateLocation: SIBLING(fo4-private@1b765c70, author-permission); adapted location cloning.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageData.cpp:159
// IAIWorldLocationHandle, IPackageDataAIWorldLocationHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class AIWorldLocationContext;
class IAIWorldLocation {
public:
    virtual ~IAIWorldLocation();
    virtual const IAIWorldLocation* Clone() const = 0;
};
class IAIWorldLocationHandle { public: virtual ~IAIWorldLocationHandle(); };
class IPackageData { public: virtual ~IPackageData(); };
class IPackageDataAIWorldLocationHandle : public IAIWorldLocationHandle, public IPackageData {};
class BGSPackageDataLocationWrapper : public IPackageDataAIWorldLocationHandle {
public:
    const IAIWorldLocation* AllocateLocation(AIWorldLocationContext&) const;
    IAIWorldLocation* location;
};
