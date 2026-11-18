// Source exposure: binary-analysis; no external implementation source reused.
// Static1764ad0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764ad0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764ad0*);
    virtual void release(Static1764ad0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764ad0*);
struct Static1764ad0 {
    void* value;
    Static1764ad0();
    ~Static1764ad0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
