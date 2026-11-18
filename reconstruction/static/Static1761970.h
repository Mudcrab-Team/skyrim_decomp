// Source exposure: binary-analysis; no external implementation source reused.
// Static1761970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761970*);
    virtual void release(Static1761970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761970*);
struct Static1761970 {
    void* value;
    Static1761970();
    ~Static1761970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
