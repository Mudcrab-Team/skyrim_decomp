// Source exposure: binary-analysis; no external implementation source reused.
// Static174bca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bca0*);
    virtual void release(Static174bca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bca0*);
struct Static174bca0 {
    void* value;
    Static174bca0();
    ~Static174bca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
