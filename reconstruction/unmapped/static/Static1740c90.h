// Source exposure: binary-analysis; no external implementation source reused.
// Static1740c90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740c90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740c90*);
    virtual void release(Static1740c90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740c90*);
struct Static1740c90 {
    void* value;
    Static1740c90();
    ~Static1740c90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
