// Source exposure: binary-analysis; no external implementation source reused.
// Static175e720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e720*);
    virtual void release(Static175e720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e720*);
struct Static175e720 {
    void* value;
    Static175e720();
    ~Static175e720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
