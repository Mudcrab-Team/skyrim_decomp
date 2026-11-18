// Source exposure: binary-analysis; no external implementation source reused.
// Static175daa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175daa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175daa0*);
    virtual void release(Static175daa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175daa0*);
struct Static175daa0 {
    void* value;
    Static175daa0();
    ~Static175daa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
