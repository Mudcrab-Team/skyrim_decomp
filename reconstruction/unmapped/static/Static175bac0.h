// Source exposure: binary-analysis; no external implementation source reused.
// Static175bac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bac0*);
    virtual void release(Static175bac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bac0*);
struct Static175bac0 {
    void* value;
    Static175bac0();
    ~Static175bac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
