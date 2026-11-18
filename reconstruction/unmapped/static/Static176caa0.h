// Source exposure: binary-analysis; no external implementation source reused.
// Static176caa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176caa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176caa0*);
    virtual void release(Static176caa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176caa0*);
struct Static176caa0 {
    void* value;
    Static176caa0();
    ~Static176caa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
