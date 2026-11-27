// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// INISettingCollection, INISettingCollection::WriteAllSettings, Setting: CRASHLOGGER_PDB(59818@2026.10.24)
// SettingNode, INISettingCollection::subKey, INISettingCollection::handle, INISettingCollection::settings, INISettingCollection::WriteSetting: GUESS
#pragma once

#include <cstdint>

struct Setting;

struct SettingNode
{
    Setting* item;
    SettingNode* next;
};

class INISettingCollection
{
  public:
    virtual ~INISettingCollection();
    virtual void InsertSetting(Setting* a_setting);
    virtual void RemoveSetting(Setting* a_setting);
    virtual bool WriteSetting(Setting* a_setting);
    virtual bool ReadSetting(Setting* a_setting);
    virtual bool OpenHandle(bool a_create);
    virtual bool CloseHandle();
    virtual void Unk_07();
    virtual bool WriteAllSettings();
    virtual bool ReadAllSettings();

    char subKey[0x104];
    void* handle;
    SettingNode settings;
};

static_assert(sizeof(INISettingCollection) == 0x128, "INISettingCollection size");
