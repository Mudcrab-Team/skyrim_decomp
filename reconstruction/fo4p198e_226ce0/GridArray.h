// Source exposure: mixed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// GridArray::SetCenter: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GridArray.cpp:46
// GridArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/G/GridArray.h.
// names: GUESS(low); local and member names are inferred.
/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#pragma once
#include <cstdint>
class GridArray { public: virtual ~GridArray(); virtual void DetachAll(); virtual void KillAll(); virtual bool SetCenter(std::int32_t x, std::int32_t y); virtual void Shift(std::int32_t x, std::int32_t y); virtual void Detach(std::uint32_t x, std::uint32_t y) = 0; virtual void ClearItem(std::uint32_t x, std::uint32_t y) = 0; virtual void MoveItem(std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t) = 0; virtual void SwapItem(std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t) = 0; std::int32_t centerX; std::int32_t centerY; std::uint32_t length; std::uint32_t pad14; };
