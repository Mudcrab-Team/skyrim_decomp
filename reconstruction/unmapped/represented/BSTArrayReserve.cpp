// Source exposure: mixed (pinned image and community allocator declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original capacity guard and allocator model. Adapted bodies: none.
// BSTArrayAllocatorFunctor, BSTArrayHeapAllocator, BSScrapArrayAllocator: EXE_RTTI
// IAllocatorFunctor and its virtual interface: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReserveAdditional, SetCapacity, BSTArrayReserve, element types and field names: GUESS(low) STANDIN
// CI hash: 0x1eb900 ?ReserveAdditional@?$BSTArrayReserve@UElement_1eb900@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x1eb950 ?ReserveAdditional@?$BSTArrayReserve@UElement_1eb950@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x1eb9a0 ?ReserveAdditional@?$BSTArrayReserve@UElement_1eb9a0@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x1eb9f0 ?ReserveAdditional@?$BSTArrayReserve@UElement_1eb9f0@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x205970 ?ReserveAdditional@?$BSTArrayReserve@UElement_205970@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x20a550 ?ReserveAdditional@?$BSTArrayReserve@UElement_20a550@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x264cf0 ?ReserveAdditional@?$BSTArrayReserve@UElement_264cf0@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x3ba1d0 ?ReserveAdditional@?$BSTArrayReserve@UElement_3ba1d0@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x3ea5f0 ?ReserveAdditional@?$BSTArrayReserve@UElement_3ea5f0@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x48caf0 ?ReserveAdditional@?$BSTArrayReserve@UElement_48caf0@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x4beb30 ?ReserveAdditional@?$BSTArrayReserve@UElement_4beb30@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x4beb80 ?ReserveAdditional@?$BSTArrayReserve@UElement_4beb80@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x4d1800 ?ReserveAdditional@?$BSTArrayReserve@UElement_4d1800@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x4e5260 ?ReserveAdditional@?$BSTArrayReserve@UElement_4e5260@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x4e52b0 ?ReserveAdditional@?$BSTArrayReserve@UElement_4e52b0@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x4e88f0 ?ReserveAdditional@?$BSTArrayReserve@UElement_4e88f0@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x4e8940 ?ReserveAdditional@?$BSTArrayReserve@UElement_4e8940@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x4eb400 ?ReserveAdditional@?$BSTArrayReserve@UElement_4eb400@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x4eb450 ?ReserveAdditional@?$BSTArrayReserve@UElement_4eb450@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x4efca0 ?ReserveAdditional@?$BSTArrayReserve@UElement_4efca0@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x53c770 ?ReserveAdditional@?$BSTArrayReserve@UElement_53c770@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x543f00 ?ReserveAdditional@?$BSTArrayReserve@UElement_543f00@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x1079740 ?ReserveAdditional@?$BSTArrayReserve@UElement_1079740@array_reserve@@UBSTArrayHeapAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x11c15a0 ?ReserveAdditional@?$BSTArrayReserve@UElement_11c15a0@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x11c8b70 ?ReserveAdditional@?$BSTArrayReserve@UElement_11c8b70@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x11c8bc0 ?ReserveAdditional@?$BSTArrayReserve@UElement_11c8bc0@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x1200140 ?ReserveAdditional@?$BSTArrayReserve@UElement_1200140@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x123cb60 ?ReserveAdditional@?$BSTArrayReserve@UElement_123cb60@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x123cbb0 ?ReserveAdditional@?$BSTArrayReserve@UElement_123cbb0@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x14a1120 ?ReserveAdditional@?$BSTArrayReserve@UElement_14a1120@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x1593b10 ?ReserveAdditional@?$BSTArrayReserve@UElement_1593b10@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// CI hash: 0x1593b60 ?ReserveAdditional@?$BSTArrayReserve@UElement_1593b60@array_reserve@@UBSScrapArrayAllocator@2@@array_reserve@@QEAAXI@Z
// 0x1eb900 BSTArrayReserve<Element_1eb900, BSScrapArrayAllocator>::ReserveAdditional
// 0x1eb950 BSTArrayReserve<Element_1eb950, BSTArrayHeapAllocator>::ReserveAdditional
// 0x1eb9a0 BSTArrayReserve<Element_1eb9a0, BSScrapArrayAllocator>::ReserveAdditional
// 0x1eb9f0 BSTArrayReserve<Element_1eb9f0, BSTArrayHeapAllocator>::ReserveAdditional
// 0x205970 BSTArrayReserve<Element_205970, BSTArrayHeapAllocator>::ReserveAdditional
// 0x20a550 BSTArrayReserve<Element_20a550, BSTArrayHeapAllocator>::ReserveAdditional
// 0x264cf0 BSTArrayReserve<Element_264cf0, BSTArrayHeapAllocator>::ReserveAdditional
// 0x3ba1d0 BSTArrayReserve<Element_3ba1d0, BSScrapArrayAllocator>::ReserveAdditional
// 0x3ea5f0 BSTArrayReserve<Element_3ea5f0, BSScrapArrayAllocator>::ReserveAdditional
// 0x48caf0 BSTArrayReserve<Element_48caf0, BSTArrayHeapAllocator>::ReserveAdditional
// 0x4beb30 BSTArrayReserve<Element_4beb30, BSTArrayHeapAllocator>::ReserveAdditional
// 0x4beb80 BSTArrayReserve<Element_4beb80, BSTArrayHeapAllocator>::ReserveAdditional
// 0x4d1800 BSTArrayReserve<Element_4d1800, BSScrapArrayAllocator>::ReserveAdditional
// 0x4e5260 BSTArrayReserve<Element_4e5260, BSTArrayHeapAllocator>::ReserveAdditional
// 0x4e52b0 BSTArrayReserve<Element_4e52b0, BSTArrayHeapAllocator>::ReserveAdditional
// 0x4e88f0 BSTArrayReserve<Element_4e88f0, BSScrapArrayAllocator>::ReserveAdditional
// 0x4e8940 BSTArrayReserve<Element_4e8940, BSScrapArrayAllocator>::ReserveAdditional
// 0x4eb400 BSTArrayReserve<Element_4eb400, BSTArrayHeapAllocator>::ReserveAdditional
// 0x4eb450 BSTArrayReserve<Element_4eb450, BSTArrayHeapAllocator>::ReserveAdditional
// 0x4efca0 BSTArrayReserve<Element_4efca0, BSTArrayHeapAllocator>::ReserveAdditional
// 0x53c770 BSTArrayReserve<Element_53c770, BSTArrayHeapAllocator>::ReserveAdditional
// 0x543f00 BSTArrayReserve<Element_543f00, BSScrapArrayAllocator>::ReserveAdditional
// 0x1079740 BSTArrayReserve<Element_1079740, BSTArrayHeapAllocator>::ReserveAdditional
// 0x11c15a0 BSTArrayReserve<Element_11c15a0, BSScrapArrayAllocator>::ReserveAdditional
// 0x11c8b70 BSTArrayReserve<Element_11c8b70, BSScrapArrayAllocator>::ReserveAdditional
// 0x11c8bc0 BSTArrayReserve<Element_11c8bc0, BSScrapArrayAllocator>::ReserveAdditional
// 0x1200140 BSTArrayReserve<Element_1200140, BSScrapArrayAllocator>::ReserveAdditional
// 0x123cb60 BSTArrayReserve<Element_123cb60, BSScrapArrayAllocator>::ReserveAdditional
// 0x123cbb0 BSTArrayReserve<Element_123cbb0, BSScrapArrayAllocator>::ReserveAdditional
// 0x14a1120 BSTArrayReserve<Element_14a1120, BSScrapArrayAllocator>::ReserveAdditional
// 0x1593b10 BSTArrayReserve<Element_1593b10, BSScrapArrayAllocator>::ReserveAdditional
// 0x1593b60 BSTArrayReserve<Element_1593b60, BSScrapArrayAllocator>::ReserveAdditional
#include "BSTArrayReserve.h"

namespace array_reserve
{
    template <class Element, class Storage>
    void BSTArrayReserve<Element, Storage>::ReserveAdditional(unsigned count)
    {
        const unsigned used = size;
        const unsigned capacity = this->capacity;
        const unsigned needed = used + count;
        if (needed > capacity) {
            BSTArrayAllocatorFunctor<Storage> allocator(*this);
            SetCapacity(allocator, capacity, needed, sizeof(Element));
        }
    }

    struct Element_1eb900 { unsigned char storage[4]; };
    template struct BSTArrayReserve<Element_1eb900, BSScrapArrayAllocator>;

    struct Element_1eb950 { unsigned char storage[4]; };
    template struct BSTArrayReserve<Element_1eb950, BSTArrayHeapAllocator>;

    struct Element_1eb9a0 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_1eb9a0, BSScrapArrayAllocator>;

    struct Element_1eb9f0 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_1eb9f0, BSTArrayHeapAllocator>;

    struct Element_205970 { unsigned char storage[4]; };
    template struct BSTArrayReserve<Element_205970, BSTArrayHeapAllocator>;

    struct Element_20a550 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_20a550, BSTArrayHeapAllocator>;

    struct Element_264cf0 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_264cf0, BSTArrayHeapAllocator>;

    struct Element_3ba1d0 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_3ba1d0, BSScrapArrayAllocator>;

    struct Element_3ea5f0 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_3ea5f0, BSScrapArrayAllocator>;

    struct Element_48caf0 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_48caf0, BSTArrayHeapAllocator>;

    struct Element_4beb30 { unsigned char storage[12]; };
    template struct BSTArrayReserve<Element_4beb30, BSTArrayHeapAllocator>;

    struct Element_4beb80 { unsigned char storage[12]; };
    template struct BSTArrayReserve<Element_4beb80, BSTArrayHeapAllocator>;

    struct Element_4d1800 { unsigned char storage[32]; };
    template struct BSTArrayReserve<Element_4d1800, BSScrapArrayAllocator>;

    struct Element_4e5260 { unsigned char storage[24]; };
    template struct BSTArrayReserve<Element_4e5260, BSTArrayHeapAllocator>;

    struct Element_4e52b0 { unsigned char storage[24]; };
    template struct BSTArrayReserve<Element_4e52b0, BSTArrayHeapAllocator>;

    struct Element_4e88f0 { unsigned char storage[24]; };
    template struct BSTArrayReserve<Element_4e88f0, BSScrapArrayAllocator>;

    struct Element_4e8940 { unsigned char storage[32]; };
    template struct BSTArrayReserve<Element_4e8940, BSScrapArrayAllocator>;

    struct Element_4eb400 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_4eb400, BSTArrayHeapAllocator>;

    struct Element_4eb450 { unsigned char storage[32]; };
    template struct BSTArrayReserve<Element_4eb450, BSTArrayHeapAllocator>;

    struct Element_4efca0 { unsigned char storage[24]; };
    template struct BSTArrayReserve<Element_4efca0, BSTArrayHeapAllocator>;

    struct Element_53c770 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_53c770, BSTArrayHeapAllocator>;

    struct Element_543f00 { unsigned char storage[12]; };
    template struct BSTArrayReserve<Element_543f00, BSScrapArrayAllocator>;

    struct Element_1079740 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_1079740, BSTArrayHeapAllocator>;

    struct Element_11c15a0 { unsigned char storage[40]; };
    template struct BSTArrayReserve<Element_11c15a0, BSScrapArrayAllocator>;

    struct Element_11c8b70 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_11c8b70, BSScrapArrayAllocator>;

    struct Element_11c8bc0 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_11c8bc0, BSScrapArrayAllocator>;

    struct Element_1200140 { unsigned char storage[16]; };
    template struct BSTArrayReserve<Element_1200140, BSScrapArrayAllocator>;

    struct Element_123cb60 { unsigned char storage[96]; };
    template struct BSTArrayReserve<Element_123cb60, BSScrapArrayAllocator>;

    struct Element_123cbb0 { unsigned char storage[16]; };
    template struct BSTArrayReserve<Element_123cbb0, BSScrapArrayAllocator>;

    struct Element_14a1120 { unsigned char storage[8]; };
    template struct BSTArrayReserve<Element_14a1120, BSScrapArrayAllocator>;

    struct Element_1593b10 { unsigned char storage[2]; };
    template struct BSTArrayReserve<Element_1593b10, BSScrapArrayAllocator>;

    struct Element_1593b60 { unsigned char storage[12]; };
    template struct BSTArrayReserve<Element_1593b60, BSScrapArrayAllocator>;
}
