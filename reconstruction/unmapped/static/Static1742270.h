// Source exposure: binary-analysis; no external implementation source reused.
// Static1742270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742270*);
    virtual void release(Static1742270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742270*);
struct Static1742270 {
    void* value;
    Static1742270();
    ~Static1742270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
