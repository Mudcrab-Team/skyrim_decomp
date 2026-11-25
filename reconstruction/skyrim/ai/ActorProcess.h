// Source exposure: mixed (pinned image listings and community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorProcess: EXE_RTTI
// GetEquippedLeftHand: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Code origin: project ActorProcess declaration with a partial layout adapted from CommonLibSSE-NG.
// ProcessData, padding, member: STANDIN GUESS(low)
// AIProcess::middleHigh, MagicSystem, MagicSystem::WardState, BSFaceGenAnimationData, BSFaceGenNiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject, NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function7265a0, Function726fa0, Function726fc0, Function727020, Function727060: GUESS(low)
// Function727080, Function7270d0, Function7270f0, Function727110, Function7271e0: GUESS(low)
// Function727200, Function727220, Function727240, Function727260, Function727280: GUESS(low)
// Function7272a0, Function727420, Function727440, Function727460, Function7274a0: GUESS(low)
// Function727ae0, Function727b00, Function727cf0, Function727d10, Function727d30: GUESS(low)
// Function727d50, Function727d70, Function727d90, Function727db0, Function727df0: GUESS(low)
// Function727e10, Function727e30, Function727e50, Function727e70, Function727e90: GUESS(low)
// Function727ee0, Function727f00, Function727f20, Function727f40, Function727f60: GUESS(low)
// Function7284e0, Function728500, Function728520, Function728540, Function728560: GUESS(low)
// Function728580: GUESS(low)
#pragma once

#include <cstdint>

struct ObjectRefHandle
{
    ObjectRefHandle& operator=(const ObjectRefHandle& a_rhs)
    {
        native_handle = a_rhs.native_handle;
        return *this;
    }

    bool operator==(const ObjectRefHandle& a_rhs) const
    {
        return native_handle == a_rhs.native_handle;
    }

    std::uint32_t native_handle;  // 0
};
static_assert(sizeof(ObjectRefHandle) == 0x4, "ObjectRefHandle size");

extern const ObjectRefHandle kNullHandle;
extern float defaultBreathTimer;
extern float defaultDetectionModifierTimer;

class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class NiAVObject;
class NiNode;
namespace MagicSystem
{
    enum class WardState;
}

// ActorProcessTarget: STANDIN GUESS(low); polymorphic object whose virtual at slot 0xe0 is called
class ActorProcessTarget
{
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
    virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127();
    virtual void v128(); virtual void v129(); virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135();
    virtual void v136(); virtual void v137(); virtual void v138(); virtual void v139(); virtual void v140(); virtual void v141(); virtual void v142(); virtual void v143();
    virtual void v144(); virtual void v145(); virtual void v146(); virtual void v147(); virtual void v148(); virtual void v149(); virtual void v150(); virtual void v151();
    virtual void v152(); virtual void v153(); virtual void v154(); virtual void v155(); virtual void v156(); virtual void v157(); virtual void v158(); virtual void v159();
    virtual void v160(); virtual void v161(); virtual void v162(); virtual void v163(); virtual void v164(); virtual void v165(); virtual void v166(); virtual void v167();
    virtual void v168(); virtual void v169(); virtual void v170(); virtual void v171(); virtual void v172(); virtual void v173(); virtual void v174(); virtual void v175();
    virtual void v176(); virtual void v177(); virtual void v178(); virtual void v179(); virtual void v180(); virtual void v181(); virtual void v182(); virtual void v183();
    virtual void v184(); virtual void v185(); virtual void v186(); virtual void v187(); virtual void v188(); virtual void v189(); virtual void v190(); virtual void v191();
    virtual void v192(); virtual void v193(); virtual void v194(); virtual void v195(); virtual void v196(); virtual void v197(); virtual void v198(); virtual void v199();
    virtual void v200(); virtual void v201(); virtual void v202(); virtual void v203(); virtual void v204(); virtual void v205(); virtual void v206(); virtual void v207();
    virtual void v208(); virtual void v209(); virtual void v210(); virtual void v211(); virtual void v212(); virtual void v213(); virtual void v214(); virtual void v215();
    virtual void v216(); virtual void v217(); virtual void v218(); virtual void v219(); virtual void v220(); virtual void v221(); virtual void v222(); virtual void v223();
    virtual void* Function6fe650Target();
};

class ActorProcess
{
public:
    virtual void* GetEquippedLeftHand() const;
    void Function7265a0();
    void Function726fa0(std::uint64_t a_value);
    std::uint64_t Function726fc0() const;
    void Function727020(bool a_value);
    void Function727060(bool a_value);
    bool Function727080() const;
    void Function7270d0(float a_value);
    float Function7270f0() const;
    void Function727110(float a_value);
    void Function7271e0();
    std::uint64_t Function727200() const;
    void Function727220(std::uint64_t a_value);
    void Function727240(bool a_value);
    bool Function727260() const;
    void Function727280(bool a_value);
    bool Function7272a0() const;
    NiNode* Function727420(std::int32_t a_index) const;
    NiAVObject* Function727440() const;
    NiAVObject* Function727460() const;
    void Function7274a0(bool a_value);
    BSFaceGenNiNode* Function727ae0() const;
    void Function727b00(BSFaceGenNiNode* a_value);
    bool Function727cf0() const;
    void Function727d10(bool a_value);
    bool Function727d30() const;
    void Function727d50(bool a_value);
    bool Function727d70() const;
    void Function727d90(bool a_value);
    void Function727db0(BSFaceGenAnimationData* a_value);
    void Function727df0(float a_value);
    float Function727e10() const;
    void Function727e30(float a_value);
    float Function727e50() const;
    void Function727e70(float a_value);
    void Function727e90(const std::uint32_t& a_value);
    bool Function727ee0() const;
    void Function727f00(bool a_value);
    bool Function727f20() const;
    void Function727f40(bool a_value);
    void Function727f60(MagicSystem::WardState a_value);
    void Function7284e0();
    void Function728500();
    void Function728520();
    void Function728540();
    void Function728560();
    bool Function728580() const;
    float Function6f5220() const;
    void Function720580();
    void Function6e97b0();
    std::uint32_t Function6ff530() const;
    bool Function6f6030() const;
    void* Function7220d0();
    void* Function7206c0(bool a_flag) const;
    void Function6f64b0(std::uint16_t a_action, std::uint64_t a_value);
    ObjectRefHandle& Function6f6de0(ObjectRefHandle& a_handle) const;
    void Function6f6e10(const ObjectRefHandle& a_handle, bool a_activated);
    void Function6f6f30(float a_value);
    bool Function6fe020() const;
    float Function6fe5d0() const;
    ObjectRefHandle& Function6ff4b0(ObjectRefHandle& a_handle) const;
    void Function6ff500(const ObjectRefHandle& a_handle);
    std::int32_t Function6ffe80(std::int32_t a_index) const;
    void Function6ffef0();
    bool Function720f60() const;
    bool Function7216e0() const;
    bool HasRunOncePackage() const;
    ObjectRefHandle& Function726eb0(ObjectRefHandle& a_handle) const;
    float Function7270a0() const;
    ObjectRefHandle& Function727eb0(ObjectRefHandle& a_handle) const;

    struct ProcessData;
    struct HighProcessData;
    ProcessData* middleHigh;  // 08
    HighProcessData* high;  // 10
    // fallbackRecord: STANDIN GUESS(low); same kind of record as ProcessData::unk58
    void* fallbackRecord;  // 18
    std::uint8_t padding[0xd0];  // 20
    void* member;  // F0
    std::uint8_t pad0F8[0x1c];  // F8
    std::uint32_t unk114;  // 114
    void* Function6fe650(ActorProcessTarget* a_target);
    float Function700140(std::int32_t a_index) const;
};
