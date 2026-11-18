// Source exposure: binary-analysis; no external implementation source reused.
// Static1747340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747340*);
    virtual void release(Static1747340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747340*);
struct Static1747340 {
    void* value;
    Static1747340();
    ~Static1747340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
