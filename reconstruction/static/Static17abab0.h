// Source exposure: binary-analysis; no external implementation source reused.
// Static17abab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17abab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17abab0*);
    virtual void release(Static17abab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17abab0*);
struct Static17abab0 {
    void* value;
    Static17abab0();
    ~Static17abab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
