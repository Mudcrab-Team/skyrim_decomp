// Source exposure: binary-analysis; no external implementation source reused.
// Static176efd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176efd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176efd0*);
    virtual void release(Static176efd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176efd0*);
struct Static176efd0 {
    void* value;
    Static176efd0();
    ~Static176efd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
