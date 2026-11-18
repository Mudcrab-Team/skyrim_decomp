// Source exposure: binary-analysis; no external implementation source reused.
// Static176d9f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d9f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d9f0*);
    virtual void release(Static176d9f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d9f0*);
struct Static176d9f0 {
    void* value;
    Static176d9f0();
    ~Static176d9f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
