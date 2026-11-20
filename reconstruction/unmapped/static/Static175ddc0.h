// Source exposure: binary-analysis; no external implementation source reused.
// Static175ddc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ddc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ddc0*);
    virtual void release(Static175ddc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ddc0*);
struct Static175ddc0 {
    void* value;
    Static175ddc0();
    ~Static175ddc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
