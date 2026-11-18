// Source exposure: binary-analysis; no external implementation source reused.
// Static175efe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175efe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175efe0*);
    virtual void release(Static175efe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175efe0*);
struct Static175efe0 {
    void* value;
    Static175efe0();
    ~Static175efe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
