// Source exposure: binary-analysis; no external implementation source reused.
// Static17abca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17abca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17abca0*);
    virtual void release(Static17abca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17abca0*);
struct Static17abca0 {
    void* value;
    Static17abca0();
    ~Static17abca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
