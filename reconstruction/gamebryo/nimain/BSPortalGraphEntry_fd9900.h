// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSPortalGraphEntry, FindVisibility: CRASHLOGGER_PDB(59818@2026.10.24)
// Adapted bodies: BSReadLockGuard constructor and destructor, CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp (MIT).
// NiNode, BSCompoundFrustum, visibilityMap: CRASHLOGGER_PDB(59818@2026.10.24)
// BSReadLockGuard, BSReadWriteLock, LockForRead, UnlockForRead, CRC32Calculator, SizeOf64: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// VisibilityEntry, VisibilityMap, portalVisibilityLock: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

#include <cstdint>

class NiNode;
class BSCompoundFrustum;
class BSReadWriteLock
{
public:
    void LockForRead();
    void UnlockForRead();
};
extern BSReadWriteLock portalVisibilityLock;

class BSReadLockGuard
{
public:
    explicit BSReadLockGuard(BSReadWriteLock& l) : lock(l) { lock.LockForRead(); }
    ~BSReadLockGuard() { lock.UnlockForRead(); }
private:
    BSReadWriteLock& lock;
};
struct CRC32Calculator
{
    static void SizeOf64(unsigned int& hash, std::uint64_t key);
};
struct VisibilityEntry
{
    NiNode* key;
    BSCompoundFrustum* value;
    VisibilityEntry* next;
};
struct VisibilityMap
{
    unsigned char unknown00[0xc];
    unsigned int capacity;
    unsigned char unknown10[8];
    VisibilityEntry* sentinel;
    unsigned char unknown20[8];
    VisibilityEntry* entries;
};

class BSPortalGraphEntry
{
public:
    BSCompoundFrustum* FindVisibility(NiNode* node) const;
private:
    unsigned char unknown00[0x38];
    VisibilityMap visibilityMap;
};
