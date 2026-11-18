// Source exposure: binary-analysis; no external implementation source reused.
// Static1761060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761060*);
    virtual void release(Static1761060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761060*);
struct Static1761060 {
    void* value;
    Static1761060();
    ~Static1761060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
