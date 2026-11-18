// Source exposure: binary-analysis; no external implementation source reused.
// Static1761470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761470*);
    virtual void release(Static1761470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761470*);
struct Static1761470 {
    void* value;
    Static1761470();
    ~Static1761470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
