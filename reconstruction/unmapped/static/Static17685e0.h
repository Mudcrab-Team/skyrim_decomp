// Source exposure: binary-analysis; no external implementation source reused.
// Static17685e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17685e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17685e0*);
    virtual void release(Static17685e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17685e0*);
struct Static17685e0 {
    void* value;
    Static17685e0();
    ~Static17685e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
