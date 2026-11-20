// Source exposure: binary-analysis; no external implementation source reused.
// Static176ceb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ceb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ceb0*);
    virtual void release(Static176ceb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ceb0*);
struct Static176ceb0 {
    void* value;
    Static176ceb0();
    ~Static176ceb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
