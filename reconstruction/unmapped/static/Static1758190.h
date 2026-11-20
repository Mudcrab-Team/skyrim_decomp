// Source exposure: binary-analysis; no external implementation source reused.
// Static1758190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758190*);
    virtual void release(Static1758190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758190*);
struct Static1758190 {
    void* value;
    Static1758190();
    ~Static1758190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
