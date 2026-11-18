// Source exposure: binary-analysis; no external implementation source reused.
// Static176caf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176caf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176caf0*);
    virtual void release(Static176caf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176caf0*);
struct Static176caf0 {
    void* value;
    Static176caf0();
    ~Static176caf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
