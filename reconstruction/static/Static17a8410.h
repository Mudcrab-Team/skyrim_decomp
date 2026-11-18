// Source exposure: binary-analysis; no external implementation source reused.
// Static17a8410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a8410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a8410*);
    virtual void release(Static17a8410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a8410*);
struct Static17a8410 {
    void* value;
    Static17a8410();
    ~Static17a8410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
