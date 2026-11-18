// Source exposure: binary-analysis; no external implementation source reused.
// Static1782710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782710*);
    virtual void release(Static1782710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782710*);
struct Static1782710 {
    void* value;
    Static1782710();
    ~Static1782710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
