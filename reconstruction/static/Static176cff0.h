// Source exposure: binary-analysis; no external implementation source reused.
// Static176cff0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cff0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cff0*);
    virtual void release(Static176cff0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cff0*);
struct Static176cff0 {
    void* value;
    Static176cff0();
    ~Static176cff0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
