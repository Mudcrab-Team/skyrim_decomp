// Source exposure: binary-analysis; no external implementation source reused.
// Static1750530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750530*);
    virtual void release(Static1750530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750530*);
struct Static1750530 {
    void* value;
    Static1750530();
    ~Static1750530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
