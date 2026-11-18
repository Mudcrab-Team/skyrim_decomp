// Source exposure: binary-analysis; no external implementation source reused.
// Static1785320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785320*);
    virtual void release(Static1785320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785320*);
struct Static1785320 {
    void* value;
    Static1785320();
    ~Static1785320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
