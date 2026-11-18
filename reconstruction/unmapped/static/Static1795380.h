// Source exposure: binary-analysis; no external implementation source reused.
// Static1795380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795380*);
    virtual void release(Static1795380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795380*);
struct Static1795380 {
    void* value;
    Static1795380();
    ~Static1795380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
