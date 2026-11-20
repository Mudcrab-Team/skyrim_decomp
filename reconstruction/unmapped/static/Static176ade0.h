// Source exposure: binary-analysis; no external implementation source reused.
// Static176ade0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ade0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ade0*);
    virtual void release(Static176ade0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ade0*);
struct Static176ade0 {
    void* value;
    Static176ade0();
    ~Static176ade0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
