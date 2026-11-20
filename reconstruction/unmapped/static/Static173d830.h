// Source exposure: binary-analysis; no external implementation source reused.
// Static173d830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d830*);
    virtual void release(Static173d830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d830*);
struct Static173d830 {
    void* value;
    Static173d830();
    ~Static173d830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
