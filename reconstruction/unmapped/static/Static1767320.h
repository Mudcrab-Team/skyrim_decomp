// Source exposure: binary-analysis; no external implementation source reused.
// Static1767320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767320*);
    virtual void release(Static1767320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767320*);
struct Static1767320 {
    void* value;
    Static1767320();
    ~Static1767320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
