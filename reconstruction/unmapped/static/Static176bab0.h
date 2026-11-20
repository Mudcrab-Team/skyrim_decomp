// Source exposure: binary-analysis; no external implementation source reused.
// Static176bab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bab0*);
    virtual void release(Static176bab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bab0*);
struct Static176bab0 {
    void* value;
    Static176bab0();
    ~Static176bab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
