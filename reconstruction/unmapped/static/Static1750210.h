// Source exposure: binary-analysis; no external implementation source reused.
// Static1750210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750210*);
    virtual void release(Static1750210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750210*);
struct Static1750210 {
    void* value;
    Static1750210();
    ~Static1750210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
