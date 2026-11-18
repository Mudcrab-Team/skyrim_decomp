// Source exposure: binary-analysis; no external implementation source reused.
// Static1780910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780910*);
    virtual void release(Static1780910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780910*);
struct Static1780910 {
    void* value;
    Static1780910();
    ~Static1780910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
