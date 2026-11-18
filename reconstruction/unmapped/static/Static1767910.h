// Source exposure: binary-analysis; no external implementation source reused.
// Static1767910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767910*);
    virtual void release(Static1767910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767910*);
struct Static1767910 {
    void* value;
    Static1767910();
    ~Static1767910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
