// Source exposure: binary-analysis; no external implementation source reused.
// Static176e300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e300*);
    virtual void release(Static176e300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e300*);
struct Static176e300 {
    void* value;
    Static176e300();
    ~Static176e300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
