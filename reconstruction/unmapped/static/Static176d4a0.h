// Source exposure: binary-analysis; no external implementation source reused.
// Static176d4a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d4a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d4a0*);
    virtual void release(Static176d4a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d4a0*);
struct Static176d4a0 {
    void* value;
    Static176d4a0();
    ~Static176d4a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
