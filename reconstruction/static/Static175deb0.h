// Source exposure: binary-analysis; no external implementation source reused.
// Static175deb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175deb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175deb0*);
    virtual void release(Static175deb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175deb0*);
struct Static175deb0 {
    void* value;
    Static175deb0();
    ~Static175deb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
