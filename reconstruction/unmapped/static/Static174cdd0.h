// Source exposure: binary-analysis; no external implementation source reused.
// Static174cdd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174cdd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174cdd0*);
    virtual void release(Static174cdd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174cdd0*);
struct Static174cdd0 {
    void* value;
    Static174cdd0();
    ~Static174cdd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
