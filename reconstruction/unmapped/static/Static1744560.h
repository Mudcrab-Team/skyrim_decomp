// Source exposure: binary-analysis; no external implementation source reused.
// Static1744560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744560*);
    virtual void release(Static1744560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744560*);
struct Static1744560 {
    void* value;
    Static1744560();
    ~Static1744560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
