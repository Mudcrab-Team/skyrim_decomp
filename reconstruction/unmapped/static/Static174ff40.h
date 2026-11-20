// Source exposure: binary-analysis; no external implementation source reused.
// Static174ff40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ff40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ff40*);
    virtual void release(Static174ff40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ff40*);
struct Static174ff40 {
    void* value;
    Static174ff40();
    ~Static174ff40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
