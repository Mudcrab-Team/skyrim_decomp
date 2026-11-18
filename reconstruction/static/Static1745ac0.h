// Source exposure: binary-analysis; no external implementation source reused.
// Static1745ac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1745ac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1745ac0*);
    virtual void release(Static1745ac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1745ac0*);
struct Static1745ac0 {
    void* value;
    Static1745ac0();
    ~Static1745ac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
