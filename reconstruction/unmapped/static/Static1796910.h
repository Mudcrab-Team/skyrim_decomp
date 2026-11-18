// Source exposure: binary-analysis; no external implementation source reused.
// Static1796910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796910*);
    virtual void release(Static1796910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796910*);
struct Static1796910 {
    void* value;
    Static1796910();
    ~Static1796910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
