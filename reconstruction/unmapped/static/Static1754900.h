// Source exposure: binary-analysis; no external implementation source reused.
// Static1754900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754900*);
    virtual void release(Static1754900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754900*);
struct Static1754900 {
    void* value;
    Static1754900();
    ~Static1754900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
