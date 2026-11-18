// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x24a020 TESCameraState::GetRotation
// 0x24a030 TESCameraState::GetTranslation
#include "TESCameraState.h"

void TESCameraState::GetRotation(NiQuaternion& a_rotation)
{
    a_rotation = niQuatDefault;
}

void TESCameraState::GetTranslation(NiPoint3& a_translation)
{
    a_translation.x = niPointZero.x;
    a_translation.y = niPointZero.y;
    a_translation.z = niPointZero.z;
}

void TESCameraState::Begin()
{
}

void TESCameraState::End()
{
}

void TESCameraState::LoadGame(BGSLoadFormBuffer*)
{
}
