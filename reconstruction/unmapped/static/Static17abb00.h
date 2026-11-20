// Source exposure: binary-analysis; no external implementation source reused.
// Static17abb00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17abb00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17abb00*);
    virtual void release(Static17abb00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17abb00*);
struct Static17abb00 {
    void* value;
    Static17abb00();
    ~Static17abb00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
