// Source exposure: binary-analysis; no external implementation source reused.
// Static1750080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750080*);
    virtual void release(Static1750080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750080*);
struct Static1750080 {
    void* value;
    Static1750080();
    ~Static1750080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
