// Source exposure: binary-analysis; no external implementation source reused.
// Static1757650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757650*);
    virtual void release(Static1757650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757650*);
struct Static1757650 {
    void* value;
    Static1757650();
    ~Static1757650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
