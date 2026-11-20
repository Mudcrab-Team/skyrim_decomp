// Source exposure: binary-analysis; no external implementation source reused.
// Static17aca10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aca10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aca10*);
    virtual void release(Static17aca10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aca10*);
struct Static17aca10 {
    void* value;
    Static17aca10();
    ~Static17aca10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
