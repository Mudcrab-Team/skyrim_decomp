// Source exposure: binary-analysis; no external implementation source reused.
// Static173f3c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f3c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f3c0*);
    virtual void release(Static173f3c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f3c0*);
struct Static173f3c0 {
    void* value;
    Static173f3c0();
    ~Static173f3c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
