// Source exposure: binary-analysis; no external implementation source reused.
// Static1750e40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750e40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750e40*);
    virtual void release(Static1750e40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750e40*);
struct Static1750e40 {
    void* value;
    Static1750e40();
    ~Static1750e40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
