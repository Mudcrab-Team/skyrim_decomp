// Source exposure: binary-analysis; no external implementation source reused.
// Static1757560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757560*);
    virtual void release(Static1757560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757560*);
struct Static1757560 {
    void* value;
    Static1757560();
    ~Static1757560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
