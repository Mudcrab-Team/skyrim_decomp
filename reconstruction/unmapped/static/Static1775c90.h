// Source exposure: binary-analysis; no external implementation source reused.
// Static1775c90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775c90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775c90*);
    virtual void release(Static1775c90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775c90*);
struct Static1775c90 {
    void* value;
    Static1775c90();
    ~Static1775c90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
