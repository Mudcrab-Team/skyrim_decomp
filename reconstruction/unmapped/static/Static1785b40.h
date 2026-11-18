// Source exposure: binary-analysis; no external implementation source reused.
// Static1785b40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785b40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785b40*);
    virtual void release(Static1785b40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785b40*);
struct Static1785b40 {
    void* value;
    Static1785b40();
    ~Static1785b40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
