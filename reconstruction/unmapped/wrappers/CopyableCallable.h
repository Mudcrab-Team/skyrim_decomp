// Source exposure: mixed (pinned image RTTI, community boundaries and destructor names).
// CallableBase, CopyableCallable and callback signature type names: EXE_RTTI
// Destructor slot: CRASHLOGGER_PDB(59818@2026.10.24)
// Capture types, virtual prototypes and inferred callable families: GUESS(low) STANDIN
// Code origin: original reconstruction of polymorphic callback construction.
// Adapted bodies: none
#pragma once

namespace bnet { struct LogParams; }

namespace bnet_callable
{
    // The callable base copies the capture before the copyable wrapper finishes construction.
    // Slot 1 is inherited. Base slots 2 and 3 are pure virtual. Their call signatures are unknown.
    template <class Capture>
    class CallableBase
    {
    public:
        explicit CallableBase(const Capture& source) : capture(source) {}
        virtual ~CallableBase();
        virtual void Slot1();
        virtual void Slot2() = 0;
        virtual void Slot3() = 0;

    private:
        Capture capture;
    };

    template <class Capture>
    class CopyableCallable : public CallableBase<Capture>
    {
    public:
        explicit CopyableCallable(const Capture& source) : CallableBase<Capture>(source) {}
        ~CopyableCallable() override;
        void Slot2() override;
        void Slot3() override;
    };

    // The wrappers copy one pointer-sized capture. Distinct types preserve distinct callable identities.
    using LogCallback = void (*)(const bnet::LogParams&);
    struct MessagesClosure127f5b0 { void* state; };
    struct FileChunkClosure12937e0 { void* state; };
    struct FileChunkClosure12938e0 { void* state; };
    struct ReleaseNoteClosure1299290 { void* state; };
    struct SearchCuratedListsResponseClosure129d6d0 { void* state; };
    struct GetCuratedListResponseClosure129d890 { void* state; };
    struct DocumentClosure12a9420 { void* state; };
    struct AuthResultClosure12a96a0 { void* state; };
    struct Closure12a97a0 { void* state; };
    struct AuthResultClosure12a9960 { void* state; };
    struct AuthResultClosure12a9a60 { void* state; };
    struct ExternalAccountInfoResultClosure12a9d10 { void* state; };
    struct AuthResultClosure12a9e10 { void* state; };
    struct DocumentClosure12a9f10 { void* state; };
    struct LinkingResultClosure12aa010 { void* state; };
    struct ListContentResponseClosure12b8be0 { void* state; };
    struct ListContentResponseClosure12c1cc0 { void* state; };
    struct Closure12c71e0 { void* state; };
    struct Closure12c7a60 { void* state; };
    struct ListCategoriesResponseClosure12cd410 { void* state; };
    struct MultipartUploadSessionClosure12d0780 { void* state; };
    struct FixedStringClosure12d0880 { void* state; };
    struct Closure12d0980 { void* state; };
    struct ChunkUploadedResultClosure12d0b40 { void* state; };
    struct FileChunkClosure12eb400 { void* state; };
    struct FileChunkClosure12eb500 { void* state; };
    struct Capture12edf10 { void* state; };
    struct Capture12ee010 { void* state; };
    struct Capture12f82d0 { void* state; };
    struct Capture12f8490 { void* state; };
    struct Capture12f8590 { void* state; };
    struct Capture130bbb0 { void* state; };
    struct Capture130bcb0 { void* state; };
    struct ListContentResponseClosure1332470 { void* state; };
    struct ListContentResponseClosure1332690 { void* state; };
    struct ListCollectionResponseClosure1333070 { void* state; };
    struct ListContentResponseClosure13333b0 { void* state; };
    struct Capture1386340 { void* state; };
    struct Capture138c560 { void* state; };
    struct Capture138c660 { void* state; };
    struct Capture138c760 { void* state; };
    struct Capture138c990 { void* state; };
    struct Capture13a4230 { void* state; };
    struct Capture13a4330 { void* state; };
    struct Capture13a4430 { void* state; };
    struct Capture13a6ed0 { void* state; };
    struct Capture13a7190 { void* state; };
    struct Capture13a7290 { void* state; };
    struct Capture13a7390 { void* state; };
    struct Capture13a7490 { void* state; };
    struct Capture13aee40 { void* state; };
    struct Capture13af930 { void* state; };
    struct Capture13b0320 { void* state; };
    struct Capture13b0fe0 { void* state; };
    struct Capture13b19e0 { void* state; };
    struct Capture13b23f0 { void* state; };
    struct Capture13b31a0 { void* state; };
    struct Capture13b4f00 { void* state; };
    struct Capture13b5000 { void* state; };
    struct Capture13b6220 { void* state; };
    struct Capture13b70d0 { void* state; };
    struct Capture13c5f60 { void* state; };
    struct Capture13c6ad0 { void* state; };
    struct Capture13c76d0 { void* state; };
    struct Capture13c8280 { void* state; };
    struct Capture13c8d20 { void* state; };
    struct Capture13c9810 { void* state; };
    struct Capture13ca340 { void* state; };
    struct Capture13cac90 { void* state; };
    struct Capture1421bf0 { void* state; };
    struct Capture1423450 { void* state; };
    struct Capture1431500 { void* state; };
    struct Capture1431600 { void* state; };
    struct Capture1431700 { void* state; };
    struct Capture1431800 { void* state; };
    struct Capture1431900 { void* state; };
    struct Capture145d200 { void* state; };
    struct Capture145d300 { void* state; };
    struct Capture145d400 { void* state; };
    struct Capture145e5a0 { void* state; };
    struct Capture145e5e0 { void* state; };
    struct Capture145e620 { void* state; };
    struct Capture145e660 { void* state; };
    struct Capture145e6a0 { void* state; };
    struct Capture145e6e0 { void* state; };
    struct Capture145e720 { void* state; };
    struct Capture145e760 { void* state; };
    struct Capture145e7a0 { void* state; };
    struct Capture147f030 { void* state; };
    struct Capture147f0b0 { void* state; };
    struct Capture147f0f0 { void* state; };
    struct Capture147f130 { void* state; };
    struct Capture147f170 { void* state; };
    struct Capture147f1b0 { void* state; };
    struct Capture147f1f0 { void* state; };
    struct Capture147f230 { void* state; };
    struct Capture147f270 { void* state; };
}
