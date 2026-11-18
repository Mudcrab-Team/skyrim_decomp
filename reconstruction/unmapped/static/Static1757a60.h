// Source exposure: binary-analysis; no external implementation source reused.
// Static1757a60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757a60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757a60*);
    virtual void release(Static1757a60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757a60*);
struct Static1757a60 {
    void* value;
    Static1757a60();
    ~Static1757a60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
