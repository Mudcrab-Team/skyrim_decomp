// Source exposure: binary-analysis; no external implementation source reused.
// Static1752970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752970*);
    virtual void release(Static1752970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752970*);
struct Static1752970 {
    void* value;
    Static1752970();
    ~Static1752970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
