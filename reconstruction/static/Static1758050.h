// Source exposure: binary-analysis; no external implementation source reused.
// Static1758050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758050*);
    virtual void release(Static1758050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758050*);
struct Static1758050 {
    void* value;
    Static1758050();
    ~Static1758050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
