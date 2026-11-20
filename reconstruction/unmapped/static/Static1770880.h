// Source exposure: binary-analysis; no external implementation source reused.
// Static1770880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770880*);
    virtual void release(Static1770880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770880*);
struct Static1770880 {
    void* value;
    Static1770880();
    ~Static1770880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
