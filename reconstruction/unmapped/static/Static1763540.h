// Source exposure: binary-analysis; no external implementation source reused.
// Static1763540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763540*);
    virtual void release(Static1763540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763540*);
struct Static1763540 {
    void* value;
    Static1763540();
    ~Static1763540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
