// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: names, bases and member offsets from CharmedBaryon/CommonLibSSE-NG (MIT); list clearing adapted from the sibling
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/BSCore/BSSimpleList.h:49
// SettingCollection, SettingCollection::~SettingCollection, SettingCollection::subKey, SettingCollection::handle, SettingCollectionList, SettingCollectionList::~SettingCollectionList, SettingCollectionList::settings: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSSimpleList, Setting: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the list is modelled with the sibling's member names
// BSSimpleList::m_item, BSSimpleList::m_pkNext, BSSimpleList::RemoveAll, BSSimpleList::~BSSimpleList: SIBLING(fo4-private@1b765c70, author-permission)
#pragma once

#include <cstddef>

class Setting;

template <class T>
class BSSimpleList
{
public:
    ~BSSimpleList();
    void RemoveAll(void (*a_delete)(BSSimpleList*, void*), void* a_data);

    T m_item;                 // 00
    BSSimpleList* m_pkNext;   // 08
};

template <class T>
inline void BSSimpleList<T>::RemoveAll(void (*a_delete)(BSSimpleList*, void*), void* a_data)
{
    while (m_pkNext) {
        BSSimpleList* next = m_pkNext->m_pkNext;
        m_pkNext->m_pkNext = nullptr;
        if (a_delete) {
            a_delete(m_pkNext, a_data);
        } else {
            delete m_pkNext;
        }
        m_pkNext = next;
    }
    m_item = T();
}

template <class T>
class SettingCollection
{
public:
    virtual ~SettingCollection() {}  // 00
    virtual void InsertSetting(T* a_setting) = 0;  // 01
    virtual void RemoveSetting(T* a_setting) = 0;  // 02
    virtual bool WriteSetting(T* a_setting) = 0;   // 03
    virtual bool ReadSetting(T* a_setting) = 0;    // 04
    virtual bool OpenHandle(bool a_create);        // 05
    virtual bool CloseHandle();                    // 06
    virtual void Unk_07();                         // 07
    virtual void WriteAllSettings();               // 08
    virtual void ReadAllSettings();                // 09

    char subKey[0x104];  // 08
    void* handle;        // 110
};

template <class T>
class SettingCollectionList : public SettingCollection<T>
{
public:
    ~SettingCollectionList() override;  // 00, compared: 0x19afb0

    BSSimpleList<T*> settings;  // 118
};
static_assert(sizeof(SettingCollectionList<Setting>) == 0x128, "SettingCollectionList size");
