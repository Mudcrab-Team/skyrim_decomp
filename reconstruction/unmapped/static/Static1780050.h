// Source exposure: binary-analysis; no external implementation source reused.
// Static1780050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780050*);
    virtual void release(Static1780050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780050*);
struct Static1780050 {
    void* value;
    Static1780050();
    ~Static1780050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
