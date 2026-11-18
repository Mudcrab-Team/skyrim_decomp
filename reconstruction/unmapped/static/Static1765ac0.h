// Source exposure: binary-analysis; no external implementation source reused.
// Static1765ac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765ac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765ac0*);
    virtual void release(Static1765ac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765ac0*);
struct Static1765ac0 {
    void* value;
    Static1765ac0();
    ~Static1765ac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
