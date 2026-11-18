// Source exposure: binary-analysis; no external implementation source reused.
// Static1757880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757880*);
    virtual void release(Static1757880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757880*);
struct Static1757880 {
    void* value;
    Static1757880();
    ~Static1757880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
