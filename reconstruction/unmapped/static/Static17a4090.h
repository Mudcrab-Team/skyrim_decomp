// Source exposure: binary-analysis; no external implementation source reused.
// Static17a4090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a4090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a4090*);
    virtual void release(Static17a4090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a4090*);
struct Static17a4090 {
    void* value;
    Static17a4090();
    ~Static17a4090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
