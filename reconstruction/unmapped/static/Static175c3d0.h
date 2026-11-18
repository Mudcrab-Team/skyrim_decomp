// Source exposure: binary-analysis; no external implementation source reused.
// Static175c3d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c3d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c3d0*);
    virtual void release(Static175c3d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c3d0*);
struct Static175c3d0 {
    void* value;
    Static175c3d0();
    ~Static175c3d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
