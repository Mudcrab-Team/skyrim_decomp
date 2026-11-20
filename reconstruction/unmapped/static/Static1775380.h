// Source exposure: binary-analysis; no external implementation source reused.
// Static1775380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775380*);
    virtual void release(Static1775380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775380*);
struct Static1775380 {
    void* value;
    Static1775380();
    ~Static1775380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
