// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xceafb0 BSSmallBlockAllocator::PushFreeBlockPage
#include "BSSmallBlockAllocator_ceafb0.h"

// Returns a block page to its mega-block free list and promotes newly available mega-blocks.
// The CrashLogger name is sub_140C0D4F0; the name used here is a guess from what the body does.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void BSSmallBlockAllocator::PushFreeBlockPage(BlockPageInternal* page, MegaBlockPage* megaPage)
{
    page->right = megaPage->freeBlockPages;
    ++megaPage->numFreeBlockPages;
    megaPage->freeBlockPages = page;
    page->check = 0xFEED;

    if (megaPage->numFreeBlockPages == 1)
    {
        MegaBlockPage* right = megaPage->right;
        if (right != megaPage && megaPage != megaBlockPageList)
        {
            right->left = megaPage->left;
            megaPage->left->right = right;

            megaPage->right = megaBlockPageList;
            megaPage->left = megaBlockPageList->left;
            megaBlockPageList->left->right = megaPage;
            megaBlockPageList->left = megaPage;
            megaBlockPageList = megaPage;
        }
        if (!megaBlockCurrAlloc)
        {
            megaBlockCurrAlloc = megaPage;
        }
    }
    ++totalFreeBlockPages;
}
