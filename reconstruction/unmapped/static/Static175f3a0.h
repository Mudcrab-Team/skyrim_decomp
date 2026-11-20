// Source exposure: binary-analysis; no external implementation source reused.
// Static175f3a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f3a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f3a0*);
    virtual void release(Static175f3a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f3a0*);
struct Static175f3a0 {
    void* value;
    Static175f3a0();
    ~Static175f3a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
