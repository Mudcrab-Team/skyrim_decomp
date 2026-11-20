// Source exposure: binary-analysis; no external implementation source reused.
// Static17aade0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aade0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aade0*);
    virtual void release(Static17aade0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aade0*);
struct Static17aade0 {
    void* value;
    Static17aade0();
    ~Static17aade0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
