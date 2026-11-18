// Source exposure: binary-analysis; no external implementation source reused.
// Static176a8e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a8e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a8e0*);
    virtual void release(Static176a8e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a8e0*);
struct Static176a8e0 {
    void* value;
    Static176a8e0();
    ~Static176a8e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
