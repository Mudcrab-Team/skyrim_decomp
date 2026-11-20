// Source exposure: binary-analysis; no external implementation source reused.
// Static1758140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758140*);
    virtual void release(Static1758140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758140*);
struct Static1758140 {
    void* value;
    Static1758140();
    ~Static1758140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
