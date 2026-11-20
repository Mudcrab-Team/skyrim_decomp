// Source exposure: binary-analysis; no external implementation source reused.
// Static176d860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d860*);
    virtual void release(Static176d860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d860*);
struct Static176d860 {
    void* value;
    Static176d860();
    ~Static176d860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
