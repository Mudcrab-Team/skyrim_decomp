// Source exposure: binary-analysis; no external implementation source reused.
// Static17a1100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a1100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a1100*);
    virtual void release(Static17a1100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a1100*);
struct Static17a1100 {
    void* value;
    Static17a1100();
    ~Static17a1100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
