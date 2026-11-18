// Source exposure: binary-analysis; no external implementation source reused.
// Static1753000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753000*);
    virtual void release(Static1753000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753000*);
struct Static1753000 {
    void* value;
    Static1753000();
    ~Static1753000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
