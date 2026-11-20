// Source exposure: binary-analysis; no external implementation source reused.
// Static1753910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753910*);
    virtual void release(Static1753910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753910*);
struct Static1753910 {
    void* value;
    Static1753910();
    ~Static1753910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
