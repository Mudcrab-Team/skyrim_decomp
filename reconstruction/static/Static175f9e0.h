// Source exposure: binary-analysis; no external implementation source reused.
// Static175f9e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f9e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f9e0*);
    virtual void release(Static175f9e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f9e0*);
struct Static175f9e0 {
    void* value;
    Static175f9e0();
    ~Static175f9e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
