// Source exposure: binary-analysis; no external implementation source reused.
// Static1757e70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757e70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757e70*);
    virtual void release(Static1757e70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757e70*);
struct Static1757e70 {
    void* value;
    Static1757e70();
    ~Static1757e70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
