// Source exposure: binary-analysis; no external implementation source reused.
// Static17aae30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aae30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aae30*);
    virtual void release(Static17aae30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aae30*);
struct Static17aae30 {
    void* value;
    Static17aae30();
    ~Static17aae30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
