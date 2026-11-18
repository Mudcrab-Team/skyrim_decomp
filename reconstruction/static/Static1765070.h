// Source exposure: binary-analysis; no external implementation source reused.
// Static1765070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765070*);
    virtual void release(Static1765070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765070*);
struct Static1765070 {
    void* value;
    Static1765070();
    ~Static1765070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
