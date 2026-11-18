// Source exposure: binary-analysis; no external implementation source reused.
// Static1750990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750990*);
    virtual void release(Static1750990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750990*);
struct Static1750990 {
    void* value;
    Static1750990();
    ~Static1750990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
