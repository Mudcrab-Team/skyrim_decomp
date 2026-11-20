// Source exposure: binary-analysis; no external implementation source reused.
// Static17a3b40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a3b40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a3b40*);
    virtual void release(Static17a3b40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a3b40*);
struct Static17a3b40 {
    void* value;
    Static17a3b40();
    ~Static17a3b40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
