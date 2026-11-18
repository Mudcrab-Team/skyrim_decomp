/*
 * Projectile: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x7fc410 29 bytes.
 * Origin: body adapted from Projectile::IsPermanent in CharmedBaryon/CommonLibSSE-NG include/RE/P/Projectile.h at b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
 * Source exposure: mixed (binary analysis and public declarations).
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Owner is unverified; only the observed TESForm-compatible prefix is represented.
 * Prefix declarations adapted from CharmedBaryon/CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT); see header notice.
 */
// Projectile: STANDIN EXE_RTTI
// TESFileContainer, TESFileArray, array, sourceFiles, formFlags, formID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESDataHandler, IsTemporaryFormID: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Function7fc410, singleton, Projectile::~Projectile: GUESS(low)
#include "Projectile_7fc410.h"

bool Projectile::Function7fc410() const { return !TESDataHandler::singleton->IsTemporaryFormID(formID); }

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
