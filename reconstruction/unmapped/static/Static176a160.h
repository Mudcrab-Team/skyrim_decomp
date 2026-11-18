// Source exposure: binary-analysis; no external implementation source reused.
// Static176a160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a160*);
    virtual void release(Static176a160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a160*);
struct Static176a160 {
    void* value;
    Static176a160();
    ~Static176a160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
