// Source exposure: binary-analysis; no external implementation source reused.
// Static1784470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784470*);
    virtual void release(Static1784470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784470*);
struct Static1784470 {
    void* value;
    Static1784470();
    ~Static1784470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
