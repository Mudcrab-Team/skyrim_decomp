// Source exposure: binary-analysis; no external implementation source reused.
// Static1758730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758730*);
    virtual void release(Static1758730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758730*);
struct Static1758730 {
    void* value;
    Static1758730();
    ~Static1758730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
