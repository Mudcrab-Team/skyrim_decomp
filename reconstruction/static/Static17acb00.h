// Source exposure: binary-analysis; no external implementation source reused.
// Static17acb00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17acb00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17acb00*);
    virtual void release(Static17acb00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17acb00*);
struct Static17acb00 {
    void* value;
    Static17acb00();
    ~Static17acb00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
