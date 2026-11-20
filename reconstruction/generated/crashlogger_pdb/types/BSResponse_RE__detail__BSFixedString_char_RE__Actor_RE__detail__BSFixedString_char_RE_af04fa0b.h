// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSResponse<RE::detail::BSFixedString<char>, RE::Actor, RE::detail::BSFixedString<char>, RE::DoNothingUnhandledPolicy>; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSIntrusiveRefCounted_8d4cb673.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_6e86b1a5.h"
#include "BSTSmartPointer_RE__BSResponse_RE__detail__BSFixedString_char_RE__Actor_RE__detail__BSF_3b7c5b70.h"
#include "DoNothingUnhandledPolicy_RE__detail__BSFixedString_char_000152ac.h"
struct BSResponse_RE__detail__BSFixedString_char_RE__Actor_RE__detail__BSFixedString_char_RE_af04fa0b {
    DoNothingUnhandledPolicy_RE__detail__BSFixedString_char_000152ac _base;
    BSIntrusiveRefCounted_8d4cb673 _base_BSIntrusiveRefCounted;
    unsigned char undefined_c[4];
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_6e86b1a5 handlerMap;
    BSTSmartPointer_RE__BSResponse_RE__detail__BSFixedString_char_RE__Actor_RE__detail__BSF_3b7c5b70 backupResponse;
};
static_assert(sizeof(BSResponse_RE__detail__BSFixedString_char_RE__Actor_RE__detail__BSFixedString_char_RE_af04fa0b) == 72, "BSResponse_RE__detail__BSFixedString_char_RE__Actor_RE__detail__BSFixedString_char_RE_af04fa0b layout differs from the PDB");
