// Source exposure: binary-analysis; no external implementation source reused.
// Static1748320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748320*);
    virtual void release(Static1748320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748320*);
struct Static1748320 {
    void* value;
    Static1748320();
    ~Static1748320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
