// Source exposure: binary-analysis; no external implementation source reused.
// Static17a5ae0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a5ae0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a5ae0*);
    virtual void release(Static17a5ae0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a5ae0*);
struct Static17a5ae0 {
    void* value;
    Static17a5ae0();
    ~Static17a5ae0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
