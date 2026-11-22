// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Body reconstructed from the target listing.
// SetActorValue: Sibling source: fo4-private@1b765c70 src/Game/Magic/StimpakEffect.cpp:6
// ValueModifierEffect, ValueModifierEffect::SetActorValue: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, actorValue, maxDistance: STANDIN GUESS(low)
#pragma once
#include <cstdint>

// MagicTarget, MagicTarget::GetOwnerActor: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); the callee is compared elsewhere
class Actor;
class MagicTarget {
public:
    Actor* GetOwnerActor();
};

// Actor::IsDead: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 0x99, the earlier slots are placeholders
class Actor {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D(); virtual void v1E(); virtual void v1F();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B(); virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D(); virtual void v4E(); virtual void v4F();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
    virtual void v58(); virtual void v59(); virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B(); virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v7A(); virtual void v7B(); virtual void v7C(); virtual void v7D(); virtual void v7E(); virtual void v7F();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v8A(); virtual void v8B(); virtual void v8C(); virtual void v8D(); virtual void v8E(); virtual void v8F();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97();
    virtual void v98();
    virtual bool IsDead(bool a_notEssential = true) const;  // 99
};

// ActiveEffectFactory, ActiveEffectFactory::CheckTargetArgs: SYMBOLS(fo4-pdb); only the first member is read
// CheckTargetArgs::target: GUESS(low)
struct ActiveEffectFactory {
    struct CheckTargetArgs {
        MagicTarget* target;  // 00
    };
};
class ValueModifierEffect {
public:
    // CheckTarget: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
    static bool CheckTarget(ActiveEffectFactory::CheckTargetArgs& a_args);
    void SetActorValue(std::uint32_t value);
    void Function5bcba0(const void* a_location);
private:
    std::uint64_t unknown00[18];
    std::uint32_t actorValue;
};
