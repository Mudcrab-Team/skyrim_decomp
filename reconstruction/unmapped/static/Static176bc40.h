// Source exposure: binary-analysis; no external implementation source reused.
// Static176bc40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bc40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bc40*);
    virtual void release(Static176bc40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bc40*);
struct Static176bc40 {
    void* value;
    Static176bc40();
    ~Static176bc40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
