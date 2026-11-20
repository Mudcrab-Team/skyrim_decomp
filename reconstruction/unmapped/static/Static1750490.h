// Source exposure: binary-analysis; no external implementation source reused.
// Static1750490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750490*);
    virtual void release(Static1750490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750490*);
struct Static1750490 {
    void* value;
    Static1750490();
    ~Static1750490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
