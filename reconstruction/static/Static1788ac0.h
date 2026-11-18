// Source exposure: binary-analysis; no external implementation source reused.
// Static1788ac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788ac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788ac0*);
    virtual void release(Static1788ac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788ac0*);
struct Static1788ac0 {
    void* value;
    Static1788ac0();
    ~Static1788ac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
