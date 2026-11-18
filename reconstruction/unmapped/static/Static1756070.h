// Source exposure: binary-analysis; no external implementation source reused.
// Static1756070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756070*);
    virtual void release(Static1756070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756070*);
struct Static1756070 {
    void* value;
    Static1756070();
    ~Static1756070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
