// Source exposure: binary-analysis; no external implementation source reused.
// Static175d7d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d7d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d7d0*);
    virtual void release(Static175d7d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d7d0*);
struct Static175d7d0 {
    void* value;
    Static175d7d0();
    ~Static175d7d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
