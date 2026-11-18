// Source exposure: binary-analysis; no external implementation source reused.
// Static17a7b20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a7b20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a7b20*);
    virtual void release(Static17a7b20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a7b20*);
struct Static17a7b20 {
    void* value;
    Static17a7b20();
    ~Static17a7b20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
