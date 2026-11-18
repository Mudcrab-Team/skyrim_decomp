// Source exposure: binary-analysis; no external implementation source reused.
// Static1771960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771960*);
    virtual void release(Static1771960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771960*);
struct Static1771960 {
    void* value;
    Static1771960();
    ~Static1771960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
