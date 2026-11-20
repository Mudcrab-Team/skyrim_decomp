// Source exposure: binary-analysis; no external implementation source reused.
// Static1780410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780410*);
    virtual void release(Static1780410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780410*);
struct Static1780410 {
    void* value;
    Static1780410();
    ~Static1780410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
