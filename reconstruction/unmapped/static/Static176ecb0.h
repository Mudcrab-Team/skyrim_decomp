// Source exposure: binary-analysis; no external implementation source reused.
// Static176ecb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ecb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ecb0*);
    virtual void release(Static176ecb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ecb0*);
struct Static176ecb0 {
    void* value;
    Static176ecb0();
    ~Static176ecb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
