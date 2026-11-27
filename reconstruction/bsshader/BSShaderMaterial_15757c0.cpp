// Source exposure: mixed (pinned image and community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original checksum reconstruction from the local listing. Adapted bodies: none.
// BSShaderMaterial, ComputeCRC32, texCoordOffset, texCoordScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ChecksumFields, seed, zero, CRC32Bytes_ce2510: GUESS(low) STANDIN
// CI hash: 0x15757c0 ?ComputeCRC32@BSShaderMaterial@@UEAAII@Z
// 0x15757c0 BSShaderMaterial::ComputeCRC32
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
#include "BSShaderMaterial_15757c0.h"

// The seed is an observed input beyond the receiver; the no-argument community prototype is insufficient.
unsigned int BSShaderMaterial::ComputeCRC32(unsigned int seed)
{
    struct ChecksumFields
    {
        float offsetX;
        float offsetY;
        float scaleX;
        float scaleY;
        unsigned int seed;
        unsigned int zero;
    } fields{texCoordOffset[0].x, texCoordOffset[0].y, texCoordScale[0].x, texCoordScale[0].y, seed, 0};
    unsigned int result;
    CRC32Bytes_ce2510(&result, &fields, sizeof(fields));
    return result;
}
