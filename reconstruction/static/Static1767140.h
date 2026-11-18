// Source exposure: binary-analysis; no external implementation source reused.
// Static1767140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767140*);
    virtual void release(Static1767140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767140*);
struct Static1767140 {
    void* value;
    Static1767140();
    ~Static1767140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
