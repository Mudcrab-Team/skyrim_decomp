// Source exposure: binary-analysis; no external implementation source reused.
// Static175e0e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e0e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e0e0*);
    virtual void release(Static175e0e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e0e0*);
struct Static175e0e0 {
    void* value;
    Static175e0e0();
    ~Static175e0e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
