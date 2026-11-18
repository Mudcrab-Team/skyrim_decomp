// Source exposure: binary-analysis; no external implementation source reused.
// Static1774ac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774ac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774ac0*);
    virtual void release(Static1774ac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774ac0*);
struct Static1774ac0 {
    void* value;
    Static1774ac0();
    ~Static1774ac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
