// Source exposure: binary-analysis; no external implementation source reused.
// Static1793730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1793730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1793730*);
    virtual void release(Static1793730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1793730*);
struct Static1793730 {
    void* value;
    Static1793730();
    ~Static1793730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
