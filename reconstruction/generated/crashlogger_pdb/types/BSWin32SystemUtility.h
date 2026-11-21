// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSWin32SystemUtility; size 0x210
#pragma once

#include "BSSystemUtility.h"
#include "CCallResult_RE__BSWin32SystemUtility_RE__EncryptedAppTicketResponse_t_8c9dcdbe.h"
#include "CCallback_RE__BSWin32SystemUtility_RE__FloatingGamepadTextInputDismissed_t_86ede765.h"
#include "CCallback_RE__BSWin32SystemUtility_RE__GameOverlayActivated_t_b94d8da2.h"
#include "CCallback_RE__BSWin32SystemUtility_RE__GamepadTextInputDismissed_t_1e904ee3.h"
struct ISteamClient;
struct ISteamUtils;
struct BSWin32SystemUtility {
    BSSystemUtility _base;
    CCallback_RE__BSWin32SystemUtility_RE__GameOverlayActivated_t_b94d8da2 steamcallback_GameOverlayActivated;
    CCallback_RE__BSWin32SystemUtility_RE__FloatingGamepadTextInputDismissed_t_86ede765 steamcallback_FloatingGamepadTextInputDismissed;
    CCallback_RE__BSWin32SystemUtility_RE__GamepadTextInputDismissed_t_1e904ee3 steamcallback_GamepadTextInputDismissed;
    CCallResult_RE__BSWin32SystemUtility_RE__EncryptedAppTicketResponse_t_8c9dcdbe steamcallresult_EncryptedAppTicketResponse;
    unsigned char virtualKeyboardDone_raw[8];
    unsigned char virtualKeyboardCancel_raw[8];
    void* virtualKeyboardUserParam;
    bool steamAPIInitialized;
    unsigned char pad1E9;
    unsigned short pad1EA;
    unsigned int pad1EC;
    ISteamClient* steamClient;
    int steamPipe;
    unsigned int pad1FC;
    ISteamUtils* steamUtils;
    bool isRunningOnSteamDeck;
    unsigned char undefined_209[7];
};
static_assert(sizeof(BSWin32SystemUtility) == 528, "BSWin32SystemUtility layout differs from the PDB");
