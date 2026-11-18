// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad250*);
    virtual void release(Static17ad250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad250*);
struct Static17ad250 {
    void* value;
    Static17ad250();
    ~Static17ad250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
