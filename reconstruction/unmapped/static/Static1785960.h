// Source exposure: binary-analysis; no external implementation source reused.
// Static1785960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785960*);
    virtual void release(Static1785960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785960*);
struct Static1785960 {
    void* value;
    Static1785960();
    ~Static1785960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
