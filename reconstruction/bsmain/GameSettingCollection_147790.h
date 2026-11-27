// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// GameSettingCollection, GameSettingCollection::vfunc_2, Setting: CRASHLOGGER_PDB(59818@2026.10.24)
// SettingMapItem, SettingMap, Hash, KeysEqual, Unk_03, ClearValue, Unk_05, DeleteItem, RemoveAt, next, key, value, unk08, buckets, count, unk00, name, settings: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

class Setting
{
public:
    std::uint8_t unk00[0x10];
    const char* name;
};

struct SettingMapItem
{
    SettingMapItem* next;
    const char* key;
    Setting* value;
};

class SettingMap
{
public:
    virtual ~SettingMap();
    virtual std::uint32_t Hash(const char* a_key) const;
    virtual bool KeysEqual(const char* a_lhs, const char* a_rhs) const;
    virtual void Unk_03();
    virtual void ClearValue(SettingMapItem* a_item);
    virtual void Unk_05();
    virtual void DeleteItem(SettingMapItem* a_item);

    void RemoveAt(const char* a_key)
    {
        const std::uint32_t hash = Hash(a_key);
        SettingMapItem* item = buckets[hash];
        if (!item)
        {
            return;
        }

        if (KeysEqual(a_key, item->key))
        {
            buckets[hash] = item->next;
            ClearValue(item);
            DeleteItem(item);
            --count;
            return;
        }

        SettingMapItem* prev = item;
        item = item->next;
        while (item && !KeysEqual(a_key, item->key))
        {
            prev = item;
            item = item->next;
        }

        if (item)
        {
            prev->next = item->next;
            ClearValue(item);
            DeleteItem(item);
            --count;
        }
    }

    std::uint64_t unk08;
    SettingMapItem** buckets;
    std::uint32_t count;
};

class GameSettingCollection
{
public:
    void vfunc_2(Setting* a_setting);

    std::uint8_t unk00[0x118];
    SettingMap settings;
};

static_assert(offsetof(Setting, name) == 0x10, "name offset");
static_assert(offsetof(SettingMap, buckets) == 0x10, "buckets offset");
static_assert(offsetof(SettingMap, count) == 0x18, "count offset");
static_assert(offsetof(GameSettingCollection, settings) == 0x118, "settings offset");
