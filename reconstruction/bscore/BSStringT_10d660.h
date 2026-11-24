// Source exposure: mixed (sibling game-code names and body; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSCore/BSString.h:234
// BSStringT, DynamicMemoryManagementPol, Set, QString, Init, pString, sLen, sMaxLen: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; declarations
#pragma once

template <class T, int N>
class DynamicMemoryManagementPol
{
};

template <class T, int N, template <class, int> class Pol>
class BSStringT : public Pol<T, N>
{
public:
    BSStringT(const BSStringT& aString);
    bool Set(const BSStringT& aString);
    bool Set(const T* apString, unsigned long long aiMaxLen = 0);
    const T* QString() const;
    void Init();

    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
};

template <class T, int N, template <class, int> class Pol>
inline BSStringT<T, N, Pol>::BSStringT(const BSStringT& aString)
{
    Init();
    Set(aString);
}

template <class T, int N, template <class, int> class Pol>
inline bool BSStringT<T, N, Pol>::Set(const BSStringT& aString)
{
    return Set(aString.QString(), 0);
}

template <class T, int N, template <class, int> class Pol>
inline const T* BSStringT<T, N, Pol>::QString() const
{
    return pString ? pString : "";
}

template <class T, int N, template <class, int> class Pol>
inline void BSStringT<T, N, Pol>::Init()
{
    pString = 0;
    sLen = 0;
    sMaxLen = 0;
}
