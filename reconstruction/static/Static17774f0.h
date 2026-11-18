// Source exposure: binary-analysis; no external implementation source reused.
// Static17774f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17774f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17774f0*);
    virtual void release(Static17774f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17774f0*);
struct Static17774f0 {
    void* value;
    Static17774f0();
    ~Static17774f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
