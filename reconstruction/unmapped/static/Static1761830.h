// Source exposure: binary-analysis; no external implementation source reused.
// Static1761830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761830*);
    virtual void release(Static1761830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761830*);
struct Static1761830 {
    void* value;
    Static1761830();
    ~Static1761830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
