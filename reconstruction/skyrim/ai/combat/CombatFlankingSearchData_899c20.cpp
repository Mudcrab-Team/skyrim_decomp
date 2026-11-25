// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x899c20 CombatFlankingSearchData::LoadGame
// Adapted bodies: CombatFlankingSearchData::LoadGame from the sibling source named in the header
#include "CombatFlankingSearchData_899c20.h"

void CombatFlankingSearchData::LoadGame(BGSLoadGameBuffer* a_buffer)
{
    a_buffer->LoadDataEndian(&StartLocation, sizeof(StartLocation), sizeof(float));
    a_buffer->LoadDataEndian(&GoalLocation, sizeof(GoalLocation), sizeof(float));
    a_buffer->LoadDataEndian(&StartDirection, sizeof(StartDirection), sizeof(float));
    a_buffer->LoadDataEndian(&ChosenLocation, sizeof(ChosenLocation), sizeof(float));
    a_buffer->LoadDataEndian(&fStartAngle, sizeof(fStartAngle), sizeof(fStartAngle));
    a_buffer->LoadDataEndian(&fGoalAngle, sizeof(fGoalAngle), sizeof(fGoalAngle));
    a_buffer->LoadDataEndian(&fCurrentAngle, sizeof(fCurrentAngle), sizeof(fCurrentAngle));
    a_buffer->LoadDataEndian(&fStartDistance, sizeof(fStartDistance), sizeof(fStartDistance));
    a_buffer->LoadDataEndian(&fFlankDistance, sizeof(fFlankDistance), sizeof(fFlankDistance));
    a_buffer->LoadDataEndian(&fRange, sizeof(fRange), sizeof(fRange));
    a_buffer->LoadDataEndian(&uiDirection, sizeof(uiDirection), sizeof(uiDirection));
}
