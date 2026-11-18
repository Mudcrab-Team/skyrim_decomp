// Source exposure: binary-analysis; no external implementation source reused.
// Static1770970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770970*);
    virtual void release(Static1770970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770970*);
struct Static1770970 {
    void* value;
    Static1770970();
    ~Static1770970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
