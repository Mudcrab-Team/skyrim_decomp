// Source exposure: binary-analysis; no external implementation source reused.
// Static176dae0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176dae0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176dae0*);
    virtual void release(Static176dae0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176dae0*);
struct Static176dae0 {
    void* value;
    Static176dae0();
    ~Static176dae0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
