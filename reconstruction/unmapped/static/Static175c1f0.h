// Source exposure: binary-analysis; no external implementation source reused.
// Static175c1f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c1f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c1f0*);
    virtual void release(Static175c1f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c1f0*);
struct Static175c1f0 {
    void* value;
    Static175c1f0();
    ~Static175c1f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
