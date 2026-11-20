// Source exposure: binary-analysis; no external implementation source reused.
// Static1766880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766880*);
    virtual void release(Static1766880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766880*);
struct Static1766880 {
    void* value;
    Static1766880();
    ~Static1766880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
