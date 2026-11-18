// Source exposure: binary-analysis; no external implementation source reused.
// Static177c810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c810*);
    virtual void release(Static177c810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c810*);
struct Static177c810 {
    void* value;
    Static177c810();
    ~Static177c810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
