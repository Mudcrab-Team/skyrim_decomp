// Source exposure: binary-analysis; no external implementation source reused.
// Static1771910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771910*);
    virtual void release(Static1771910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771910*);
struct Static1771910 {
    void* value;
    Static1771910();
    ~Static1771910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
