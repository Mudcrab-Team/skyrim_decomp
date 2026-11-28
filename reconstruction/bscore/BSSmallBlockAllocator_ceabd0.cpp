// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xceabd0 BSSmallBlockAllocator::PopUnusedBlockPages
#include "BSSmallBlockAllocator_ceabd0.h"

// Unlinks trailing completely free mega-blocks and optionally decommits their pages.
void BSSmallBlockAllocator::PopUnusedBlockPages()
{
    char* commit = blockPageCommit;
    if (commit <= blockPageCommitMin)
    {
        return;
    }

    MegaBlockPage* page = reinterpret_cast<MegaBlockPage*>(commit) - 1;
    do
    {
        if (page->numFreeBlockPages != 255)
        {
            break;
        }

        MegaBlockPage* right = page->right;
        if (page == megaBlockCurrAlloc)
        {
            megaBlockCurrAlloc = nullptr;
        }
        if (right == page)
        {
            megaBlockPageList = nullptr;
        }
        else
        {
            if (page == megaBlockPageList)
            {
                megaBlockPageList = right;
            }
            right->left = page->left;
            page->left->right = right;
        }

        totalFreeBlockPages -= 255;
        commit = reinterpret_cast<char*>(page);
        --page;
    } while (commit > blockPageCommitMin);

    if (allowDecommits)
    {
        std::size_t bytesToFree = static_cast<std::size_t>(blockPageCommit - commit);
        if (bytesToFree >= sizeof(MegaBlockPage))
        {
            VirtualFree(commit, bytesToFree, 0x4000);
            blockPageCommit = commit;
        }
    }
}
