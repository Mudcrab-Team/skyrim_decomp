// Source exposure: binary-analysis; no external implementation source reused.
// Static1771320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771320*);
    virtual void release(Static1771320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771320*);
struct Static1771320 {
    void* value;
    Static1771320();
    ~Static1771320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
