// Source exposure: mixed
// Origin: authorized sibling and public declarations
// GPL-3.0: declarations adapted from powerof3/CommonLibSSE at 654e55f7979c1733033d5dbef176e43827bac944, include/RE/C/CombatBehaviorThread.h, CombatBehaviorStack.h, CombatBehaviorTreeNode.h and include/RE/B/BSTArray.h.
// CombatBehaviorThread, CombatBehaviorStack, CombatBehaviorTreeNode: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0); declarations adapted
// names: GUESS(low); method signatures and auxiliary names remain provisional
// CombatBehaviorTreeRootNode::Enter: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:165
// CombatBehaviorTreeRootNode::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:216
#pragma once
#include <cstdint>
class CombatBehaviorTreeNode;
struct CombatBehaviorStack {
    char* buffer;
    std::uint32_t bufferSize;
    std::uint32_t size;
    struct ObjectPtr { const CombatBehaviorStack* stack; std::uint32_t pos; };
};
struct StackFrame { const CombatBehaviorTreeNode* node; std::uint32_t position; };
struct SmallStackFrames {
    std::uint32_t capacity : 31;
    std::uint32_t local : 1;
    union { void* heap; StackFrame entries[16]; } data;
    std::uint32_t size;
};
class CombatBehaviorThread {
public:
    CombatBehaviorStack stack;
    SmallStackFrames stackFrame;
    std::uint32_t stackPos;
    CombatBehaviorStack::ObjectPtr currentContext;
    const CombatBehaviorTreeNode* currentNode;
    const CombatBehaviorTreeNode* previousNode;
    std::int32_t status;
    std::int32_t state;
    void Ascend();
    void Push(const CombatBehaviorTreeNode* const* node);
    void Descend(unsigned int index);
};
class BSFixedString { const char* data; };
class CombatBehaviorTreeNode {
public:
    virtual ~CombatBehaviorTreeNode();
    virtual const BSFixedString& GetName();
    virtual void Enter(CombatBehaviorThread*);
    virtual void Exit(CombatBehaviorThread*);
    virtual void Update(CombatBehaviorThread*);
    virtual void Abort(CombatBehaviorThread*);
    virtual void SaveGame(CombatBehaviorThread*, void*);
    virtual void LoadGame(CombatBehaviorThread*, void*);
    virtual bool Validate(const CombatBehaviorTreeNode*);
    virtual const BSFixedString& GetType() = 0;
    BSFixedString name;
    CombatBehaviorTreeNode* parent;
    CombatBehaviorTreeNode** children;
    std::uint32_t childCount;
};
class CombatBehaviorTreeRootNode : public CombatBehaviorTreeNode {
public:
    void Enter(CombatBehaviorThread*) override;
    void LoadGame(CombatBehaviorThread*, void*) override;
};
