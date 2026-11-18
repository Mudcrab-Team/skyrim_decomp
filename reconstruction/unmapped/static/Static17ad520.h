// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad520*);
    virtual void release(Static17ad520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad520*);
struct Static17ad520 {
    void* value;
    Static17ad520();
    ~Static17ad520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
