// Source exposure: binary-analysis; no external implementation source reused.
// Static174fae0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fae0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fae0*);
    virtual void release(Static174fae0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fae0*);
struct Static174fae0 {
    void* value;
    Static174fae0();
    ~Static174fae0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
