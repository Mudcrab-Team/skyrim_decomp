// Source exposure: binary-analysis; no external implementation source reused.
// Static178a810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a810*);
    virtual void release(Static178a810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a810*);
struct Static178a810 {
    void* value;
    Static178a810();
    ~Static178a810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
