// Source exposure: binary-analysis; no external implementation source reused.
// Static17c1280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c1280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c1280*);
    virtual void release(Static17c1280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c1280*);
struct Static17c1280 {
    void* value;
    Static17c1280();
    ~Static17c1280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
