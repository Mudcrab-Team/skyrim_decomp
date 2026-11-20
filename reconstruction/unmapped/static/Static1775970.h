// Source exposure: binary-analysis; no external implementation source reused.
// Static1775970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775970*);
    virtual void release(Static1775970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775970*);
struct Static1775970 {
    void* value;
    Static1775970();
    ~Static1775970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
