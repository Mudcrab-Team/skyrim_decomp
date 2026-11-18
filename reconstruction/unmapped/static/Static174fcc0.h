// Source exposure: binary-analysis; no external implementation source reused.
// Static174fcc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fcc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fcc0*);
    virtual void release(Static174fcc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fcc0*);
struct Static174fcc0 {
    void* value;
    Static174fcc0();
    ~Static174fcc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
