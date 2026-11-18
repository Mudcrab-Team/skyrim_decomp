// Source exposure: binary-analysis; no external implementation source reused.
// Static17a9870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a9870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a9870*);
    virtual void release(Static17a9870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a9870*);
struct Static17a9870 {
    void* value;
    Static17a9870();
    ~Static17a9870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
