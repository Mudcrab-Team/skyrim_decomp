// Source exposure: binary-analysis; no external implementation source reused.
// Static1797b10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1797b10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1797b10*);
    virtual void release(Static1797b10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1797b10*);
struct Static1797b10 {
    void* value;
    Static1797b10();
    ~Static1797b10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
