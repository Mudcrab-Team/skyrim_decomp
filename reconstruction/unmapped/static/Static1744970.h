// Source exposure: binary-analysis; no external implementation source reused.
// Static1744970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744970*);
    virtual void release(Static1744970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744970*);
struct Static1744970 {
    void* value;
    Static1744970();
    ~Static1744970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
