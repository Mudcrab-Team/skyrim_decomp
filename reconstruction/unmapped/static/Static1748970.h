// Source exposure: binary-analysis; no external implementation source reused.
// Static1748970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748970*);
    virtual void release(Static1748970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748970*);
struct Static1748970 {
    void* value;
    Static1748970();
    ~Static1748970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
