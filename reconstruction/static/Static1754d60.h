// Source exposure: binary-analysis; no external implementation source reused.
// Static1754d60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754d60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754d60*);
    virtual void release(Static1754d60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754d60*);
struct Static1754d60 {
    void* value;
    Static1754d60();
    ~Static1754d60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
