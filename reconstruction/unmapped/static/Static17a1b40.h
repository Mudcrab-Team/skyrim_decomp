// Source exposure: binary-analysis; no external implementation source reused.
// Static17a1b40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a1b40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a1b40*);
    virtual void release(Static17a1b40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a1b40*);
struct Static17a1b40 {
    void* value;
    Static17a1b40();
    ~Static17a1b40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
