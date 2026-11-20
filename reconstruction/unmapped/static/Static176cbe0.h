// Source exposure: binary-analysis; no external implementation source reused.
// Static176cbe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cbe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cbe0*);
    virtual void release(Static176cbe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cbe0*);
struct Static176cbe0 {
    void* value;
    Static176cbe0();
    ~Static176cbe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
