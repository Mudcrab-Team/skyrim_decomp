// Source exposure: binary-analysis; no external implementation source reused.
// Static1751070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751070*);
    virtual void release(Static1751070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751070*);
struct Static1751070 {
    void* value;
    Static1751070();
    ~Static1751070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
