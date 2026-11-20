// Source exposure: binary-analysis; no external implementation source reused.
// Static1775560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775560*);
    virtual void release(Static1775560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775560*);
struct Static1775560 {
    void* value;
    Static1775560();
    ~Static1775560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
