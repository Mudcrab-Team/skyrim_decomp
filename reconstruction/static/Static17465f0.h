// Source exposure: binary-analysis; no external implementation source reused.
// Static17465f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17465f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17465f0*);
    virtual void release(Static17465f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17465f0*);
struct Static17465f0 {
    void* value;
    Static17465f0();
    ~Static17465f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
