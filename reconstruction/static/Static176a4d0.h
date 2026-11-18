// Source exposure: binary-analysis; no external implementation source reused.
// Static176a4d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a4d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a4d0*);
    virtual void release(Static176a4d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a4d0*);
struct Static176a4d0 {
    void* value;
    Static176a4d0();
    ~Static176a4d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
