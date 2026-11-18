// Source exposure: binary-analysis; no external implementation source reused.
// Static174cce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174cce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174cce0*);
    virtual void release(Static174cce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174cce0*);
struct Static174cce0 {
    void* value;
    Static174cce0();
    ~Static174cce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
