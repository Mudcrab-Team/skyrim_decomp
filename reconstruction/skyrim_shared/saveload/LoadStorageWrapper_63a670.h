// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// LoadStorageWrapper::Read: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveLoadStorageWrappers.cpp:125
// LoadStorageWrapper, BSFile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/L/LoadStorageWrapper.h, include/RE/B/BSMemStorage.h, include/RE/B/BSStorage.h, include/RE/B/BSFile.h, include/RE/N/NiFile.h and include/RE/N/NiBinaryStream.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class NiBinaryStream { public: virtual ~NiBinaryStream(); unsigned absolutePosition, pad; using ReadFn = unsigned(NiBinaryStream*, void*, unsigned, unsigned*, unsigned); ReadFn* readFn; void* writeFn; };
class NiFile : public NiBinaryStream { public: unsigned bufferAllocSize, bufferReadSize, position, pad; char* buffer; void* file; unsigned mode; bool good; };
class BSFile : public NiFile { public: bool useAuxBuffer; unsigned char pad49; unsigned short pad4a; unsigned pad4c; char* auxBuffer; int auxTrueFilePos; unsigned auxBufferMinIndex, auxBufferMaxIndex; char fileName[260]; unsigned result, ioSize, trueFilePos, fileSize; };
class BSStorage { public: virtual ~BSStorage(); unsigned refCount; bool swapBytes, unknown0d; unsigned short unknown0e; void* unknown10; unsigned long long unknown18; };
class BSMemStorage : public BSStorage { public: BSFile* file; unsigned long long startingPosition; };
class LoadStorageWrapper : public BSMemStorage { public: unsigned Read(unsigned long long, unsigned char*) const; };
