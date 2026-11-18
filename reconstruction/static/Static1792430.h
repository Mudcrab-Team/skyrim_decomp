// Source exposure: binary-analysis; no external implementation source reused.
// Static1792430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792430*);
    virtual void release(Static1792430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792430*);
struct Static1792430 {
    void* value;
    Static1792430();
    ~Static1792430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
