// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Sky; size 0x2c8
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSTArray_RE__NiPointer_RE__NiTexture_5ccea35d.h"
#include "BSTArray_RE__Sky__SkyStaticRefData_6f8331d3.h"
#include "NiColor_e5e1ad7d.h"
#include "NiPointer_RE__BSMultiBoundNode_89b53a24.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "NiPointer_RE__ReferenceEffect_2bc3c4de.h"
#include "RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265.h"
#include "SkyEffectController.h"
#include "Sky__Flags.h"
#include "Sky__Mode.h"
struct Atmosphere;
struct BGSLightingTemplate;
struct Clouds;
struct ImageSpaceModifierInstanceForm;
struct Moon;
struct Precipitation;
struct RE__BSSimpleList_RE__SkySound_8712c759;
struct Sky_vtbl;
struct Stars;
struct Sun;
struct TESClimate_c9cfcf5f;
struct TESRegion;
struct TESWeather_4adb958d;
struct Sky {
    Sky_vtbl* __vftable;
    NiPointer_RE__BSMultiBoundNode_89b53a24 root;
    NiPointer_RE__NiNode_28171d5b moonsRoot;
    NiPointer_RE__NiNode_28171d5b auroraRoot;
    RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265 auroraModel;
    BGSLightingTemplate* extLightingOverride;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 currentRoom;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 previousRoom;
    float lightingTransition;
    float lightingTransitionTimer;
    TESClimate_c9cfcf5f* currentClimate;
    TESWeather_4adb958d* currentWeather;
    TESWeather_4adb958d* lastWeather;
    TESWeather_4adb958d* defaultWeather;
    TESWeather_4adb958d* overrideWeather;
    TESRegion* region;
    Atmosphere* atmosphere;
    Stars* stars;
    Sun* sun;
    Clouds* clouds;
    Moon* masser;
    Moon* secunda;
    Precipitation* precip;
    NiColor_e5e1ad7d skyColorSkyUpper;
    NiColor_e5e1ad7d skyColorFogNear;
    NiColor_e5e1ad7d skyColorUnknown;
    NiColor_e5e1ad7d skyColorAmbient;
    NiColor_e5e1ad7d skyColorSunlight;
    NiColor_e5e1ad7d skyColorSun;
    NiColor_e5e1ad7d skyColorStars;
    NiColor_e5e1ad7d skyColorSkyLower;
    NiColor_e5e1ad7d skyColorHorizon;
    NiColor_e5e1ad7d skyColorEffectLighting;
    NiColor_e5e1ad7d skyColorCloudLODDiffuse;
    NiColor_e5e1ad7d skyColorCloudLODAmbient;
    NiColor_e5e1ad7d skyColorFogFar;
    NiColor_e5e1ad7d skyColorSkyStatics;
    NiColor_e5e1ad7d skyColorWaterMultiplier;
    NiColor_e5e1ad7d skyColorSunGlare;
    NiColor_e5e1ad7d skyColorMoonGlare;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    NiColor_e5e1ad7d unk180;
    float windSpeed;
    float windAngle;
    float fogNear;
    float fogFar;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    float fogPower;
    float fogClamp;
    float currentGameHour;
    float lastWeatherUpdate;
    float currentWeatherPct;
    Sky__Mode mode;
    RE__BSSimpleList_RE__SkySound_8712c759* skySoundList;
    float flash;
    unsigned int pad1CC;
    unsigned int flashTime;
    float windowReflectionTimer;
    unsigned int lastMoonPhaseUpdate;
    Sky__Flags flags;
    ImageSpaceModifierInstanceForm* currentWeatherImageSpaceMod;
    ImageSpaceModifierInstanceForm* currentWeatherImageSpaceMod2;
    ImageSpaceModifierInstanceForm* lastWeatherImageSpaceMod;
    ImageSpaceModifierInstanceForm* lastWeatherImageSpaceMod2;
    NiColor_e5e1ad7d directionalAmbientColors[3][2];
    NiColor_e5e1ad7d ambientSpecularTint;
    float ambientSpecularFresnel;
    float auroraInStart;
    float auroraIn;
    float auroraOutStart;
    float auroraOut;
    NiPointer_RE__ReferenceEffect_2bc3c4de currentReferenceEffect;
    NiPointer_RE__ReferenceEffect_2bc3c4de lastReferenceEffect;
    SkyEffectController effectController;
    BSTArray_RE__NiPointer_RE__NiTexture_5ccea35d storedCloudTextures;
    BSTArray_RE__NiPointer_RE__NiTexture_5ccea35d storedWorldMapCloudTextures;
    BSTArray_RE__Sky__SkyStaticRefData_6f8331d3 skyStaticRefData;
};
static_assert(sizeof(Sky) == 712, "Sky layout differs from the PDB");
