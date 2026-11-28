// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BSWin32AwardsSystemUtility: CRASHLOGGER_PDB(59818@2026.10.24)
// BSAwardsSystemUtility, enabled: GUESS(low)
#pragma once

class BSAwardsSystemUtility
{
public:
    BSAwardsSystemUtility();
    virtual ~BSAwardsSystemUtility();

    bool enabled;  // 08
};

class BSWin32AwardsSystemUtility : public BSAwardsSystemUtility
{
public:
    BSWin32AwardsSystemUtility();  // compared: 0x159f1b0
};
