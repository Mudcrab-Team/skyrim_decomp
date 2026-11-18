// Source exposure: binary-analysis; no external implementation source reused.
// Static1784880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784880*);
    virtual void release(Static1784880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784880*);
struct Static1784880 {
    void* value;
    Static1784880();
    ~Static1784880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
