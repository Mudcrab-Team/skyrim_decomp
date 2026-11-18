// Source exposure: binary-analysis; no external implementation source reused.
// Static176b6f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b6f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b6f0*);
    virtual void release(Static176b6f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b6f0*);
struct Static176b6f0 {
    void* value;
    Static176b6f0();
    ~Static176b6f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
