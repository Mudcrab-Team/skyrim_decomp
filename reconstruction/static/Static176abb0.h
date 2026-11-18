// Source exposure: binary-analysis; no external implementation source reused.
// Static176abb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176abb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176abb0*);
    virtual void release(Static176abb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176abb0*);
struct Static176abb0 {
    void* value;
    Static176abb0();
    ~Static176abb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
