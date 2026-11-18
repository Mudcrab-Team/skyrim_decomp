// Source exposure: binary-analysis; no external implementation source reused.
// Static176bdd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bdd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bdd0*);
    virtual void release(Static176bdd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bdd0*);
struct Static176bdd0 {
    void* value;
    Static176bdd0();
    ~Static176bdd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
