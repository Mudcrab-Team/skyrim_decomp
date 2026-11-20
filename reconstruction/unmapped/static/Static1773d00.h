// Source exposure: binary-analysis; no external implementation source reused.
// Static1773d00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773d00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773d00*);
    virtual void release(Static1773d00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773d00*);
struct Static1773d00 {
    void* value;
    Static1773d00();
    ~Static1773d00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
