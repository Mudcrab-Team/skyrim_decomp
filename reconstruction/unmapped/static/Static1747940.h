// Source exposure: binary-analysis; no external implementation source reused.
// Static1747940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747940*);
    virtual void release(Static1747940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747940*);
struct Static1747940 {
    void* value;
    Static1747940();
    ~Static1747940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
