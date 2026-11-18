// Source exposure: binary-analysis; no external implementation source reused.
// Static1767960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767960*);
    virtual void release(Static1767960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767960*);
struct Static1767960 {
    void* value;
    Static1767960();
    ~Static1767960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
