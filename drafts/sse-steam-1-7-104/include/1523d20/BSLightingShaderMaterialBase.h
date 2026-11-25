// BSLightingShaderMaterialBase type declarations, build sse-steam-1-7-104.
//
// Exposure detail: (binary-analysis of the pinned image, community-headers).
// Source exposure: mixed
// Lock and Unlock names follow powerof3/CommonLibSSE@654e55f (GPL-3.0); no code is copied.
// Class, member and method names follow CharmedBaryon/CommonLibSSE-NG
// b93280e832f263dbef44e44cbe2936622a02f91a (MIT): include/RE/B/BSLightingShaderMaterialBase.h,
// BSShaderMaterial: EXE_RTTI STANDIN; other stand-ins include BSTextureSet and NiSourceTexture,
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once

#include <cstdint>

#include <intrin.h>

// NiRefObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject::DeleteThis, ::IncRefCount, ::DecRefCount, ::_refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiRefObject
{
public:
	virtual ~NiRefObject();  // 00
	virtual void DeleteThis();  // 01

	void IncRefCount()
	{
		// atomic: references are shared across loader threads
		_InterlockedIncrement(reinterpret_cast<volatile long*>(&_refCount));
	}

	void DecRefCount()
	{
		// atomic: the last releaser deletes the object
		if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&_refCount), -1) == 1) {
			DeleteThis();
		}
	}

	volatile std::uint32_t _refCount;  // 08
	std::uint32_t          _pad0C;     // 0C
};

// NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the base is needed
class NiSourceTexture : public NiRefObject
{
};

// NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPointer::reset, ::get: GUESS(low); smart-pointer helpers, not named in NG's NiPointer
// _ptr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG declares it protected in a different shape
// operator=: attach the new reference, store, then release the old one, as the image does
template <class T>
class NiPointer
{
public:
	NiPointer& operator=(const NiPointer& a_rhs)
	{
		T* old = _ptr;
		T* incoming = a_rhs._ptr;
		if (old != incoming) {
			if (incoming) {
				incoming->IncRefCount();
			}
			_ptr = incoming;
			if (old) {
				old->DecRefCount();
			}
		}
		return *this;
	}

	void reset(T* a_ptr)
	{
		T* old = _ptr;
		if (old != a_ptr) {
			if (a_ptr) {
				a_ptr->IncRefCount();
			}
			_ptr = a_ptr;
			if (old) {
				old->DecRefCount();
			}
		}
	}

	void reset()
	{
		T* old = _ptr;
		if (old) {
			_ptr = nullptr;
			old->DecRefCount();
		}
	}

	T* get() const { return _ptr; }
	explicit operator bool() const { return _ptr != nullptr; }
	T* operator->() const { return _ptr; }

	T* _ptr;  // 00
};

// BSTextureSet: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTextureSet::Texture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_NN: GUESS; placeholders for slots 02 to 25 before slot 26 at offset 0x130.
// SetTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares
// (Texture, NiSourceTexture*) but the image passes the address of the texture pointer member.
class BSTextureSet : public NiRefObject
{
public:
	enum Texture : std::uint32_t
	{
		kDiffuse = 0,
		kNormal,
		kEnvironmentMask,
		kGlowMap,
		kHeight,
		kEnvironment,
		kMultilayer,
		kBacklightMask,
	};

	virtual void Unk_02();  // 02
	virtual void Unk_03();  // 03
	virtual void Unk_04();  // 04
	virtual void Unk_05();  // 05
	virtual void Unk_06();  // 06
	virtual void Unk_07();  // 07
	virtual void Unk_08();  // 08
	virtual void Unk_09();  // 09
	virtual void Unk_0A();  // 0A
	virtual void Unk_0B();  // 0B
	virtual void Unk_0C();  // 0C
	virtual void Unk_0D();  // 0D
	virtual void Unk_0E();  // 0E
	virtual void Unk_0F();  // 0F
	virtual void Unk_10();  // 10
	virtual void Unk_11();  // 11
	virtual void Unk_12();  // 12
	virtual void Unk_13();  // 13
	virtual void Unk_14();  // 14
	virtual void Unk_15();  // 15
	virtual void Unk_16();  // 16
	virtual void Unk_17();  // 17
	virtual void Unk_18();  // 18
	virtual void Unk_19();  // 19
	virtual void Unk_1A();  // 1A
	virtual void Unk_1B();  // 1B
	virtual void Unk_1C();  // 1C
	virtual void Unk_1D();  // 1D
	virtual void Unk_1E();  // 1E
	virtual void Unk_1F();  // 1F
	virtual void Unk_20();  // 20
	virtual void Unk_21();  // 21
	virtual void Unk_22();  // 22
	virtual void Unk_23();  // 23
	virtual void Unk_24();  // 24
	virtual void Unk_25();  // 25
	virtual void SetTexture(Texture a_texture, NiPointer<NiSourceTexture>& a_srcTexture);  // 26
};

// NiColor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiColor::SaveBinary2, NiColor::LoadBinary2: GUESS(low); the image calls helpers taking
// (NiColor*, NiStream*) at 0xef2fd0 and 0xef2f10 whose names no community source gives
class NiStream;
class NiColor
{
public:
	void SaveBinary2(NiStream& a_stream) const;
	void LoadBinary2(NiStream& a_stream);

	float red;    // 0
	float green;  // 4
	float blue;   // 8
};

// NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBinaryStream::read, ::write, ::binary_read, ::binary_write, ::_absoluteCurrentPos, ::_readFn,
// ::_writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiBinaryStream
{
public:
	using ReadFn = std::uint32_t(NiBinaryStream* a_this, void* a_buffer, std::uint32_t a_bytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);
	using WriteFn = std::uint32_t(NiBinaryStream* a_this, const void* a_buffer, std::uint32_t a_bytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

	template <class CharT>
	bool read(CharT* a_str, std::uint32_t a_count)
	{
		std::uint32_t size = sizeof(CharT);
		std::uint32_t toRead = a_count * size;
		std::uint32_t bytesRead = binary_read(a_str, toRead, &size);
		return bytesRead == toRead;
	}

	template <class CharT>
	bool write(const CharT* a_str, std::uint32_t a_count)
	{
		std::uint32_t size = sizeof(CharT);
		std::uint32_t toWrite = a_count * size;
		std::uint32_t bytesWritten = binary_write(a_str, toWrite, &size);
		return bytesWritten == toWrite;
	}

	std::uint32_t binary_read(void* a_buffer, std::uint32_t a_totalBytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents = 1)
	{
		std::uint32_t bytesRead = _readFn(this, a_buffer, a_totalBytes, a_componentSizes, a_numComponents);
		_absoluteCurrentPos += bytesRead;
		return bytesRead;
	}

	std::uint32_t binary_write(const void* a_buffer, std::uint32_t a_totalBytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents = 1)
	{
		std::uint32_t bytesWritten = _writeFn(this, a_buffer, a_totalBytes, a_componentSizes, a_numComponents);
		_absoluteCurrentPos += bytesWritten;
		return bytesWritten;
	}

	virtual ~NiBinaryStream();      // 00
	virtual bool good() const = 0;  // 01
	virtual void seek(std::int32_t a_numBytes) = 0;  // 02
	virtual std::uint32_t tell() const;  // 03
	virtual void get_info();  // 04
	virtual void set_endian_swap(bool a_doSwap) = 0;  // 05

	std::uint32_t _absoluteCurrentPos;  // 08
	std::uint32_t _pad0C;               // 0C
	ReadFn*       _readFn;              // 10
	WriteFn*      _writeFn;             // 18
};

// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream::iStr, ::oStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08: GUESS(low); members before the two stream pointers, sized so they land at 0x298 and 0x2A0
class NiStream
{
public:
	virtual ~NiStream();  // 00

	std::uint8_t    unk08[0x290];  // 08
	NiBinaryStream* iStr;          // 298
	NiBinaryStream* oStr;          // 2A0
};

// Sleep: OBSERVED STANDIN; Win32 import, bound to the image's import slot
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long a_milliseconds);

// BSNonReentrantSpinLock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSNonReentrantSpinLock::Lock, ::Unlock: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); names only, bodies are written from the image behaviour (spin with Sleep(0), store zero then fence)
struct BSNonReentrantSpinLock
{
	void Lock()
	{
		// atomic: the lock word is shared with loader threads
		while (_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&lock), 1, 0) != 0) {
			Sleep(0);
		}
		// fence: later reads must see what the previous owner published
		_mm_mfence();
	}

	void Unlock()
	{
		lock = 0;
		// fence: publish the texture pointers before the lock is released
		_mm_mfence();
	}

	volatile std::uint32_t lock;  // 0
};

// BSShaderMaterial: STANDIN EXE_RTTI; class name and base from the image RTTI, 8 primary vftable slots
// BSShaderMaterial::Feature, BSShaderMaterial::Type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// sizeof BSShaderMaterial 0x38: OBSERVED; size argument of operator delete in the deleting destructor (slot 0)
// refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); member declared as refCount in the source header
// unk0C: GUESS(low); members not recovered yet, sized so the static_assert holds
class BSShaderMaterial
{
public:
	enum class Feature
	{
		kDefault = 0,
	};

	enum class Type
	{
		kBase = 0,
		kEffect = 1,
		kLighting = 2,
		kWater = 3
	};

	virtual ~BSShaderMaterial();  // 00
	virtual BSShaderMaterial* Create();  // 01
	virtual void CopyMembers(BSShaderMaterial* a_other);  // 02
	virtual bool DoIsCopy(BSShaderMaterial* a_other);  // 03
	virtual std::uint32_t ComputeCRC32();  // 04
	virtual BSShaderMaterial* GetDefault();  // 05
	virtual Feature GetFeature() const;  // 06
	virtual Type GetType() const;  // 07

	volatile std::uint32_t refCount;  // 08
	std::uint8_t           unk0C[0x2C];  // 0C
};
static_assert(sizeof(BSShaderMaterial) == 0x38, "layout");

// Globals: GUESS(low); inferred names for the image reads a default material pointer and two default texture
// pointers from fixed .data addresses (0x33d4db0, 0x3336448, 0x3336428). Bound by hint to those RVAs.
extern BSShaderMaterial* g_defaultLightingMaterial;
extern NiPointer<NiSourceTexture> g_defaultTexture;
extern NiPointer<NiSourceTexture> g_defaultBackLightingTexture;

// BSLightingShaderMaterialBase: EXE_RTTI; class name and base from the image RTTI, 14 primary vftable slots
// sizeof BSLightingShaderMaterialBase 0xA0: OBSERVED; size argument of operator delete in the deleting destructor (slot 0)
// Member names are those of NG at the same offsets, checked against the image offsets
// lock98: GUESS(low); NG calls the 8 bytes at 0x98 unk98, the image uses a spin lock word at 0x98
class BSLightingShaderMaterialBase : public BSShaderMaterial
{
public:
	~BSLightingShaderMaterialBase() override;  // 00
	BSShaderMaterial* Create() override;  // 01
	void CopyMembers(BSShaderMaterial* a_other) override;  // 02
	bool DoIsCopy(BSShaderMaterial* a_other) override;  // 03
	std::uint32_t ComputeCRC32() override;  // 04
	BSShaderMaterial* GetDefault() override;  // 05
	Feature GetFeature() const override;  // 06
	Type GetType() const override;  // 07
	virtual void OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet);  // 08
	virtual void ClearTextures();  // 09
	virtual void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN);  // 0A
	virtual void GetTextures();  // 0B
	virtual void SaveBinary(NiStream& a_stream);  // 0C
	virtual void LoadBinary(NiStream& a_stream);  // 0D

	NiColor                    specularColor;                   // 38
	std::uint32_t              pad44;                           // 44
	NiPointer<NiSourceTexture> diffuseTexture;                  // 48
	std::int32_t               diffuseRenderTargetSourceIndex;  // 50
	std::uint32_t              pad54;                           // 54
	NiPointer<NiSourceTexture> normalTexture;                   // 58
	NiPointer<NiSourceTexture> rimSoftLightingTexture;          // 60
	NiPointer<NiSourceTexture> specularBackLightingTexture;     // 68
	std::int32_t               textureClampMode;                // 70
	std::int32_t               pad74;                           // 74
	NiPointer<BSTextureSet>    textureSet;                      // 78
	float                      materialAlpha;                   // 80
	float                      refractionPower;                 // 84
	float                      specularPower;                   // 88
	float                      specularColorScale;              // 8C
	float                      subSurfaceLightRolloff;          // 90
	float                      rimLightPower;                   // 94
	BSNonReentrantSpinLock     lock98;                          // 98
	std::uint32_t              pad9C;                           // 9C
};
static_assert(sizeof(BSLightingShaderMaterialBase) == 0xA0, "layout");
