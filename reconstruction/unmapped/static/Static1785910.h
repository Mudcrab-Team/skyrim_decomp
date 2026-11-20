// Source exposure: binary-analysis; no external implementation source reused.
// Static1785910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785910*);
    virtual void release(Static1785910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785910*);
struct Static1785910 {
    void* value;
    Static1785910();
    ~Static1785910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
