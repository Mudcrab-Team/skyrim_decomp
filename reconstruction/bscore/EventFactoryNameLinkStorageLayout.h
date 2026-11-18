// Source exposure: mixed (original target-binary storage evidence and authorized game-code sibling role hints).
// Code origin: original data declarations recovered from target constructors/import contracts and vtable-bound field accesses; no external implementation body reused.
// ConcreteEventCallbackFactory, IEventCallbackFactory: EXE_RTTI
// ConcreteEventCallbackFactory: SIBLING(fo4-private@1b765c70, author-permission)
// EventFactoryNameLinkStorageLayout, name, next: GUESS(medium) STANDIN
#pragma once
#include <cstddef>
namespace ResearchLayouts {
class EventFactoryNameLinkStorageLayout {
public:
    virtual ~EventFactoryNameLinkStorageLayout();
    char name[80];
    EventFactoryNameLinkStorageLayout* next;
};
static_assert(sizeof(EventFactoryNameLinkStorageLayout)==96,"represented text/link prefix");
static_assert(offsetof(EventFactoryNameLinkStorageLayout,name)==8,"target bounded-copy destination");
static_assert(sizeof(EventFactoryNameLinkStorageLayout::name)==80,"target strncpy_s capacity");
static_assert(offsetof(EventFactoryNameLinkStorageLayout,next)==88,"target initialized and linked object pointer");
}
