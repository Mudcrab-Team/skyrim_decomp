// Source exposure: binary-analysis; no external implementation source reused.
// Static1741880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741880*);
    virtual void release(Static1741880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741880*);
struct Static1741880 {
    void* value;
    Static1741880();
    ~Static1741880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
