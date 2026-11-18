// Source exposure: binary-analysis; no external implementation source reused.
// Static1796970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796970*);
    virtual void release(Static1796970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796970*);
struct Static1796970 {
    void* value;
    Static1796970();
    ~Static1796970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
