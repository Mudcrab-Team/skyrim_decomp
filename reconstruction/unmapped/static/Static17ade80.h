// Source exposure: binary-analysis; no external implementation source reused.
// Static17ade80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ade80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ade80*);
    virtual void release(Static17ade80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ade80*);
struct Static17ade80 {
    void* value;
    Static17ade80();
    ~Static17ade80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
