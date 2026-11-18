// Source exposure: binary-analysis; no external implementation source reused.
// Static1751ac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751ac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751ac0*);
    virtual void release(Static1751ac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751ac0*);
struct Static1751ac0 {
    void* value;
    Static1751ac0();
    ~Static1751ac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
