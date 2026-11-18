// Source exposure: binary-analysis; no external implementation source reused.
// Static1769940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769940*);
    virtual void release(Static1769940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769940*);
struct Static1769940 {
    void* value;
    Static1769940();
    ~Static1769940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
