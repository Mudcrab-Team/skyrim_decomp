// Source exposure: binary-analysis; no external implementation source reused.
// Static174fbd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fbd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fbd0*);
    virtual void release(Static174fbd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fbd0*);
struct Static174fbd0 {
    void* value;
    Static174fbd0();
    ~Static174fbd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
