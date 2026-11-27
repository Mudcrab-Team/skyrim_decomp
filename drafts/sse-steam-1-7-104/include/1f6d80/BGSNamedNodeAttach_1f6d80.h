// Build: sse-steam-1-7-104; 0x1f6d80, 42 bytes.
// Exposure detail: (local binary analysis and permitted sibling source).
// Source exposure: mixed
// Code origin: adapted from fo4-private@1b765c70 src/Shared/Misc/BGSAttachTechniques.cpp:306; author-permission.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSAttachTechniques.cpp:306; body and policy naming lead only.
// BGSNamedNodeAttach, BGSNamedNodeAttach::AttachPolicy, BGSNamedNodeAttach::ActionPolicy: EXE_RTTI
// BGSNamedNodeAttach::Attach, BGSNamedNodeAttach::Process: SIBLING(fo4-private@1b765c70, author-permission)
// BSAttachTechniques, BSAttachTechniques::AttachTechniqueInput, RefAttachTechniqueInput: EXE_RTTI
// Return type is inferred as void; the sibling bool signature remains an alternative.
// Correspondence to the sibling method is inferred from local vtable ownership and policy use.
// 0x1f6d80 BGSNamedNodeAttach::Attach
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSAttachTechniques.cpp:300

#pragma once

namespace BSAttachTechniques { class AttachTechniqueInput; }
class RefAttachTechniqueInput;

class BGSNamedNodeAttach {
public:
    virtual ~BGSNamedNodeAttach();
    class ActionPolicy {
    public:
        virtual ~ActionPolicy() {}
        virtual bool Process(RefAttachTechniqueInput&) = 0;
    };
    class AttachPolicy : public ActionPolicy {
    public:
        bool Process(RefAttachTechniqueInput&) override;
    };

    void Process(const BSAttachTechniques::AttachTechniqueInput& input, ActionPolicy& policy)
    {
        policy.Process(reinterpret_cast<RefAttachTechniqueInput&>(
            const_cast<BSAttachTechniques::AttachTechniqueInput&>(input)));
    }

    // 0x1f6d80 BGSNamedNodeAttach::Attach
    virtual void Attach(const BSAttachTechniques::AttachTechniqueInput& input);
};
