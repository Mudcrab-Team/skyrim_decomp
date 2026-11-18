// Source exposure: binary-analysis; no external implementation source reused.
// Static1750030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750030*);
    virtual void release(Static1750030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750030*);
struct Static1750030 {
    void* value;
    Static1750030();
    ~Static1750030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
