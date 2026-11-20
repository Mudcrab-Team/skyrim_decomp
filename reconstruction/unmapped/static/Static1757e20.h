// Source exposure: binary-analysis; no external implementation source reused.
// Static1757e20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757e20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757e20*);
    virtual void release(Static1757e20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757e20*);
struct Static1757e20 {
    void* value;
    Static1757e20();
    ~Static1757e20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
