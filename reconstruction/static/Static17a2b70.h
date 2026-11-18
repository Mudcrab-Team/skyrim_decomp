// Source exposure: binary-analysis; no external implementation source reused.
// Static17a2b70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a2b70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a2b70*);
    virtual void release(Static17a2b70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a2b70*);
struct Static17a2b70 {
    void* value;
    Static17a2b70();
    ~Static17a2b70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
