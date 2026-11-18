// Source exposure: binary-analysis; no external implementation source reused.
// Static1778940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778940*);
    virtual void release(Static1778940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778940*);
struct Static1778940 {
    void* value;
    Static1778940();
    ~Static1778940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
