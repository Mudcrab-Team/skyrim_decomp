// Source exposure: binary-analysis; no external implementation source reused.
// Static176aa70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176aa70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176aa70*);
    virtual void release(Static176aa70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176aa70*);
struct Static176aa70 {
    void* value;
    Static176aa70();
    ~Static176aa70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
