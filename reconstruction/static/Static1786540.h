// Source exposure: binary-analysis; no external implementation source reused.
// Static1786540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786540*);
    virtual void release(Static1786540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786540*);
struct Static1786540 {
    void* value;
    Static1786540();
    ~Static1786540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
