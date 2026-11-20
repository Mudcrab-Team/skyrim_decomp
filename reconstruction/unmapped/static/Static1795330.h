// Source exposure: binary-analysis; no external implementation source reused.
// Static1795330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795330*);
    virtual void release(Static1795330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795330*);
struct Static1795330 {
    void* value;
    Static1795330();
    ~Static1795330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
