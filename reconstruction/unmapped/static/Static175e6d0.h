// Source exposure: binary-analysis; no external implementation source reused.
// Static175e6d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e6d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e6d0*);
    virtual void release(Static175e6d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e6d0*);
struct Static175e6d0 {
    void* value;
    Static175e6d0();
    ~Static175e6d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
