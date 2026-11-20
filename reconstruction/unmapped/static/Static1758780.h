// Source exposure: binary-analysis; no external implementation source reused.
// Static1758780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758780*);
    virtual void release(Static1758780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758780*);
struct Static1758780 {
    void* value;
    Static1758780();
    ~Static1758780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
